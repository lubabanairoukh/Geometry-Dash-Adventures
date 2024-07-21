#pragma once
#include <SFML/Audio.hpp>
#include <array>
#include <SFML/Graphics.hpp>
#include "Define.h"
#include "Texture.h"

/*
*
* class upload an music file
* define static object class
* start the music of the game
* pause the music of the game
*
*
*/



class Music
{

public:
	virtual ~Music() = default; // close music file

	static Music& instance();
	void setSounds();
	//sf::SoundBuffer* getSound(Audio audio);


	void PlayMusic(std::string name);

	void startMusic();

	void pauseMusic();

	

	bool getSoundStatus();
	

private:

	Music();
	std::vector<sf::SoundBuffer> m_soundVec;

	bool m_MusicOnOff;
	sf::Music m_music;
};
