#include "Music.h"


//-----------------------------------------------------------------------------------------------

bool Music::getSoundStatus()
{
	if (m_music.getStatus() == sf::SoundSource::Status::Playing)
	{
		return true;
	}
	return false;
}

Music::Music()
{
	/*
	* save the audo of the music of the menu game
	* save the pics of the music of the menu game
	* put the begin of the music to be on wfor the first time
	*/
	setSounds();

}

void Music::PlayMusic(std::string name)
{
	m_music.openFromFile(name);
	m_music.play();
	m_music.setLoop(true);
	m_music.setVolume(20);
}
void Music::startMusic()
{
	m_music.play();
}
void Music::pauseMusic()
{
	m_music.pause();
}
//-----------------------------------------------------------------------------------------------

Music& Music::instance()
{
	/*
	* define an static object of class and return it
	*/
	static Music music;
	return music;
}

void Music::setSounds()
{
	sf::SoundBuffer newSound;

	newSound.loadFromFile("StayInsideMe.wav");
	m_soundVec.push_back(newSound);

	newSound.loadFromFile("DryOut.wav");
	m_soundVec.push_back(newSound);

	newSound.loadFromFile("BackOnTrack.wav");
	m_soundVec.push_back(newSound);

	newSound.loadFromFile("StereoMadness.wav");
	m_soundVec.push_back(newSound);




}