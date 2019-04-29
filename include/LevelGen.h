#ifndef LEVELGEN_H
#define LEVELGEN_H
#include <ObjList.h>
#include <Player.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class LevelNode
{
    public:
        LevelNode();
        virtual ~LevelNode();

        void setRoom(int);
        bool* getPossibleDoors(); // for being able to add doors
        void addDoor(int, LevelNode*); /// note: 8 possible door locations per room 1 on both left and right and 3 on top and bottom

        bool* getDoors();
        bool* getOpenDoors();

        bool isRoomBeat();



    protected:
        int* tileInfo;
        bool* doors;
        bool* openDoors;
        bool roomBeat;

        LevelNode* doorLinks;

    private:

};

class LevelGen
{
    public:
        LevelGen();
        virtual ~LevelGen();

        InitLevelGen(ObjList* objectList, Player* player); // uses Objlist to spawn and clear objects and uses player to move player when changing levels and to figure out when to change levels
        void generateLevels();

        void drawLevel();

        bool* getWallMatrix();// get the list of wall locations as a list (with every gridX being a new row)
        int getGridX();
        int getGridY();

        double getMaxY();
        double getMaxX();

        double getOffsetX();
        double getOffsetY();


        bool inTransition; // true if the level gen is transitioning between levels

    protected:
        int gridX;
        int gridY;
        double maxX;
        double maxY;

        bool* WallMatrix;

        double tileSizeX; // used as temp var for drawing
        double tileSizeY;
        double tileX;
        double tileY;

        LevelNode* startingRoom;
        LevelNode* currentRoom;



    private:
};

#endif // LEVELGEN_H
