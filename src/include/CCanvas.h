#ifndef FUNWITHKRLE_CCANVAS_H
#define FUNWITHKRLE_CCANVAS_H

#include "ICanvas.h"

class CCanvas : public ICanvas {
public:
    void drawPoint(float x, float y, float pointSize) override;
    void drawPoints(std::list<Position> list, float pointSize) override;
    void setRedrawFunction(void(*newRedrawFn)()) override;
private:
    void(*redrawFn)();
};


#endif //FUNWITHKRLE_CCANVAS_H
