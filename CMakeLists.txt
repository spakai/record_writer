project(record_writer)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_VERBOSE_MAKEFILE on)
include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)

add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -g")
set(sources 
   main.cpp
   Singleton.h
   Semaphore.h)
 
 set(test_sources
   SingletonTest.cpp
   SemaphoreTest.cpp)

add_executable(test ${test_sources} ${sources})

target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)
