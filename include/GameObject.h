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
        double rotation; // current angle from default

        virtual void drawObject();
        virtual void runPerFrame();
        virtual void Init(TextureLoader*);

        ObjList* objList; // the object list that the object is a member (for self deletion)
        int objListIndex; // index of self for above

        Timer lifetime;

        void deleteSelf();

        TextureLoader *defaultTex;

    protected:
    private:
};

class Projectile: public GameObject{
        public:
            Projectile();
            virtual ~Projectile();

            float xVelo, yVelo;

            void runPerFrame();
        protected:
        private:
};

#endif // GAMEOBJECT_H
