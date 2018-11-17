#ifndef FUNWITHKRLE_POSITION_H
#define FUNWITHKRLE_POSITION_H

class Position {
public:
    Position(float newX, float newY) : x(newX), y(newY) {}
    Position() : x(0), y(0) {}
    float x;
    float y;
};

#endif //FUNWITHKRLE_POSITION_H
