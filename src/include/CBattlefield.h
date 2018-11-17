#ifndef FUNWITHKRLE_BATTLEFIELD_H
#define FUNWITHKRLE_BATTLEFIELD_H

#include <memory>
#include "ICanvas.h"

class CBattlefield {
public:
    CBattlefield() = delete;
    CBattlefield(std::shared_ptr<ICanvas>& canvas) : pCanvas(canvas) {}

private:
    std::shared_ptr<ICanvas> pCanvas;

};


#endif //FUNWITHKRLE_BATTLEFIELD_H
