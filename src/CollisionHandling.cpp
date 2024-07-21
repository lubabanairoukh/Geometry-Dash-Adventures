#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>



namespace // anonymous namespace — the standard way to make function "static"
{
    using HitFunctionPtr = void (*)(GameObject&, GameObject&);

    using Key = std::pair<std::type_index, std::type_index>;

    using HitMap = std::map<Key, HitFunctionPtr>;


    void changePic(GameObject& object1, GameObject& object2) {

        Texture::instance().set_player("plane.png");
      
    }

    void PlayerTriangle(GameObject& object1,
        GameObject& object2)
    {
        Player::m_gameover = true;
    }


    void PlayerRectangle(GameObject& object1,
        GameObject& object2)
    {
        Player::has_ground = true;
    }


    void PlayerFloor(GameObject& object1,
        GameObject& object2)
    {
       
        Player::has_ground = true;
      
    }


    void PlayerPortal(GameObject& object1,
        GameObject& object2)
    {
        changePic(object1, object2);
        Player::has_ground = true;
       
        Player::m_plane = true;
        dynamic_cast<Player*>(&object1)->getBody()->SetGravityScale(2.0f);

    }
    void PlayerDoublejump(GameObject& object1,
        GameObject& object2)
    {
        
        dynamic_cast<Player*>(&object1)->double_jump = true;

    }


    void PlayerThorns(GameObject& object1,
        GameObject& object2)
    {
        Player::m_gameover = true;
    }


    void RectanglePlayer(GameObject& object1,
        GameObject& object2)
    {


        PlayerRectangle(object2, object1);
    }


    void TrianglePlayer(GameObject& object1,
        GameObject& object2)
    {


        PlayerTriangle(object2, object1);
    }


    void FloorPlayer(GameObject& object1,
        GameObject& object2)
    {


        PlayerFloor(object2, object1);
    }


    void PortalPlayer(GameObject& object1,
        GameObject& object2)
    {


        PlayerPortal(object2, object1);

    }


    void ThornsPlayer(GameObject& object1,
        GameObject& object2)
    {


        PlayerThorns(object2, object1);

    }


    void PlayerTrophy(GameObject& object1, GameObject& object2)
    {
        
         Player::m_winGame = true;

    }
    void TrophyPlayer(GameObject& object1, GameObject& object2)
    {
        Player::m_plane = false;
        PlayerTrophy(object2, object1);
    }
    void DoublejumpPlayer(GameObject& object1,
        GameObject& object2)
    {


        PlayerDoublejump(object2, object1);

    }

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(Triangle))] = &PlayerTriangle;
        phm[Key(typeid(Triangle), typeid(Player))] = &TrianglePlayer;


        phm[Key(typeid(Player), typeid(Rectangle))] = &PlayerRectangle;
        phm[Key(typeid(Rectangle), typeid(Player))] = &RectanglePlayer;



        phm[Key(typeid(Player), typeid(Floor))] = &PlayerFloor;
        phm[Key(typeid(Floor), typeid(Player))] = &FloorPlayer;



        phm[Key(typeid(Player), typeid(Portal))] = &PlayerPortal;
        phm[Key(typeid(Portal), typeid(Player))] = &PortalPlayer;



        phm[Key(typeid(Player), typeid(Thorns))] = &PlayerThorns;
        phm[Key(typeid(Thorns), typeid(Player))] = &ThornsPlayer;

        phm[Key(typeid(Player), typeid(Trophy))] = &PlayerTrophy;
        phm[Key(typeid(Trophy), typeid(Player))] = &TrophyPlayer;

        phm[Key(typeid(Player), typeid(Doublejump))] = &PlayerDoublejump;
        phm[Key(typeid(Doublejump), typeid(Player))] = &DoublejumpPlayer;

        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
