#ifndef FUNWITHKRLE_PLAYER_H
#define FUNWITHKRLE_PLAYER_H
#include <string>
#include "IDrawable.h"
#include "Position.h"

class Player : IDrawable{
public:

    enum class Color {
        BLUE = 0x4285f4,
        RED = 0xea4335,
        YELLOW = 0xfbbc05,
        GREEN = 0x34a853,
        VIOLET = 0x673ab7
    };


    class Velocity {
    public:
        Velocity(int newX, int newY) : x(newX), y(newY) {}
        Velocity() = default;
        int x;
        int y;
    };

    Player() = delete;
    Player(const std::string &name, Color color);

    const Position &getPosition() const;
    void setPosition(const Position &position);

    const Velocity &getVelocity() const;
    void setVelocity(const Velocity &velocity);

    Color getColor() const;

    const std::string &getName() const;

    unsigned int getScore() const;
    void setScore(unsigned int score);

    void draw(std::shared_ptr<ICanvas> &canvas) override;

private:
    Position position;
    Velocity velocity;
    std::string name;
    unsigned int score;
    Color color;
};


#endif //FUNWITHKRLE_PLAYER_H
