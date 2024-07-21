#include "Controller.h"

Controller::Controller()
    :m_window(sf::RenderWindow(sf::VideoMode(M_WidthWindow, M_HieghtWindow), "Circle the cat", sf::Style::Close | sf::Style::Titlebar))
{
    startagain = false;
}


//run the program
void Controller::run()
{
    Board b;


    
    do {
        startagain = false;

        m_menugame.menurun(m_window);

       
        while (m_window.isOpen())
        {
            m_window.clear(sf::Color::White);
            b.drawWindow(m_window);
            m_caption.draw(m_window);

            if (auto event = sf::Event{}; m_window.waitEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    m_window.close();
                case sf::Event::MouseButtonPressed:

                    auto mousePosWindow = sf::Mouse::getPosition(m_window);
                    auto mousePosView = m_window.mapPixelToCoords(mousePosWindow);
                    if (m_caption.handleCollision(mousePosView))
                    {
                        b.clearBoard(false);
                        m_caption.resetCaption(false);
                    }
                    if (b.mouseClick(event, m_window))
                    {
                        m_caption.updateclicks();
                        
                        if (b.getwinlevel())
                        {
                            if (handleWingame())
                            {
                                b.clearBoard(true);
                                m_caption.resetCaption(true);
                            }
                        }
                        if (b.getGameover())
                        {
                            if (handleGameOver())
                            {
                                b.clearBoard(false);
                                m_caption.resetCaption(false);
                            }
                        }
                    }

                    break;
                }
                m_window.display();
            }

        }
    } while (startagain);
}

bool Controller::handleGameOver()
{

    if (GameOver::instance().run(m_window, startagain))
    {
       
        return true;
    }
    return false;

}
bool Controller::handleWingame()
{
   
     if (WinGame::instance().run(m_window, startagain))
          return true;

    return false;

}