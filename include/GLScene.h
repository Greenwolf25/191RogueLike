#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <GL/glut.h>

class GLScene
{
    public:
        GLScene();          //Constructor
        virtual ~GLScene(); //Destructor

        GLint initGL();     //Initialize
        GLint drawGLScene();//Draw Scene
        GLint idleGLScene();//run idle process
        GLvoid resizeGLScene(GLsizei,GLsizei); //Window resize function

        int winMsg(HWND,UINT,WPARAM,LPARAM);
        float screenWidth, screenHeight;

    protected:

    private:
};

#endif // GLSCENE_H
