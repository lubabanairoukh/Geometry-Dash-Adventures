#pragma once

#include"Board.h"
#include "Caption.h"
#include "MenuGame.h"
#include "GameOver.h"
#include "WinGame.h"
class Controller {
public:
	Controller();
	void run();
	bool handleGameOver();

	bool handleWingame();

private:
	Caption m_caption;
	sf::Sprite m_background;
	MenuGame m_menugame;
	sf::RenderWindow m_window;
	bool startagain;
};