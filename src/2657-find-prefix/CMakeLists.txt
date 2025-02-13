cmake_minimum_required(VERSION 3.27)
#set(GOOGLETEST_VERSION 1.15.2)
project(2657) #name of your project
enable_testing() #to  discover tests in test explorer
#add_subdirectory(googletest) # add googletest subdirectory
#include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
add_executable(test_find_prefix test_find_prefix.cpp) # add this executable
target_link_libraries(test_find_prefix PRIVATE gtest gtest_main) # link google test to this executable
#gtest_discover_tests(test_take_k) # discovers tests by asking the compiled test executable to enumerate its tests