#include "PauseMenu.h"

PauseMenu::PauseMenu(MenuGame& menugame)
{
    PracticeMode = false;
    m_musicstatus = false;
    initObjects(menugame);
}

void PauseMenu::runPauseMenu(sf::RenderWindow& m_window, MenuGame& menugame, bool& returnthegame)
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
                if (m_practiceMode.getGlobalBounds().contains(sf::Vector2f(mouseX, mouseY)))
                    PracticeMode = true;

                if (menugame.handleclick(window, m_continue))
                {
                    return;
                }
                if (menugame.handleclick(window, m_exit))
                {
                    window.close();
                    m_window.close();

                }
                if (menugame.handleclick(window, m_menu))
                {
                    Player::m_plane = false;
                    Player::has_ground = false;
                   
                     window.close();
                    returnthegame = true;
                    return;
                }
                if (menugame.handleclick(window, m_sound))
                {
                    if (Music::instance().getSoundStatus())
                    {
                        m_musicstatus = true;
                        Music::instance().pauseMusic();
                    }
                    else
                    {
                        m_musicstatus = false;
                        Music::instance().startMusic();

                    }
                }
                break;
            }
        }


        window.clear();
        window.draw(m_backgroundpause);
        window.draw(m_continue);
        window.draw(m_exit);
        window.draw(m_menu);
        if (!m_musicstatus)
            window.draw(m_sound);
        else
            window.draw(m_nosound);


        window.draw(m_practiceMode);

        window.display();
    }
}

void PauseMenu::initObjects(MenuGame& menugame)
{
    m_backgroundpause.setTexture(*Texture::instance().getBackgroundPuase());
    m_backgroundpause.setScale(sf::Vector2f((1000 / m_backgroundpause.getGlobalBounds().width),
        (680 / m_backgroundpause.getGlobalBounds().height)));
    m_backgroundpause.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1700, 800)));

    m_continue.setTexture(*Texture::instance().getcontinue());
    m_continue.setPosition(sf::Vector2f(355, 200));
    m_continue.setScale(sf::Vector2f((300 / m_continue.getGlobalBounds().width),
        (100 / m_continue.getGlobalBounds().height)));

    m_menu.setTexture(*Texture::instance().getmenu());
    m_menu.setPosition(sf::Vector2f(355, 300));
    m_menu.setScale(sf::Vector2f((300 / m_menu.getGlobalBounds().width),
        (100 / m_menu.getGlobalBounds().height)));


    m_exit.setTexture(*Texture::instance().getexit());
    m_exit.setPosition(sf::Vector2f(355, 400));
    m_exit.setScale(sf::Vector2f((300 / m_exit.getGlobalBounds().width),
        (100 / m_exit.getGlobalBounds().height)));
//====================
    m_sound.setTexture(*Texture::instance().getsound());
    m_sound.setPosition(sf::Vector2f(300, 490));
    m_sound.setScale(sf::Vector2f((100 / m_sound.getGlobalBounds().width),
        (100 / m_sound.getGlobalBounds().height)));


    m_nosound.setTexture(*Texture::instance().getnosound());
    m_nosound.setPosition(sf::Vector2f(300, 490));
    m_nosound.setScale(sf::Vector2f((100 / m_nosound.getGlobalBounds().width),
        (100 / m_nosound.getGlobalBounds().height)));

    m_practiceMode.setTexture(*Texture::instance().getPracticeModeIcon());
    m_practiceMode.setScale(sf::Vector2f((88 / m_practiceMode.getGlobalBounds().width),
        (88 / m_practiceMode.getGlobalBounds().height)));
    m_practiceMode.setPosition(sf::Vector2f(600, 500));
}

void PauseMenu::handlecoliision(MenuGame& menugame, sf::RenderWindow& window, bool& returnthegame)
{
}

bool PauseMenu::getPracticeMode() const
{
    return PracticeMode;
}
