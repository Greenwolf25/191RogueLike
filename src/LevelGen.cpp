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
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
                                 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1

                              }, ((x_tiles-2) * (y_tiles-2)));
        levels[0].setEnemyLocations(NULL,0);
        levels[0].setItemLocations(NULL,0);
        levels[0].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});
    // end level templates


    doors = new bool[maximum_doors_per_room]{};
    openDoors = new bool[maximum_doors_per_room]{};

    levelTemplateIndex = 0; // default to default room

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
    for(int i = 0; i < maximum_doors_per_room; i++){
        doorLinks[i] = NULL;
    }
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
    if(doorLinks[newDoorIndex] != NULL){
            delete doorLinks[newDoorIndex];
            doorLinks[newDoorIndex] = NULL;
    }
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

LevelTemplate LevelNode::getLevelTemplate()
{
    for(int i = 0; i < levels[0].getTileInfoSize(); i++){
        cout << levels[0].getTileInfo()[i] << endl;
        }
        cout << endl;
    return levels[levelTemplateIndex];
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
    tileSet = new TextureLoader;
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
    tileSet->LoadTexture("images/tilesetdebug.png"); // generate functions as init in this case

    startingRoom = new LevelNode();
    startingRoom->addDoor(0, startingRoom);
    startingRoom->addDoor(2, startingRoom);
    startingRoom->addDoor(4, startingRoom);
    startingRoom->addDoor(6, startingRoom);

    currentRoom = startingRoom;

    setWallMatrix();

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

void LevelGen::runPerFrame()
{

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

int LevelGen::getDoorX(int door)
{
    switch (door){
    case 0:
        return 0; // left
        break;
    case 1:
    case 7:
        return 5; // left top and bottom door
        break;
    case 2:
    case 6:
        return 10; // middle
        break;
    case 3:
    case 5:
        return 15;
        break;
    case 4:
        return gridX;
        break;
    default:
        return -1;

    }

}

int LevelGen::getDoorY(int door)
{
    if(door == 0 || door == 4) return 6; // left and right door is y = 6 (coords are from 0 being top left tile)

    if(door > 0 && door < 4) return 0; // top doors

    return gridX; // bottom doors
}


void LevelGen::setWallMatrix()
{
    for(int x=0; x < gridX; x++){ // set wall matrix
        for(int y=0; y < gridY; y++){
            if(x == 0 || x == gridX-1){// if outer wall x
                if(y == getDoorY(0)){ // if it is the correct level for the left or right door in y  axis
                    if((currentRoom->getDoors()[0] && x == getDoorX(0))  ||  (currentRoom->getDoors()[4] && x == getDoorX(4))){ //if door 0 or door 4
                        WallMatrix[(gridX)*y + x] = 0;
                    }
                }else{ // otherwise wall
                    WallMatrix[(gridX)*y + x] = 1;
                }
            }else if(y == 0 || y == gridY-1){// if top and bottom wall
                if(x == getDoorX(1)){ // if door 1 or 7
                    if((currentRoom->getDoors()[1] && y == getDoorY(1))  ||  (currentRoom->getDoors()[7] && y == getDoorY(7))){
                        WallMatrix[(gridX)*y + x] = 0;
                    }
                }else if(x == getDoorX(2)){ // door 2 or 6
                    if((currentRoom->getDoors()[2] && y == getDoorY(2))  ||  (currentRoom->getDoors()[6] && y == getDoorY(6))){
                        WallMatrix[(gridX)*y + x] = 0;
                    }
                }else if(x == getDoorX(3)){ // door 3 or 5
                    if((currentRoom->getDoors()[3] && y == getDoorY(3))  ||  (currentRoom->getDoors()[5] && y == getDoorY(5))){
                        WallMatrix[(gridX)*y + x] = 0;
                    }
                }else{ // otherwise wall
                    WallMatrix[(gridX)*y + x] = 1;
                }
            }else{

                //if and inside wall
                switch (currentRoom->getLevelTemplate().getTileInfo()[(gridX-2)*(y-1) + (x-1)]){ // the subtractions are because tile info does not include the outer walls
                    case 1: // list of solid tiles types
                    case 2: // see tile set debug for numbering
                    case 3:
                    case 4:
                    case 5:
                    case 7:
                    case 9:
                    case 10:
                    case 11:
                    case 13:
                    case 14:
                    case 15:
                    case 33:
                    case 64:
                    case 65:
                    case 66:
                    case 70:
                    case 71:
                    case 76:
                    case 77:
                    case 78:
                    case 81:
                    case 82:
                    case 87:
                    case 88:
                        WallMatrix[(gridX)*y + x] = 1;
                        break;
                    default:
                        WallMatrix[(gridX)*y + x] = 0;//
                        break;
                }
            }
        }
    }

    /*for(int y=0; y < y_tiles; y++){
        for(int x=0; x < x_tiles; x++){
                cout << WallMatrix[(x_tiles)*y + x] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

}
