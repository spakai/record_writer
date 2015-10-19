#pragma once

#include <mutex>
#include <condition_variable>

class Semaphore {
public:

//1. When you create the semaphore, you can initialize its value to any
//integer, but after that the only operations you are allowed to perform are
//increment (increase by one) and decrement (decrease by one). You cannot
//read the current value of the semaphore.

  Semaphore(int n ) : n_(n) {};

//2. When a thread increments the semaphore, if there are other threads
//waiting, one of the waiting threads gets unblocked.

  void signal() {
    {
      std::unique_lock<std::mutex> ul(m_);
      ++n_;
    }
    cv_.notify_one();
  }

//3. When a thread decrements the semaphore, if the result is negative, the
//thread blocks itself and cannot continue until another thread increments
//the semaphore.

  void wait() {
    std::unique_lock<std::mutex> ul(m_);
    cv_.wait(ul,[&] { return n_ > 0;});
    --n_;
  }

  void P() {
    wait();
  }

  void V() {
    signal();
  }

private:
  int n_;
  std::mutex m_;
  std::condition_variable cv_;
};
