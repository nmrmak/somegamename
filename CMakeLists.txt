cmake_minimum_required(VERSION 3.12)
project(funwithkrle)

set(CMAKE_CXX_STANDARD 17)
get_filename_component(gtest_SOURCE_DIR "./gtest" ABSOLUTE)


add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/googletest/include)
include_directories(${gtest_SOURCE_DIR}/googlemock/include)

add_executable(funwithkrle main.cpp tests/GameServerTest.cpp)

target_link_libraries(funwithkrle gtest gtest_main)
target_link_libraries(funwithkrle gmock gmock_main)