#include "GLScene.h"
#include <GLLight.h>
#include <Inputs.h>
#include <iostream>
#include <Model.h>
#include <Parallax.h>
#include <Player.h>
#include <GameObject.h>
#include <Timer.h>

Inputs *KbMs = new Inputs();
Parallax *Plx = new Parallax();
Player *player = new Player();

ObjList *objectList = new ObjList(100);


GLScene::GLScene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}
GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // For smooth animation transitions
    glClearColor(0.6f, 0.8f, 0.8f, 0.0f); // set Background color (R,G,B,A)
    glClearDepth(1.0d); // What is in front and behind
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0); // Create light
    Light.setLight(GL_LIGHT0); // Set up light

    Plx->parallaxInit("images/parallax.png");
    player->playerInit(objectList);
    objectList->initTextures();

    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(10);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        glVertex3d(0,0,-1.0);
        glVertex3d(-0.5,0,-1.0);
        //glVertex3d(0.5,0,-1.0);
    glEnd();

    glPushMatrix(); // draw the background object
    Plx->drawSquare(screenWidth,screenHeight);
    glPopMatrix();

    player->drawPlayer();

    objectList->draw();

}

GLint GLScene::idleGLScene()
{
    player->playerInput(KbMs);
    objectList->runPerFrame();
}


GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspectRatio,0.1,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}
int GLScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
            KbMs->wParam = wParam;
            KbMs->keyPressed();
            KbMs->keyEnv(Plx,0.001);
            if(KbMs->isKeyPressed(0x50)){// p key
                if(Timer::isPaused()){
                    Timer::unpause();
                }else{
                    Timer::pause();
                }
            }
            break;
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
            KbMs->wParam = wParam;
            KbMs->keyUp();
			break;
		}
		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            cout << LOWORD(lParam) << " " << HIWORD(lParam) << endl;
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
        break;								// Jump Back
        }
    }
}
