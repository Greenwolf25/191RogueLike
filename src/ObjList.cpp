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
	 for(int i = 0; i < size; i++){
        if(objectList[i]){
            delete objectList[i];
        }
    }
    delete[] objectList;
    delete[] textures;
}


void ObjList::objListInit(LevelGen* newLevelGen, Player* player1)
{
    play = player1;
    levelGenerator = newLevelGen;
    textures = new TextureLoader[8];
    textures[0].LoadTexture("images/mine.png");
    textures[1].LoadTexture("images/bullet.png");
    textures[2].LoadTexture("images/boom.png");
    textures[3].LoadTexture("images/health.png");
    textures[4].LoadTexture("images/key.png");
    textures[5].LoadTexture("images/BossKey.png");
    textures[6].LoadTexture("images/tilesetdebug.png");
    textures[7].LoadTexture("images/skull2.png");
    //textures[8].LoadTexture("images/trollface.png")
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

int ObjList::createItem(char type, double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    if (type == 'k'){
        Key *temp = new Key();
        temp->Init(&textures[4]);
        temp->z += (zOffput * index); // to avoid z fighting
        temp->x = inputX;
        temp->y = inputY;
        temp->objList = this;
        temp->objListIndex = index;
        objectList[index] = temp;

    }else if(type == 'b'){
        BossKey *temp = new BossKey();
        temp->Init(&textures[5]);
        temp->z += (zOffput * index); // to avoid z fighting
        temp->x = inputX;
        temp->y = inputY;
        temp->objList = this;
        temp->objListIndex = index;
        objectList[index] = temp;

    }else{
        HealthKit *temp = new HealthKit();
        temp->Init(&textures[3]);
        temp->z += (zOffput * index); // to avoid z fighting
        temp->x = inputX;
        temp->y = inputY;
        temp->objList = this;
        temp->objListIndex = index;
        objectList[index] = temp;

    }
    return index;
}

int ObjList::createTorch(double inputX, double inputY, bool* litStatusBool)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Torch *temp = new Torch();
    temp->lit = litStatusBool;
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[6]);
    objectList[index] = temp;

    return index;
}
///ENEMY CREATION
int ObjList::createEnemy(double inputX, double inputY)
{
    cout<<"in createEmeny"<<endl;
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Enemy *temp = new Enemy();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[7]);
    objectList[index] = temp;

    return index;
}

/*void ObjList::updateEnemy(double inputX, double inputY, int index)
{
    objectList[index]->updatePos(inputX,inputY);

}*/
/*void ObjList::updateX(double inputX, double inputY, int index)
{
    objectList[index]->updateX() = inputX;
    objectList[index]->updateY() = inputY;

}
void ObjList::updateY(double inputX, double inputY, int index)
{
    objectList[index]->updateX() = inputX;
    objectList[index]->updateY()= inputY;

}*/


bool ObjList::deleteObject(int index)
{
    if(index >= size) return false;
    if(objectList[index] == NULL) return false;

    delete objectList[index];
    objectList[index] = NULL;
    return true;
}

void ObjList::clearObjList()
{

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




bool ObjList::collisioncheckEpW() // play enemy's sound somehow
{
    for(int i = 0; i < size; i++) //
    {
        double var = .05; //enemy and mine (placeholder) //adjust later
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'g')
        {
            double skullx = getObj(i)->x;
            double skully = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - skullx) <= var) && (fabs(firey - skully) <= var))
                    {
                        cout << "hit" << endl;
                        getObj(i)->HP -= 4;
                        getObj(j)->deleteSelf();
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - skullx) <= var) && (fabs(miney - skully) <= var))
                    {
                        cout << "hit" << endl;
                        getObj(j)->deleteSelf();
                        getObj(i)->HP -= 10;
                        createExplosion(skullx,skully);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}



///Discard pile///
/*bool ObjList::collisioncheckEF(double Ex, double Ey) // play enemy's sound somehow
//still need: enemy class/ enemy hurt sound/
//explo sound to play upon it's draw-(call the sound in enemy class?)
{
    for(int i = 0; i < size; i++) //
    {
        double var = .05; //enemy and mine (placeholder) //adjust later
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if((fabs(getObj(i)->x - Ex) <= var) && (fabs(getObj(i)->y - Ey) <= var))
        {
            if(getObj(i)->typeCheck == 'f')
            {
                double ax = getObj(i)->x;
                double by = getObj(i)->y;
                getObj(i)->deleteSelf();
                cout << "hit" << endl;
                //createExplosion(ax, by);
                return true;
            }
        }
    }
    return false;
}*/

/*
bool ObjList::collisioncheckEM(double Ex, double Ey) // remember to play sound in enemy class if true
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
}*/
