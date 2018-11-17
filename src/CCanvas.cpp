#include "CCanvas.h"
#include <GL/glut.h>

void CCanvas::drawPoint(float x, float y, float pointSize) {
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void CCanvas::drawPoints(std::list<Position> list, float pointSize) {

}
