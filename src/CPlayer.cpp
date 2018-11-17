#include <ICanvas.h>
#include <memory>
#include "include/CPlayer.h"

const std::string &CPlayer::getName() const {
    return name;
}

unsigned int CPlayer::getScore() const {
    return score;
}

void CPlayer::setScore(unsigned int score) {
    CPlayer::score = score;
}

CPlayer::Color CPlayer::getColor() const {
    return color;
}

CPlayer::CPlayer(const std::string &name, CPlayer::Color color) : name(name), color(color), score(0)
{}

const Position &CPlayer::getPosition() const {
    return position;
}

void CPlayer::setPosition(const Position &position) {
    CPlayer::position = position;
}

const CPlayer::Velocity &CPlayer::getVelocity() const {
    return velocity;
}

void CPlayer::setVelocity(const CPlayer::Velocity &velocity) {
    CPlayer::velocity = velocity;
}

void CPlayer::draw(std::shared_ptr<ICanvas> &canvas)
{
    constexpr float pointSize(5);
    canvas->drawPoint(position.x, position.y, pointSize);
}