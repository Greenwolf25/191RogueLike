#ifndef PARTICLES_H
#define PARTICLES_H
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <GL/gl.h>
using namespace std;

#define MAX_DROPS 50000
#define PI 3.14159

class particles
{
    public:
        particles();
        virtual ~particles();
        //yay//
        int numDrops;
        //float mouseX;
        //float mouseY;

        typedef struct{
        bool alive;
        float xpos;
        float ypos;
        float xDir;
        float yDir;
        float mass; //maybe lol

        float radius;
        float explosionRadius;

        float angle;
        int   color = 255;

        float veloX;
        float veloY;
        float alpha;
        }Particles;

        Particles drops[MAX_DROPS]; //very big Particles array called drops
        void drawParticles(); //render
        void lifeTime(); //update
        void generateParticles(float, float); //emitter, passed with xpos & ypos


    protected:

    private:
};

#endif // PARTICLES_H
