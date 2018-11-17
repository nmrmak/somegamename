#include "include/CBattlefield.h"

void CBattlefield::draw() {
    for(auto& element : drawableElements)
    {
        element->draw(pCanvas);
    }
}

void CBattlefield::addDrawable(std::shared_ptr<IDrawable> element) {
    drawableElements.emplace_back(element);
}