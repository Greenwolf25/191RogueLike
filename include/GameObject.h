#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <TextureLoader.h>
#include <ObjList.h>
#include <Timer.h>
#include <sound.h>





class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        double x, y, z;
        double xScale, yScale, zScale;
        double xMin, xMax, yMin, yMax; //for mine animation
        //check
        char typeCheck; // current used: f, m, s, k, b, h, t
        bool activ;
        int  timecheck;
        int HP;
        bool hit;
        double px;
        double py;
        double gpx;
        double gpy;




        double rotation; // current angle from default

        /// VIRTUAL CAN BE OVER WRITTEN FOR INHERITANCE but still called when assuming the object is a GameObject
        virtual void drawObject(); // draw the object to screen
        virtual void runPerFrame(); // tasks to run each frame (Animation, AI, ETC)
        virtual void Init(TextureLoader*);// initiate object and textures

        ObjList* objList; // the object list that the object is a member (for self deletion)
        int objListIndex; // index of self for above

        Timer lifetime; // time since object creation  ------------ DO NOT RESET ULESS NEEDED (if you need a new timer create one)
        Timer animationTimer;// timer for animations
        Timer projectileInterval;

        void deleteSelf();


        TextureLoader *defaultTex;

    protected:
    private:
};

class Projectile: public GameObject{
        public:
            Projectile();
            virtual ~Projectile();

            float xVelo, yVelo; //bullet speed

            void runPerFrame();
            void drawObject();
        protected:
        private:
};

class Mine: public GameObject{
        public:
            Mine();
            virtual ~Mine();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            //int  runtime;
            //test
            //bool acting;


        protected:
        private:
};

class Explode: public GameObject{
        public:
            Explode();
            virtual ~Explode();

            void runPerFrame();
            void sfx(sound*);
            void drawObject();
            void Init(TextureLoader*);

//            WPARAM wParam;
        protected:
            bool playedSound;
        private:
};

class Key: public GameObject{
        public:
            Key();
            virtual ~Key();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);

};

class BossKey: public GameObject{
        public:
            BossKey();
            virtual ~BossKey();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);

};

class HealthKit: public GameObject{
        public:
            HealthKit();
            virtual ~HealthKit();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);

};

class Torch: public GameObject{
        public:
            Torch();
            virtual ~Torch();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            bool* lit;

        protected:
            double tileSizeY;

};

class Enemy: public GameObject{
     public:
        Enemy();
        virtual ~Enemy();

        void runPerFrame();
        void drawObject();
        void Init(TextureLoader*);

        void sfx(sound*);
        void lifeStatus();
        bool alive;
        int  health;
        bool once; //for death ani
        bool onceagain; // for hurt ani
        bool dyingSound; //to play sound once
        void updatePath();
        double speed;
        //bool hitSound; // to play sound once

};

class Boss: public GameObject{ //reminder: invulnerable while at least one hand is alive
 public:
            Boss();
            virtual ~Boss();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            void sfx(sound*);
            bool defenseless;
            void lifeStatus();
            bool alive;
            int  health;
            bool once; // for death ani
            bool dyingSound; //to play sound once
};
///may merge hands and their projectiles into the bosses class if possible
class BossHandR: public GameObject{
 public:
            BossHandR();
            virtual ~BossHandR();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            void sfx(sound*);
            void lifeStatus();
            bool alive;
            int  health;
            bool once; //for death ani
            bool dyingSound; //to play sound once
};

class BossHandL: public GameObject{
 public:
            BossHandL();
            virtual ~BossHandL();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            void sfx(sound*);
            void lifeStatus();
            bool alive;
            int  health;
            bool once; //for death ani
            bool dyingSound; //to play sound once
};

class BossFistR: public GameObject{ //reminder: striking these with the mine decreases Bosses right hands hit points
     public:
            BossFistR();
            virtual ~BossFistR();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            void sfx(sound*);
            bool alive;
            void updatePath();
            double speed;
};

class BossFistL: public GameObject{ //reminder: striking these with the mine decreases Bosses left hands hit points
     public:
            BossFistL();
            virtual ~BossFistL();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            void sfx(sound*);
            bool alive;
            void updatePath();
            double speed;
};

class BossSkullatk: public GameObject{ // Bosses projectile attack.
     public:
            BossSkullatk();
            virtual ~BossSkullatk();

            void runPerFrame();
            void drawObject();
            void Init(TextureLoader*);
            void sfx(sound*);
            bool alive;
};

#endif // GAMEOBJECT_H
