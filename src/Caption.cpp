
#include "Caption.h"



Caption::Caption()
{
	
	m_level = 0;
	resetCaption(true);


	m_clicksText.setFont(*Texture::instance().getFont());
	m_clicksText.setCharacterSize(CAP_CHAR_SIZE);
	m_clicksText.setPosition(1100, 300);
	m_clicksText.setColor(sf::Color::Black);



	m_levelText.setFont(*Texture::instance().getFont());
	m_levelText.setCharacterSize(CAP_CHAR_SIZE);
	m_levelText.setPosition(1100, 400);
	m_levelText.setColor(sf::Color::Black);


	m_resetText.setFont(*Texture::instance().getFont());
	m_resetText.setCharacterSize(40);
	m_resetText.setPosition(200, 750);
	m_resetText.setColor(sf::Color::Black);
	m_resetText.setString("Reset");
}

Caption::~Caption()
{
}



void Caption::updateclicks()
{
	m_clicksText.setString("clicks: " + std::to_string(++m_clicks));
}

void Caption::updatelevel()
{
	
	m_levelText.setString("level: " + std::to_string(++m_level));

}


void Caption::resetCaption(bool win)
{
	m_clicks = -1;
	updateclicks();
	if(win)
	updatelevel();
}

void Caption::draw(sf::RenderWindow& window)
{
	window.draw(m_clicksText);
	window.draw(m_levelText);
	window.draw(m_resetText);
}

bool Caption::handleCollision(const sf::Vector2f position)
{
	return m_resetText.getGlobalBounds().contains(position);
}
