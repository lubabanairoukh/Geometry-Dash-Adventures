#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Define.h"
#include "Texture.h"
#include "Level.h"
#include "Music.h"


/*
*
* class that creat the menu of the game it's from three option
* start the game
* about the game
* exit
* the class contain the music of menu of the game
* background of the menu game
* a page about the game
* if exit then finish
* start then return to game controller to start the game
* it's class control the menu game

*/



class MenuGame
{
public:

	MenuGame();

	void draw(sf::RenderWindow& window);

	void menurun(sf::RenderWindow& window, std::string& level);
	void run(sf::RenderWindow& window, std::string& level);

	void setTextInfo(sf::Text& text_ic);
	void setColorText(sf::RenderWindow& window, sf::Text& m_menu1, sf::Vector2f LocationMouseMoved);
	bool handleclick1(sf::RenderWindow& window, sf::Text rec);
	bool handleclick(sf::RenderWindow& window, sf::Sprite rec);
	void aboutTheGame(sf::RenderWindow& window);

	void chosePlayer(sf::RenderWindow& window);
private:



	sf::Text m_namegame;
	sf::Text m_donegame;
	sf::Sprite m_background;
	sf::Sprite m_start;
	sf::Sprite m_charecter;
	sf::Sprite m_info;
	sf::Sprite m_name;
	sf::Sprite m_aboutheGame;

	sf::Sprite m_player1;
	sf::Sprite m_player2;
	sf::Sprite m_player3;
	sf::Sprite m_player4;
	sf::Sprite m_chose;



	sf::Sprite m_music[2];
	sf::Sprite m_NextButtom;
	sf::Sprite m_closeButtom;
	bool chose = false;
	bool m_MusicOnOff;


	Level m_level;
};