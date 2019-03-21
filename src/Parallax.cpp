#include "Parallax.h"
#include <TextureLoader.h>

TextureLoader *bTexture = new TextureLoader();
Parallax::Parallax()
{
    //ctor
    xMax = 1.0;
    xMin = 0.0;
    yMax = 1.0;
    yMin = 0.0;
}

Parallax::~Parallax()
{
    //dtor
}
void Parallax::drawSquare(float width, float height)
{
    bTexture->binder();
    glScaled(3.33,3.33,1.0);
    glBegin(GL_POLYGON);
        glTexCoord2f(xMin,yMax);
        glVertex3f(-width/height,-1.0,-8.0);

        glTexCoord2f(xMax,yMax);
        glVertex3f(width/height,-1.0,-8.0);

        glTexCoord2f(xMax,yMin);
        glVertex3f(width/height,1.0,-8.0);

        glTexCoord2f(xMin,yMin);
        glVertex3f(-width/height,1.0,-8.0);
    glEnd();
}

void Parallax::parallaxInit(char* fileName)
{
    bTexture->LoadTexture(fileName);
}

void Parallax::scroll(string dir, float speed)
{
    if(dir == "up"){
        yMin +=speed;
        yMax +=speed;
    }else if(dir == "down"){
        yMin -=speed;
        yMax -=speed;
    }else if(dir == "left"){
        xMin +=speed;
        xMax +=speed;
    }else if(dir == "right"){
        xMin -=speed;
        xMax -=speed;
    }
}

