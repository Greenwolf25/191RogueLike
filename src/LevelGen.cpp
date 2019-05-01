#include "LevelGen.h"



LevelTemplate::LevelTemplate()
{

}

LevelTemplate::~LevelTemplate()
{
    delete[] tileInfo;
    delete[] possibleDoors;
    delete[] enemyLocations;
    delete[] itemLocations;
    delete[] torchLocations;
}

int* LevelTemplate::getTileInfo()
{
    return tileInfo;
}

bool* LevelTemplate::getPossibleDoors()
{
    return possibleDoors;
}

int* LevelTemplate::getEnemyLocations()
{
    return enemyLocations;
}

int* LevelTemplate::getItemLocations()
{
    return itemLocations;
}

int* LevelTemplate::getTorchLocations()
{
    return torchLocations;
}

void LevelTemplate::setTileInfo(int* TI, int size)
{
    tileInfo = TI;
    tileInfoSize = size;
}

void LevelTemplate::setPossibleDoors(bool* PD)
{
     possibleDoors = PD;
}

void LevelTemplate::setEnemyLocations(int* EL, int size)
{
    enemyLocations = EL;
    enemyLocationsSize = size;
}

void LevelTemplate::setItemLocations(int* IL, int size)
{
    itemLocations = IL;
    itemlocationsSize = size;
}

void LevelTemplate::setTorchLocations(int* TL, int size)
{
    torchLocations = TL;
    torchLocationsSize = size;
}

int LevelTemplate::getTileInfoSize()
{
    return tileInfoSize;
}

int LevelTemplate::getEnemyLocationsSize()
{
    return enemyLocationsSize;
}

int LevelTemplate::getItemlocationsSize()
{
    return itemlocationsSize;
}

int LevelTemplate::getTorchLocationsSize()
{
    return torchLocationsSize;
}



/// LEVEL NODE ------------------------------------------------------------------------------

LevelNode::LevelNode()
{
    levels = new LevelTemplate[number_of_level_templates]; /// CHANGE DEFINE WHEN ADDING TEMPATES
        // template 0 default room
        levels[0].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                              }, ((x_tiles-2) * (y_tiles-2)));
        levels[0].setEnemyLocations(NULL,0);
        levels[0].setItemLocations(NULL,0);
        levels[0].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});
    // end level templates


    doors = new bool[maximum_doors_per_room]{};
    openDoors = new bool[maximum_doors_per_room]{};

    roomBeat = false;
    enemiesCleared = false;
    chestOpened = false;
    itemTaken = false;

    itemX = 0;
    itemY = 0;
    Item = 0;
    itemInChest = false;

    torchStatusTracker = NULL;
    doorLinks = (LevelNode**)malloc(maximum_doors_per_room * sizeof(LevelNode*));
}

LevelNode::~LevelNode()
{
    delete[] doors;
    delete[] openDoors;
    delete[] levels;
    delete[] torchStatusTracker;

    for(int i=0; i < maximum_doors_per_room; i++){
        delete doorLinks[i];
    }
}

void LevelNode::setRoom(int input)
{
    levelTemplateIndex = input;

    if(torchStatusTracker != NULL){
        delete[] torchStatusTracker;
    }

    torchStatusTracker = new bool[levels[input].getTorchLocationsSize()]{};
}

bool* LevelNode::getPossibleDoors()
{
    return levels[levelTemplateIndex].getPossibleDoors();
}

void LevelNode::addDoor(int newDoorIndex, LevelNode* newRoom)
{
    // creates a door from this room to newRoom at the door locations of newDoorIndex
    doors[newDoorIndex] = true;
    if(doorLinks[newDoorIndex] != NULL) delete doorLinks[newDoorIndex];
    doorLinks[newDoorIndex] = newRoom;
}

bool* LevelNode::getDoors()
{
    return doors;
}

bool* LevelNode::getOpenDoors()
{
    return openDoors;
}

LevelNode* LevelNode::getNextRoom(int doorIndex)
{
    return doorLinks[doorIndex];
}


bool LevelNode::isRoomBeat()
{
    return roomBeat;
}

bool LevelNode::isEnemiesCleared()
{
    return enemiesCleared;
}

bool LevelNode::isChestOpened()
{
    return chestOpened;
}

bool LevelNode::isItemTaken()
{
    return itemTaken;
}


/// Level generator ----------------------------------------------------------------

LevelGen::LevelGen()
{
    gridX = x_tiles; // see defined constants
    gridY = y_tiles;

    maxX = 0.773; // edge of screen x
    maxY = 0.434; // edge of screen y

    tileSizeX = (maxX*2)/gridX; // size of one tile in x direction
    tileSizeY = (maxY*2)/gridY; //        "         in y direction

    WallMatrix = new bool[gridX*gridY]{};
}

LevelGen::~LevelGen()
{
    delete[] WallMatrix;
    delete startingRoom;
    delete currentRoom;
    delete tileSet;
}

void LevelGen::generateLevels()
{
    tileSet->LoadTexture("images/tileset.png"); // generate functions as init in this case


}

void LevelGen::drawLevel()
{
    tileX = -maxX;//set to top left
    tileY = maxY;

    glPushMatrix();

        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        glColor3d(1.0,0.0,0.0);

        glBegin(GL_QUADS);

        glVertex3d(-maxX, -maxY, -1.0501); // background for debug reasons
        glVertex3d(maxX, -maxY, -1.0501);
        glVertex3d(maxX, maxY, -1.0501);
        glVertex3d(-maxX, maxY, -1.0501);

        glEnd();

        for(int x=0; x < gridX; x++){
            tileY = maxY;// reset Y to top

            for(int y=0; y < gridY; y++){

                glColor3d((tileX+maxX/2),(tileY+maxY/2),1.0);
                glBegin(GL_QUADS);
                    glVertex3d(tileX, (tileY - tileSizeY), -1.05);
                    glVertex3d((tileX + tileSizeX),(tileY - tileSizeY), -1.05);
                    glVertex3d((tileX + tileSizeX), tileY, -1.05);
                    glVertex3d(tileX,tileY, -1.05);
                glEnd();

                tileY-=tileSizeY; // go to next y tile
            }
                tileX+=tileSizeX; // go to next x tile
        }

        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);

        glColor3d(1.0,1.0,1.0);

    glPopMatrix();
}

bool* LevelGen::getWallMatrix()
{
    return WallMatrix;
}

int LevelGen::getGridX()
{
    return gridX;
}

int LevelGen::getGridY()
{
    return gridY;
}

double LevelGen::getMaxY()
{
    return maxX;
}

double LevelGen::getMaxX()
{
    return maxY;
}

double LevelGen::getOffsetX()
{
    return tileSizeX;
}

double LevelGen::getOffsetY()
{
    return tileSizeY;
}

int LevelGen::getTileX(int tile) // return 0-5 for tile location in tile sheet
{
    if(tile == 0){ // 0 counts as ground and is thus equal to 8
        return 1;
    }

    return (tile-1)%6; // mode number of tile per row
}


int LevelGen::getTileY(int tile) // 0-16
{
    if(tile == 0){ // 0 counts as ground and is thus equal to 8
        return 1;
    }

    return (tile-1)/6; // dived by the number of tile per row
}
