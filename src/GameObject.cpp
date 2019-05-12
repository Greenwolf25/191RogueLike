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
        //out << "test" << endl;
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
    z = -1.0 - 0.002;
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
    HP = 10;
    speed = 0.0005;

    lifetime.start();
    animationTimer.start();
}

Enemy::~Enemy()
{

}

void Enemy::runPerFrame() //fix
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
    px = objList->play->x;
    py = objList->play->y;
    updatePath();
    lifeStatus();
}
void Enemy::updatePath()
{
    if(px<=x)
    {
        x -= speed;
    }
    if(py<=x)
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

}

void Enemy::lifeStatus()
{
    if(HP <= 0)
    {
        alive = false;
    }
    if(!alive)
    {
        deleteSelf();
    }
}
/*void Enemy::updatePos(double playx, double playy)
{
    px = playx;
    py = playy;
}*/

///BOSS CLASS
Boss::Boss()
{

}

Boss::~Boss()
{

}

void Boss::runPerFrame()
{

}

void Boss::drawObject()
{

}

void Boss::Init(TextureLoader*)
{

}

void Boss::sfx(sound*)
{

}

void Boss::lifeStatus()
{
    if(!alive)
    {
        deleteSelf();
    }
}

///BOSSES RIGHT HAND CLASS
BossHandR::BossHandR()
{

}

BossHandR::~BossHandR()
{

}

void BossHandR::runPerFrame()
{

}

void BossHandR::drawObject()
{

}

void BossHandR::Init(TextureLoader*)
{

}

void BossHandR::sfx(sound*)
{

}

void BossHandR::lifeStatus()
{
    if(!alive)
    {
        deleteSelf();
    }
}

///BOSSESS LEFT HAND CLASS
BossHandL::BossHandL()
{

}

BossHandL::~BossHandL()
{

}

void BossHandL::runPerFrame()
{

}

void BossHandL::drawObject()
{

}

void BossHandL::Init(TextureLoader*)
{

}

void BossHandL::sfx(sound*)
{

}

void BossHandL::lifeStatus()
{
    if(!alive)
    {
        deleteSelf();
    }
}

///BOSSESS RIGHT ROCKET POWERED FIST CLASS
BossFistR::BossFistR()
{

}

BossFistR::~BossFistR()
{

}

void BossFistR::runPerFrame()
{

}

void BossFistR::drawObject()
{

}

void BossFistR::Init(TextureLoader*)
{

}

void BossFistR::sfx(sound*)
{

}
///BOSSESS LEFT ROCKET POWERED FIST CLASS
BossFistL::BossFistL()
{

}

BossFistL::~BossFistL()
{

}

void BossFistL::runPerFrame()
{

}

void BossFistL::drawObject()
{

}

void BossFistL::Init(TextureLoader*)
{

}

void BossFistL::sfx(sound*)
{

}
///BOSSESS PROJECTILE ATK CLASS
BossSkullatk::BossSkullatk()
{

}

BossSkullatk::~BossSkullatk()
{

}

void BossSkullatk::runPerFrame()
{

}

void BossSkullatk::drawObject()
{

}

void BossSkullatk::Init(TextureLoader*)
{

}

void BossSkullatk::sfx(sound*)
{

}
