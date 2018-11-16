#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/include/Player.h"
#include <string>

TEST(PlayerTest, GetName) {
    std::string testName("Pera");
    Player player(testName, Player::Color::RED);
    ASSERT_EQ(player.getName(), testName);
}

TEST(PlayerTest, GetSetScore) {
    Player player("", Player::Color::BLUE);
    constexpr unsigned int testScore = 5;
    player.setScore(testScore);
    ASSERT_EQ(player.getScore(), testScore);
}

TEST(PlayerTest, GetSetColor) {
    constexpr Player::Color testColor = Player::Color::GREEN;
    Player player("", testColor);
    ASSERT_EQ(player.getColor(), testColor);
}

TEST(PlayerTest, NameColorConstructor)
{

}