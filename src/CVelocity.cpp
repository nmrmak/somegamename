#include "CVelocity.h"
#include <cmath>


float Velocity::getX(int elapsedMs) {
    return speed * elapsedMs / 1000 * cosf(angle / 180 * static_cast<float>(M_PI));
}

float Velocity::getY(int elapsedMs) {
    return speed * elapsedMs / 1000 * sinf(angle / 180 * static_cast<float>(M_PI));
}
