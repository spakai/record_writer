#include "gmock/gmock.h" 
#include "Singleton.h"

using namespace testing;

TEST(SingletonTest,CheckIfObjectIsSame) {

    class SingletonTest : public Singleton<SingletonTest> 
    {
        private:
            int value;
        public:
            void setVar(int value) { this->value = value; };
            int getVar() { return value;};
    };

    new SingletonTest();
    SingletonTest &singletonTest { SingletonTest::GetSingleton() };     
    singletonTest.setVar(120578);
    SingletonTest &anotherSingleton { SingletonTest::GetSingleton() };     
    ASSERT_THAT(singletonTest.getVar(),Eq(anotherSingleton.getVar()));

}

TEST(SingletonTest,ThrowsIfObjectisCreatedAgain) {

    class SingletonTest : public Singleton<SingletonTest> 
    {
        private:
            int value;
        public:
            void setVar(int value) { this->value = value; };
            int getVar() { return value;};
    };

    new SingletonTest();
    ASSERT_DEATH(new SingletonTest(),"Assertion `m_Instance == nullptr' failed");

}
