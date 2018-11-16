#include "include/Player.h"

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
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

void Player::setColor(Player::Color color) {
    Player::color = color;
}
