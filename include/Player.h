#ifndef PLAYER_H
#define PLAYER_H
#include <gl/gl.h>
#include <textureLoader.h>
#include <Inputs.h>
#include <Timer.h>
#include <ObjList.h>
#include <LevelGen.h>
#include <sound.h>

class ObjList;

class LevelGen;

class Player
{
    public:
        Player();
        virtual ~Player();
        void playerInit(ObjList*, LevelGen*);

        double x, y, z;
        double xMin, xMax, yMin, yMax;
        double xScale, yScale, zScale;
        double rotation; // current angle from default
        double speed;
        double xM, yM;

        void drawPlayer();
        void lookAt(double,double);
        void playerInput(Inputs*);
        void Explo(double, double);
        void runperframe();

        double getX();
        double getY();

        bool stillAlive;
        int  healthPoints; // keeps track of the number of hits player has taken
        int numberOfKeys;
        bool BossKey; // Does the player have the boss key?



    protected:
        ObjList* objectList;
        LevelGen* levelGenerator;
        Timer spawnTimer;
        Timer mineSpawnTimer;
        Timer explosionTimer;
        Timer mineDurationTimer;
        Timer animationTimer;

        double tempX; // used for calculations to avoid variable decelerations
        double tempY;

    private:
        TextureLoader *idle;
};

#endif // PLAYER_H
