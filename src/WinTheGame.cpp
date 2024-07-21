#include "WinTheGame.h"

WinTheGame::WinTheGame()
{
    initObjects();
}

void WinTheGame::activateWinScreen(sf::RenderWindow& m_window, MenuGame& menugame, bool& returnthegame)
{

    auto  window = (sf::RenderWindow(sf::VideoMode(1000, 650), "Geometry Dash", sf::Style::None));

    while (window.isOpen())
    {

        for (auto event = sf::Event{}; window.pollEvent(event); )
        {
            switch (event.type)
            { 

            case sf::Event::MouseButtonReleased:
                float mouseX = sf::Mouse::getPosition(window).x;
                float mouseY = sf::Mouse::getPosition(window).y;



                if (menugame.handleclick(window, m_exit))
                {
                    window.close();
                    m_window.close();

                }
                if (menugame.handleclick(window, m_menu))
                {
                    window.close();
                    returnthegame = true;
                    return;
                }
                break;
            }
        }


        window.clear();
        window.draw(m_background);
         window.draw(m_exit);
        window.draw(m_menu);
           
         window.display();
    }
}

void WinTheGame::initObjects()
{
    m_background.setTexture(*Texture::instance().getWin());
     m_background.setScale(sf::Vector2f((1000 / m_background.getGlobalBounds().width),
       (690 / m_background.getGlobalBounds().height)));
    m_background.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1800, 800)));



    m_menu.setTexture(*Texture::instance().getmenu());
    m_menu.setPosition(sf::Vector2f(170,580));
    m_menu.setScale(sf::Vector2f((200 / m_menu.getGlobalBounds().width),
        (80 / m_menu.getGlobalBounds().height)));


    m_exit.setTexture(*Texture::instance().getexit());
    m_exit.setPosition(sf::Vector2f(640, 580));
    m_exit.setScale(sf::Vector2f((200 / m_exit.getGlobalBounds().width),
        (80 / m_exit.getGlobalBounds().height)));
    //====================

}

void WinTheGame::handlecoliision(MenuGame& menugame, sf::RenderWindow& window, bool& returnthegame)
{
}
  
