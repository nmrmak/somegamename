#ifndef FUNWITHKRLE_CVELOCITY_H
#define FUNWITHKRLE_CVELOCITY_H

class Velocity {
public:
    Velocity(float aAngle, float aSpeed) : angle(aAngle), speed(aSpeed) {}
    Velocity() : angle(0), speed(1) {};
    void steerLeft(float degrees);
    void steerRight(float degrees);
    float getX(int elapsedMs);
    float getY(int elapsedMs);
private:
    float angle;
    float speed;
};

#endif //FUNWITHKRLE_CVELOCITY_H
