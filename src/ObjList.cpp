#include "ObjList.h"
#include <cstddef>
#include <GameObject.h>

ObjList::ObjList(int input)
{
    //ctor
    objectList = new GameObject*[input]();
    size = input;
}

ObjList::~ObjList()
{
    //dtor
    delete[] objectList;
    delete[] textures;
}
/*
int ObjList::createObj(double inputX, double inputY, double inputZ, double scaleX, double scaleY, double inputRotation)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    GameObject *temp = new GameObject();
    temp->z = inputZ;
    temp->x = inputX;
    temp->y = inputY;
    temp->xScale = scaleX;
    temp->yScale = scaleY;
    temp->rotation = inputRotation;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[0]);
    objectList[index] = temp;

    return index;

}

int ObjList::createObj(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    GameObject *temp = new GameObject();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[0]);
    objectList[index] = temp;

    return index;
}*/

int ObjList::createProjectile(double inputX, double inputY, double inputZ, double scaleX, double scaleY, double inputRotation, double xVelocity, double YVelocity)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Projectile *temp = new Projectile();
    temp->z = inputZ;
    temp->x = inputX;
    temp->y = inputY;
    temp->xScale = scaleX;
    temp->yScale = scaleY;
    temp->rotation = inputRotation;
    temp->xVelo = xVelocity;
    temp->yVelo = YVelocity;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[1]);
    objectList[index] = temp;

    return index;
}

int ObjList::createProjectile(double inputX, double inputY, double xVelocity, double YVelocity)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Projectile *temp = new Projectile();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->xVelo = xVelocity;
    temp->yVelo = YVelocity;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[1]);
    objectList[index] = temp;

    return index;
}

//new: to adjust bullet direction (just createProjectile again with only rotation added)
int ObjList::createProjectile(double inputX, double inputY, double xVelocity, double YVelocity, double inputRotation)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Projectile *temp = new Projectile();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->rotation = inputRotation;
    temp->xVelo = xVelocity;
    temp->yVelo = YVelocity;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[1]);
    objectList[index] = temp;

    return index;
}

int ObjList::createMine(double inputX, double inputY, double inputZ, double scaleX, double scaleY, double inputRotation)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Mine *temp = new Mine();
    temp->z = inputZ;
    temp->x = inputX;
    temp->y = inputY;
    temp->xScale = scaleX;
    temp->yScale = scaleY;
    temp->rotation = inputRotation;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[0]);
    objectList[index] = temp;

    return index;

}

int ObjList::createMine(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Mine *temp = new Mine();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[0]);
    objectList[index] = temp;

    //createExplosion(inputX, inputY);


    return index;
}

int ObjList::createExplosion(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Explode *temp = new Explode();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[2]);
    objectList[index] = temp;

    return index;
}


bool ObjList::deleteObject(int index)
{
    if(index >= size) return false;
    if(objectList[index] == NULL) return false;

    delete objectList[index];
    objectList[index] = NULL;
    return true;
}

GameObject* ObjList::getObj(int index)
{
    if(index >= size) throw "index out of range";
    return objectList[index];
}

void ObjList::draw()
{
    for(int i = 0; i < size; i++){
        if(objectList[i] != NULL){
            objectList[i]->drawObject();
        }
    }
}

void ObjList::runPerFrame()
{
    for(int i = 0; i < size; i++){
        if(objectList[i] != NULL){
            objectList[i]->runPerFrame();
        }
    }
}

int ObjList::Size()
{
    return size;
}

void ObjList::initTextures()
{
    textures = new TextureLoader[2];
    textures[0].LoadTexture("images/mine.png");
    textures[1].LoadTexture("images/bullet.png");
    textures[2].LoadTexture("images/boom.png");
}

