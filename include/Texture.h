#pragma once
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include "Define.h"



=======
#include "Macros.h"
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
/*
*
* class that save in it all the pics of objects in the game
* return an specific pic
*
*/

class Texture
{
public:
<<<<<<< HEAD
	

	

	
	sf::Texture* getStart();
	sf::Texture* getCharecter();
	sf::Texture* getInformation();
	sf::Texture* getname();
	sf::Texture* getchose();
	sf::Texture* getPlayer(PlayerType);

	void set_player(std::string st);

=======
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9

	~Texture() = default;

	static Texture& instance();

<<<<<<< HEAD
	sf::Texture* getMenuGame();
	sf::Font* getFont();
	sf::Texture* getAboutTheGame(int index);

	sf::Texture* getNextButtom();
	sf::Texture* getCloseButtom();
	sf::Texture* getStaticObject(Staticobject_t);
	sf::Texture* getGameBackGround(BackgroundColor);
	sf::Texture* getPlayerObject();

	sf::Texture* getBackgroundPuase();
	
	sf::Texture* getcontinue();
	sf::Texture* getexit();
	sf::Texture* getmenu();
	sf::Texture* getsound();
	sf::Texture* getnosound();

	sf::Texture* getPiclevel();
 
	sf::Texture* getBackgroundlevels();
	
	
	sf::Texture* getPracticeModeIcon();
	sf::Texture* getModeType();
	


	sf::Texture* getWin();

private:

	Texture();

	

	std::array <std::string, 5> m_stringAboutTheGame;
	std::array <sf::Texture, 5> m_TextureAboutTheGame;

	std::array<sf::String, PLAYERNUM>m_playername;
	std::array<sf::Texture, PLAYERNUM> m_playersVec;

	std::vector<sf::Texture> m_staticobjects;
	std::vector<sf::Texture> m_gameBackGround;

	



	sf::Font m_font;
	sf::Texture m_MenuGame;
	sf::Texture m_nextButtom;
	sf::Texture m_closeButtom;
	
	sf::Texture m_backgroundpause;


	void loadTextures();



	sf::Texture m_start;
	sf::Texture m_charecter;
	sf::Texture m_information;
	sf::Texture m_name;
	sf::Texture m_player;
	sf::Texture m_chose;
	sf::Texture m_practiceMode;
	sf::Texture m_modeType;
	sf::Texture m_continue;
	sf::Texture m_exit;
	sf::Texture m_menu;
	sf::Texture m_sound;
	sf::Texture m_nosound;

	sf::Texture m_level;
	 
	sf::Texture m_levelsBacground;
	sf::Texture m_floor;

	sf::Texture m_win;
	sf::Texture m_portal;
	sf::Texture m_plane;


	std::array< sf::Texture,2> m_musicpic;




	std::array <std::string, ICONSTATICNUM > m_staticobjectsname;
	std::array<sf::Texture, ICONSTATICNUM>m_staticobjectstexture;
=======
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
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
};