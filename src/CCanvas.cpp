#include "CCanvas.h"
#include <GL/glut.h>
#include <iostream>

void CCanvas::drawPoint(float x, float y, float pointSize) {
    std::cout << "Inside drawPoint in CCanvas" << std::endl << std::flush;
    std::cout << "x: " << x << ", y: " << y << ", pointSize: " << pointSize << std::endl;
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    (void) *redrawFn;
}

void CCanvas::drawPoints(std::list<Position> list, float pointSize) {

}

void CCanvas::setRedrawFunction(void (*newRedrawFn)()) {
    redrawFn = newRedrawFn;
}