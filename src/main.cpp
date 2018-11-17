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
std::shared_ptr<CPlayer> pPlayer1 = nullptr;
std::shared_ptr<CPlayer> pPlayer2 = nullptr;

static void Reshape(int width, int height)
{

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timerTest(int val)
{
    std::cout << "timer test " << val << std::endl;
}

static void Key(unsigned char key, int x, int y)
{
    Position position = pPlayer1->getPosition();
    switch (key) {
        case '1':
            position.x -= 0.01;
            break;
        case '2':
            position.x += 0.01;
            break;
        case '3':
            glutTimerFunc(5000, timerTest, 3);
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
    pPlayer1->setPosition(position);
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

static void glutInitialization(int argc, char **argv)
{
    GLenum type;

    glutInit(&argc, argv);
    Args(argc, argv);

    type = GLUT_RGB | GLUT_ACCUM;
    type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(type);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Igrica");
}

int main(int argc, char **argv)
{
    glutInitialization(argc, argv);

    std::shared_ptr<ICanvas> canvas(new CCanvas());
    canvas->setRedrawFunction(Draw);

    CBattlefield battlefield(canvas);
    pBattlefield = std::make_unique<CBattlefield>(battlefield);

    Position startPositionPlayer1(-0.4, -0.2);
    Position startPositionPlayer2(0.6, 0.7);

    CPlayer player1("Player 1", CPlayer::Color::RED, startPositionPlayer1);
    CPlayer player2("Player 2", CPlayer::Color::BLUE, startPositionPlayer2);

    pPlayer1 = std::make_shared<CPlayer>(player1);
    pPlayer2 = std::make_shared<CPlayer>(player2);

    pBattlefield->addDrawable(pPlayer1);
    pBattlefield->addDrawable(pPlayer2);



    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Draw);
    glutMainLoop();
}