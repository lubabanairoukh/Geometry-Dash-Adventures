#pragma once
#include <SFML\Graphics.hpp>
#include <Vector>
#include <string>
#include <fstream> 
#include <iostream>
#include <cstdlib>
#include "StaticObject.h"
#include "box2d/box2d.h"
#include "utils.h"
#include "Floor.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Thorns.h"
#include "Portal.h"
#include"Trophy.h"
#include "Doublejump.h"

using namespace std;
class Board
{
public:
	
	Board(b2World& world , std::string level  );
	~Board() {};
	void copyFileVector(ifstream& file, b2World& world);
	void buildObjects(pair<int, int> loc, char charctar, b2World& world);
	int getHeightOfStairs(int line);
	void draw(sf::RenderWindow& window);
	void initStaticObject(b2World& world);

	int randomNumber(int min, int max)
	{
		return min + rand() % (max - min + 1);
	}

	
private:
	int m_level, m_length, m_width;
	 int m_i;
	vector <std::unique_ptr<GameObject>>m_board; //static objects vector.
	
};