#
#include "Texture.h"

//--------------------------Texture Constructor----------------------------------------

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



sf::Texture* Texture::getCate(int index)
{
	return &m_ObjectTextures[index];
}

//-----------------------------------------------------------------------------------------------
sf::Font* Texture::getFont()
{
	return &m_font;
}


sf::Texture* Texture::getAboutTheGame()
{

	/*
	*
	*return an specific texture of music
	*
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