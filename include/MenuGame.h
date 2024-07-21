#pragma once
<<<<<<< HEAD

=======
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
<<<<<<< HEAD
#include "Define.h"
#include "Texture.h"
#include "Level.h"
#include "Music.h"


/*
*
* class that creat the menu of the game it's from three option
=======
#include "Macros.h"
#include "Texture.h"

/*
* 
* class that creat the menu of the game it's from three option 
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
* start the game
* about the game
* exit
* the class contain the music of menu of the game
* background of the menu game
* a page about the game
<<<<<<< HEAD
* if exit then finish
=======
* if exit then finish 
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
* start then return to game controller to start the game
* it's class control the menu game

*/



<<<<<<< HEAD
class MenuGame
=======
class MenuGame 
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
{
public:

	MenuGame();
<<<<<<< HEAD

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
=======
	
	void draw(sf::RenderWindow& window);

	void menurun(sf::RenderWindow& window);
	void run(sf::RenderWindow& window);

	bool handleclick(sf::RenderWindow& window, sf::Text rec);

	void setColorText(sf::RenderWindow& window, sf::Text& m_menu1, sf::Vector2f LocationMouseMoved);

	void aboutTheGame(sf::RenderWindow& window);
	
	void setTextInfo(sf::Text& text_ic);


private:

	sf::Text m_menu[MenuStart];
	sf::Text m_namegame;
	sf::Text m_donegame;
	sf::Sprite m_background;
	sf::Sprite m_aboutheGame;

	sf::Sprite m_music[MUSICONOFF];

	

	bool m_MusicOnOff;
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
};