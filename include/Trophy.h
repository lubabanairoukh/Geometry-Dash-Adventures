#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "StaticObject.h"


class Trophy :public StaticObject
{
public:
    Trophy(b2World& world, sf::Vector2f center);

   

    void draw(sf::RenderWindow& window)override;

protected:
    sf::RectangleShape m_shape;
    std::pair<int, int>m_size;
    int m_center;
private:

};
