#ifndef FUNWITHKRLE_CVELOCITY_H
#define FUNWITHKRLE_CVELOCITY_H

class Velocity {
public:
    Velocity(float aAzimuth, float aSpeed) : azimuth(aAzimuth), speed(aSpeed) {}
    Velocity() : azimuth(0), speed(1) {};
    void steerLeft(float degrees);
    void steerRight(float degrees);
    float getX();
    float getY();
private:
    float azimuth;
    float speed;
};

#endif //FUNWITHKRLE_CVELOCITY_H
