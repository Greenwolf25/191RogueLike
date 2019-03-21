#include "Model.h"
#include <windows.h>
#include <GL/glut.h>



Model::Model()
{
    //ctor
     RotateX = 0;
     RotateY = 0;
     RotateZ = 0;

     Zoom = 1;

     xPos = 0;
     yPos = 0;
     zPos = -8.0;
}

Model::~Model()
{
    //dtor
}
void Model::modelInit(char* filename){
    tex = tex = new TextureLoader();
    tex->LoadTexture(filename);
}
void Model::drawModel()
{
    tex->binder();
    glTranslated(xPos,yPos,zPos);
    glColor3f(0.3,0.7,0.7);
    glRotated(RotateX,0,1,0);
    glRotated(RotateY,1,0,0);
    glRotated(RotateZ,0,0,1);
    glScaled(Zoom,Zoom,Zoom);

    glutSolidTeapot(1.5);
}
