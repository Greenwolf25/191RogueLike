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
        levelList[5].setTorchLocations(new int[8]{2,8, 3,6, 15,10, 18,3},8);
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
        levelList[12].setPossibleDoors(new bool[maximum_doors_per_room]{1,1,1,1,0,0,1,1});

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
    itemTaken = true;

    itemX = 0;
    itemY = 0;
    Item = 3;
    itemInChest = false;
    isBossRoom = false;
    bossRoomDoor = -1;

    torchStatusTracker = NULL;

    graphCounter = 0;
    branch = -1;
    generated = false;


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
        torchStatusTracker = NULL;
    }

    torchStatusTracker = new bool[levels[input].getTorchLocationsSize()]{};

    if(levels[input].getItemlocationsSize() > 0){
        itemTaken = false;
        int index = rand()%(levels[input].getItemlocationsSize()/3);
        itemX = levels[input].getItemLocations(index*3);
        itemY = levels[input].getItemLocations(index*3 + 1);
    }
}

void LevelNode::addDoor(int newDoorIndex, LevelNode* newRoom, bool open)
{
    if(!levels[levelTemplateIndex].getPossibleDoors(newDoorIndex)) return;// if not a possible door don't do anything
    // creates a door from this room to newRoom at the door locations of newDoorIndex
    doors[newDoorIndex] = true;
    /*if(doorLinks[newDoorIndex] != NULL){ // May cause leak
            delete doorLinks[newDoorIndex];
            doorLinks[newDoorIndex] = NULL;
    }*/
    doorLinks[newDoorIndex] = newRoom;

    if(open){ // set door as open or closed
        openDoors[newDoorIndex] = 1;
    }else{
        openDoors[newDoorIndex] = 0;
    }
}

void LevelNode::closeDoor(int input)
{
    openDoors[input] = false;
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

int LevelNode::getItemX()
{
    return itemX;
}

int LevelNode::getItemY()
{
    return itemY;
}

int LevelNode::getItemType()
{
    return Item;
}


bool LevelNode::setRoomBeat()
{
    roomBeat = true;
}

bool LevelNode::setEnemiesCleared()
{
    enemiesCleared = true;
}

bool LevelNode::setChestOpened()
{
    chestOpened = true;
}

bool LevelNode::setItemTaken()
{
    itemTaken = true;
}

void LevelNode::setItemCoord(int x, int y)
{
    itemX = x;
    itemY = y;
}

void LevelNode::setItemType(int input)
{
    Item = input;
}


void LevelNode::openDoor(int door)
{
    openDoors[door] = true;

}

void LevelNode::generateRoom(bool requireMajorItem)
{
    vector<int> possibleRooms;

    for(int i = 0; i < number_of_level_templates; i++){
        if(requireMajorItem){
            if(levels[i].getItemlocationsSize() == 0) continue; // if no items fail
            bool itemPassFlag = false;
            for(int j = 0; j < levels[i].getItemlocationsSize()/3; j++){
                if(levels[i].getItemLocations((j*3)+2) == 1) itemPassFlag = true;
            }

            if(!itemPassFlag) continue;
        }

        if(doors[0] && !levels[i].getPossibleDoors(0)){
            continue; // do not use i
        }
        if(doors[1] && !levels[i].getPossibleDoors(1)){
            continue; // do not use i
        }
        if(doors[2] && !levels[i].getPossibleDoors(2)){
            continue; // do not use i
        }
        if(doors[3] && !levels[i].getPossibleDoors(3)){
            continue; // do not use i
        }
        if(doors[4] && !levels[i].getPossibleDoors(4)){
            continue; // do not use i
        }
        if(doors[5] && !levels[i].getPossibleDoors(5)){
            continue; // do not use i
        }
        if(doors[6] && !levels[i].getPossibleDoors(6)){
            continue; // do not use i
        }
        if(doors[7] && !levels[i].getPossibleDoors(7)){
            continue; // do not use i
        }
        // it allows the needed doors
        possibleRooms.push_back(i);
    }

    setRoom(possibleRooms.at( (rand()%possibleRooms.size())));
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
    tileSet = new TextureLoader();
    bossDoor = new TextureLoader();

    lockRoom = false;
}

LevelGen::~LevelGen()
{
    delete[] wallMatrix;
    delete[] pitMatrix;
    delete startingRoom;
    delete currentRoom;
    delete tileSet;
    delete bossDoor;
}

void LevelGen::InitLevelGen(ObjList* newObjectList)
{
    tileSet->LoadTexture("images/tileset.png"); // generate functions as init in this case
    bossDoor->LoadTexture("images/BossDoor3.png");
    objectList = newObjectList;
}


void LevelGen::generateLevels()
{
    startingRoom = new LevelNode();
    currentRoom = startingRoom;
    srand(time(0));

    // 0 1 2 x 4 3 6

    LevelNode* mapGrid[7][7]{};
    dir dirMapGrid[7][7]{};
    vector<int> frontier;

    dirMapGrid[3][3].up = 1; // 0,0 is top left
    dirMapGrid[3][3].down = 1;
    dirMapGrid[3][3].left = 1;
    dirMapGrid[3][3].right = 1;
    dirMapGrid[3][3].done = 1;

    frontier.push_back(3); // x
    frontier.push_back(4); // y
    dirMapGrid[3][4].up = 1;
    dirMapGrid[3][4].done = 1;

    frontier.push_back(3); // x
    frontier.push_back(2); // y
    dirMapGrid[3][2].down = 1;
    dirMapGrid[3][2].done = 1;

    frontier.push_back(2);
    frontier.push_back(3);
    dirMapGrid[2][3].right = 1;
    dirMapGrid[2][3].done = 1;

    frontier.push_back(4);
    frontier.push_back(3);
    dirMapGrid[4][3].left = 1;
    dirMapGrid[4][3].done = 1;

    int x,y,randomVal;
    dir temp;
    while(!frontier.empty()){

        y = frontier.back();
        frontier.pop_back();
        x = frontier.back();
        frontier.pop_back();
        temp.up = 0;
        temp.down = 0;
        temp.left = 0;
        temp.right = 0;

        //up
        if(y-1 >= 0 && !dirMapGrid[x][y].up){
            if(!dirMapGrid[x][y-1].done){
                temp.up = 1;
            }
        }

        //down
        if(y+1 <= 6 && !dirMapGrid[x][y].down){
            if(!dirMapGrid[x][y+1].done){
                temp.down = 1;
            }
        }

        //left
        if(x-1 >= 0 && !dirMapGrid[x][y].left){
            if(!dirMapGrid[x-1][y].done){
                temp.left = 1;
            }
        }

        //right
        if(x+1 <=6 && !dirMapGrid[x][y].up){
            if(!dirMapGrid[x+1][y].done){
                temp.right = 1;
            }
        }

        randomVal = rand()%4;
        switch(randomVal){
        case 0:
            if(temp.up){
                dirMapGrid[x][y].up = true;

                dirMapGrid[x][y-1].down = true; // new room
                dirMapGrid[x][y-1].done = true;

                frontier.push_back(x); // add new room to frontier
                frontier.push_back(y-1);
            }
            break;
        case 1:
            if(temp.down){
                dirMapGrid[x][y].down = true;

                dirMapGrid[x][y+1].up = true; // new room
                dirMapGrid[x][y+1].done = true;

                frontier.push_back(x); // add new room to frontier
                frontier.push_back(y+1);
            }
            break;
        case 2:
            if(temp.left){
                dirMapGrid[x][y].left = true;

                dirMapGrid[x-1][y].right = true; // new room
                dirMapGrid[x-1][y].done = true;

                frontier.push_back(x-1); // add new room to frontier
                frontier.push_back(y);
            }
            break;
        case 3:
            if(temp.right){
                dirMapGrid[x][y].right = true;

                dirMapGrid[x+1][y].left = true; // new room
                dirMapGrid[x+1][y].done = true;

                frontier.push_back(x+1); // add new room to frontier
                frontier.push_back(y);
            }
            break;
        }

        if(rand()%4 != 0){ // 75% chance of creating another branch
            randomVal++%4;
            switch(randomVal){
            case 0:
                if(temp.up){
                    dirMapGrid[x][y].up = true;

                    dirMapGrid[x][y-1].down = true; // new room
                    dirMapGrid[x][y-1].done = true;

                    frontier.push_back(x); // add new room to frontier
                    frontier.push_back(y-1);
                }
                break;
            case 1:
                if(temp.down){
                    dirMapGrid[x][y].down = true;

                    dirMapGrid[x][y+1].up = true; // new room
                    dirMapGrid[x][y+1].done = true;

                    frontier.push_back(x); // add new room to frontier
                    frontier.push_back(y+1);
                }
                break;
            case 2:
                if(temp.left){
                    dirMapGrid[x][y].left = true;

                    dirMapGrid[x-1][y].right = true; // new room
                    dirMapGrid[x-1][y].done = true;

                    frontier.push_back(x-1); // add new room to frontier
                    frontier.push_back(y);
                }
                break;
            case 3:
                if(temp.right){
                    dirMapGrid[x][y].right = true;

                    dirMapGrid[x+1][y].left = true; // new room
                    dirMapGrid[x+1][y].done = true;

                    frontier.push_back(x+1); // add new room to frontier
                    frontier.push_back(y);
                }
                break;
            }
        }
    }

    // Create LevelNodes
    for(int y = 0; y < 7; y++){
        for(int x = 0; x < 7; x++){
            if(dirMapGrid[x][y].done){
                mapGrid[x][y] = new LevelNode();
            }
        }
    }

    // link LevelNodes
    mapGrid[3][3] = startingRoom;
    startingRoom->graphCounter = 0;

    startingRoom->addDoor(0, mapGrid[3-1][3],1);
    frontier.push_back(2);
    frontier.push_back(3);
    mapGrid[2][3]->addDoor(4,startingRoom,1);
    mapGrid[2][3]->graphCounter = 1;
    mapGrid[2][3]->branch = 0; // left branch
    dirMapGrid[2][3].right = 0;

    startingRoom->addDoor(2, mapGrid[3][3-1],1);
    frontier.push_back(3);
    frontier.push_back(2);
    mapGrid[3][2]->addDoor(6,startingRoom,1);
    mapGrid[3][2]->graphCounter = 1;
    mapGrid[3][2]->branch = 1; // up branch
    dirMapGrid[3][2].down = 0;

    startingRoom->addDoor(4, mapGrid[3+1][3],1);
    frontier.push_back(4);
    frontier.push_back(3);
    mapGrid[4][3]->addDoor(0,startingRoom,1);
    mapGrid[4][3]->graphCounter = 1;
    mapGrid[4][3]->branch = 2; // right branch
    dirMapGrid[4][3].left = 0;

    startingRoom->addDoor(6, mapGrid[3][3+1],1);
    frontier.push_back(3);
    frontier.push_back(4);
    mapGrid[3][4]->addDoor(2,startingRoom,1);
    mapGrid[3][4]->graphCounter = 1;
    mapGrid[3][4]->branch = 3; // right branch
    dirMapGrid[3][4].up = 0;

    dirMapGrid[3][3].up = 0;
    dirMapGrid[3][3].down = 0;
    dirMapGrid[3][3].left = 0;
    dirMapGrid[3][3].right = 0;


    while(!frontier.empty()){
        y = frontier.back();
        frontier.pop_back();
        x = frontier.back();
        frontier.pop_back();

        //up
        if(dirMapGrid[x][y].up){
                cout << dirMapGrid[x][y].up << endl;
            switch (rand()%3){
            case 0: // left door
                mapGrid[x][y]->addDoor(1,mapGrid[x][y-1],1);
                mapGrid[x][y-1]->addDoor(7,mapGrid[x][y],1);
                mapGrid[x][y-1]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
                mapGrid[x][y-1]->branch = mapGrid[x][y]->branch;
                dirMapGrid[x][y-1].down = 0;// new node down direction has door
                dirMapGrid[x][y].up = 0; // current node up direction has door
                break;

            case 1: // center door
                mapGrid[x][y]->addDoor(2,mapGrid[x][y-1],1);
                mapGrid[x][y-1]->addDoor(6,mapGrid[x][y],1);
                mapGrid[x][y-1]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
                mapGrid[x][y-1]->branch = mapGrid[x][y]->branch;
                dirMapGrid[x][y-1].down = 0;// new node down direction has door
                dirMapGrid[x][y].up = 0; // current node up direction has door
                break;

            case 2: // right door
                mapGrid[x][y]->addDoor(3,mapGrid[x][y-1],1);
                mapGrid[x][y-1]->addDoor(5,mapGrid[x][y],1);
                mapGrid[x][y-1]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
                mapGrid[x][y-1]->branch = mapGrid[x][y]->branch;
                dirMapGrid[x][y-1].down = 0;// new node down direction has door
                dirMapGrid[x][y].up = 0; // current node up direction has door
                break;

            }
            frontier.push_back(x);
            frontier.push_back(y-1);
        }

        //down
        if(dirMapGrid[x][y].down){
            switch (rand()%3){
            case 0: // left door
                mapGrid[x][y]->addDoor(7,mapGrid[x][y+1],1);
                mapGrid[x][y+1]->addDoor(1,mapGrid[x][y],1);
                mapGrid[x][y+1]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
                mapGrid[x][y+1]->branch = mapGrid[x][y]->branch;
                dirMapGrid[x][y+1].up = 0;// new node down direction has door
                dirMapGrid[x][y].down = 0; // current node up direction has door
                break;

            case 1: // center door
                mapGrid[x][y]->addDoor(6,mapGrid[x][y+1],1);
                mapGrid[x][y+1]->addDoor(2,mapGrid[x][y],1);
                mapGrid[x][y+1]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
                mapGrid[x][y+1]->branch = mapGrid[x][y]->branch;
                dirMapGrid[x][y+1].up = 0;// new node down direction has door
                dirMapGrid[x][y].down = 0; // current node up direction has door
                break;

            case 2: // right door
                mapGrid[x][y]->addDoor(5,mapGrid[x][y+1],1);
                mapGrid[x][y+1]->addDoor(3,mapGrid[x][y],1);
                mapGrid[x][y+1]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
                mapGrid[x][y+1]->branch = mapGrid[x][y]->branch;
                dirMapGrid[x][y+1].up = 0;// new node down direction has door
                dirMapGrid[x][y].down = 0; // current node up direction has door
                break;

            }
            frontier.push_back(x);
            frontier.push_back(y+1);
        }

        //left
        if(dirMapGrid[x][y].left){
            mapGrid[x][y]->addDoor(0,mapGrid[x-1][y],1);
            mapGrid[x-1][y]->addDoor(4,mapGrid[x][y],1);
            mapGrid[x-1][y]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
            mapGrid[x-1][y]->branch = mapGrid[x][y]->branch;
            dirMapGrid[x-1][y].right = 0;// new node down direction has door
            dirMapGrid[x][y].left = 0; // current node up direction has door

            frontier.push_back(x-1);
            frontier.push_back(y);
        }

        //right
        if(dirMapGrid[x][y].right){
            mapGrid[x][y]->addDoor(4,mapGrid[x+1][y],1);
            mapGrid[x+1][y]->addDoor(0,mapGrid[x][y],1);
            mapGrid[x+1][y]->graphCounter = mapGrid[x][y]->graphCounter + 1; // new node is further from starting room
            mapGrid[x+1][y]->branch = mapGrid[x][y]->branch;
            dirMapGrid[x+1][y].left = 0;// new node down direction has door
            dirMapGrid[x][y].right = 0; // current node up direction has door

            frontier.push_back(x+1);
            frontier.push_back(y);
        }

    }

    int maxLeft[3]{};
    int maxRight[3]{};
    int maxUp[3]{};
    int maxDown[3]{};

    for(int y = 0; y < 7; y++){
        for(int x = 0; x < 7; x++){
           if(mapGrid[x][y]){
                if(mapGrid[x][y]->branch == 0){//left
                    if(maxLeft[2] < mapGrid[x][y]->graphCounter){
                        maxLeft[0] = x;
                        maxLeft[1] = y;
                        maxLeft[2] = mapGrid[x][y]->graphCounter;
                    }

                }else if(mapGrid[x][y]->branch == 1){ // up
                    if(maxUp[2] < mapGrid[x][y]->graphCounter){
                        maxUp[0] = x;
                        maxUp[1] = y;
                        maxUp[2] = mapGrid[x][y]->graphCounter;
                    }

                }else if(mapGrid[x][y]->branch == 2){ // right
                    if(maxRight[2] < mapGrid[x][y]->graphCounter){
                        maxRight[0] = x;
                        maxRight[1] = y;
                        maxRight[2] = mapGrid[x][y]->graphCounter;
                    }

                }else if(mapGrid[x][y]->branch == 3){ // down
                    if(maxDown[2] < mapGrid[x][y]->graphCounter){
                        maxDown[0] = x;
                        maxDown[1] = y;
                        maxDown[2] = mapGrid[x][y]->graphCounter;
                    }

                }
            }
        }
    }

    //find max branch
    int maxMax = maxLeft[2];
    int maxBranch = 0;
    if(maxMax < maxUp[2]){
        maxBranch = 1;
        maxMax = maxUp[3];

    }
    if(maxMax < maxRight[2]){
        maxBranch = 2;
        maxMax = maxRight[3];

    }
    if(maxMax < maxDown[2]){
        maxBranch = 3;
        maxMax = maxDown[3];
    }

    cout << maxLeft[2] << ' ' << maxUp[2] << ' ' << maxRight[2] << ' ' << maxDown[2] << ' ' << maxBranch << endl;

    // make max branch be boss room
    switch (maxBranch){
    case 0:
        mapGrid[maxLeft[0]][maxLeft[1]]->isBossRoom = true;
        mapGrid[maxLeft[0]][maxLeft[1]]->generated = true;
        cout << maxLeft[0] << ' ' << maxLeft[1] << endl;

        for(int i = 0; i < maximum_doors_per_room; i++){ // find door
            if(mapGrid[maxLeft[0]][maxLeft[1]]->getDoors()[i]){
                switch(i){ // find corresponding door
                case 0:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 4;
                    break;
                case 1:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 7;
                    break;
                case 2:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 6;
                    break;
                case 3:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 5;
                    break;
                case 4:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 0;
                    break;
                case 5:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 3;
                    break;
                case 6:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 2;
                    break;
                case 7:
                    mapGrid[maxLeft[0]][maxLeft[1]]->getNextRoom(i)->bossRoomDoor = 1;
                    break;
                }
            }
        }
        break;
    case 1:
        mapGrid[maxUp[0]][maxUp[1]]->isBossRoom = true;
        mapGrid[maxUp[0]][maxUp[1]]->generated = true;
        cout << maxUp[0] << ' ' << maxUp[1] << endl;

        for(int i = 0; i < maximum_doors_per_room; i++){ // find door
            if(mapGrid[maxUp[0]][maxUp[1]]->getDoors()[i]){
                switch(i){ // find corresponding door
                case 0:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 4;
                    break;
                case 1:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 7;
                    break;
                case 2:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 6;
                    break;
                case 3:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 5;
                    break;
                case 4:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 0;
                    break;
                case 5:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 3;
                    break;
                case 6:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 2;
                    break;
                case 7:
                    mapGrid[maxUp[0]][maxUp[1]]->getNextRoom(i)->bossRoomDoor = 1;
                    break;
                }
            }
        }
        break;
    case 2:
        mapGrid[maxRight[0]][maxRight[1]]->isBossRoom = true;
        mapGrid[maxRight[0]][maxRight[1]]->generated = true;
        cout << maxRight[0] << ' ' << maxRight[1] << endl;

        for(int i = 0; i < maximum_doors_per_room; i++){ // find door
            if(mapGrid[maxRight[0]][maxRight[1]]->getDoors()[i]){
                switch(i){ // find corresponding door
                case 0:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 4;
                    break;
                case 1:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 7;
                    break;
                case 2:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 6;
                    break;
                case 3:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 5;
                    break;
                case 4:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 0;
                    break;
                case 5:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 3;
                    break;
                case 6:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 2;
                    break;
                case 7:
                    mapGrid[maxRight[0]][maxRight[1]]->getNextRoom(i)->bossRoomDoor = 1;
                    break;
                }
            }
        }
        break;
    case 3:
        mapGrid[maxDown[0]][maxDown[1]]->isBossRoom = true;
        mapGrid[maxDown[0]][maxDown[1]]->generated = true;
        cout << maxDown[0] << ' ' << maxDown[1] << endl;

        for(int i = 0; i < maximum_doors_per_room; i++){ // find door
            if(mapGrid[maxDown[0]][maxDown[1]]->getDoors()[i]){
                switch(i){ // find corresponding door
                case 0:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 4;
                    break;
                case 1:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 7;
                    break;
                case 2:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 6;
                    break;
                case 3:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 5;
                    break;
                case 4:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 0;
                    break;
                case 5:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 3;
                    break;
                case 6:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 2;
                    break;
                case 7:
                    mapGrid[maxDown[0]][maxDown[1]]->getNextRoom(i)->bossRoomDoor = 1;
                    break;
                }
            }
        }
        break;
    }

    int keyBranch = (maxBranch+(rand()%3 + 1))%4; // choose random branch other than max to be the boss key
    int keyBranchX, keyBranchY;

    switch(keyBranch){
    case 0:
        keyBranchX = maxLeft[0];//set coords
        keyBranchY = maxLeft[1];

        startingRoom->closeDoor(0); // close that branch and make it need a key
        break;
    case 1:
        keyBranchX = maxUp[0];//set coords
        keyBranchY = maxUp[1];

        startingRoom->closeDoor(2); // close that branch and make it need a key
        break;
    case 2:
        keyBranchX = maxRight[0];//set coords
        keyBranchY = maxRight[1];

        startingRoom->closeDoor(4); // close that branch and make it need a key
        break;
    case 3:
        keyBranchX = maxDown[0];//set coords
        keyBranchY = maxDown[1];

        startingRoom->closeDoor(6); // close that branch and make it need a key
        break;
    }

    mapGrid[keyBranchX][keyBranchY]->generated = true;
    mapGrid[keyBranchX][keyBranchY]->generateRoom(true); // create a room with an item spawn
    mapGrid[keyBranchX][keyBranchY]->setItemType(2); // type 2 is boss key;

    keyBranch++; // then set the branch for the normal key;
    if(keyBranch == maxBranch){
        keyBranch++; // if it is the max branch just inc it again
    }

    switch(keyBranch){
    case 0:
        keyBranchX = maxLeft[0];//set coords
        keyBranchY = maxLeft[1];
        break;
    case 1:
        keyBranchX = maxUp[0];//set coords
        keyBranchY = maxUp[1];
        break;
    case 2:
        keyBranchX = maxRight[0];//set coords
        keyBranchY = maxRight[1];
        break;
    case 3:
        keyBranchX = maxDown[0];//set coords
        keyBranchY = maxDown[1];
        break;
    }

    mapGrid[keyBranchX][keyBranchY]->generated = true;
    mapGrid[keyBranchX][keyBranchY]->generateRoom(true); // create a room with an item spawn
    mapGrid[keyBranchX][keyBranchY]->setItemType(1); // type 1 is normal key;

    startingRoom->generated = true; // do not generate the starting room

    //Generate all of the other rooms
    for(int y = 0; y < 7; y++){
        for(int x = 0; x < 7; x++){
           if(mapGrid[x][y] && !(mapGrid[x][y]->generated)){ // if it is a room and has not been generated yet
                mapGrid[x][y]->generateRoom(0);
                mapGrid[x][y]->generated = true;
           }
        }
    }


    for(int y = 0; y < 7; y++){
        for(int x = 0; x < 7; x++){
           if(mapGrid[x][y]){
                cout << mapGrid[x][y]->branch << mapGrid[x][y]->graphCounter << ' ';
            }else{
                cout << "bx" << ' ';
            }
        }
        cout << endl;
    }


    //SET UP ROOM

    //spawn item
    if(!(currentRoom->isItemTaken()) && currentRoom->getItemType() != 0){ // if there is an item
        switch (currentRoom->getItemType()){
        case 1: // spawn key
            objectList->createItem('k',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        case 2: // spawn boss key
            objectList->createItem('b',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        case 3: // spawn health
            objectList->createItem('h',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        default: // if item type is wrong spawn health kit
            objectList->createItem('h',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        }
    }

    //spawn torches
    for(int i = 0; i < (currentRoom->getLevelTemplate().getTorchLocationsSize()/2); i++){
        objectList->createTorch(gridToCoordX(currentRoom->getLevelTemplate().getTorchLocations(i*2)), // get x location
                                gridToCoordY(currentRoom->getLevelTemplate().getTorchLocations(i*2 +1)), // get y location
                                &currentRoom->torchStatusTracker[i]
                                );
    }
    //spawn enemies
        //TODO


    setWallMatrix();
    setPitMatrix();

}

int LevelGen::enterDoor(int door)
{
    if(door < 0 || door > 7) return 0; // if error do nothing and return door 0
    objectList->clearObjList(); // clear room
    currentRoom = currentRoom->getNextRoom(door);

    //spawn item
    if(!(currentRoom->isItemTaken()) && currentRoom->getItemType() != 0){ // if there is an item
        switch (currentRoom->getItemType()){
        case 1: // spawn key
            objectList->createItem('k',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        case 2: // spawn boss key
            objectList->createItem('b',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        case 3: // spawn health
            objectList->createItem('h',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        default: // if item type is wrong or default spawn health kit
            objectList->createItem('h',gridToCoordX(currentRoom->getItemX()), gridToCoordY(currentRoom->getItemY()));
            break;
        }
    }

    //spawn torches
    for(int i = 0; i < (currentRoom->getLevelTemplate().getTorchLocationsSize()/2); i++){
        objectList->createTorch(gridToCoordX(currentRoom->getLevelTemplate().getTorchLocations(i*2)), // get x location
                                gridToCoordY(currentRoom->getLevelTemplate().getTorchLocations(i*2 +1)), // get y location
                                &currentRoom->torchStatusTracker[i]
                                );
    }
    //spawn enemies
        //TODO

    setWallMatrix();
    setPitMatrix();

    switch(door){ // return opposite door (entering door)
        case 0:
            currentRoom->openDoor(4); // open equivalent door
            wallMatrix[(gridX)*getDoorY(4) + getDoorX(4)] = 0;
            return 4;
        case 1:
            currentRoom->openDoor(7); // open equivalent door
            wallMatrix[(gridX)*getDoorY(7) + getDoorX(7)] = 0;
            return 7;
        case 2:
            currentRoom->openDoor(6); // open equivalent door
            wallMatrix[(gridX)*getDoorY(6) + getDoorX(6)] = 0;
            return 6;
        case 3:
            currentRoom->openDoor(5); // open equivalent door
            wallMatrix[(gridX)*getDoorY(5) + getDoorX(5)] = 0;
            return 5;
        case 4:
            currentRoom->openDoor(0); // open equivalent door
            wallMatrix[(gridX)*getDoorY(0) + getDoorX(0)] = 0;
            return 0;
        case 5:
            currentRoom->openDoor(3); // open equivalent door
            wallMatrix[(gridX)*getDoorY(3) + getDoorX(3)] = 0;
            return 3;
        case 6:
            currentRoom->openDoor(2); // open equivalent door
            wallMatrix[(gridX)*getDoorY(2) + getDoorX(2)] = 0;
            return 2;
        case 7:
            currentRoom->openDoor(1); // open equivalent door
            wallMatrix[(gridX)*getDoorY(1) + getDoorX(1)] = 0;
            return 1;
    }

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

                        if((!(currentRoom->getOpenDoors()[i]) && currentRoom->bossRoomDoor != i) || (lockRoom)){ // if closed render door (unless boss door, then render boss door
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
                        } else if(currentRoom->bossRoomDoor == i){
                            glPushMatrix();
                            bossDoor->binder();
                            glBegin(GL_QUADS);
                            glTexCoord2d(0.0, 0.0);// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(0.0, 1.0);// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(1.0, 1.0);// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)-maxY), -1.018);

                            glTexCoord2d(1.0, 0.0);// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)-maxY), -1.018);
                            glEnd();
                            glPopMatrix();
                            tileSet->binder(); // return to tile set
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

                        if((!(currentRoom->getOpenDoors()[i]) && currentRoom->bossRoomDoor != i) || (lockRoom)){ // if closed render door (unless boss door, then render boss door
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
                        }else if(currentRoom->bossRoomDoor == i){
                            bossDoor->binder();
                            glBegin(GL_QUADS);
                            glTexCoord2d(0.0, 1.0);// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(1.0, 1.0);// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(1.0, 0.0);// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)+maxY), -1.018);

                            glTexCoord2d(0.0, 0.0);// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)+maxY), -1.018);
                            glEnd();
                            tileSet->binder(); // return to tile set
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

                        if((!(currentRoom->getOpenDoors()[i]) && currentRoom->bossRoomDoor != i) || (lockRoom)){ // if closed render door (unless boss door, then render boss door
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
                        }else if(currentRoom->bossRoomDoor == i){
                            bossDoor->binder();
                            glBegin(GL_QUADS);
                            glTexCoord2d(1.0, 1.0);// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(1.0, 0.0);// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),(((getDoorY(i)*tileSizeY)-maxY) - tileSizeY), -1.018);

                            glTexCoord2d(0.0, 0.0);// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), ((getDoorY(i)*tileSizeY)-maxY), -1.018);

                            glTexCoord2d(0.0, 1.0);// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((getDoorY(i)*tileSizeY)-maxY), -1.018);
                            glEnd();
                            tileSet->binder(); // return to tile set
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

                        if((!(currentRoom->getOpenDoors()[i]) && currentRoom->bossRoomDoor != i) || (lockRoom)){ // if closed render door (unless boss door, then render boss door
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
                        }else if(currentRoom->bossRoomDoor == i){
                            bossDoor->binder();
                            glBegin(GL_QUADS);
                            glTexCoord2d(1.0, 0.0);// bottom left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, ((-(getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(0.0, 0.0);// bottom right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX),((-(getDoorY(i)*tileSizeY)+maxY) - tileSizeY), -1.018);

                            glTexCoord2d(0.0, 1.0);// top right
                            glVertex3d((((getDoorX(i)*tileSizeX)-maxX) + tileSizeX), (-(getDoorY(i)*tileSizeY)+maxY), -1.018);

                            glTexCoord2d(1.0, 1.0);// top left
                            glVertex3d((getDoorX(i)*tileSizeX)-maxX, (-(getDoorY(i)*tileSizeY)+maxY), -1.018);
                            glEnd();
                            tileSet->binder(); // return to tile set
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

bool LevelGen::openDoor(int door)
{
    if(lockRoom) return false;

    if(currentRoom->getOpenDoors()[door]){
        return false; // door is open so do not use key
    }else{
        currentRoom->openDoor(door);
        wallMatrix[(gridX)*getDoorY(door) + getDoorX(door)] = 0;
        return true;
    }
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
        if(x == getDoorX(1)){
            return 1;
        }else if(x == getDoorX(2)){
            return 2;
        }else if (x == getDoorX(3)){
            return 3;
        }else{
            return -1;
        }

    }else if(y == gridY-1){
        if(x == getDoorX(5)){
            return 5;
        }else if(x == getDoorX(6)){
            return 6;
        }else if (x == getDoorX(7)){
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

    return (tile-1)/6; // dived by the number of tile per column
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
