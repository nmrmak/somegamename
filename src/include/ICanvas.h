#ifndef FUNWITHKRLE_ICANVAS_H
#define FUNWITHKRLE_ICANVAS_H
#include <list>
#include "Position.h"

class ICanvas {
    virtual void drawPoint(float x, float y) = 0;
    virtual void drawPoints(std::list<Position>) = 0;
};


#endif //FUNWITHKRLE_ICANVAS_H
