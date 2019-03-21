#include "Player.h"
#include <string.h>
#include <GL/glut.h>
#include <TextureLoader.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.14159265


Player::Player()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0 - 0.001;
    xScale = 0.2;
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
}

Player::~Player()
{
    //dtor
    delete idle;
}
void Player::drawPlayer()
{
    glPushMatrix();
    idle->binder();
    glTranslated(x,y,z);
    glRotated(rotation, 0,0,1);
    glScaled(xScale, yScale, zScale);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0,1.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glTexCoord2f(1.0,1.0);
    glVertex3f(0.5, -0.5, 0.0);

    glTexCoord2f(1.0,0.0);
    glVertex3f(0.5, 0.5, 0.0);

    glTexCoord2f(0.0,0.0);
    glVertex3f(-0.5, 0.5, 0.0);

    glEnd();
    glPopMatrix();
}

void Player::lookAt(double x3, double y3)
{

}

void Player::playerInit(ObjList* newObjectList)
{
    objectList = newObjectList;
    spawnTimer.start();
    idle = new TextureLoader();
    idle->LoadTexture("images/player.png");
}

void Player::playerInput(Inputs *KbMs)
{
    if(KbMs->isKeyPressed(0x57)){// w key
        y += 0.005;
    }
    if(KbMs->isKeyPressed(0x41)){// a key
        x -= 0.005;
    }
    if(KbMs->isKeyPressed(0x53)){// s key
        y -= 0.005;
    }
    if(KbMs->isKeyPressed(0x44)){// d key
        x += 0.005;
    }
    if(KbMs->isKeyPressed(0x20) && spawnTimer.getTicks() > 100){// spacebar
        objectList->createProjectile(x, y, ((rand()%100 * 0.0001) - 0.005), ((rand()%100 * 0.0001) - 0.005));
        spawnTimer.reset();
    }
    if(KbMs->isKeyPressed(16)&& spawnTimer.getTicks() > 100){// L shift
        objectList->createObj(x, y);
        spawnTimer.reset();
    }
}

