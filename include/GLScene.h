#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <sound.h>
#include <time.h>

class GLScene
{
    public:
        GLScene();          //Constructor
        virtual ~GLScene(); //Destructor

        GLint initGL(bool*);     //Initialize
        GLint drawGLScene();//Draw Scene
        GLint idleGLScene();//run idle process
        GLvoid resizeGLScene(GLsizei,GLsizei); //Window resize function

        bool enemyPlayerCollision(double, double, double, double); //for later
        bool bossPlayerCollision(double,double,double,double); // for later

        int winMsg(HWND,UINT,WPARAM,LPARAM);
        float screenWidth, screenHeight;
        bool* closeGame;
        bool bossExist;

    protected:

    private:
};

#endif // GLSCENE_H
