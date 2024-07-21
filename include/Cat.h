#include <iostream>
#include "Texture.h"
#include <Windows.h>

class Cat {

private:
	sf::Sprite m_Cat;
	std::pair<int, int> m_circlepoint;
public:
	Cat();
	~Cat() {};
	void setPosition(sf::Vector2f location,std::pair<int,int> loc);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setTexture(int index);
	void move(sf::Vector2f location);
	void setTextureRect(sf::IntRect textrect);
	void moveCat(sf::Vector2f cat, sf::Vector2f circle, sf::RenderWindow& window);
	void setCirclePoint(std::pair<int, int> loc);
	std::pair<int, int> getCirclePoint();
};