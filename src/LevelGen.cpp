#include "LevelGen.h"

int blankroom[21*12*4] =
{
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,
0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0
};

LevelNode::LevelNode()
{
    tileInfo = new int[21*12*4]{};

    doors = new bool[8]{};
    openDoors = new bool[8]{};
    bool roomBeat = false;
    LevelNode* doorLinks = new LevelNode[8]{};
}

LevelNode::~LevelNode()
{
    delete[] tileInfo;
    delete[] doors;
    delete[] openDoors;
    delete[] doorLinks;
}

void LevelNode::setRoom(int)
{

}

bool* LevelNode::getPossibleDoors()
{

}

void LevelNode::addDoor(int, LevelNode*)
{

}

bool* LevelNode::getDoors()
{

}

bool* LevelNode::getOpenDoors()
{

}

bool LevelNode::isRoomBeat()
{

}

/// Level generator

LevelGen::LevelGen()
{
    gridX = 21;
    gridY = 12;
    maxX = 0.773;
    maxY = 0.434;

    tileSizeX = (maxX*2)/gridX;
    tileSizeY = (maxY*2)/gridY;

    WallMatrix = new bool[gridX*gridY]{};
}

LevelGen::~LevelGen()
{
    delete[] WallMatrix;
}

void LevelGen::generateLevels()
{

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

        glVertex3d(-maxX, -maxY, -1.0501);
        glVertex3d(maxX, -maxY, -1.0501);
        glVertex3d(maxX, maxY, -1.0501);
        glVertex3d(-maxX, maxY, -1.0501);

        glEnd();

        for(int x=0; x < gridX; x++){
            tileY = maxY;
            for(int y=0; y < gridY; y++){
                glColor3d((tileX+maxX/2),(tileY+maxY/2),1.0);
                glBegin(GL_QUADS);
                    glVertex3d(tileX, (tileY - tileSizeY), -1.05);
                    glVertex3d((tileX + tileSizeX),(tileY - tileSizeY), -1.05);
                    glVertex3d((tileX + tileSizeX), tileY, -1.05);
                    glVertex3d(tileX,tileY, -1.05);
                glEnd();

                tileY-=tileSizeY;
            }
                tileX+=tileSizeX;
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
