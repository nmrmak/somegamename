include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${project_ROOT_DIR})

add_executable(Unit_Tests_run
    PlayerTest.cpp
        ../src/CPlayer.cpp
        ../src/include/CPlayer.h main.cpp
        ../src/CVelocity.cpp
        ../src/include/CVelocity.h
        ../src/CBattlefield.cpp
        ../src/include/CBattlefield.h
        ../src/CCanvas.cpp
        ../src/include/CCanvas.h)

target_link_libraries(Unit_Tests_run gtest gmock GL GLU glut)
target_link_libraries(Unit_Tests_run ${CMAKE_PROJECT_NAME}_lib)