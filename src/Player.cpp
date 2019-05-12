#include "Player.h"
#include <string.h>
#include <GL/glut.h>
#include <TextureLoader.h>
#include <math.h>
#include <iostream>
#include <Timer.h>
using namespace std;

#define PI 3.14159265

sound* PS = new sound();


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
    healthPoints = 100;
    numberOfKeys = 10;
    BossKey = false;
    stillAlive = true;
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
///69
double Player::getX()
{
    return x;
}

double Player::getY()
{
    return y;
}
///79

void Player::playerInit(ObjList* newObjectList, LevelGen* newLevelGen)
{
    objectList = newObjectList;
    levelGenerator = newLevelGen;
    spawnTimer.start();
    Iframes.start();
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
        tempY = y + speed;
        if(!(levelGenerator->getWallMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(x), levelGenerator->coordToGridY(tempY)))) && !(levelGenerator->getPitMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(x), levelGenerator->coordToGridY(tempY))))){
                // if coord is not in solid or pit tile then
            y = tempY;
            if(animationTimer.getTicks() > 100)
            {
                xMin += .25;
                xMax += .25;
                animationTimer.reset();
            }
        } // otherwise do not move
        rotation = 0;
        //cout<<"getTicks == "<<animationTimer.getTicks()<<endl;

    }else if(KbMs->isKeyPressed(0x41)){// a key
         tempX = x - speed;
         if(!(levelGenerator->getWallMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(tempX), levelGenerator->coordToGridY(y)))) && !(levelGenerator->getPitMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(tempX), levelGenerator->coordToGridY(y))))){
                // if coord is not in solid or pit tile then
            x = tempX;
            if(animationTimer.getTicks() > 100)
            {
                xMin += .25;
                xMax += .25;
                animationTimer.reset();
            }
        }
        rotation = 90.0;
        //cout<<"getTicks == "<<animationTimer.getTicks()<<endl;

    }else if(KbMs->isKeyPressed(0x53)){// s key
        tempY = y - speed;
        if(!(levelGenerator->getWallMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(x), levelGenerator->coordToGridY(tempY)))) && !(levelGenerator->getPitMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(x), levelGenerator->coordToGridY(tempY))))){
                // if coord is not in solid or pit tile then
            y = tempY;
            if(animationTimer.getTicks() > 100)
            {
                xMin += .25;
                xMax += .25;
                animationTimer.reset();
            }
        } // otherwise do not move
        rotation = 180.0;
        //cout<<"getTicks == "<<animationTimer.getTicks()<<endl;

    }else if(KbMs->isKeyPressed(0x44)){// d key
        tempX = x + speed;
         if(!(levelGenerator->getWallMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(tempX), levelGenerator->coordToGridY(y)))) && !(levelGenerator->getPitMatrix(levelGenerator->getTileIndex(levelGenerator->coordToGridX(tempX), levelGenerator->coordToGridY(y))))){
                // if coord is not in a solid or pit tile then
            x = tempX;
            if(animationTimer.getTicks() > 100)
            {
                xMin += .25;
                xMax += .25;
                animationTimer.reset();
            }
        }
        rotation = -90.0;
        //cout<<"getTicks == "<<animationTimer.getTicks()<<endl;

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
        PS->playSound("sounds/fire.wav");
    }
    if(KbMs->isKeyPressed(16) && mineSpawnTimer.getTicks() > 1000)//&& mineSpawnTimer.getTicks() > 1000)// L shift (hold shift to place mine)
    {
        mineSpawnTimer.reset();
        xM = x; //adjusted for testing mine collision
        yM = y; //just remove the .1s
        objectList->createMine(xM, yM);


        PS->playSound("sounds/setmine.wav");
    }
    ///For Testing!!! comment out when done
    /*if(KbMs->isKeyPressed(0x58)&&mineSpawnTimer.getTicks() >1000) // z key
    {
        mineSpawnTimer.reset();
        xM = x; //adjusted for testing mine collision
        yM = y;
        //objectList->createEnemy(xM, yM+.15);
        objectList->createBoss(xM, yM+.35);
        objectList->createHandR(xM-.25,yM+.25);
        objectList->createHandL(xM+.25,yM+.25);
        //objectList->createFFR(xM-.2,yM);
        //objectList->createFFL(xM+.2,yM);
        //objectList->createSkullP(xM,yM-.1);
    }*/

}
void Player::Explo(double x1, double y1)
{
    if(explosionTimer.getTicks() > 7500)
        {
            objectList->createExplosion(x1,y1);
            explosionTimer.reset();
        }
}

bool Player::lifeStatus()
{
    if(healthPoints <= 0)
    {
        stillAlive = false;
    }
}


void Player::runperframe()
{
        objectList->mineRuntimeCheck();
        ///temporary!! just to check if player is destroyed
        lifeStatus();
        if(stillAlive)
        {

        }
        else
        {
            ///Player is dead
            ///do something (gameover screen?)
            cout << "you are dead" << endl;
        }
        ///

        if(Iframes.getTicks() >= 500)
        {
            ///PLAYER-RELATED COLLISIONS CALLED HERE
            if( objectList->collisioncheckPE(x,y)  )
            {
                healthPoints -=10;
            }
            if( objectList->collisioncheckPB(x,y) )
            {
                healthPoints -=20;
            }


            Iframes.reset();
        }
        if( objectList->collisioncheckPBp(x,y) )
        {
            healthPoints -=15;
        }

}



