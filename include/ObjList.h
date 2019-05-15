#ifndef OBJLIST_H
#define OBJLIST_H
#include <TextureLoader.h>
#include <LevelGen.h>
#include <sound.h>
#include <Player.h>

using namespace std;
//sound* letmeusethisplease = new sound();

class GameObject;

class LevelGen;

class Player;

class ObjList
{
    public:
        ObjList(int);
        virtual ~ObjList();

        //void objListInit(LevelGen*);
        void objListInit(LevelGen*, Player*);

        LevelGen* levelGenerator;

        Player* play;

        sound* sfx;

        bool victory;

        //int createObj(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        //int createObj(double, double); // X,Y (return index) if no free space return -1

        int createProjectile(double, double, double, double, double, double, double, double);// X,Y,Z,scaleX,scaleY,Rotate,speedX,SpeedY (return index) if no free space return -1
        int createProjectile(double, double, double, double); // X,Y,VelocityX,VelocityY (return index) if no free space return -1
        int createProjectile(double,double,double,double,double); //x,y,Vx,Vy,rotation

        int createMine(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        int createMine(double, double); // X,Y (return index) if no free space return -1

        int createExplosion(double, double);

        int createItem(char, double, double); // type, X, Y

        int createTorch(double, double, bool*); // X, Y, Lit/Unlit (pointer as it will be give by level Gen so it knows when the torch is lit)

        ///enemy and bosses
        bool bossIsDead();
        int createEnemy(double, double);

        int createBoss(double, double);
        int createHandR(double, double);
        int createHandL(double, double);
        ///projectiles
        int createFFR(double, double);
        int createFFL(double, double);
        int createSkullP(double, double);

        bool deleteObject(int); // delete index (return false if NULL)
        void clearObjList(); // empty the ObjList and delete all objects

        GameObject* getObj(int);
        void draw();
        void runPerFrame();
        int Size();

        //called in an entities runperframe, and given the object type, returns true upon
        //collision between entity and certain object
        //for enemy and plaer (two entities), create the functn n glscene
        bool collisioncheck(double, double); // x y //call jn enemes rnperframe, passng enemes vale

        //functon that checks for collsion between enemy and mine called in
        //enemies runperframe, inputs are enemies xpos,ypos
        //bool collisioncheckEM(double,double);

        //funtion that checks for collision between enemy and projectile
        //called in enemies runperdframe, npts are enemies xpos, ypos
        //bool collisioncheckEF(double,double);
        ///PLAYER COLLISIONS (called in player.cpp in "runperframe" w/ players x and y passed)
        bool collisioncheckPE(double,double);        /// (fix) collision between player and enemy
        bool collisioncheckPBmovement(double,double);/// (fix) prevent player from passing over boss
        bool collisioncheckPB(double,double);        /// (fix) collision between player and boss or boss hands
        bool collisioncheckPBp(double,double);       /// (fix) collision between player and boss projectiles

        ///ENEMY COLLISIONS (called in GLSCENE in "idle")
        bool collisioncheckEpW(); //Enemy - playerWeapons
        ///BOSS COLLISIONS (called in GLSCENE in "idle")
        bool collisioncheckBpW(); //Boss  - playerWeapons
        bool collisioncheckBhrpW();//Boss R hand  - playerWeapons
        bool collisioncheckBhlpW();//Boss L hand  - playerWeapons
        bool collisioncheckBfrpW();//Boss R fire fist - playerWeapons
        bool collisioncheckBflpW();//boss L fire fist - playerWeapons
        bool collisioncheckSppW();//skull projectile - playerWeapons

        ///FOR BOSS PROJECTILE SPAWNING (called in GLSCENE in "idle")
        bool bossAtk(int);
        bool rightHandAtk(int);
        bool leftHandAtk(int);

        ///ALT FUNCTIONS IN GLSCENE "idle"
        void skullPmotion(double,double);
        void FFRmotion(double,double);
        void FFLmotion(double,double);

        //collision Check for gunFire and Torch
        bool collisioncheckTF(double,double);

        //collision Check for pickup items
        char collisioncheckPickUp(double, double);

        //for collision sound, call it where this function is called
        //void setXpos(double); // called in the area object is spawned so it can give xPos a value
        //void setYpos(double); // called in the area object is spawned so it can give yPos a value
        //double getXpos(); //
        //double getYpos();
        //void soundT(sound*);
        ///For Explosion on Mine Expiration
        bool mineRuntimeCheck();

        bool checkingtype(int,char);
        bool test(int);

    protected:

        TextureLoader* textures;

        GameObject **objectList;
        int size;

        const double zOffput = 0.00015;

    private:
        //double xPos;
        //double yPos;
};

#endif // OBJLIST_H
