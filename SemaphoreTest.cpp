#include "gmock/gmock.h"
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>

using namespace testing;

TEST(SemaphoreTest,InitialCreation) {
  Semaphore semaphore(5);
}

TEST(SemaphoreTest,WaitSignal) {
  Semaphore semaphore(1);
  semaphore.wait();
  semaphore.signal();
  semaphore.wait();
}

TEST(SemaphoreTest, WaitForever) {
  Semaphore semaphore(0);
  semaphore.wait();
}

TEST(SemaphoreTest,Rendezvous) {
  std::vector<std::shared_ptr<std::thread>> threads;
  Semaphore aArrived(0);
  Semaphore bArrived(0);

  //Thread A
  threads.push_back(
    std::make_shared<std::thread>([&] {
      std::cout << "statement a1" << std::endl;
      aArrived.signal();
      bArrived.wait();
      std::cout << "statement a2" << std::endl;
    })
  );

  //Thread B
  threads.push_back(
    std::make_shared<std::thread>([&] {
      std::cout << "statement b1" << std::endl;
      bArrived.signal();
      aArrived.wait();
      std::cout << "statement b2" << std::endl;
    })
  );

  for (auto& t: threads) t->join();

}

TEST(SemaphoreTest,DISABLED_RendezvousDeadLock) {
  std::vector<std::shared_ptr<std::thread>> threads;
  Semaphore aArrived(0);
  Semaphore bArrived(0);

  //Thread A
  threads.push_back(
    std::make_shared<std::thread>([&] {
      std::cout << "statement a1" << std::endl;
      bArrived.wait();
      aArrived.signal();
      std::cout << "statement a2" << std::endl;
    })
  );

  //Thread B
  threads.push_back(
    std::make_shared<std::thread>([&] {
      std::cout << "statement b1" << std::endl;
      aArrived.wait();
      bArrived.signal();
      std::cout << "statement b2" << std::endl;
    })
  );

  for (auto& t: threads) t->join();

}

TEST(SemaphoreTest,Mutex) {
  std::vector<std::shared_ptr<std::thread>> threads;
  Semaphore mutex(1);
  int count=0;
  int numberOfThreads=50;
  int numberOfIncrements=10000;

  for(int i=0 ; i < numberOfThreads; i++) {
    threads.push_back(
      std::make_shared<std::thread>([&] {
        for(int j=0; j< numberOfIncrements; j++) {
          mutex.wait();
          count++;
          mutex.signal();
        }
      })
    );
  }

  for (auto& t: threads) t->join();
  ASSERT_THAT(count, Eq(numberOfThreads*numberOfIncrements));
}
