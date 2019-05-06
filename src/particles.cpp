#include "particles.h"

particles::particles()
{
    //ctor
}

particles::~particles()
{
    //dtor
}
void particles::drawParticles()
{
    int i = 0;
    glPointSize(5);

    glPushMatrix();
    glBegin(GL_POINTS);
    ////////
    while(i < numDrops)
    {
        if(drops[i].alive) //drawing
        {
            glVertex3f(drops[i].xpos, drops[i].ypos, -1.0);

        }//end if
        i++;
    }//end while
    ////////
    glEnd();
    glPopMatrix();
}

void particles::lifeTime()
{
    for(int i = 0; i < numDrops; i++) //allows the navigation of the entire drops array
    {
        if(drops[i].alive) // if certain drop is alive
        {
            drops[i].xpos += drops[i].veloX; //
            drops[i].ypos += drops[i].veloY; //
            drops[i].alpha -= 0.1;

            drops[i].alpha < 0 ? drops[i].alive = false : NULL; // if alpha is less then zero, kill certain drop, otherwise do nothing

        }//end if
    }//end for
}

void particles::generateParticles(float, float) //emitter
{
    //hard part
    //random each time w/o excedding maxdrops
    //set new particles to alive & their movement
    int newdrops = rand()%60+1;
    if((numDrops + newdrops) > MAX_DROPS)
    {
        newdrops = MAX_DROPS - numDrops;
    }
    for(int i = numDrops; i < numDrops + newdrops; i++)
    {
        //set a certain number of the complete array to alive
        drops[i].alive = true;
        drops[i].xpos  = 0.0;
        drops[i].ypos  = 0.0;
        drops[i].explosionRadius = 0.001;
        drops[i].angle = rand()%360; //some angle between 0 % 360

        drops[i].veloX = sin(drops[i].angle)*drops[i].explosionRadius; //movement
        drops[i].veloY = cos(drops[i].angle)*drops[i].explosionRadius;
        drops[i].alpha = (float)(rand()%100)/10; // number between 1 and 100 divided by 10;

    }
    numDrops += newdrops;
    if(numDrops >= MAX_DROPS) // keeps particles from going out of hand
    {
        numDrops = 0;
    }
}
