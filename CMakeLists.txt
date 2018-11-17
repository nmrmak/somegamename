cmake_minimum_required(VERSION 3.12)
project(funwithkrle)

set(CMAKE_CXX_STANDARD 17)
get_filename_component(gtest_SOURCE_DIR "./gtest" ABSOLUTE)
get_filename_component(tests_SOURCE_DIR "./tests" ABSOLUTE)
get_filename_component(project_ROOT_DIR "." ABSOLUTE)

add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/googletest/include)
include_directories(${gtest_SOURCE_DIR}/googlemock/include)

add_executable(funwithkrle src/main.cpp src/CPlayer.cpp src/include/CPlayer.h src/include/IDrawable.h src/include/ICanvas.h src/include/Position.h src/CBattlefield.cpp src/include/CBattlefield.h src/CCanvas.cpp src/CCanvas.h)
add_library(funwithkrle_lib src/main.cpp src/CPlayer.cpp src/include/CPlayer.h)
target_link_libraries(funwithkrle GL GLU glut)

add_subdirectory(${tests_SOURCE_DIR})
