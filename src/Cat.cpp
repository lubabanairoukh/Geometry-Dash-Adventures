#include "Cat.h"

Cat::Cat()
{

	m_Cat.setTexture(*Texture::instance().getCate(0));

	m_Cat.setTextureRect(sf::IntRect(10, 20, 100, 80));

	
}

void Cat::setPosition(sf::Vector2f location, std::pair<int, int> loc)
{
	m_Cat.setPosition(location);
	m_circlepoint = loc;
}

void Cat::draw(sf::RenderWindow& window)
{
	window.draw(m_Cat);
}

sf::Vector2f Cat::getPosition()
{
	return m_Cat.getPosition();
}

void Cat::setTexture(int index)
{
	m_Cat.setTexture(*Texture::instance().getCate(index));
}


void Cat::setTextureRect(sf::IntRect textrect)
{
	m_Cat.setTextureRect(textrect);
}
void Cat::setCirclePoint(std::pair<int, int> loc)
{
	m_circlepoint = loc;
}
std::pair<int, int> Cat::getCirclePoint()
{
	return m_circlepoint;
}
/*
void Cat::moveCat(sf::Vector2f cat, sf::Vector2f circle, sf::RenderWindow& window)
{
	int x = 0, y = 0;
	if (m_Cat.getPosition().x > circle.x && m_Cat.getPosition().y == circle.y)
	{
		m_Cat.setTexture(*Texture::instance().getCate(0));
		int x1 = (cat.x - circle.x) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);
				m_Cat.move(sf::Vector2f(-x1, 0.f));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100) + 10, 100 + 20, 100, 80));
				window.display();
				Sleep(80);
			}

		}
	}

	if (m_Cat.getPosition().x < circle.x && m_Cat.getPosition().y == circle.y)
	{
		m_Cat.setTexture(*Texture::instance().getCate(0));
		int x1 = (circle.x - cat.x) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(x1, 0.f));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100) + 10, 20, 100, 80));
				window.display();
				Sleep(50);
			}

		}
	}
	if (m_Cat.getPosition().x > circle.x && m_Cat.getPosition().y < circle.y)
	{
		m_Cat.setTexture(*Texture::instance().getCate(2));
		int x1 = (cat.x - circle.x) / 5;
		int y1 = (circle.y - cat.y) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(-x1, y1));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 0, 100, 100));
				window.display();
				Sleep(50);
			}

		}

	}
	if (m_Cat.getPosition().x < circle.x && m_Cat.getPosition().y < circle.y)
	{
		m_Cat.setTexture(*Texture::instance().getCate(2));
		int x1 = (circle.x - cat.x) / 5;
		int y1 = (circle.y - cat.y) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(x1, y1));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 100, 100, 100));
				window.display();
				Sleep(30);
			}

		}

	}
	if (m_Cat.getPosition().x > circle.x && m_Cat.getPosition().y > circle.y)
	{
		m_Cat.setTexture(*Texture::instance().getCate(1));
		int x1 = (cat.x - circle.x) / 4;
		int y1 = (cat.y - circle.y) / 4;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 4; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(-x1, -y1));
				y = 0;
				x++;
				x = x % 4;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 100, 100, 100));
				window.display();
				Sleep(80);
			}

		}



	}
	if (m_Cat.getPosition().x < circle.x && m_Cat.getPosition().y > circle.y)
	{
		m_Cat.setTexture(*Texture::instance().getCate(1));
		int x1 = (circle.x - cat.x) / 4;
		int y1 = (cat.y - circle.y) / 4;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 4; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(x1, -y1));
				y = 0;
				x++;
				x = x % 4;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 0, 100, 100));
				window.display();
				Sleep(30);
			}

		}

	}

	m_Cat.setPosition(circle);
}


*/
void Cat::move(sf::Vector2f location)
{
	m_Cat.move(location);
}