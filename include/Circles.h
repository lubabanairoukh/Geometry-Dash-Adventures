#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "Texture.h"



class Circles {


private:

	sf::CircleShape m_circle;
	
	std::pair<int, int> m_location;
	std::list< std::pair<int, int>> neighbors;

public:
	Circles(const sf::Vector2f position,std::pair< int, int>);
	
	~Circles();
	void draw(sf::RenderWindow&);
	bool handleCollision(const sf::Vector2f);
	sf::Vector2f getPosition();
	sf::Color getFillColor();
	void setFillColor(sf::Color color);
	sf::CircleShape getcircle() const;

	int print() const;
	int print1()const;
	std::pair<int, int> getpair();

	void changeCircleColor();
	void setNeighborsOod(int row, int col);
	void setNeighborsEven(int row, int col);
	std::list<std::pair<int, int>> getListNeighbors();
};