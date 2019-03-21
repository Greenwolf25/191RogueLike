#ifndef MODEL_H
#define MODEL_H
#include <TextureLoader.h>



class Model
{
    public:
        Model();
        virtual ~Model();

        void drawModel();
        void modelInit(char*);

        double RotateX;
        double RotateY;
        double RotateZ;

        double Zoom;

        double xPos;
        double yPos;
        double zPos;
        TextureLoader* tex;

    protected:

    private:
};

#endif // MODEL_H
