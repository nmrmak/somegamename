#ifndef FUNWITHKRLE_ICANVAS_H
#define FUNWITHKRLE_ICANVAS_H
#include <list>
#include "Position.h"

class ICanvas {
    virtual void drawPoint(float x, float y, float pointSize) = 0;
    virtual void drawPoints(std::list<Position>, float pointSize) = 0;
};


#endif //FUNWITHKRLE_ICANVAS_H
