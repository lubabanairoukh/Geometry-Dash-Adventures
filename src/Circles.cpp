#include "Circles.h"


Circles::Circles(const sf::Vector2f location,std::pair<int,  int> pos)
{

	m_circle.setRadius(static_cast<float>(30));

	m_circle.setFillColor(sf::Color(173, 255, 47));

	m_circle.setPosition(location);

	m_location = pos;
}

Circles::~Circles()
{
}

void Circles::draw(sf::RenderWindow& window)
{
	
	window.draw(m_circle);
	
}

bool Circles::handleCollision(const sf::Vector2f position)
{
	return m_circle.getGlobalBounds().contains(position);
}

void Circles::changeCircleColor()
{
	m_circle.setFillColor(sf::Color(85, 107, 47));
}


sf::Vector2f  Circles::getPosition()
{
	return m_circle.getPosition();
}
sf::Color  Circles::getFillColor()
{
	return m_circle.getFillColor();
}
void  Circles::setFillColor(sf::Color color)
{
	m_circle.setFillColor(color);
}
sf::CircleShape  Circles::getcircle() const
{
	return m_circle;
}

int Circles::print() const
{
	return m_location.first;
}
int  Circles::print1()const
{
	return m_location.second;
}
std::pair<int, int>  Circles::getpair()
{
	return m_location;
}


void  Circles::setNeighborsOod(int row, int col)
{
	neighbors = {
		{row - 1,col},
		{row - 1,col + 1},
		{row, col + 1},
		{row,col - 1},
		{row + 1,col},
		{row + 1,col + 1}
	};
}

void  Circles::setNeighborsEven(int row, int col)
{
	neighbors = {
		{row - 1,col - 1},
		{row - 1,col },
		{row, col + 1},
		{row,col - 1},
		{row + 1,col - 1},
		{row + 1,col}
	};
}

std::list<std::pair<int, int>> Circles::getListNeighbors()
{
	return neighbors;
}
