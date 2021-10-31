//Header file for all Entity Component related objects
#include "GameObject.h"

namespace GameProjectiles
{

    enum ProjectileID
    {
        projectile = 2,
        missle = 3,
        rocket = 4
    };

    class Projectile : public GameObject
    {
    public:
        void on_hit();

        unsigned short projectileID;

        Projectile(float posX, float posY);
    };

    class Missle : public Projectile
    {
    public:
        Missle(float posX, float posY);
        //void on_hit() override;
    };

    class Rocket : public Projectile
    {
    public:
        Rocket(float posX, float posY);
        //void on_hit() override
    };

}
