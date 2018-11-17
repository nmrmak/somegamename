#ifndef FUNWITHKRLE_BATTLEFIELD_H
#define FUNWITHKRLE_BATTLEFIELD_H

#include <memory>
#include <vector>
#include "ICanvas.h"
#include "IDrawable.h"

class CBattlefield {
public:
    CBattlefield() = delete;
    CBattlefield(std::shared_ptr<ICanvas>& canvas) : pCanvas(canvas) {}
    void addDrawable(std::shared_ptr<IDrawable> element);
    void draw();

private:
    std::shared_ptr<ICanvas> pCanvas;
    std::vector<std::shared_ptr<IDrawable>> drawableElements;

};


#endif //FUNWITHKRLE_BATTLEFIELD_H
