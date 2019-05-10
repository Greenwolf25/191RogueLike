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
    sfx = new sound();
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
//    delete sfx;
}


void ObjList::objListInit(LevelGen* newLevelGen)
{
    levelGenerator = newLevelGen;
    textures = new TextureLoader[14];
    sound* sfx = new sound();
    textures[0].LoadTexture("images/mine.png");
    textures[1].LoadTexture("images/bullet.png");
    textures[2].LoadTexture("images/boom.png");
    textures[3].LoadTexture("images/health.png");
    textures[4].LoadTexture("images/key.png");
    textures[5].LoadTexture("images/BossKey.png");
    textures[6].LoadTexture("images/tilesetdebug.png");
    textures[7].LoadTexture("images/skull2.png");
    textures[8].LoadTexture("images/boss.png");
    textures[9].LoadTexture("images/handL2.png");
    textures[10].LoadTexture("images/handR2.png");
    textures[11].LoadTexture("images/firefistL2.png");
    textures[12].LoadTexture("images/firefistR2.png");
    textures[13].LoadTexture("images/skullP.png");
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

int ObjList::createBoss(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    Boss *temp = new Boss();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[8]);
    objectList[index] = temp;

    return index;
}

int ObjList::createHandR(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    BossHandR *temp = new BossHandR();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[10]);
    objectList[index] = temp;

    return index;
}

int ObjList::createHandL(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    BossHandL *temp = new BossHandL();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[9]);
    objectList[index] = temp;

    return index;
}

int ObjList::createFFR(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    BossFistR *temp = new BossFistR();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[12]);
    objectList[index] = temp;

    return index;
}

int ObjList::createFFL(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    BossFistL *temp = new BossFistL();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[11]);
    objectList[index] = temp;

    return index;
}

int ObjList::createSkullP(double inputX, double inputY)
{
    int index = -1;
    for(int i = 0; i < size; i++){
        if(objectList[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1) return -1; // if no free space return -1

    BossSkullatk *temp = new BossSkullatk();
    temp->z += (zOffput * index); // to avoid z fighting
    temp->x = inputX;
    temp->y = inputY;
    temp->objList = this;
    temp->objListIndex = index;
    temp->Init(&textures[13]);
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

bool ObjList::bossAtk(int i) //now adjust ani frames
{
    double ax = getObj(i)->x;
    double by = getObj(i)->y;
    createSkullP(ax,by-.07);
    return true;
}

bool ObjList::rightHandAtk(int i)
{
    double ax = getObj(i)->x;
    double by = getObj(i)->y;
    createFFR(ax,by-.02);
    return true;
}

bool ObjList::leftHandAtk(int i)
{
    double ax = getObj(i)->x;
    double by = getObj(i)->y;
    createFFL(ax,by-.02);
    return true;
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
                        sfx->playSound("sounds/skullhurt.wav"); //fix
                        getObj(i)->hit = true;
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
                        sfx->playSound("sounds/skullhurt.wav"); //fix
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

bool ObjList::collisioncheckBpW() //add sound //adjust size of enemy // adjust var //weapon power
{
   for(int i = 0; i < size; i++) //
    {
        double var = .09; //enemy and mine (placeholder) //adjust later
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'a') //boss
        {
            double bossx = getObj(i)->x;
            double bossy = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - bossx) <= var) && (fabs(firey - bossy) <= var))
                    {
                        sfx->playSound("sounds/bosshit.wav");
                        cout << "hit" << endl;
                        getObj(i)->HP -= 1;
                        getObj(j)->deleteSelf();
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - bossx) <= var) && (fabs(miney - bossy) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/bosshit.wav");
                        getObj(j)->deleteSelf();
                        getObj(i)->HP -= 3;
                        createExplosion(bossx,bossy);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ObjList::collisioncheckBhlpW() //adjust var//adjust weapon power//add sound
{
    for(int i = 0; i < size; i++)
    {
        double var = .08;
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'r') //boss right hand
        {
            double bosshlx = getObj(i)->x;
            double bosshly = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - bosshlx) <= var) && (fabs(firey - bosshly) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/handhit.wav");
                        getObj(i)->HP -= 4;
                        getObj(j)->deleteSelf();
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - bosshlx) <= var) && (fabs(miney - bosshly) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/handhit.wav");
                        getObj(j)->deleteSelf();
                        getObj(i)->HP -= 10;
                        createExplosion(bosshlx,bosshly);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ObjList::collisioncheckBhrpW()
{
     for(int i = 0; i < size; i++)
    {
        double var = .08;
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'l') //boss left hand
        {
            double bosshrx = getObj(i)->x;
            double bosshry = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - bosshrx) <= var) && (fabs(firey - bosshry) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/handhit.wav");
                        getObj(i)->HP -= 4;
                        getObj(j)->deleteSelf();
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - bosshrx) <= var) && (fabs(miney - bosshry) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/handhit.wav");
                        getObj(j)->deleteSelf();
                        getObj(i)->HP -= 10;
                        createExplosion(bosshrx,bosshry);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ObjList::collisioncheckBfrpW()
{
    for(int i = 0; i < size; i++)
    {
        double var = .05;
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'x') //boss left hand
        {
            double bossfrx = getObj(i)->x;
            double bossfry = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - bossfrx) <= var) && (fabs(firey - bossfry) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/notveryeffective.wav");
                        //getObj(i)->HP -= 4;
                        getObj(j)->deleteSelf();
                        //ineffective
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - bossfrx) <= var) && (fabs(miney - bossfry) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/projhit.wav");
                        getObj(j)->deleteSelf();
                        //getObj(i)->HP -= 10;
                        createExplosion(bossfrx,bossfry);
                        getObj(i)->deleteSelf();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ObjList::collisioncheckBflpW()
{
    for(int i = 0; i < size; i++)
    {
        double var = .05;
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'y') //boss left hand
        {
            double bossflx = getObj(i)->x;
            double bossfly = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - bossflx) <= var) && (fabs(firey - bossfly) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/notveryeffective.wav");
                        //getObj(i)->HP -= 4;
                        getObj(j)->deleteSelf();
                        //ineffective
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - bossflx) <= var) && (fabs(miney - bossfly) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/projhit.wav");
                        getObj(j)->deleteSelf();
                        //getObj(i)->HP -= 10;
                        createExplosion(bossflx,bossfly);
                        getObj(i)->deleteSelf();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool ObjList::collisioncheckSppW()
{
    for(int i = 0; i < size; i++)
    {
        double var = .05;
        //if(getObj(i)->typeCheck == 'e'){//enemy is an object;
        if(getObj(i) == NULL){}
        //if(getObj(i)->typeCheck == 'g')
        else if(getObj(i)->typeCheck == 'z') //boss left hand
        {
            double skullPx = getObj(i)->x;
            double skullPy = getObj(i)->y;
            for(int j = 0; j<size;j++)
            {
                if(getObj(j) == NULL){}
                else if(getObj(j)->typeCheck == 'f')
                {
                    double firex = getObj(j)->x;
                    double firey = getObj(j)->y;
                    if((fabs(firex - skullPx) <= var) && (fabs(firey - skullPy) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/projhit.wav");
                        getObj(j)->deleteSelf();
                        getObj(i)->deleteSelf();
                        return true;
                    }
                }
                else if(getObj(j)->typeCheck == 'm')
                {
                    double minex = getObj(j)->x;
                    double miney = getObj(j)->y;
                    if((fabs(minex - skullPx) <= var) && (fabs(miney - skullPy) <= var))
                    {
                        cout << "hit" << endl;
                        sfx->playSound("sounds/projhit.wav");
                        getObj(j)->deleteSelf();
                        createExplosion(skullPx,skullPy);
                        getObj(i)->deleteSelf();
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
