#ifndef LEVELGEN_H
#define LEVELGEN_H
#include <ObjList.h>
#include <Player.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <TextureLoader.h>
#include <vector>
using namespace std;


#define number_of_level_templates 1 /// CHANGE ME WHEN ADDING TEMPLATES
#define maximum_doors_per_room 8

#define x_tiles 21
#define y_tiles 12

class LevelTemplate{
    public:
        LevelTemplate();
        virtual ~LevelTemplate();

        int getTileInfo(int);
        bool getPossibleDoors(int);
        int getEnemyLocations(int);
        int getItemLocations(int);
        int getTorchLocations(int);

        int getTileInfoSize();
        int getEnemyLocationsSize();
        int getItemlocationsSize();
        int getTorchLocationsSize();

        void setTileInfo(int*, int);
        void setPossibleDoors(bool*);
        void setEnemyLocations(int*, int);
        void setItemLocations(int*, int);
        void setTorchLocations(int*, int);

        protected:
        vector<int> tileInfo;
        vector<bool> possibleDoors;
        vector<int> enemyLocations;
        vector<int> itemLocations;
        vector<int> torchLocations;

};

class LevelNode
{
    public:
        LevelNode();
        virtual ~LevelNode();

        void setRoom(int);
        void addDoor(int, LevelNode*, bool); /// note: 8 possible door locations per room 1 on both left and right and 3 on top and bottom

        bool* getDoors();
        bool* getOpenDoors();
        LevelNode* getNextRoom(int);
        LevelTemplate getLevelTemplate();

        bool isRoomBeat();
        bool isEnemiesCleared();
        bool isChestOpened();
        bool isItemTaken();

        bool* torchStatusTracker;  // for keeping track of the states of the torches in a room (lit or unlit)


    protected:
        int levelTemplateIndex;
        LevelTemplate* levels;

        bool* doors;
        bool* openDoors;
        bool roomBeat;
        bool enemiesCleared;
        bool chestOpened;
        bool itemTaken;

        int itemX; // topLeft is 0,0
        int itemY;
        int Item; // 0 means no item
        bool itemInChest;

        LevelNode** doorLinks;

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
        void runPerFrame(); // check whether to transition levels or open doors, etc.

        bool getWallMatrix(int);// get the list of wall locations as a list (with every gridX being a new row)
        bool getPitMatrix(int);
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

        bool* wallMatrix;
        bool* pitMatrix;

        double tileSizeX; // size of tile in world cords
        double tileSizeY;

        double tileX; // used as temp var for drawing
        double tileY;
        int textureX;
        int textureY;

        LevelNode* startingRoom;
        LevelNode* currentRoom;

        TextureLoader* tileSet;

        int getTileX(int tile);
        int getTileY(int tile);

        int getDoorX(int door);
        int getDoorY(int door);

        void setWallMatrix();
        void setPitMatrix();

    private:
};

#endif // LEVELGEN_H
