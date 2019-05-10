#ifndef LEVELGEN_H
#define LEVELGEN_H
#include <ObjList.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <TextureLoader.h>
#include <vector>
using namespace std;


#define number_of_level_templates 16 /// CHANGE ME WHEN ADDING TEMPLATES
#define maximum_doors_per_room 8

#define x_tiles 21
#define y_tiles 12

class ObjList;

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

class templateList{
    public:
        templateList();
        virtual ~templateList();
        LevelTemplate& operator[] (int x);
    private:
        LevelTemplate* levelList;
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
        int getItemX();
        int getItemY();
        int getItemType();

        bool setRoomBeat();
        bool setEnemiesCleared();
        bool setChestOpened();
        bool setItemTaken();
        void setItemCoord(int, int);

        void openDoor(int);

        bool* torchStatusTracker;  // for keeping track of the states of the torches in a room (lit or unlit)

        bool isBossRoom;

        int bossRoomDoor;// which door is a bossRoom Door (-1 if none)

    protected:
        int levelTemplateIndex;
        static templateList levels;

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

        void InitLevelGen(ObjList*); // uses Objlist to spawn and clear objects and uses player to move player when changing levels and to figure out when to change levels
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

        double gridToCoordX(int);
        double gridToCoordY(int);

        int coordToGridX(double);
        int coordToGridY(double);

        int getTileIndex(int x, int y); // return the index value for a tile in wall or pit matrix;

        int gridToDoorNum(int x, int y); // returns the door number of a door given x and y or -1 if not door

        bool openDoor(int); // returns true if door is opened. returns false if door is already open or is not able to be opened by key.

        bool inTransition; // true if the level gen is transitioning between levels

        int enterDoor(int);

        int getDoorX(int door);
        int getDoorY(int door);

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

        bool lockRoom; // if true then have all doors be locked and unOpenable

        LevelNode* startingRoom;
        LevelNode* currentRoom;

        TextureLoader* tileSet;
        TextureLoader* bossDoor;

        ObjList* objectList;

        int getTileX(int tile);
        int getTileY(int tile);

        void setWallMatrix();
        void setPitMatrix();

    private:
};

#endif // LEVELGEN_H
