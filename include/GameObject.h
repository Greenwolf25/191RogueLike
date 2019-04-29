#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <TextureLoader.h>
#include <ObjList.h>
#include <Timer.h>

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        double x, y, z;
        double xScale, yScale, zScale;
        double xMin, xMax, yMin, yMax; //for mine animation



        double rotation; // current angle from default

        virtual void drawObject();
        virtual void runPerFrame();
        virtual void Init(TextureLoader*);

        ObjList* objList; // the object list that the object is a member (for self deletion)
        int objListIndex; // index of self for above

        Timer lifetime;
        Timer animationTimer;

        void deleteSelf();
        //void Gtimer();
        //string gAction = " "; // these 3 won't be needed, only used with grenade
        //void gExplode();


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
        protected:
        private:
};
#endif // GAMEOBJECT_H
