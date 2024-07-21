#pragma once

#include <iostream>
#include <vector>
#include "Texture.h"


const int P_SIZE = 50;

class Circles {


private:

	sf::CircleShape m_circle;

public:
	Circles(const sf::Vector2f position);
	~Circles();
	void draw(sf::RenderWindow&);
	bool handleCollision(const sf::Vector2f);
	sf::Vector2f getPosition()
	{
		return m_circle.getPosition();
	}
	sf::Color getFillColor()
	{
		return m_circle.getFillColor();
	}
	void setFillColor(sf::Color color)
	{
		m_circle.setFillColor(color);
	}
};