#ifndef INPUTS_H
#define INPUTS_H
#include <windows.h>
#include <Model.h>
#include <Parallax.h>
#include <sound.h>

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed();
        void keyUp();
        bool isKeyPressed(int);
        void keySounds(sound*);

        void mouseEventDown(double, double);
        void mouseEventUp();
        void mouseEventWheel(Model*, double);
        void mouseEventMove(Model*, double,double);

        void keyEnv(Parallax* ,float);                  //scroll due to keys

        double prev_mouse_X;
        double prev_mouse_Y;
        bool mouse_Translate;
        bool mouse_Rotate;

        WPARAM wParam;

    protected:

    private:
        bool* keys;

};

#endif // INPUTS_H
