#ifndef ENEMY_H
#define ENEMY_H

#include <gl/gl.h>
#include <Inputs.h>
#include <ObjList.h>
#include <sound.h>
#include <string.h>
#include <GL/glut.h>
#include <TextureLoader.h>
#include <math.h>
#include <iostream>
#include <Timer.h>
#include <string>
using namespace std;

#define PI 3.14159265

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();

        double hp;
        bool alive;
        double x, y, z;

        double xMin, xMax, yMin, yMax;
        double xScale, yScale, zScale;
        //double rotation; // current angle from default
        double speed;

        bool isAlive();
        void hit();
        void movement(double, double);


        void drawEnemy();
        void enemyInit();

    protected:

    private:
        TextureLoader* idle;
};

#endif // ENEMY_H
