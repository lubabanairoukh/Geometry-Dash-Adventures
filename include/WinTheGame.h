#pragma once

#include <SFML/Graphics.hpp>
#include "MenuGame.h"
#include "box2d/box2d.h"
#include "Define.h"

class WinTheGame {

public:
	WinTheGame();
	void activateWinScreen(sf::RenderWindow& window, MenuGame& menugame, bool&);


	void initObjects();
	void handlecoliision(MenuGame& menugame, sf::RenderWindow& window, bool&);
private:
	sf::Sprite m_background;
	sf::Text m_menupause[3];
	sf::Sprite m_exit;
	sf::Sprite m_menu;


};