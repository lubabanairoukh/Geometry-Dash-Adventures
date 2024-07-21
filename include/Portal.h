#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "StaticObject.h"


class Portal :public StaticObject
{
public:
    Portal(b2World& world, sf::Vector2f center);

    void draw(sf::RenderWindow& window)override;

   
protected:
    sf::RectangleShape m_shape;

private:
};