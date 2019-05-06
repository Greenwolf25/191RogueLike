#include "GameObject.h"
#include <iostream>
#include <ObjList.h>

using namespace std;

sound *SNDS = new sound();
ObjList* test = new ObjList(100);
/// Game Object is for other Game objects to inherent
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
    xMax = 1.0; //
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;

    lifetime.start();
    animationTimer.start();
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

void GameObject::runPerFrame()
{
    //EMPTY AS IT IS A TEMPLATE
}

void GameObject::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

void GameObject::deleteSelf()
{
    objList->deleteObject(objListIndex);
}

/// Start of Projectile Object -------------------------------

Projectile::Projectile()
{
    //ctor
    xMax = 0.25; //
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    xScale = 0.15;
    yScale = 0.15;
    zScale = 1.0;

    // default ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;

    rotation = 0;

    lifetime.start();
    animationTimer.start();
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
    if(animationTimer.getTicks() > 200)
    {
        xMin += 0.25;
        xMax += 0.25;
        animationTimer.reset();
    }

    //
    if(lifetime.getTicks() > 2000) deleteSelf();
}
void Projectile::drawObject()
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

/// Start of Mine Object -----------------------------------------------

Mine::Mine()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.1;
    yScale = 0.1;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.5; //
    yMax = 0.5;
    xMin = 0.0;
    yMin = 0.0;


    lifetime.start();
    animationTimer.start();

}

Mine::~Mine()
{
    //dtor
}

void Mine::drawObject()
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

void Mine::runPerFrame() //makes mine blink
{
    if(animationTimer.getTicks() > 600)
    {
        xMin += 0.5;
        xMax += 0.5;
        animationTimer.reset();
        if(lifetime.getTicks() > 7500)
        {
            deleteSelf();
            //S->playSound();
            //test->createExplosion(x,y);
        }

    }
}

void Mine::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}




/// Start of Explosion Object

Explode::Explode()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2;
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.25; //
    yMax = 0.5;
    xMin = 0.0;
    yMin = 0.0;

    lifetime.start();
    animationTimer.start();
}

Explode::~Explode()
{
    //dtor
}

void Explode::runPerFrame()
{
    if(animationTimer.getTicks() > 60) //adjust later
    {
        xMin += 0.25;
        xMax += 0.25;

        if(xMax+xMin >= 2.0)
        {
            yMax = .5;
            yMin = 1.0;
            xMax = 0.25;
            xMin = 0.0;
        }

        animationTimer.reset();
        if(lifetime.getTicks() > 7500)
        {

            sfx(SNDS);
        }
        if(lifetime.getTicks() > 7980) deleteSelf();

    }

}

void Explode::sfx(sound* snds)
{
    snds->playSound("sounds/explode.wav");
}


void Explode::drawObject()
{
    if(lifetime.getTicks() > 7500){
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
    glPopMatrix();}
}

void Explode::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}


