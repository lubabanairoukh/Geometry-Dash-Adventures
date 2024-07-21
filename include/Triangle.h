#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "StaticObject.h"


class Triangle :public StaticObject
{
public:
    Triangle(b2World& world, sf::Vector2f center, Staticobject_t symbol);



    void draw(sf::RenderWindow& window)override;

    void initTriangle();
    void initMINTriangle();
    void initBackTraingle();


protected:
    sf::ConvexShape m_shape;
    int m_size;

private:
};