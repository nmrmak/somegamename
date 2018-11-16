include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${project_ROOT_DIR})

add_executable(Unit_Tests_run
    PlayerTest.cpp
        ../src/Player.cpp ../src/include/Player.h main.cpp)

target_link_libraries(Unit_Tests_run gtest gmock)
target_link_libraries(Unit_Tests_run ${CMAKE_PROJECT_NAME}_lib)