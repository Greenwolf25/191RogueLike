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
    typeCheck = 'f';
    activ = true;

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

    //collision with level
    if((objList->levelGenerator->getWallMatrix(objList->levelGenerator->getTileIndex(objList->levelGenerator->coordToGridX(x), objList->levelGenerator->coordToGridY(y))))){
        deleteSelf();
    }
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
    typeCheck = 'm';
    activ = true;
    timecheck = 7500;


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
    //timecheck -= 1;
    if(animationTimer.getTicks() > 600)
    {
        xMin += 0.5;
        xMax += 0.5;
        animationTimer.reset();
        //Explode* E = new Explode();
        if(lifetime.getTicks()> 7501) //|| activ == false)
        //if(timecheck <= 0)
        {
            deleteSelf();
        }
    }
}

void Mine::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

/*void Mine::Lifecheck()
{
    if(activ == false)
    {
        deleteSelf();
    }
}*/


/// Start of Explosion Object --------------------------------

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
    typeCheck = 's';
    activ = false;
    playedSound = false;

    lifetime.start();
    animationTimer.start();
}

Explode::~Explode()
{
    //dtor
}

void Explode::runPerFrame()
{
    if(!playedSound)
    {
        sfx(SNDS); // plays sound???
        playedSound = true;
    }
    if(animationTimer.getTicks() > 60) //allows it to noticeably run through frames
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


        if(lifetime.getTicks() > 480) deleteSelf(); // deletes itself once explosion is over

    }

}

void Explode::sfx(sound* snds)
{
    snds->playSound("sounds/explode.wav");
}


void Explode::drawObject()
{
    //if(lifetime.getTicks() > 7500 || activ == true){ //restriction in draw sene
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

void Explode::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

/// KEY OBJECT CLASS ------------------------------------------------------

Key::Key()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.05;
    yScale = 0.05;
    zScale = 1.0;
    rotation = 0;
    xMax = 1.0;
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'k';
    activ = true;
    timecheck = -1;


    lifetime.start();
    animationTimer.start();
}

Key::~Key()
{
    //dtor
}

void Key::runPerFrame()
{

}

void Key::drawObject()
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

void Key::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

/// BOSS KEY OBJECT CLASS ------------------------------------------------------

BossKey::BossKey()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.05;
    yScale = 0.05;
    zScale = 1.0;
    rotation = 0;
    xMax = 1.0;
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'b';
    activ = true;
    timecheck = -1;


    lifetime.start();
    animationTimer.start();
}

BossKey::~BossKey()
{
    //dtor
}

void BossKey::runPerFrame()
{

}

void BossKey::drawObject()
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

void BossKey::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

/// HEALTH KIT OBJECT CLASS ------------------------------------------------------

HealthKit::HealthKit()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.05;
    yScale = 0.05;
    zScale = 1.0;
    rotation = 0;
    xMax = 1.0;
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'h';
    activ = true;
    timecheck = -1;


    lifetime.start();
    animationTimer.start();
}

HealthKit::~HealthKit()
{
    //dtor
}

void HealthKit::runPerFrame()
{

}

void HealthKit::drawObject()
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

void HealthKit::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

/// TORCH OBJECT CLASS --------------------------------------------------

Torch::Torch()
{
    //ctor
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.05;
    yScale = 0.05;
    zScale = 1.0;
    rotation = 0;
    tileSizeY = 1.0/17.0;
    xMax = (1.0/6.0)* 6.0;
    yMax = tileSizeY * 11.0;
    xMin = (1.0/6.0)* 5.0;
    yMin = tileSizeY * 10.0;
    typeCheck = 't';
    activ = true;
    timecheck = -1;
}

Torch::~Torch()
{
    //dtor
}

void Torch::runPerFrame()
{
    if((!*lit) && xMax == ((1.0/6.0)* 6.0)){
        xMax = (1.0/6.0)* 4.0;
        yMax = tileSizeY * 12.0;
        xMin = (1.0/6.0)* 3.0;
        yMin = tileSizeY * 11.0;
    }

    if( *lit && animationTimer.getTicks() > 200)
    {
        xMax = (1.0/6.0)* 6.0;
        xMin = (1.0/6.0)* 5.0;
        yMin += tileSizeY;
        yMax += tileSizeY;
        if(yMax > tileSizeY* 14){
            yMax = tileSizeY * 11.0;
            yMin = tileSizeY * 10.0;
        }
        animationTimer.reset();
    }

    if(!*lit){
        if(objList->collisioncheckTF(x,y)) *lit = true; // if the torch is hit by a projectile light it
    }
}

void Torch::drawObject()
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

void Torch::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}
///ENEMY CLASS
Enemy::Enemy()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    //z = -1.0 - .002;
    xScale = 0.2;
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.25; //
    yMax = 0.1428;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'g'; //for ghost i guess
    alive = true;
    once = true;
    onceagain = true;
    speed = 0.001;
    hit = false;
    HP = 10;
    dyingSound = true;

    lifetime.start();
    animationTimer.start();
}

Enemy::~Enemy()
{

}

void Enemy::runPerFrame() //fix
{
    lifeStatus();
    if(alive && !hit)
    {
        if(animationTimer.getTicks() > 60) //allows it to noticeably run through frames
        {
            //x+=.001;
            xMin += 0.25;
            xMax += 0.25;

            if(xMax >= 1.0)
            {
                yMax += .1428;
                yMin += .1428;
                xMax = 0.25;
                xMin = 0.0;
            }
            if(yMax >= .714)
            {
                yMax = 0.1428;
                yMin = 0.0;
                xMax = 0.25;
                xMin = 0.0;
            }

            animationTimer.reset();
        }
    }
    if(hit && alive) // maybe make t a var in gamebject tself
    {
        if(onceagain)
        {
            yMax = 1.0;
            yMin = 0.8568;
            xMax = 0.25;
            xMin = 0.0;
            onceagain = false;
        }
        if(animationTimer.getTicks() > 60) //allows it to noticeably run through frames
        {
        //x+=.001;
            xMin += 0.25;
            xMax += 0.25;

            if(xMin >= 1.0) // fix the others!
            {
                onceagain = true;
                hit = false;
            }
            animationTimer.reset();
        }
    }
   else if(!alive)
   {
        if(dyingSound)
        {
            sfx(SNDS);
            dyingSound = false;
        }
        if(once)
        {
            yMax = 0.714;
            yMin = 0.5712;
            xMax = 0.25;
            xMin = 0.0;
            once = false;
        }
        if(animationTimer.getTicks() > 100) //allows it to noticeably run through frames
        {
        //x+=.001;
            xMin += 0.25;
            xMax += 0.25;

            if(xMin >= 1.0) // fix the others!
            {
                yMax += .1428;
                yMin += .1428;
                xMax = 0.25;
                xMin = 0.0;
            }
            if(yMin >= .8568) //deleteself
            {

                deleteSelf();
            }

            animationTimer.reset();
        }
    }
    px = objList->play->x; /// a change
    py = objList->play->y; /// a change
    updatePath(); /// a change
}

void Enemy::updatePath()
{
    if(px<=x)
    {
        x -= speed;
    }
    if(py<=y)
    {
        y -= speed;
    }
    if(x<=px)
    {
        x += speed;
    }
    if(y<=py)
    {
        y += speed;
    }
}

void Enemy::drawObject()
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

void Enemy::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

void Enemy::sfx(sound* sfx)
{
    sfx->playSound("sounds/skulldeath.wav");
}

void Enemy::lifeStatus()
{
    if(HP <= 0)
    {
        alive = false;
    }
}

///BOSS CLASS
Boss::Boss()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2; //fix
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = .25;//1.0;//0.25; //fix
    yMax = 0.2;
    xMin = 0.0;//0.75;//0.0;
    yMin = 0.0;
    typeCheck = 'a';
    alive = true;
    once = true;
    HP = 10;
    dyingSound = true;
    attacking = false;

    lifetime.start();
    animationTimer.start();
    projectileInterval.start();
}

Boss::~Boss()
{

}

void Boss::runPerFrame()
{
//shoot projetile ani
//smile ani?
//death ani
    lifeStatus(); //checks health to see if it dieded
    if(alive)
    {
        if(animationTimer.getTicks() > 200 && attacking) //allows it to noticeably run through frames
        {
            //x+=.001;
            xMin += 0.25;
            xMax += 0.25;

            if(xMax >= 1.0)
            {
                yMax += .2;
                yMin += .2;
                xMax = 0.25;
                xMin = 0.0;
            }
            if(yMax >= .6)
            {
                yMax = 0.2;
                yMin = 0.0;
                xMax = 0.25;
                xMin = 0.0;
                attacking = false;
            }

            animationTimer.reset();
        }
    }

    ///death animation (use for the others too)
   if(!alive) //death check
   {
    //initial for death ani
        if(dyingSound)
        {
            sfx(SNDS);
            dyingSound = false;
        }
        if(once) ///give this to enemy and hands
        {
            yMax = 0.8;
            yMin = 0.6;
            xMax = 0.25;
            xMin = 0.0;
            once = false;
        }
        if(animationTimer.getTicks() > 300) //allows it to noticeably run through frames
        {
        //x+=.001;
            xMin += 0.25;
            xMax += 0.25;

            if(xMin >= 1.0) // fix the others!
            {
                yMax += .2;
                yMin += .2;
                xMax = 0.25;
                xMin = 0.0;
            }
            if(yMin >= 1.0) //deleteself
            {
                objList->victory = true;
                deleteSelf();
            }

        animationTimer.reset();
        }
    }


}

void Boss::drawObject()
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

void Boss::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

void Boss::sfx(sound* snds)
{
    snds->playSound("sounds/bossdeath2.wav");
}

void Boss::lifeStatus()
{
    if(HP <= 0)
    {
        alive = false;
    }
}

///BOSSES RIGHT HAND CLASS
BossHandR::BossHandR()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2;//fix
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.6668;//1.0;//.6668;//1.0;//0.1666; //now do ani FIX LATER
    yMax = 0.5;
    xMin = 0.5002;//0.8334;//.5002;//0.8334;//0.0;
    yMin = 0.0;
    typeCheck = 'r'; //for ghost i guess
    alive = true;
    once = true;
    HP = 30;
    dyingSound = true;
    attacking = false;

    lifetime.start();
    animationTimer.start();
}

BossHandR::~BossHandR()
{

}

void BossHandR::runPerFrame()
{
    lifeStatus();
    if(alive)
    {
        if(animationTimer.getTicks() > 550 && attacking) //allows it to noticeably run through frames
        {
            //x+=.001;

            xMin += 0.1666;
            xMax += 0.1666;

            if(xMax+.0001 >= 1.6668)
            {
                xMax = 0.6668;//0.1666;
                xMin = 0.5002;//0.0;
                attacking = false;
            }
            animationTimer.reset();

        }
    }
    if(!alive)
    {
        if(dyingSound)
        {
            sfx(SNDS);
            dyingSound = false;
        }
        if(once)
        {
            xMax = 0.1666; //now do ani
            yMax = 1.0;
            xMin = 0.0;
            yMin = 0.5;
            once = false;
        }
        if(animationTimer.getTicks() > 300) //allows it to noticeably run through frames
        {
        //x+=.001;
            xMin += 0.1666;
            xMax += 0.1666;

            if(xMax+.0004 >= 1.0) // fix the others!
            {

                deleteSelf();
            }
            animationTimer.reset();
        }
    }
}

void BossHandR::drawObject()
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

void BossHandR::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

void BossHandR::sfx(sound* snds)
{
    snds->playSound("sounds/handdeath.wav");
}

void BossHandR::lifeStatus()
{
    if(HP <= 0)
    {
        alive = false;
    }
}

///BOSSESS LEFT HAND CLASS
BossHandL::BossHandL()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2;//fix
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = .6668;//1.0;//0.1666; //now do ani FIX LATER
    yMax = 0.5;
    xMin = .5002;//0.8334;//0.0;
    yMin = 0.0;
    typeCheck = 'l'; //for ghost i guess
    once = true;
    alive = true;
    HP = 30;
    dyingSound = true;

    lifetime.start();
    animationTimer.start();
}

BossHandL::~BossHandL()
{

}

void BossHandL::runPerFrame()
{
    lifeStatus();
    if(alive)
    {
        if(animationTimer.getTicks() > 550 && attacking) //allows it to noticeably run through frames
        {
            xMin += 0.1666;
            xMax += 0.1666;
            if(xMax+.0001 >= 1.6668)
            {
                xMax = 0.6668;//0.1666;
                xMin = 0.5002;//0.0;
                attacking = false;
            }
            animationTimer.reset();

        }
    }
    if(!alive)
    {
        if(dyingSound)
        {
            sfx(SNDS);
            dyingSound = false;
        }
        if(once)
        {
            xMax = 0.1666; //now do ani
            yMax = 1.0;
            xMin = 0.0;
            yMin = 0.5;
            once = false;
        }
        if(animationTimer.getTicks() > 300) //allows it to noticeably run through frames
        {
        //x+=.001;
            xMin += 0.1666;
            xMax += 0.1666;

            if(xMax+.0004 >= 1.0) // fix the others!
            {
                deleteSelf();
            }
            animationTimer.reset();
        }
    }
}

void BossHandL::drawObject()
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

void BossHandL::Init(TextureLoader* newTex)
{
     defaultTex = newTex;
}

void BossHandL::sfx(sound* snds)
{
    snds->playSound("sounds/handdeath.wav");
}

void BossHandL::lifeStatus()
{
    if(HP <= 0)
    {
        alive = false;
    }
}

///BOSSESS RIGHT ROCKET POWERED FIST CLASS
BossFistR::BossFistR()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2;//fix
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.3333; //now do ani
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'x'; //for ghost i guess
    alive = true;
    //HP = 10;
    speed = .003;

    lifetime.start();
    animationTimer.start();
}

BossFistR::~BossFistR()
{

}

void BossFistR::runPerFrame()
{
    //y-=.001;
    px = objList->play->x; /// a change
    py = objList->play->y; /// a change
    updatePath(); /// a change
if(animationTimer.getTicks() > 60) //allows it to noticeably run through frames
    {
        //x+=.001;
        xMin += 0.3333;
        xMax += 0.3333;

        if(xMax+.0001 >= 1.0)
        {
            xMax = 0.3333;
            xMin = 0.0;
        }
        animationTimer.reset();
    }
    if(lifetime.getTicks() >= 3000)
    {
        deleteSelf();
    }
}

void BossFistR::updatePath()
{
    if(px<x)
    {
        x -= speed;
    }
    if(py<y)
    {
        y -= speed;
    }
    if(x<px)
    {
        x += speed;
    }
    if(y<py)
    {
        y += speed;
    }
}


void BossFistR::drawObject()
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

void BossFistR::Init(TextureLoader* newTex)
{
     defaultTex = newTex;
}

void BossFistR::sfx(sound* snds)
{
    snds->playSound("sounds/destroyed.wav");
}
///BOSSESS LEFT ROCKET POWERED FIST CLASS
BossFistL::BossFistL()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2;//fix
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.3333; //now do ani
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'y'; //for ghost i guess
    alive = true;
    //HP = 10;
    speed = .003;

    lifetime.start();
    animationTimer.start();
}

BossFistL::~BossFistL()
{

}

void BossFistL::runPerFrame()
{
    //y-=.001;
    px = objList->play->x; /// a change
    py = objList->play->y; /// a change
    updatePath(); /// a change
if(animationTimer.getTicks() > 60) //allows it to noticeably run through frames
    {
        //x+=.001;
        xMin += 0.3333;
        xMax += 0.3333;

        if(xMax+.0001 >= 1.0)
        {
            xMax = 0.3333;
            xMin = 0.0;
        }
        animationTimer.reset();
    }
    if(lifetime.getTicks() >= 3000)
    {
        deleteSelf();
    }
}

void BossFistL::updatePath()
{
    if(px<=x)
    {
        x -= speed;
    }
    if(py<=y)
    {
        y -= speed;
    }
    if(x<=px)
    {
        x += speed;
    }
    if(y<=py)
    {
        y += speed;
    }
}


void BossFistL::drawObject()
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

void BossFistL::Init(TextureLoader* newTex)
{
    defaultTex = newTex;
}

void BossFistL::sfx(sound* snds)
{
    snds->playSound("sounds/destroyed.wav");
}
///BOSSESS PROJECTILE ATK CLASS
BossSkullatk::BossSkullatk()
{
    x = 0.0;
    y = 0.0;
    z = -1.0;
    xScale = 0.2;//fix
    yScale = 0.2;
    zScale = 1.0;
    rotation = 0;
    xMax = 0.25; //now do ani
    yMax = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    typeCheck = 'z'; //for ghost i guess
    alive = true;
    //HP = 10;

    lifetime.start();
    animationTimer.start();
}

BossSkullatk::~BossSkullatk()
{

}

void BossSkullatk::runPerFrame()
{
    if(lifetime.getTicks() <= 60)
    {
         y-=.001;
    }
    if(animationTimer.getTicks() > 60) //allows it to noticeably run through frames
    {
        //x+=.001;
        xMin += 0.25;
        xMax += 0.25;

        if(xMax >= 1.0)
        {
            xMax = 0.25;
            xMin = 0.0;
        }
        animationTimer.reset();
    }
    if(lifetime.getTicks() >= 20000)
    {
        deleteSelf();
    }
    //lifeStatus();
}

void BossSkullatk::drawObject()
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

void BossSkullatk::Init(TextureLoader* newTex)
{
     defaultTex = newTex;
}

void BossSkullatk::sfx(sound* snds)
{
    snds->playSound("sounds/destroyed.wav");
}
