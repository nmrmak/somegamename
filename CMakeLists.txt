cmake_minimum_required(VERSION 3.12)
project(funwithkrle)

set(CMAKE_CXX_STANDARD 17)
get_filename_component(gtest_SOURCE_DIR "./gtest" ABSOLUTE)
get_filename_component(tests_SOURCE_DIR "./tests" ABSOLUTE)
get_filename_component(project_ROOT_DIR "." ABSOLUTE)

add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/googletest/include)
include_directories(${gtest_SOURCE_DIR}/googlemock/include)

add_executable(funwithkrle src/main.cpp src/Player.cpp src/include/Player.h)
add_library(funwithkrle_lib src/main.cpp src/Player.cpp src/include/Player.h)
target_link_libraries(funwithkrle GL GLU glut)

add_subdirectory(${tests_SOURCE_DIR})
