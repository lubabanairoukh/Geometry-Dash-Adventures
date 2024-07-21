#include "Level.h"
sf::Color Level::colorLevel = sf::Color(0, 0, 250);
Level::Level()
{
    initObjects();
}

std::string Level::runthelevel(sf::RenderWindow& window)
{

    while (window.isOpen())
    {

        for (auto event = sf::Event{}; window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseButtonReleased:

                if (handlecollision(window, m_level1))
                {
                   
                   // colorLevel = sf::Color(0, 0, 255);
                    return "level1";
                }
                if (handlecollision(window, m_level2))
                {
                   // colorLevel = sf::Color(147, 112, 219);
                    return "level2";
                }
                if (handlecollision(window, m_level3))
                {
                 //   colorLevel = sf::Color(255, 69, 0);
                    return "level3";
                }
                break;
            }
        }


        window.clear();

        window.draw(m_background);
        window.draw(m_level1);
        window.draw(m_level2);
        window.draw(m_level3);



        window.display();
    }
    return "level1.txt";
}

void Level::initObjects()
{
    m_level1.setTexture(*Texture::instance().getPiclevel());
    m_level1.setScale(sf::Vector2f((300 / m_level1.getGlobalBounds().width),
        (300 / m_level1.getGlobalBounds().height)));
    m_level1.setPosition(350, 320);

    m_level2.setTexture(*Texture::instance().getPiclevel());
    m_level2.setScale(sf::Vector2f((300 / m_level2.getGlobalBounds().width),
        (300 / m_level2.getGlobalBounds().height)));
    m_level2.setPosition(750, 320);

    m_level3.setTexture(*Texture::instance().getPiclevel());
    m_level3.setScale(sf::Vector2f((300 / m_level3.getGlobalBounds().width),
        (300 / m_level3.getGlobalBounds().height)));
    m_level3.setPosition(1140, 320);

    m_background.setTexture(*Texture::instance().getBackgroundlevels());
    m_background.setScale(sf::Vector2f((M_WidthWindow / m_background.getGlobalBounds().width),
        (M_HieghtWindow / m_background.getGlobalBounds().height)));

}


bool Level::handlecollision(sf::RenderWindow& window, sf::Sprite rec)
{

    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;
    if (rec.getGlobalBounds().contains(sf::Vector2f(mouseX, mouseY)))
        return true;
    else
        return false;
}
