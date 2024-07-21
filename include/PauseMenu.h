#pragma once

#include <SFML/Graphics.hpp>
#include "MenuGame.h"
#include "box2d/box2d.h"
#include "Define.h"
#include "Player.h"
class PauseMenu {

public:
	PauseMenu(MenuGame& menugame);
	void runPauseMenu(sf::RenderWindow& window, MenuGame& menugame, bool&);
	void initObjects(MenuGame& menugame);
	void handlecoliision(MenuGame& menugame, sf::RenderWindow& window, bool&);
	bool getPracticeMode()const;
private:
	sf::Sprite m_backgroundpause;
	sf::Text m_menupause[3];
	sf::Sprite m_practiceMode;
	sf::Sprite m_continue;
	sf::Sprite m_exit;
	sf::Sprite m_menu;
	sf::Sprite m_sound;
	sf::Sprite m_nosound;

	bool m_musicstatus;
	bool PracticeMode;
};