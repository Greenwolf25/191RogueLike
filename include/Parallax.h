#ifndef PARALAX_H
#define PARALAX_H
#include <iostream>
#include <windows.h>
using namespace std;
class Parallax
{
    public:
        Parallax();
        virtual ~Parallax();
        void drawSquare(float, float);
        void parallaxInit(char*);
        void scroll(string,float); // scroll background

        float xMax,xMin,yMax,yMin;

    protected:

    private:
};

#endif // PARALAX_H
