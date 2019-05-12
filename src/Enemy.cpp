#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
    x = 0.2;
    y = 0.2;
    z = -1.0 - 0.002;
    xScale = 0.1;
    yScale = 0.1;
    zScale = 1.0;
    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
    speed = 0.00050;
    alive = true;
    hp = 3;

}

Enemy::~Enemy()
{
    //dtor
}
bool Enemy::isAlive()
{
    return alive;
}

void Enemy::hit()
{
    hp -= 1;
    if (hp <= 0)
    {
        alive = false;
    }
}

void Enemy::movement(double xp, double yp)
{
    double w = -0.0005;
    double e = 0.0005;
    double test = xp - x;
    if(w < (test) < e){
        if(y<yp){
            y += speed;
        }else {
            y -= speed;
        }
    }else{
        if (x<xp){
            x += speed;
        }else if(x>xp){
            x -= speed;
        }
    }


}

void Enemy::drawEnemy()
{
    if(alive)
    {
    glPushMatrix();
    idle->binder();
    glTranslated(x,y,z);
    glRotated(0, 0,0,1);
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

}

void Enemy::enemyInit()
{
    idle = new TextureLoader();
    idle->LoadTexture("images/trollface.png");
}
