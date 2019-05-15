#include "GLScene.h"
#include <GLLight.h>
#include <Inputs.h>
#include <iostream>
#include <Model.h>
#include <Parallax.h>
#include <Player.h>
#include <GameObject.h>
#include <Timer.h>
#include <Menus.h>
#include <LevelGen.h>
#include <sound.h>
#include <particles.h>
///
#include <time.h>
#include <stdlib.h>
///

Inputs *KbMs = new Inputs();
Parallax *Plx = new Parallax();
Player *player = new Player();
Menus *menu = new Menus();
LevelGen *level = new LevelGen();
sound* SND = new sound();
particles* p = new particles();
Timer* T = new Timer();
Timer* bt = new Timer();
Timer* rt = new Timer();
Timer* lt = new Timer();

int eindex;///27 a change

double tempX, tempY = 0.0;

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
GLint GLScene::initGL(bool* quit)
{
    //bossExist = false;

    closeGame = quit;
    glShadeModel(GL_SMOOTH); // For smooth animation transitions
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // set Background color (R,G,B,A)
    glClearDepth(1.0d); // What is in front and behind
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0); // Create light
    Light.setLight(GL_LIGHT0); // Set up light

    menu->landingMenuInit("images/landPage.png");
    menu->mainMenuInit("images/mMfix.png");
    menu->helpMenuInit("images/helpMenu.png");
    menu->pauseMenuInit("images/pauseMenu.png");
    menu->creditMenuInit("images/creditMenu.png");
    menu->gameOverMenuInit("images/gameOverMenu.png");
    menu->victoryMenuInit("images/victoryMenu.png");
    Plx->parallaxInit("images/test2.png");
    player->playerInit(objectList, level);
    //objectList->objListInit(level);
    objectList->objListInit(level, player); /// a change 68
    level->InitLevelGen(objectList);
    level->generateLevels();

    for(int y=0; y < y_tiles; y++){
        for(int x=0; x < x_tiles; x++){
                cout << level->getWallMatrix(level->getTileIndex(x,y)) << " ";
        }
        cout << endl;
    }
    eindex = objectList->createEnemy(0.5,0.2);/// a change 77
    SND->playMusic("sounds/underworld.mp3");
    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    glPointSize(3);
    glTranslated(tempX,tempY,0.0);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        glVertex3d(0,0,-1.05);
    glEnd();

    //glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    if(menu->inMenu)
    {
        glPushMatrix();
        menu->drawMenus(screenWidth, screenHeight);
        glPopMatrix();
    }

    else
    {
        if(!Timer::isPaused())
        {
            glPushMatrix(); // draw the background object
                //Plx->drawSquare(screenWidth,screenHeight);
            glPopMatrix();

            level->drawLevel();

            player->drawPlayer();
            objectList->draw();

        }

    }

    /*glPushMatrix(); // draw the background object
    Plx->drawSquare(screenWidth,screenHeight);
    glPopMatrix();*/

    //glPushMatrix();
    //p->generateParticles(1,1);
    //p->drawParticles();
    //p->lifeTime();
    //glPopMatrix();

}




GLint GLScene::idleGLScene()
{
    menu->menuInputs(KbMs,closeGame);

    if(menu->inMenu == false){ // if the game is running

        player->playerInput(KbMs);
        player->runperframe();
        objectList->runPerFrame();
        ///COLLISIONS
        objectList->collisioncheckEpW();
        objectList->collisioncheckBpW();
        objectList->collisioncheckBhrpW();
        objectList->collisioncheckBhlpW();
        objectList->collisioncheckBfrpW();
        objectList->collisioncheckBflpW();
        objectList->collisioncheckSppW();
        srand(time(NULL));
        ///FOR BOSS PROJETILES
    ///BOSSES FACE PROJECTILE SPAWN///////////////////////////////////////////////////////////////////
        if(bt->getTicks() > 3200) ///For Now                                                       ///
        {                                                                                          ///
            for(int i = 0; i < objectList->Size(); i++)                                            ///
            {                                                                                      ///
                if(objectList->getObj(i) == NULL){}                                                ///
                else if(objectList->getObj(i)->typeCheck == 'a')                                   ///
                {                                                                                  ///
                                                                                 ///
                    int atk = rand()%10+1;                                                         ///
                    if( (objectList->getObj(i)->HP > 0) && (atk >= 3))                             ///
                    {                                                                              ///
                         objectList->bossAtk(i);
                         objectList->getObj(i)->attacking = true;                                                   ///
                    }                                                                              ///
                    if( (objectList->getObj(i)->HP > 0) && (atk < 3))                              ///
                    {                                                                              ///
                        objectList->createEnemy(objectList->getObj(i)->x,objectList->getObj(i)->y-.05);///
                        objectList->getObj(i)->attacking = true;
                    }                                                                              ///
                }                                                                                  ///
            }                                                                                      ///
            bt->reset();                                                                           ///
        }                                                                                          ///
    /// //////////////////////////////////////////////////////////////////////////////////////////////

    ///BOSS RIGHT HAND ATTACKING PROJECTILE SPAWN////////////////////
        if(rt->getTicks() > 3500) ///For Now                      ///
        {                                                         ///
            for(int i = 0; i < objectList->Size(); i++)           ///
            {                                                     ///
                if(objectList->getObj(i) == NULL){}               ///
                else if(objectList->getObj(i)->typeCheck == 'r')  ///
                {                                                 ///
                    if(objectList->getObj(i)->HP > 0)             ///
                    {                                             ///
                        objectList->rightHandAtk(i);              ///
                        objectList->getObj(i)->attacking = true;  ///causes attacking ani
                    }                                             ///
                }                                                 ///
            }                                                     ///
            rt->reset();                                          ///
        }                                                         ///
    /// /////////////////////////////////////////////////////////////

    ///BOSS LEFT HAND ATTACKING PROJECTILE SPAWN/////////////////////
        if(lt->getTicks() > 4000) ///For Now                      ///
        {                                                         ///
            for(int i = 0; i < objectList->Size(); i++)           ///
            {                                                     ///
                if(objectList->getObj(i) == NULL){}               ///
                else if(objectList->getObj(i)->typeCheck == 'l')  ///
                {                                                 ///
                    if(objectList->getObj(i)->HP > 0)             ///
                    {                                             ///
                        objectList->leftHandAtk(i);               ///
                        objectList->getObj(i)->attacking = true;  ///causes attacking ani
                    }                                             ///
                }                                                 ///
            }                                                     ///
            lt->reset();                                          ///
        }                                                         ///
    /// /////////////////////////////////////////////////////////////

    ///BOSS PROJECTILE MOTION////////////////////////////// ADJUST?
    for(int i = 0; i < objectList->Size(); i++)         ///
    {                                                   ///
        if(objectList->getObj(i) == NULL){}             ///
        else if(objectList->getObj(i)->typeCheck == 'z')///
        {                                               ///
            double projX = objectList->getObj(i)->x;    ///
            double projY = objectList->getObj(i)->y;    ///
            double slopeX = player->x - projX;          ///
            double slopeY = player->y - projY;          ///
            objectList->getObj(i)->x += (slopeX*.005);  ///
            objectList->getObj(i)->y += (slopeY*.005);  ///
        }                                               ///
    }                                                   ///
    /// ///////////////////////////////////////////////////

    /// TEMP ENEMY MOTION /////////////////////////////////
    /*for(int i = 0; i < objectList->Size(); i++)         ///
    {                                                   ///
        if(objectList->getObj(i) == NULL){}             ///
        else if(objectList->getObj(i)->typeCheck == 'g')///
        {                                               ///
            double projX = objectList->getObj(i)->x;    ///
            double projY = objectList->getObj(i)->y;    ///
            double slopeX = player->x - projX;          ///
            double slopeY = player->y - projY;          ///
            objectList->getObj(i)->x += (slopeX*.005);  ///
            objectList->getObj(i)->y += (slopeY*.005);  ///
        }                                               ///
    }*/                                                   ///
    /// ///////////////////////////////////////////////////

    /// //////////////////////
    double pX = player->x; ///
    double pY = player->y; ///
    /// //////////////////////

    ///FIRE FIST RIGHT PROJECTILE MOTION///////////////////////////////
    /*for(int i = 0; i < objectList->Size(); i++)
    {
        if(objectList->getObj(i) == NULL){}
        else if(objectList->getObj(i)->typeCheck == 'x')
        {
            double projX = objectList->getObj(i)->x;
            double projY = objectList->getObj(i)->y;
            if(pX > 0) ///POSITIVE
            {
                if(pX >= projX){objectList->getObj(i)->x+=.003;}
            }
            else       ///NEGATIVE
            {
                if(pX <= projX){objectList->getObj(i)->x-=.003;}
            }
            if(pY > 0) ///POSITIVE
            {
                if(pY >= projY){objectList->getObj(i)->y+=.003;}
            }
            else       ///NEGATIVE
            {
                if(pY <= projY){objectList->getObj(i)->y-=.003;}
            }
        }
    }*/
    /// /////////////////////////////////////////////////////////////

    ///FIRE FIST LEFT PROJECTILE MOTION//////////////////////////////
    /*for(int i = 0; i < objectList->Size(); i++)
        {
        if(objectList->getObj(i) == NULL){}
        else if(objectList->getObj(i)->typeCheck == 'y')
        {
            double projX = objectList->getObj(i)->x;
            double projY = objectList->getObj(i)->y;
            if(pX > 0) ///POSITIVE
            {
                if(pX >= projX){objectList->getObj(i)->x+=.003;}
            }
            else       ///NEGATIVE
            {
                if(pX <= projX){objectList->getObj(i)->x-=.003;}
            }
            if(pY > 0) ///POSITIVE
            {
                if(pY >= projY){objectList->getObj(i)->y+=.003;}
            }
            else       ///NEGATIVE
            {
                if(pY <= projY){objectList->getObj(i)->y-=.003;}
            }
        }
    }*/
    /// /////////////////////////////////////////////////////////////
    }

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
            KbMs->keySounds(SND);

            /* if(KbMs->isKeyPressed(VK_UP)){// up
                tempY += 0.001;
                cout << "Y: " << tempY << endl;
            }else if(KbMs->isKeyPressed(VK_DOWN)){// up
                tempY -= 0.001;
                cout << "Y: " << tempY << endl;
            }else if(KbMs->isKeyPressed(VK_LEFT)){// up
                tempX -= 0.001;
                cout << "X: " << tempX << endl;
            }else if(KbMs->isKeyPressed(VK_RIGHT)){// up
                tempX += 0.001;
                cout << "X: " << tempX << endl;
            }*/
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

bool GLScene::enemyPlayerCollision(double pX, double pY, double eX, double eY)
{
    for(int i = 0; i < objectList->Size(); i++)
    {
        double var = .05; //enemy and player
        if(objectList->getObj(i) == NULL){}
        //else if( fabs((pX-eX) ) && fabs() )
        //{
            //player hurt sound
            //increase player hit count (player's life status is checked in player's run per frame)
            //SND->playSound()
        //}

    }
    return false;
    /*
    for(int i = 0; i < size; i++) //
    {
        double var = .05; //enemy and gunfire (placeholder) //adjust later

        if(getObj(i) == NULL){}
        else if((fabs(getObj(i)->x - Ex) <= var) && (fabs(getObj(i)->y - Ey) <= var))
        {
            if(getObj(i)->typeCheck == 'f')
            {
                double ax = getObj(i)->x;
                double by = getObj(i)->y;
                getObj(i)->deleteSelf();
                //createExplosion(ax, by);
                return true;
            }
        }
    }
    return false;
    */
}

bool GLScene::bossPlayerCollision(double, double, double, double)
{
    //
}
