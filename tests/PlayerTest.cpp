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
