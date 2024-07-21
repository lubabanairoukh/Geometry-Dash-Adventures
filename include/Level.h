#pragma once


#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include "Define.h"
#include "Texture.h"

class Level {

public:

	static  sf::Color colorLevel;
	Level();
	std::string runthelevel(sf::RenderWindow& window);
	void initObjects();
	bool handlecollision(sf::RenderWindow& window, sf::Sprite rec);

private:
	sf::Sprite m_level1;
	sf::Sprite m_level2;
	sf::Sprite m_level3;
	sf::Sprite m_background;
};