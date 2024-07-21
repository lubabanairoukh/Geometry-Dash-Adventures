<<<<<<< HEAD
=======
#
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
#include "Texture.h"

//--------------------------Texture Constructor----------------------------------------

<<<<<<< HEAD

=======
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
Texture::Texture()
{
	/*
	* set up the pics of every object
	*/

	loadTextures();

}

//-----------------------------------------------------------------------------------------------

void Texture::loadTextures()
{
	/*
	* save the name of pics of objects in array
	* save the pic of every static and moving objects
	*/
<<<<<<< HEAD
	
	sf::Texture m_stat;
	



	m_staticobjectsname = {
		"thorns.png","triangle.png","floor.jpg","player.png","floor_stat.png","rectangle.png","smallRectangle.png","stairs.png"
		,"floor_stat.png","triangle_stair.png","portal.png","backtriangle.png","triangle.png","trophy.png"
	};

	m_playername = {
		"player1.png","player2.png","player3.png","player4.png"
	};

	for (int i = 0; i < PLAYERNUM; i++) {
		m_playersVec[i].loadFromFile(m_playername[i]);
	}
	for (int i = 0; i < ICONSTATICNUM; i++) {
		m_staticobjectstexture[i].loadFromFile(m_staticobjectsname[i]);
	}
	



	m_font.loadFromFile("CHILLER.TTF");

	m_stringAboutTheGame = { "HowToPlay1.png","HowToPlay2.png","HowToPlay3.png","HowToPlay4.png","HowToPlay5.png" };
	for (int i = 0; i < 5; i++)
	{
		m_TextureAboutTheGame[i].loadFromFile(m_stringAboutTheGame[i]);
	}

	m_levelsBacground.loadFromFile("levels.png");

	m_level.loadFromFile("open.png");

	m_MenuGame.loadFromFile("MenuGame.png");
	
	m_backgroundpause.loadFromFile("pausee.png");
	
	





	m_stat.loadFromFile("background.jpg");
	m_gameBackGround.push_back(m_stat);
	


	m_modeType.loadFromFile("modetype.png");
	m_information.loadFromFile("info.png");
	m_start.loadFromFile("start.png");
	m_charecter.loadFromFile("charecter.png");
	m_name.loadFromFile("name.png");
	m_chose.loadFromFile("chose.png");
	m_practiceMode.loadFromFile("PracticeMode.png");
	m_menu.loadFromFile("menu.png");
	m_sound.loadFromFile("sound.png");
	m_nosound.loadFromFile("nosound.png");
	
	m_win.loadFromFile("win.png");
	m_plane.loadFromFile("plane.png");
	m_continue.loadFromFile("continue.png");
	m_exit.loadFromFile("exit.png");
	m_nextButtom.loadFromFile("NextButtom.png");
	m_closeButtom.loadFromFile("Close.png");
	
}



void Texture::set_player(std::string str)
{
	m_player.loadFromFile(str);
}

sf::Texture* Texture::getStart()
{
	return &m_start;
}
sf::Texture* Texture::getCharecter()
{
	return &m_charecter;
}
sf::Texture* Texture::getInformation()
{
	return &m_information;
}
sf::Texture* Texture::getname()
{
	return &m_name;
}
sf::Texture* Texture::getchose()
{
	return &m_chose;
=======
	m_ObjectTextures[0].loadFromFile("twoinone.png");
	m_ObjectTextures[1].loadFromFile("upleftright.png");
	m_ObjectTextures[2].loadFromFile("downleftright.png");
	//m_winbackground.loadFromFile


	m_gameOverBackGround.loadFromFile("34fmPl.jpg");
	m_winbackground.loadFromFile("Level+Up.jpg");

	m_font.loadFromFile("FREESCPT.TTF");
	for (int i = 0; i < MUSICONOFF; i++)
	{
		m_MusicTextures[i].loadFromFile(m_MusicName[i]);
	}
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
}



//-----------------------------------------------------------------------------------------------

Texture& Texture::instance()
{
	/*
	*
	* make an static object of class and return it
	*
	*/

	static Texture texture;
	return texture;
}

<<<<<<< HEAD
sf::Texture* Texture::getPracticeModeIcon()
{
	return &m_practiceMode;
}
sf::Texture* Texture::getModeType()
{
	return &m_modeType;
}
=======


sf::Texture* Texture::getCate(int index)
{
	return &m_ObjectTextures[index];
}

>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
//-----------------------------------------------------------------------------------------------
sf::Font* Texture::getFont()
{
	return &m_font;
}


<<<<<<< HEAD
sf::Texture* Texture::getGameBackGround(BackgroundColor color)
=======
sf::Texture* Texture::getAboutTheGame()
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
{

	/*
	*
	*return an specific texture of music
	*
<<<<<<< HEAD
	* */

	return &m_gameBackGround[(int)color];
}
sf::Texture* Texture::getPlayerObject()
{
	return &m_player;
}


 
sf::Texture* Texture::getMenuGame()
{
	return &m_MenuGame;
}


sf::Texture* Texture::getNextButtom()
{
	return &m_nextButtom;
}

sf::Texture* Texture::getCloseButtom()
{
	return &m_closeButtom;
}



sf::Texture* Texture::getWin()
{
	return &m_win;
}

sf::Texture* Texture::getcontinue()
{
	return &m_continue;
}

sf::Texture* Texture::getexit()
{
	return &m_exit;
}

sf::Texture* Texture::getmenu()
{
	return &m_menu;
}

sf::Texture* Texture::getsound()
{
	return &m_sound;
}

sf::Texture* Texture::getnosound()
{
	return &m_nosound;
}









sf::Texture* Texture::getPiclevel()
{
	return &m_level;
}

sf::Texture* Texture::getBackgroundlevels()
{
	return &m_levelsBacground;
}

sf::Texture* Texture::getStaticObject(Staticobject_t symbol)
{
	return &m_staticobjectstexture[(int)symbol];
}

sf::Texture* Texture::getAboutTheGame(int index)
{
	return &m_TextureAboutTheGame[index];
}

sf::Texture* Texture::getPlayer(PlayerType type)
{
	return &m_playersVec[(int)type];
}


sf::Texture* Texture::getBackgroundPuase()
{
	return &m_backgroundpause;
}
=======
	*/

	return &m_abouttheGame;
}

sf::Texture* Texture::getGameWinBackGround()
{
	return &m_winbackground;
}


sf::Texture* Texture::getMusicTexture(int symbol)
{

	/*
	*
	*return an specific texture of music
	*
	*/

	return &m_MusicTextures[symbol];
}

sf::Texture* Texture::getGameOverBackGround()
{
	return &m_gameOverBackGround;
}
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
