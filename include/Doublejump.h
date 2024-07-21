#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "StaticObject.h"


class Doublejump :public StaticObject
{
public:
    Doublejump(b2World& world, sf::Vector2f center);

    void draw(sf::RenderWindow& window)override;

protected:
    sf::CircleShape m_shape;
    float           m_radius;

private:
};

/*#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    public:
        Circle(b2World &world, sf::Vector2f center);

        void draw(sf::RenderWindow &window);

    protected:
        float           m_radius;
        sf::CircleShape m_shape;
    private:
};

#endif // CIRCLE_H
*/