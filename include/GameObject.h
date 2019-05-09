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




        double rotation; // current angle from default

        /// VIRTUAL CAN BE OVER WRITTEN FOR INHERITANCE but still called when assuming the object is a GameObject
        virtual void drawObject(); // draw the object to screen
        virtual void runPerFrame(); // tasks to run each frame (Animation, AI, ETC)
        virtual void Init(TextureLoader*);// initiate object and textures

        ObjList* objList; // the object list that the object is a member (for self deletion)
        int objListIndex; // index of self for above

        Timer lifetime; // time since object creation  ------------ DO NOT RESET ULESS NEEDED (if you need a new timer create one)
        Timer animationTimer;// timer for animations

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
#endif // GAMEOBJECT_H
