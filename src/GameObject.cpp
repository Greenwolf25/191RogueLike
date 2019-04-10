#include "GameObject.h"
#include <iostream>
using namespace std;

GameObject::GameObject()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.1;
    yScale = 0.1;
    zScale = 1.0;
    //xMscale = 0.02;
    //yMscale = 0.05;
    //zMscale = 1.0;
    rotation = 0;
    xMax = 0.5; //
    yMax = 0.5;
    xMin = 0.0;
    yMin = 0.0;

    lifetime.start();
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::drawObject()
{
    glPushMatrix();
    defaultTex->binder();
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

void GameObject::runPerFrame() //makes mine blink
{
    if(lifetime.getTicks() > 600)
    {
        xMin += 0.5;
        xMax += 0.5;
        lifetime.reset();
    }
}

void GameObject::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
    //defaultTex->LoadTexture("images/ball.png");
    //cout << "GameObject init" << endl;
}

void GameObject::deleteSelf()
{
    objList->deleteObject(objListIndex);
}

Projectile::Projectile()
{
    //ctor
    xMaxP = 0.25; //
    yMaxP = 1.0;
    xMinP = 0.0;
    yMinP = 0.0;
    xPscale = 0.15;
    yPscale = 0.15;
    zPscale = 1.0;
}

Projectile::~Projectile()
{
    //dtor

}

void Projectile::runPerFrame()
{
    x += xVelo;
    y += yVelo;

    //run through frames here
    if(lifetime.getTicks() > 400)
    {
        xMinP += 0.25;
        xMaxP += 0.25;
    }

    //
    if(lifetime.getTicks() > 1000) deleteSelf();
}
void Projectile::drawObject()
{
    glPushMatrix();
    defaultTex->binder();
    glTranslated(x,y,z);
    glRotated(rotation, 0,0,1);
    glScaled(xPscale, yPscale, zPscale);
    glBegin(GL_QUADS);

    glTexCoord2f(xMinP,yMaxP);
    glVertex3f(-0.5, -0.5, 0.0);

    glTexCoord2f(xMaxP,yMaxP);
    glVertex3f(0.5, -0.5, 0.0);

    glTexCoord2f(xMaxP,yMinP);
    glVertex3f(0.5, 0.5, 0.0);

    glTexCoord2f(xMinP,yMinP);
    glVertex3f(-0.5, 0.5, 0.0);

    glEnd();
    glPopMatrix();
}


