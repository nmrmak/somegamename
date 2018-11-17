#include <ICanvas.h>
#include <memory>
#include "include/CPlayer.h"

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

const Position &Player::getPosition() const {
    return position;
}

void Player::setPosition(const Position &position) {
    Player::position = position;
}

const Player::Velocity &Player::getVelocity() const {
    return velocity;
}

void Player::setVelocity(const Player::Velocity &velocity) {
    Player::velocity = velocity;
}

void Player::draw(std::shared_ptr<ICanvas> &canvas)
{
    constexpr float pointSize(5);
    canvas->drawPoint(position.x, position.y, pointSize);
}