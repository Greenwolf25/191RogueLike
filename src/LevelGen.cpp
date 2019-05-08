#include "LevelGen.h"



LevelTemplate::LevelTemplate()
{

}

LevelTemplate::~LevelTemplate()
{

}

int LevelTemplate::getTileInfo(int index)
{
    return tileInfo.at(index);
}

bool LevelTemplate::getPossibleDoors(int index)
{
    return possibleDoors.at(index);
}

int LevelTemplate::getEnemyLocations(int index)
{
    return enemyLocations.at(index);
}

int LevelTemplate::getItemLocations(int index)
{
    return itemLocations.at(index);
}

int LevelTemplate::getTorchLocations(int index)
{
    return torchLocations.at(index);
}

void LevelTemplate::setTileInfo(int* TI, int size)
{
    if(!tileInfo.empty()){
        tileInfo.clear();
    }
    tileInfo.reserve(size);
    for(int i=0; i < size ; i++){
        tileInfo.push_back(TI[i]);
    }

    delete TI;
}

void LevelTemplate::setPossibleDoors(bool* PD)
{
     if(!possibleDoors.empty()){
        possibleDoors.clear();
     }
     possibleDoors.reserve(maximum_doors_per_room);
     for(int i=0; i < maximum_doors_per_room ; i++){
        possibleDoors.push_back(PD[i]);
    }

    delete PD;
}

void LevelTemplate::setEnemyLocations(int* EL, int size)
{
    if(!enemyLocations.empty()){
        enemyLocations.clear();
    }
    enemyLocations.reserve(size);
    for(int i=0; i < size ; i++){
        enemyLocations.push_back(EL[i]);
    }
    delete EL;
}

void LevelTemplate::setItemLocations(int* IL, int size)
{
    if(!itemLocations.empty()){
        itemLocations.clear();
    }
    itemLocations.reserve(size);
    for(int i=0; i < size ; i++){
        itemLocations.push_back(IL[i]);
    }

    delete IL;
}

void LevelTemplate::setTorchLocations(int* TL, int size)
{
    if(!torchLocations.empty()){
        torchLocations.clear();
    }
    torchLocations.reserve(size);
    for(int i=0; i < size ; i++){
        torchLocations.push_back(TL[i]);
    }

    delete TL;
}

int LevelTemplate::getTileInfoSize()
{
    return tileInfo.size();
}

int LevelTemplate::getEnemyLocationsSize()
{
    return enemyLocations.size();
}

int LevelTemplate::getItemlocationsSize()
{
    return itemLocations.size();
}

int LevelTemplate::getTorchLocationsSize()
{
    return torchLocations.size();
}

/// LELEL LIST ------------------------------------------------------------------------------

templateList::templateList()
{
    levelList = new LevelTemplate[number_of_level_templates]; /// CHANGE DEFINE WHEN ADDING TEMPATES
        // template 0 default room
        levelList[0].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[0].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 1
        levelList[1].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                43, 44, 44, 45,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 44, 45,
                                49, 50, 50, 51,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 50, 51,
                                49, 50, 50, 51,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 50, 51,
                                55, 56, 56, 57,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 55, 56, 56, 57,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                43, 44, 44, 45,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 44, 45,
                                49, 50, 50, 51,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 50, 51,
                                55, 56, 56, 57,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 55, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[1].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 2
        levelList[2].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45,
                                49, 50, 33, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[2].setPossibleDoors(new bool[maximum_doors_per_room]{1,0,0,0,1,0,0,0});

        // template 3
        levelList[3].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45,
                                49, 50, 50, 50, 50, 50, 33, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                55, 56, 56, 56, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                 0,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 33, 51,
                                 0,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                 0,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                 0,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                 0,  0,  0,  0, 49, 50, 50, 50, 50, 50, 33, 50, 50, 50, 50, 50, 50, 50, 51,
                                43, 44, 44, 44, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[3].setItemLocations(new int[3]{3,6,1},3); // item one (key) at (3,6)
        levelList[3].setPossibleDoors(new bool[maximum_doors_per_room]{1,0,0,0,0,0,0,0});

         // template 4
        levelList[4].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 56, 56, 56, 57,
                                49, 50, 50, 50, 50, 50, 33, 50, 50, 50, 50, 50, 50, 50, 51,  0,  0,  0,  0,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,  0,  0,  0,  0,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,  0,  0,  0,  0,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51,  0,  0,  0,  0,
                                49, 50, 50, 50, 50, 50, 50, 50, 50, 33, 50, 50, 50, 50, 51,  0,  0,  0,  0,
                                49, 33, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 44, 44, 44, 45,
                                55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[4].setItemLocations(new int[3]{17,6,1},3); // item one (key) at (17,6)
        levelList[4].setPossibleDoors(new bool[maximum_doors_per_room]{0,0,0,0,1,0,0,0});

        // template 5
        levelList[5].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                43, 44, 44, 44, 44, 44, 44, 45,  0,  0,  0, 43, 44, 44, 44, 44, 44, 44, 45,
                                49, 50, 56, 56, 56, 56, 56, 57,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                49, 51,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 50, 50, 50, 50, 33, 51,
                                49, 50, 44, 44, 44, 44, 44, 45,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                49, 50, 56, 50, 50, 50, 50, 51,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                49, 51,  0, 49, 50, 63, 65, 51,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                55, 56, 44, 50, 50, 75, 77, 51,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                 0,  0, 49, 50, 50, 50, 50, 51,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                43, 44, 50, 50, 50, 50, 50, 51,  0,  0,  0, 49, 50, 50, 56, 50, 50, 50, 51,
                                55, 56, 56, 56, 56, 56, 56, 57,  0,  0,  0, 55, 56, 57,  0, 55, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[5].setTorchLocations(new int[8]{2,8, 3,3, 15,10, 18,3},8);
        levelList[5].setPossibleDoors(new bool[maximum_doors_per_room]{0,0,1,0,0,0,1,0});

        // template 6
        levelList[6].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                43, 44, 45,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 44, 45,
                                49, 50, 51,  0,  0,  0, 43, 44, 44, 44, 44, 44, 44, 45,  0, 49, 50, 50, 51,
                                49, 50, 56, 39, 39, 39, 50, 50, 50, 56, 56, 56, 50, 51,  0, 49, 50, 50, 51,
                                55, 57,  0,  0,  0,  0, 49, 50, 51,  0,  0,  0, 49, 51,  0, 49, 50, 56, 57,
                                 0,  0,  0, 43, 45,  0, 49, 50, 51,  0,  0,  0, 55, 57,  0, 55, 57,  0,  0,
                                 0,  0, 43, 50, 51,  0, 49, 50, 51,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0, 49, 50, 51,  0, 49, 50, 51,  0, 43, 44, 44, 44, 44, 44, 45,  0,  0,
                                43, 44, 50, 50, 51,  0, 49, 50, 57,  0, 55, 50, 50, 50, 50, 50, 50, 44, 45,
                                49, 33, 50, 50, 51,  0, 55, 57,  0,  0,  0, 49, 50, 50, 50, 50, 50, 50, 51,
                                55, 56, 56, 56, 57,  0,  0,  0,  0,  0,  0, 55, 56, 56, 56, 56, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[6].setItemLocations(new int[3]{11,5,1},3); // item one (key) at (17,6)
        levelList[6].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,0,0,1,0,1,0});

        // template 7
        levelList[7].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0, 63, 64, 64, 64, 64, 64, 64, 64, 64, 64, 65,  0,  0,  0,  0,
                                 0,  0,  0,  0, 69,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0,  0,  0,  0,
                                 0,  0,  0,  0, 69,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0,  0,  0,  0,
                                 0,  0,  0,  0, 69,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0,  0,  0,  0,
                                 0,  0,  0,  0, 75, 76, 76, 76, 76, 54, 76, 76, 76, 76, 77,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[7].setItemLocations(new int[6]{6,5,1,14,5,1},6);
        levelList[7].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 8
        levelList[8].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0, 63,  0, 65,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0, 75,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[8].setItemLocations(new int[3]{10,6,1},3);
        levelList[8].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 9
        levelList[9].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  1,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  0,  0,
                                 0,  0, 13, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 13, 15,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  1,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  0,  0,
                                 0,  0, 13, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 13, 15,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[9].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 10
        levelList[10].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  1,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  0,  0,
                                 0,  0, 13, 15,  0,  0,  0,  0, 43, 44, 45,  0,  0,  0,  0, 13, 15,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 51,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 51,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  1,  3,  0,  0,  0,  0, 55, 56, 57,  0,  0,  0,  0,  1,  3,  0,  0,
                                 0,  0, 13, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 13, 15,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[10].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 11
        levelList[11].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 45,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0, 43, 50, 50, 50, 45,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0, 43, 50, 50, 33, 50, 50, 45,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0, 55, 50, 50, 33, 50, 50, 57,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0, 55, 50, 50, 50, 57,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0, 55, 56, 57,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[11].setTorchLocations(new int[4]{10,6, 10,5},4);
        levelList[11].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 12
        levelList[12].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 45,  0, 43, 45,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 56, 44, 50, 51,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 51,  0, 49, 50, 51,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 50, 50, 44, 50, 50, 51,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 55, 56, 56, 56, 56, 56, 56, 57

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[12].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

        // template 13
        levelList[13].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 44, 44, 44, 45,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 56, 50, 50, 50, 51,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0, 55, 50, 50, 51,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0,  0, 49, 50, 57,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0,  0, 55, 57,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0, 43, 82, 76, 76,  0, 76, 76, 76, 77,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0, 55, 56, 57,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[13].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,0,1,1,1,1});

         // template 14
        levelList[14].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0, 11, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  9,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  9,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  9,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  9, 13, 14, 14, 14, 10, 54, 11, 14, 14, 14, 10,  0,  0,  0,  0,
                                 0,  0,  0,  5,  2,  2,  2,  2,  4, 54,  5,  2,  2,  2,  4,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[14].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});

          // template 14
        levelList[15].setTileInfo(new int[(x_tiles-2) * (y_tiles-2)] // -2 to subtract outer walls as they are known
                              {
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 43, 44, 44, 45,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 50, 56, 57,  0,  0,  0,
                                 0,  0, 43, 44, 44, 44, 44, 44, 44, 54, 44, 44, 50, 51,  0,  0,  0,  0,  0,
                                 0,  0, 55, 56, 56, 56, 56, 56, 56, 54, 56, 56, 56, 57,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                                 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0

                              }, ((x_tiles-2) * (y_tiles-2)));
        levelList[15].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,1,1,1,1});
    // end level templates


    /// for loading levels REMEBER THAT THE TEMPLATE IS FOR TILES 1-19 not 0-20
    /// left and right door y = 6
    /// top and bottom door x = 5, 10, 15
}

templateList::~templateList()
{
    delete[] levelList;
}

LevelTemplate& templateList::operator[](int x)
{
    return levelList[x];
}


/// LEVEL NODE ------------------------------------------------------------------------------
templateList LevelNode::levels;

LevelNode::LevelNode()
{
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


    doorLinks = new LevelNode*[maximum_doors_per_room];
    for(int i = 0; i < maximum_doors_per_room; i++){
        doorLinks[i] = NULL;
    }
}

LevelNode::~LevelNode()
{
    delete[] doors;
    delete[] openDoors;
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

void LevelNode::addDoor(int newDoorIndex, LevelNode* newRoom, bool open)
{
    if(!levels[levelTemplateIndex].getPossibleDoors(newDoorIndex)) return;// if not a possible door don't do anything
    // creates a door from this room to newRoom at the door locations of newDoorIndex
    doors[newDoorIndex] = true;
    if(doorLinks[newDoorIndex] != NULL){
            delete doorLinks[newDoorIndex];
            doorLinks[newDoorIndex] = NULL;
    }
    doorLinks[newDoorIndex] = newRoom;

    if(open){ // set door as open or closed
        openDoors[newDoorIndex] = 1;
    }else{
        openDoors[newDoorIndex] = 0;
    }
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
    /*for(int i = 0; i < levels[0].getTileInfoSize(); i++){
        cout << levels[0].getTileInfo(i) << endl;
        }
        cout << endl;*/

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

    wallMatrix = new bool[gridX*gridY]{};
    pitMatrix = new bool [gridX*gridY]{};
    tileSet = new TextureLoader;
}

LevelGen::~LevelGen()
{
    delete[] wallMatrix;
    delete[] pitMatrix;
    delete startingRoom;
    delete currentRoom;
    delete tileSet;
}

void LevelGen::generateLevels()
{
    tileSet->LoadTexture("images/tileset.png"); // generate functions as init in this case

    startingRoom = new LevelNode();
    startingRoom->setRoom(0);
    startingRoom->addDoor(0, startingRoom, 0);
    startingRoom->addDoor(1, startingRoom, 1);
    startingRoom->addDoor(2, startingRoom, 1);
    startingRoom->addDoor(3, startingRoom, 0);
    startingRoom->addDoor(4, startingRoom, 1);
    startingRoom->addDoor(5, startingRoom, 1);
    startingRoom->addDoor(6, startingRoom, 1);
    startingRoom->addDoor(7, startingRoom, 1);

    currentRoom = startingRoom;

    setWallMatrix();
    setPitMatrix();

}

void LevelGen::drawLevel()
{
    tileX = -maxX;//set to top left
    tileY = maxY;

    glPushMatrix();

        //glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        glColor3d(1.0,0.0,0.0);

        glBegin(GL_QUADS);

        glVertex3d(-maxX, -maxY, -1.0201); // background for debug reasons
        glVertex3d(maxX, -maxY, -1.0201);
        glVertex3d(maxX, maxY, -1.0201);
        glVertex3d(-maxX, maxY, -1.0201);

        glEnd();

        glColor3d(1.0,1.0,1.0);
        glEnable(GL_TEXTURE_2D);
        tileSet->binder();

        for(int x=0; x < gridX; x++){
            tileY = maxY;// reset Y to top

            for(int y=0; y < gridY; y++){

                // Set tile texture
                if(x == 0){ // if rendering the left wall

                        if(y == getDoorY(0) && currentRoom->getDoors()[0]){// if door 0 (left door)
                            textureX = getTileX(8); // then set tile to be floor
                            textureY = getTileY(8);
                        }else if(y == 0){ // if top left
                            textureX = getTileX(1);
                            textureY = getTileY(1);
                        }else if(y == gridY-1){// if bottom left
                            textureX = getTileX(13);
                            textureY = getTileY(13);
                        }else{// otherwise left wall
                            textureX = getTileX(7);
                            textureY = getTileY(7);
                        }

                }else if(x == gridX-1){ // if rendering the right wall

                    if(y == getDoorY(4) && currentRoom->getDoors()[4]){// if door 4 (right door)
                            textureX = getTileX(8); // then set tile to be floor
                            textureY = getTileY(8);
                    }else if(y == 0){ // if top right
                        textureX = getTileX(3);
                        textureY = getTileY(3);
                    }else if(y == gridY-1){// if bottom right
                        textureX = getTileX(15);
                        textureY = getTileY(15);
                    }else{// otherwise right wall
                        textureX = getTileX(9);
                        textureY = getTileY(9);
                    }

                }else if(y == 0){ // if rendering the top wall
                    // corners are taken care off by above cases
                    if((x == getDoorX(1) && currentRoom->getDoors()[1]) || (x == getDoorX(2) && currentRoom->getDoors()[2]) || (x == getDoorX(3) && currentRoom->getDoors()[3])){// if door 1,2, or 3 (top doors)
                            textureX = getTileX(8); // then set tile to be floor
                            textureY = getTileY(8);
                    }else{
                        textureX = getTileX(2);
                        textureY = getTileY(2);
                    }

                }else if(y == gridY-1){ // if rendering the bottom wall
                    // corners are taken care off by above cases
                    if((x == getDoorX(5) && currentRoom->getDoors()[5]) || (x == getDoorX(6) && currentRoom->getDoors()[6]) || (x == getDoorX(7) && currentRoom->getDoors()[7])){// if door 5,6, or 7 (bottom doors)
                            textureX = getTileX(8); // then set tile to be floor
                            textureY = getTileY(8);
                    }else{
                        textureX = getTileX(14);
                        textureY = getTileY(14);
                    }

                }else{ // otherwise get the tile data from the template
                    textureX = getTileX(currentRoom->getLevelTemplate().getTileInfo((gridX-2)*(y-1) + (x-1)));
                    textureY = getTileY(currentRoom->getLevelTemplate().getTileInfo((gridX-2)*(y-1) + (x-1)));
                }

                //glColor3d((tileX+maxX/2),(tileY+maxY/2),1.0);
                glBegin(GL_QUADS);

                    glTexCoord2d(textureX * (1.0/6.0), textureY * (1.0/17.0) + (1.0/17.0));// bottom left
                    glVertex3d(tileX, (tileY - tileSizeY), -1.02);

                    glTexCoord2d(textureX * (1.0/6.0) + (1.0/6.0), textureY * (1.0/17.0) + (1.0/17.0));// bottom right
                    glVertex3d((tileX + tileSizeX),(tileY - tileSizeY), -1.02);

                    glTexCoord2d(textureX * (1.0/6.0) + (1.0/6.0), textureY * (1.0/17.0));// top right
                    glVertex3d((tileX + tileSizeX), tileY, -1.02);

                    glTexCoord2d(textureX * (1.0/6.0), textureY * (1.0/17.0));// top left
                    glVertex3d(tileX,tileY, -1.02);

                glEnd();

                tileY-=tileSizeY; // go to next y tile
            }
                tileX+=tileSizeX; // go to next x tile
        }

        for(int i = 0; i < maximum_doors_per_room; i++){ // render doors
            if(currentRoom->getDoors()[i]){
                switch(i){
                    case 0:
                        glBegin(GL_QUADS);
                        glTexCoord2d(3 * (1.0/6.0), 5 * (1.0/17.0));// bottom left
                        glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)-maxY) - tileSizeY) - tileSizeY, -1.019);

                        glTexCoord2d(4 * (1.0/6.0), 5 * (1.0/17.0));// bottom right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)-maxY) - tileSizeY) - tileSizeY, -1.019);

                        glTexCoord2d(4 * (1.0/6.0), 2 * (1.0/17.0));// top right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)-maxY) + tileSizeY, -1.019);

                        glTexCoord2d(3 * (1.0/6.0), 2 * (1.0/17.0));// top left
                        glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)-maxY)  + tileSizeY, -1.019);
                        glEnd();

                        if(!(currentRoom->getOpenDoors()[i])){ // if closed render door
                            glBegin(GL_QUADS);
                            glTexCoord2d(getTileX(68) * (1.0/6.0), getTileY(68) * (1.0/17.0) + (1.0/17.0));// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(68) * (1.0/6.0) + (1.0/6.0), getTileY(68) * (1.0/17.0) + (1.0/17.0));// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(68) * (1.0/6.0) + (1.0/6.0), getTileY(68) * (1.0/17.0));// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)-maxY), -1.018);

                            glTexCoord2d(getTileX(68) * (1.0/6.0), getTileY(68) * (1.0/17.0));// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)-maxY), -1.018);
                            glEnd();
                        }
                        break;
                    case 1:
                    case 2:
                    case 3:
                        glBegin(GL_QUADS);
                        glTexCoord2d(0 * (1.0/6.0), 4 * (1.0/17.0));// bottom left
                        glVertex3d(((getDoorX(i)*tileSizeX)-maxX) - tileSizeX, (((getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.019);

                        glTexCoord2d(3 * (1.0/6.0), 4 * (1.0/17.0));// bottom right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX) + tileSizeX,(((getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.019);

                        glTexCoord2d(3 * (1.0/6.0), 3 * (1.0/17.0));// top right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX) + tileSizeX, ((getDoorY(i)*tileSizeY)+maxY), -1.019);

                        glTexCoord2d(0 * (1.0/6.0), 3 * (1.0/17.0));// top left
                        glVertex3d(((getDoorX(i)*tileSizeX)-maxX) - tileSizeX, ((getDoorY(i)*tileSizeY)+maxY), -1.019);
                        glEnd();

                        if(!(currentRoom->getOpenDoors()[i])){ // if closed render door
                            glBegin(GL_QUADS);
                            glTexCoord2d(getTileX(41) * (1.0/6.0), getTileY(41) * (1.0/17.0) + (1.0/17.0));// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(41) * (1.0/6.0) + (1.0/6.0), getTileY(41) * (1.0/17.0) + (1.0/17.0));// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(41) * (1.0/6.0) + (1.0/6.0), getTileY(41) * (1.0/17.0));// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)+maxY), -1.018);

                            glTexCoord2d(getTileX(41) * (1.0/6.0), getTileY(41) * (1.0/17.0));// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)+maxY), -1.018);
                            glEnd();
                        }
                        break;
                    case 4:
                        glBegin(GL_QUADS);
                        glTexCoord2d(4 * (1.0/6.0), 5 * (1.0/17.0));// bottom left
                        glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)-maxY) - tileSizeY) - tileSizeY, -1.019);

                        glTexCoord2d(5 * (1.0/6.0), 5 * (1.0/17.0));// bottom right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)-maxY) - tileSizeY) - tileSizeY, -1.019);

                        glTexCoord2d(5 * (1.0/6.0), 2 * (1.0/17.0));// top right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)-maxY) + tileSizeY, -1.019);

                        glTexCoord2d(4 * (1.0/6.0), 2 * (1.0/17.0));// top left
                        glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)-maxY)  + tileSizeY, -1.019);
                        glEnd();

                        if(!(currentRoom->getOpenDoors()[i])){ // if closed render door
                            glBegin(GL_QUADS);
                            glTexCoord2d(getTileX(67) * (1.0/6.0), getTileY(67) * (1.0/17.0) + (1.0/17.0));// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(67) * (1.0/6.0) + (1.0/6.0), getTileY(67) * (1.0/17.0) + (1.0/17.0));// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(67) * (1.0/6.0) + (1.0/6.0), getTileY(67) * (1.0/17.0));// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)-maxY), -1.018);

                            glTexCoord2d(getTileX(67) * (1.0/6.0), getTileY(67) * (1.0/17.0));// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)-maxY), -1.018);
                            glEnd();
                        }
                        break;
                    case 5:
                    case 6:
                    case 7:
                        glBegin(GL_QUADS);
                        glTexCoord2d(0 * (1.0/6.0), 5 * (1.0/17.0));// bottom left
                        glVertex3d(((getDoorX(i)*tileSizeX)-maxX) - tileSizeX, ((-(getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.019);

                        glTexCoord2d(3 * (1.0/6.0), 5 * (1.0/17.0));// bottom right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX) + tileSizeX,((-(getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.019);

                        glTexCoord2d(3 * (1.0/6.0), 4 * (1.0/17.0));// top right
                        glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX) + tileSizeX, (-(getDoorY(i)*tileSizeY)+maxY), -1.019);

                        glTexCoord2d(0 * (1.0/6.0), 4 * (1.0/17.0));// top left
                        glVertex3d(((getDoorX(i)*tileSizeX)-maxX) - tileSizeX, (-(getDoorY(i)*tileSizeY)+maxY), -1.019);
                        glEnd();

                        if(!(currentRoom->getOpenDoors()[i])){ // if closed render door
                            glBegin(GL_QUADS);
                            glTexCoord2d(getTileX(47) * (1.0/6.0), getTileY(47) * (1.0/17.0) + (1.0/17.0));// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((-(getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(47) * (1.0/6.0) + (1.0/6.0), getTileY(47) * (1.0/17.0) + (1.0/17.0));// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),((-(getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(getTileX(47) * (1.0/6.0) + (1.0/6.0), getTileY(47) * (1.0/17.0));// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), (-(getDoorY(i)*tileSizeY)+maxY), -1.018);

                            glTexCoord2d(getTileX(47) * (1.0/6.0), getTileY(47) * (1.0/17.0));// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (-(getDoorY(i)*tileSizeY)+maxY), -1.018);
                            glEnd();
                        }
                        break;
                }
            }
        }
    glPopMatrix();
}

void LevelGen::runPerFrame()
{

}

bool LevelGen::getWallMatrix(int index)
{
    return wallMatrix[index];
}

bool LevelGen::getPitMatrix(int index)
{
    return pitMatrix[index];
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

double LevelGen::gridToCoordX(int tileX)
{
    return (-maxX + tileSizeX * tileX) + tileSizeX/2;
}

double LevelGen::gridToCoordY(int tileY)
{
    return (maxY - tileSizeY * tileY) - tileSizeY/2;
}

int LevelGen::coordToGridX(double coordX)
{
    if(coordX+maxX < 0) return 0;
    if((coordX+maxX) > maxX*2) return gridX-1;
    int quotient = 1;
    while(quotient*tileSizeX < (coordX+maxX)){
        quotient++;
    }

    return quotient-1;
}

int LevelGen::coordToGridY(double coordY)
{
    if(maxY-coordY < 0) return 0;
    if((maxY-coordY) > maxY*2) return gridY-1;
    int quotient = 1;
    while(quotient*tileSizeY < (maxY-coordY)){
        quotient++;
    }

    return (quotient-1);
}

int LevelGen::getTileIndex(int x, int y)
{
    return (gridX)*y + x;
}

int LevelGen::gridToDoorNum(int x, int y)
{
    if(x == 0){
        if(x == getDoorX(0)){
            return 0;
        }else{
            return -1;
        }

    }else if(x == gridX-1){
        if(x == getDoorX(4)){
            return 4;
        }else{
            return -1;
        }

    }else if(y == 0){
        if(y == getDoorY(1)){
            return 1;
        }else if(y == getDoorY(2)){
            return 2;
        }else if (y == getDoorY(3)){
            return 3;
        }else{
            return -1;
        }

    }else if(y == gridY-1){
        if(y == getDoorY(5)){
            return 5;
        }else if(y == getDoorY(6)){
            return 6;
        }else if (y == getDoorY(7)){
            return 7;
        }else{
            return -1;
        }
    }else{
        return -1; // not a door
    }
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
        return gridX-1;
        break;
    default:
        return -1;

    }

}

int LevelGen::getDoorY(int door)
{
    if(door == 0 || door == 4) return 6; // left and right door is y = 6 (coords are from 0 being top left tile)

    if(door > 0 && door < 4) return 0; // top doors

    return gridY-1; // bottom doors
}


void LevelGen::setWallMatrix()
{
    for(int x=0; x < gridX; x++){ // set wall matrix
        for(int y=0; y < gridY; y++){
            if(x == 0 || x == gridX-1){// if outer wall x
                if(y == getDoorY(0)){ // if it is the correct level for the left or right door in y  axis
                    if((currentRoom->getDoors()[0] && x == getDoorX(0) && currentRoom->getOpenDoors()[0])  ||  (currentRoom->getDoors()[4] && x == getDoorX(4) && currentRoom->getOpenDoors()[4])){ //if door 0 or door 4
                        wallMatrix[(gridX)*y + x] = 0;
                    }else{ // otherwise wall
                        wallMatrix[(gridX)*y + x] = 1;
                    }
                }else{ // otherwise wall
                    wallMatrix[(gridX)*y + x] = 1;
                }
            }else if(y == 0 || y == gridY-1){// if top and bottom wall
                if(x == getDoorX(1)){ // if door 1 or 7
                    if((currentRoom->getDoors()[1] && y == getDoorY(1) && currentRoom->getOpenDoors()[1]) || (currentRoom->getDoors()[7] && y == getDoorY(7) && currentRoom->getOpenDoors()[7])){
                        wallMatrix[(gridX)*y + x] = 0;
                    }else{ // otherwise wall
                        wallMatrix[(gridX)*y + x] = 1;
                    }
                }else if(x == getDoorX(2)){ // door 2 or 6
                    if((currentRoom->getDoors()[2] && y == getDoorY(2) && currentRoom->getOpenDoors()[2])  ||  (currentRoom->getDoors()[6] && y == getDoorY(6) && currentRoom->getOpenDoors()[6])){
                        wallMatrix[(gridX)*y + x] = 0;
                    }else{ // otherwise wall
                        wallMatrix[(gridX)*y + x] = 1;
                    }
                }else if(x == getDoorX(3)){ // door 3 or 5
                    if((currentRoom->getDoors()[3] && y == getDoorY(3) && currentRoom->getOpenDoors()[3])  ||  (currentRoom->getDoors()[5] && y == getDoorY(5) && currentRoom->getOpenDoors()[5])){
                        wallMatrix[(gridX)*y + x] = 0;
                    }else{ // otherwise wall
                        wallMatrix[(gridX)*y + x] = 1;
                    }
                }else{ // otherwise wall
                    wallMatrix[(gridX)*y + x] = 1;
                }
            }else{

                //if and inside wall
                switch (currentRoom->getLevelTemplate().getTileInfo((gridX-2)*(y-1) + (x-1))){ // the subtractions are because tile info does not include the outer walls
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
                    case 63:
                    case 64:
                    case 65:
                    case 69:
                    case 71:
                    case 75:
                    case 76:
                    case 77:
                    case 81:
                    case 82:
                    case 87:
                    case 88:
                        wallMatrix[(gridX)*y + x] = 1;
                        break;
                    default:
                        wallMatrix[(gridX)*y + x] = 0;//
                        break;
                }
            }
        }
    }
}

void LevelGen::setPitMatrix()
{
    for(int x=0; x < gridX; x++){ // set wall matrix
        for(int y=0; y < gridY; y++){
            if(x == 0 || x == gridX-1){// if outer wall x
                pitMatrix[(gridX)*y + x] = 0;
            }else if(y == 0 || y == gridY-1){// if top and bottom wall
                pitMatrix[(gridX)*y + x] = 0;
            }else{

                //if and inside wall
                switch (currentRoom->getLevelTemplate().getTileInfo((gridX-2)*(y-1) + (x-1))){ // the subtractions are because tile info does not include the outer walls
                    case 6: // list of solid tiles types
                    case 34: // see tile set debug for numbering
                    case 39:
                    case 43:
                    case 44:
                    case 45:
                    case 49:
                    case 50:
                    case 51:
                    case 55:
                    case 56:
                    case 57:
                        pitMatrix[(gridX)*y + x] = 1;
                        break;
                    default:
                        pitMatrix[(gridX)*y + x] = 0;//
                        break;
                }
            }
        }
    }
}
