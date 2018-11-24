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

TEST(PlayerTest, NameColorConstructor)
{
    const std::string testName = "TestName";
    CPlayer::Color testColor = CPlayer::Color::YELLOW;
    CPlayer player(testName, testColor);
    ASSERT_EQ(player.getColor(), testColor);
    ASSERT_EQ(player.getName(), testName);
}

TEST(PlayerTest, AdvancePosition)
{
    constexpr float startX = 0;
    constexpr float startY = 0;
    constexpr float speed = 0.1;
    constexpr float direction = 90;

    constexpr int elapsedTimeMs = 100;
    constexpr float expectedX = startX;
    constexpr float expectedY = startY + speed / 1000 * elapsedTimeMs;

    CPlayer player("name", CPlayer::Color::VIOLET);
    player.setPosition(Position(0,0));
    player.setVelocity(Velocity(direction,speed));
    player.advancePosition(elapsedTimeMs);

    ASSERT_NEAR(expectedX, player.getPosition().x, 1e-9);
    ASSERT_NEAR(expectedY, player.getPosition().y, 1e-9);
}