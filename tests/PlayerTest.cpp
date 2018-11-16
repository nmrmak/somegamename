#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/include/Player.h"
#include <string>

TEST(PlayerTest, GetSetName) {
    Player player;
    std::string testName("Pera");
    player.setName("Pera");
    ASSERT_EQ(player.getName(), testName);
}

TEST(PlayerTest, GetSetScore) {
    Player player;
    constexpr unsigned int testScore = 5;
    player.setScore(testScore);
    ASSERT_EQ(player.getScore(), testScore);
}