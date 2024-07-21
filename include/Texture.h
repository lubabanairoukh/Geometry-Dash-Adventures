#pragma once
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include "Macros.h"
/*
*
* class that save in it all the pics of objects in the game
* return an specific pic
*
*/

class Texture
{
public:

	~Texture() = default;

	static Texture& instance();

	sf::Texture* getCate(int index);
	sf::Font* getFont();
	sf::Texture* getAboutTheGame();
	sf::Texture* getGameWinBackGround();
	sf::Texture* getMusicTexture(int symbol);
	sf::Texture* getGameOverBackGround();
private:
	
	Texture();

	
	sf::Font m_font;


	sf::Texture m_ObjectTextures[3];
	sf::Texture m_backgrounfgame;
	sf::Texture m_winbackground;
	std::string texturesName;
	std::string m_back;
	sf::Texture m_abouttheGame;
	std::array < std::string, MUSICONOFF> m_MusicName;
	std::array<sf::Texture, MUSICONOFF> m_MusicTextures;



	
	

	sf::Texture m_gameBackGround;
	sf::Texture m_gameOverBackGround;
	sf::Texture m_gameWinBackGround;
	


	
	void loadTextures();
};