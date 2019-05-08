#ifndef PLAYER_H
#define PLAYER_H
#include <gl/gl.h>
#include <textureLoader.h>
#include <Inputs.h>
#include <Timer.h>
#include <ObjList.h>
#include <LevelGen.h>
#include <sound.h>



class Player
{
    public:
        Player();
        virtual ~Player();

        double x, y, z;
        double xMin, xMax, yMin, yMax;
        double xScale, yScale, zScale;
        double rotation; // current angle from default
        double speed;

        void drawPlayer();
        void lookAt(double,double);
        void playerInit(ObjList*, LevelGen*);
        void playerInput(Inputs*);


    protected:
        ObjList* objectList;
        LevelGen* levelGenerator;
        Timer spawnTimer;
        Timer mineSpawnTimer;
        Timer animationTimer;

        double tempX; // used for calculations to avoid variable decelerations
        double tempY;

    private:
        TextureLoader *idle;
};

#endif // PLAYER_H
