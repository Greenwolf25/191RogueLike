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
    rotation = 0;

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

void GameObject::runPerFrame()
{

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
}

Projectile::~Projectile()
{
    //dtor
}

void Projectile::runPerFrame()
{
    x += xVelo;
    y += yVelo;
    if(lifetime.getTicks() > 1000) deleteSelf();
}

