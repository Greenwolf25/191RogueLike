#ifndef OBJLIST_H
#define OBJLIST_H
#include <TextureLoader.h>
#include <LevelGen.h>

class GameObject;

class LevelGen;

class ObjList
{
    public:
        ObjList(int);
        virtual ~ObjList();

        void objListInit(LevelGen*);

        LevelGen* levelGenerator;

        //int createObj(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        //int createObj(double, double); // X,Y (return index) if no free space return -1

        int createProjectile(double, double, double, double, double, double, double, double);// X,Y,Z,scaleX,scaleY,Rotate,speedX,SpeedY (return index) if no free space return -1
        int createProjectile(double, double, double, double); // X,Y,VelocityX,VelocityY (return index) if no free space return -1
        int createProjectile(double,double,double,double,double); //x,y,Vx,Vy,rotation

        int createMine(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        int createMine(double, double); // X,Y (return index) if no free space return -1

        bool deleteObject(int); // delete index (return false if NULL)
        GameObject* getObj(int);
        void draw();
        void runPerFrame();
        int Size();


    protected:

        TextureLoader* textures;

        GameObject **objectList;
        int size;

        const double zOffput = 0.00015;

    private:
};

#endif // OBJLIST_H
