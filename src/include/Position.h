#ifndef FUNWITHKRLE_POSITION_H
#define FUNWITHKRLE_POSITION_H

class Position {
public:
    Position(int newX, int newY) : x(newX), y(newY) {}
    Position() = default;
    int x;
    int y;
};

#endif //FUNWITHKRLE_POSITION_H
