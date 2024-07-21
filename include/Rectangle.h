#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "StaticObject.h"


class Rectangle :public StaticObject
{
public:
    Rectangle(b2World& world, sf::Vector2f center, Staticobject_t symbol);


    void initRectangle();
    void initFloorState();
    void initBigFloorState();
    void initSmallRectangle();
    void initStairs();
    void initTriangleStairs();
    void initAllTriangles(Staticobject_t symbol);
 
    void draw(sf::RenderWindow& window)override;
   

protected:
    sf::RectangleShape m_shape;
    std::pair<int, int>m_size;
    int m_center;
private:

};
