#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MenuGame.h"
#include "box2d/box2d.h"

#include "Board.h"

#include "Define.h"
#include "PauseMenu.h"

#include "Player.h"
#include "OnCollision.h"
#include "Music.h"
#include "WinTheGame.h"

class GameController {
public:

	GameController();
	void runTheGame(bool& returnthegame);
	void initObjects(b2World& m_world);
	void draw(Player& player, Board& board);

	void initView();

	void resetGame(Player& m_player);

private:
	sf::RenderWindow m_window;
	std::vector <sf::Sprite> m_background;
	sf::View m_view;
	MenuGame m_menugame;
	std::string m_level;
	sf::Text m_attemped;
	int m_attemp;


};
