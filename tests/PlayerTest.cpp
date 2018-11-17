#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/include/CPlayer.h"
#include <string>

TEST(PlayerTest, GetName) {
    std::string testName("Pera");
    CPlayer player(testName, CPlayer::Color::RED);
    ASSERT_EQ(player.getName(), testName);
}

TEST(PlayerTest, GetSetScore) {
    CPlayer player("", CPlayer::Color::BLUE);
    constexpr unsigned int testScore = 5;
    player.setScore(testScore);
    ASSERT_EQ(player.getScore(), testScore);
}

TEST(PlayerTest, GetSetColor) {
    constexpr CPlayer::Color testColor = CPlayer::Color::GREEN;
    CPlayer player("", testColor);
    ASSERT_EQ(player.getColor(), testColor);
}

TEST(PlayerTest, GetSetPosition) {
    CPlayer player("", CPlayer::Color::VIOLET);
    constexpr unsigned int testX = 10;
    constexpr unsigned int testY = 10;
    player.setPosition(Position(testX, testY));
    ASSERT_EQ(player.getPosition().x, testX);
    ASSERT_EQ(player.getPosition().y, testY);
}

TEST(PlayerTest, GetSetVelocity) {
    CPlayer player("", CPlayer::Color::VIOLET);
    constexpr unsigned int testX = 10;
    constexpr unsigned int testY = 10;
    player.setVelocity(CPlayer::Velocity(testX, testY));
    ASSERT_EQ(player.getVelocity().x, testX);
    ASSERT_EQ(player.getVelocity().y, testY);
}

TEST(PlayerTest, NameColorConstructor)
{
    const std::string testName = "TestName";
    CPlayer::Color testColor = CPlayer::Color::YELLOW;
    CPlayer player(testName, testColor);
    ASSERT_EQ(player.getColor(), testColor);
    ASSERT_EQ(player.getName(), testName);
}