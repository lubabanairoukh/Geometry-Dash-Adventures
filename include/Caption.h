#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Texture.h"

#include "Macros.h"



class Caption
{
public:

	Caption();
	~Caption();

	void resetCaption(bool win);
	void updateclicks();
	void updatelevel();
	
	void draw(sf::RenderWindow&);

	bool handleCollision(const sf::Vector2f);
private:
	
	int m_clicks;
	

	sf::Text m_clicksText;
	sf::Text m_levelText;
	sf::Text m_resetText;
	
	sf::Font m_font;
	int m_level;

};