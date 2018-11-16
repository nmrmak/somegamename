cmake_minimum_required(VERSION 3.12)
project(funwithkrle)

set(CMAKE_CXX_STANDARD 17)
get_filename_component(gtest_SOURCE_DIR "./gtest" ABSOLUTE)


add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/googletest/include)
include_directories(${gtest_SOURCE_DIR}/googlemock/include)

add_executable(funwithkrle_test main_test.cpp tests/GameServerTest.cpp)
add_executable(funwithkrle main.cpp)

target_link_libraries(funwithkrle GL GLU glut)
target_link_libraries(funwithkrle_test gtest_main gmock gmock_main)
