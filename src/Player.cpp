#include "include/Player.h"

const std::string &Player::getName() const {
    return name;
}

unsigned int Player::getScore() const {
    return score;
}

void Player::setScore(unsigned int score) {
    Player::score = score;
}

Player::Color Player::getColor() const {
    return color;
}

Player::Player(const std::string &name, Player::Color color) : name(name), color(color), score(0)
{}
