#ifndef PLAYER_H
#define PLAYER_H
#include <gl/gl.h>
#include <textureLoader.h>
#include <Inputs.h>
#include <Timer.h>
#include <ObjList.h>
#include <LevelGen.h>
#include <sound.h>

///11
class ObjList; // a change
class LevelGen;// a change
///14


class Player
{
    public:
        Player();
        virtual ~Player();
        ///21
        void playerInit(ObjList*, LevelGen*); /// a change
        ///23 (comment out the other)

        double x, y, z;
        double xMin, xMax, yMin, yMax;
        double xScale, yScale, zScale;
        double rotation; // current angle from default
        double speed;
        double xM, yM;

        void drawPlayer();
        void lookAt(double,double);
        //void playerInit(ObjList*, LevelGen*);
        void playerInput(Inputs*);
        void Explo(double, double);
        double getX();/// a change 37
        double getY();/// a change 38
        void runperframe();
        bool lifeStatus();

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
        Timer Iframes; /// to keep player-related collisions from activating several times

        double tempX; // used for calculations to avoid variable decelerations
        double tempY;

    private:
        TextureLoader *idle;
};

#endif // PLAYER_H
