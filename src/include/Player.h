#ifndef FUNWITHKRLE_PLAYER_H
#define FUNWITHKRLE_PLAYER_H
#include <string>

class Player {
public:

    enum class Color {
        BLUE = 0x4285f4,
        RED = 0xea4335,
        YELLOW = 0xfbbc05,
        GREEN = 0x34a853,
        VIOLET = 0x673ab7
    };

private:

    std::string name;
    unsigned int score;
    Color color;
public:
    Player() = delete;
    Player(const std::string &name, Color color);
    Color getColor() const;

    unsigned int getScore() const;
    void setScore(unsigned int score);

    const std::string &getName() const;
};


#endif //FUNWITHKRLE_PLAYER_H
