#include "ObjList.h"
#include <cstddef>
#include <GameObject.h>
#include <Timer.h>

//sound* sfx = new sound(); // causes an error: skips menue and takes away control from player, moving up forever while activating all actions

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
        if(objectList[i] == NULL){ //
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
 /// (placeholder) for testing if this function works
bool ObjList::collisioncheck(double Ex, double Ey)
{
    for(int i = 0; i < size; i++)
    {

        double var = .05; //player and mine combined radius (/2 to compensate for empty space in the images)

        if(getObj(i) == NULL){}
        else if((fabs(getObj(i)->x - Ex) <= var) && (fabs(getObj(i)->y - Ey) <= var))
        {
            if(getObj(i)->typeCheck == 'm')
            {
                cout << "hit" << endl;
                getObj(i)->deleteSelf();
                createExplosion(Ex, Ey);
                return true;
            }

        }
    }
    return false;
}

bool ObjList::mineRuntimeCheck() //checks if any mine has been active for too long
{
    for(int i = 0; i < size; i++)
    {
        if(getObj(i) == NULL){}
        else if(getObj(i)->lifetime.getTicks() > 7500)
        {
            if(getObj(i)->typeCheck == 'm') // type mine
            {
                double ax = getObj(i)->x;
                double by = getObj(i)->y;
                getObj(i)->deleteSelf();
                createExplosion(ax, by);
                return true;
            }

        }
    }
    return false;
}


bool ObjList::collisioncheckEM(double Ex, double Ey) // play enemy's sound somehow
//still need: enemy class/ enemy hurt sound/
//explo sound to play upon it's draw-(call the sound in enemy class?)
{
    for(int i = 0; i < size; i++) //
    {
        double var = .05; //enemy and mine (placeholder) //adjust later
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        else if((fabs(getObj(i)->x - Ex) <= var) && (fabs(getObj(i)->y - Ey) <= var))
        {
            if(getObj(i)->typeCheck == 'm')
            {
                double ax = getObj(i)->x;
                double by = getObj(i)->y;
                getObj(i)->deleteSelf();
                createExplosion(ax, by);
                return true;
            }
        }
    }
    return false;
}

bool ObjList::collisioncheckEF(double Ex, double Ey) // remember to play sound in enemy class if true
{
    for(int i = 0; i < size; i++) //
    {
        double var = .05; //enemy and gunfire (placeholder) //adjust later

        if(getObj(i) == NULL){}
        else if((fabs(getObj(i)->x - Ex) <= var) && (fabs(getObj(i)->y - Ey) <= var))
        {
            if(getObj(i)->typeCheck == 'f')
            {
                double ax = getObj(i)->x;
                double by = getObj(i)->y;
                getObj(i)->deleteSelf();
                //createExplosion(ax, by);
                return true;
            }
        }
    }
    return false;
}

bool ObjList::collisioncheckBM(double, double)
{
    // just in case enemy - mine does not work
}

bool ObjList::collisioncheckBF(double, double)
{
    // just in case enemy - gunfire does not work
}

