#include "Player.h"
#include <string.h>
#include <GL/glut.h>
#include <TextureLoader.h>
#include <math.h>
#include <iostream>
#include <Timer.h>
using namespace std;

#define PI 3.14159265


Player::Player()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0 - 0.001;
    xScale = 0.1;
    yScale = 0.1;
    zScale = 1.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    rotation = 0;
    speed = 0.004;
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

    glTexCoord2f(xMin,yMax);
    glVertex3f(-0.5, -0.5, 0.0);

    glTexCoord2f(xMax,yMax);
    glVertex3f(0.5, -0.5, 0.0);

    glTexCoord2f(xMax,yMin);
    glVertex3f(0.5, 0.5, 0.0);

    glTexCoord2f(xMin,yMin);
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
    idle->LoadTexture("images/playerT.png");
    xMin = 0.0;
    yMin = 0.0;
    xMax = 1.0/8.0;
    yMax = .18;

    /*xMin = 0.06;
    yMin = 0.21258;
    xMax = 0.16;
    yMax = 0.2350299;*/

}

void Player::playerInput(Inputs *KbMs)
{
    if(KbMs->isKeyPressed(0x57)){// w key
        y += speed;
        rotation = 0;
        cout<<"getTicks == "<<animationTimer.getTicks()<<endl;
        if(spawnTimer.getTicks() > 100)
        {
            xMin += .25;
            xMax += .25;
            spawnTimer.reset();
        }

    }else if(KbMs->isKeyPressed(0x41)){// a key
        x -= speed;
        rotation = 90.0;
        cout<<"getTicks == "<<animationTimer.getTicks()<<endl;
        if(animationTimer.getTicks() > 100)
        {
            xMin += .25;
            xMax += .25;
            animationTimer.reset();
        }
    }else if(KbMs->isKeyPressed(0x53)){// s key
        y -= speed;
        rotation = 180.0;
        cout<<"getTicks == "<<animationTimer.getTicks()<<endl;
        if(animationTimer.getTicks() > 100)
        {
            xMin += .25;
            xMax += .25;
            animationTimer.reset();
        }
    }else if(KbMs->isKeyPressed(0x44)){// d key
        x += speed;
        rotation = -90.0;
        cout<<"getTicks == "<<animationTimer.getTicks()<<endl;
        if(animationTimer.getTicks() > 100)
        {
            xMin += .25;
            xMax += .25;
            animationTimer.reset();
        }
    }else{
        xMin = 0.0;
        xMax = 1.0/8.0;
    }
    if(KbMs->isKeyPressed(0x20) && spawnTimer.getTicks() > 500){// spacebar
        if(rotation == 0.0)
        {
            objectList->createProjectile(x + .035, y, 0.0, speed, rotation); //now includes angle (.035 to adjust spawn point for now)
        }else if(rotation == 180.0)
        {
            objectList->createProjectile(x - .035, y, 0.0, -speed, rotation); //now includes angle
        }else if(rotation == 90.0)
        {
            objectList->createProjectile(x, y + .035, -speed, 0.0, rotation); //now includes angle
        }else if(rotation == -90.0)
        {
            objectList->createProjectile(x, y - .035, speed, 0.0, rotation); //now includes angle
        }

        spawnTimer.reset();
    }
    if(KbMs->isKeyPressed(16)&& spawnTimer.getTicks() > 1000){// L shift (hold shift to place mine)
        objectList->createObj(x, y);
        spawnTimer.reset();
    }
}

