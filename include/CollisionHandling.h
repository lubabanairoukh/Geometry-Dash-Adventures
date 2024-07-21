#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Floor.h"
#include "Triangle.h"
#include <iostream>
#include <typeinfo>
#include"Rectangle.h"
#include "Portal.h"
#include "Thorns.h"
#include "Trophy.h"
#include "Doublejump.h"
// Sample struct for exception throwing
struct UnknownCollision : public std::runtime_error
{
    UnknownCollision(GameObject& a, GameObject& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    {
    }
};

void processCollision(GameObject& object1, GameObject& object2);
