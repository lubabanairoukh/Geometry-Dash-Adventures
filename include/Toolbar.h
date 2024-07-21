#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <locale>
#include "GameController.h"




class Toolbar
{
public:

	~Toolbar();

	static Toolbar& instance();

	void load();

	void updateLevel();
	void updateplayer();

	void draw(sf::RenderWindow&);
	void resetLevelNum();


	void update();

	
	


private:

	Toolbar();

	sf::Text m_levelText;


	

};
