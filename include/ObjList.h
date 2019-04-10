#ifndef OBJLIST_H
#define OBJLIST_H
#include <TextureLoader.h>

class GameObject;

class ObjList
{
    public:
        ObjList(int);
        virtual ~ObjList();

        int createObj(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        int createObj(double, double); // X,Y (return index) if no free space return -1

        int createProjectile(double, double, double, double, double, double, double, double);// X,Y,Z,scaleX,scaleY,Rotate,speedX,SpeedY (return index) if no free space return -1
        int createProjectile(double, double, double, double); // X,Y,VelocityX,VelocityY (return index) if no free space return -1
        int createProjectile(double,double,double,double,double); //x,y,Vx,Vy,rotation

        bool deleteObject(int); // delete index (return false if NULL)
        GameObject* getObj(int);
        void draw();
        void runPerFrame();
        int Size();

        void initTextures();


    protected:

        TextureLoader* textures;

        GameObject **objectList;
        int size;

        const double zOffput = 0.00015;

    private:
};

#endif // OBJLIST_H
