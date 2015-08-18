#include "gmock/gmock.h" 

using namespace testing;

TEST(SingletonTest,NoMatchLookup) {
    ASSERT_THAT(1,Eq(1));
}
