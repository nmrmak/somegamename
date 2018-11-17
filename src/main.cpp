#include <iostream>
#include <gmock/gmock.h>

#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <CPlayer.h>
#include "CCanvas.h"
#include "CBattlefield.h"


GLenum doubleBuffer;
std::unique_ptr<CBattlefield> pBattlefield = nullptr;
std::shared_ptr<CPlayer> pPlayer = nullptr;


static void Init(void)
{

}

static void Reshape(int width, int height)
{

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void Key(unsigned char key, int x, int y)
{
    Position position = pPlayer->getPosition();
    switch (key) {
        case '1':
            position.x -= 0.01;
            break;
        case '2':
            position.x += 0.01;
            break;
        case '8':
            position.y -= 0.01;
            break;
        case '9':
            position.y += 0.01;
            break;
        case 27:
            exit(0);
    }
    pPlayer->setPosition(position);
    glutPostRedisplay();
}

static void Draw(void)
{

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearAccum(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    std::cout << "Inside main Draw" << std::endl <<std::flush;
    pBattlefield->draw();

    glPopMatrix();

    if (doubleBuffer) {
        glutSwapBuffers();
    } else {
        glFlush();
    }
}

static void Args(int argc, char **argv)
{
    GLint i;

    doubleBuffer = GL_FALSE;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-sb") == 0) {
            doubleBuffer = GL_FALSE;
        } else if (strcmp(argv[i], "-db") == 0) {
            doubleBuffer = GL_TRUE;
        }
    }
}

int main(int argc, char **argv)
{
    GLenum type;

    glutInit(&argc, argv);
    Args(argc, argv);

    type = GLUT_RGB | GLUT_ACCUM;
    type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(type);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Igrica");

    Init();

    std::shared_ptr<ICanvas> canvas(new CCanvas());
    canvas->setRedrawFunction(Draw);
    CBattlefield battlefield(canvas);
    pBattlefield = std::make_unique<CBattlefield>(battlefield);
    CPlayer player("Pera", CPlayer::Color::RED);
    pPlayer = std::make_shared<CPlayer>(player);


    pBattlefield->addDrawable(pPlayer);

    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Draw);
    glutMainLoop();
}