#include "MenuGame.h"


MenuGame::MenuGame()
{
<<<<<<< HEAD

}

void MenuGame::menurun(sf::RenderWindow& window, std::string& level)
=======
    
}

void MenuGame::menurun(sf::RenderWindow& window)
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
{

    /*
    *
<<<<<<< HEAD
    * upload the text of every three options and set position
=======
    * upload the text of every three options and set position 
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
    * run the menu game
    *
    */



<<<<<<< HEAD

    m_aboutheGame.setTexture(*Texture::instance().getAboutTheGame(0));
    m_aboutheGame.setScale(sf::Vector2f((M_WidthWindow / m_aboutheGame.getGlobalBounds().width),
        (M_HieghtWindow / m_aboutheGame.getGlobalBounds().height)));



    m_NextButtom.setTexture(*Texture::instance().getNextButtom());
    m_NextButtom.setPosition(1300, 640);


    m_closeButtom.setTexture(*Texture::instance().getCloseButtom());
    m_closeButtom.setPosition(20, 20);
    m_closeButtom.setScale(sf::Vector2f((70 / m_closeButtom.getGlobalBounds().width),
        (70 / m_closeButtom.getGlobalBounds().height)));


    m_background.setTexture(*Texture::instance().getMenuGame());
=======
  
 
    sf::Texture tex;
    tex.loadFromFile("backgroundmenu.jpg");
    m_background.setTexture(tex);
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
    m_background.setScale(sf::Vector2f((M_WidthWindow / m_background.getGlobalBounds().width),
        (M_HieghtWindow / m_background.getGlobalBounds().height)));


<<<<<<< HEAD
    m_chose.setTexture(*Texture::instance().getchose());
    m_chose.setScale(sf::Vector2f((M_WidthWindow / m_chose.getGlobalBounds().width),
        (M_HieghtWindow / m_chose.getGlobalBounds().height)));


    //=========================
    m_name.setTexture(*Texture::instance().getname());
    m_name.setScale(sf::Vector2f((M_WidthWindow * 5 / m_aboutheGame.getGlobalBounds().width),
        (M_HieghtWindow * 5 / m_aboutheGame.getGlobalBounds().height)));
    m_name.setPosition(440, 50);


    m_info.setTexture(*Texture::instance().getInformation());
    m_info.setScale(sf::Vector2f((M_WidthWindow / m_aboutheGame.getGlobalBounds().width),
        (M_HieghtWindow / m_aboutheGame.getGlobalBounds().height)));
    m_info.setPosition(955, 420);


    m_start.setTexture(*Texture::instance().getStart());
    m_start.setScale(sf::Vector2f((M_WidthWindow * 1.3 / m_aboutheGame.getGlobalBounds().width),
        (M_HieghtWindow * 1.3 / m_aboutheGame.getGlobalBounds().height)));
    m_start.setPosition(670, 350);


    m_charecter.setTexture(*Texture::instance().getCharecter());
    m_charecter.setScale(sf::Vector2f((M_WidthWindow / m_aboutheGame.getGlobalBounds().width),
        (M_HieghtWindow / m_aboutheGame.getGlobalBounds().height)));
    m_charecter.setPosition(490, 430);


    //===================
    m_player1.setTexture(*Texture::instance().getPlayer(PLAYER1));
    m_player1.setPosition(540, 200);

    m_player2.setTexture(*Texture::instance().getPlayer(PLAYER2));
    m_player2.setPosition(940, 500);

    m_player3.setTexture(*Texture::instance().getPlayer(PLAYER3));
    m_player3.setPosition(540, 500);

    m_player4.setTexture(*Texture::instance().getPlayer(PLAYER4));
    m_player4.setPosition(940, 200);
   









    run(window, level);
}

void MenuGame::run(sf::RenderWindow& window, std::string& level)
{

    /*
    *
    * run the menu game
    *
    *
    */
    

    Music::instance().PlayMusic("Menu.ogg");
=======

    for (int i = 0; i < MENUSTART; i++)
    {

        setTextInfo(m_menu[i]);
        m_menu[i].setCharacterSize(70); 
        m_menu[i].setOutlineColor(sf::Color::Red);
    }

    m_menu[0].setString("Start The Game");
    m_menu[0].setPosition(sf::Vector2f(
        550,250));


  

    m_menu[1].setString("Exit The Game");
    m_menu[1].setPosition(sf::Vector2f(
        550,450));

   
   


    run(window);
}

void MenuGame::run(sf::RenderWindow& window)
{

    /*
    * 
    * run the menu game
    * 
    * 
    */


>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
    while (window.isOpen())
    {
        window.clear();
        draw(window);

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {


            case sf::Event::Closed:
                window.close();
                break;


            case sf::Event::MouseMoved:

<<<<<<< HEAD

=======
                for (int i = 0; i < MENUSTART; i++)
                    setColorText(window, m_menu[i], window.mapPixelToCoords
                    ({ event.mouseButton.x, event.mouseButton.y }));
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
                break;


            case sf::Event::MouseButtonReleased:
<<<<<<< HEAD
                if (handleclick(window, m_charecter)) {
                    chosePlayer(window);
                    level = m_level.runthelevel(window);

                    return;
                }
                if (handleclick(window, m_start))
                {
                    if (!chose)
                        Texture::instance().set_player("mplayer1.png");
                    level = m_level.runthelevel(window);
                    if (level != "")
                    {

                        return;
                    }
                }
                if (handleclick(window, m_info))
                    aboutTheGame(window);

=======

                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
               
                if (handleclick(window, m_menu[0]))
                    return;
                if (handleclick(window, m_menu[1]))
                     window.close();
                
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9

                break;
            }

        }
        window.display();

    }
}
<<<<<<< HEAD
void MenuGame::draw(sf::RenderWindow& window)
{
    /*
    * draw the background of the menu game
    * draw the three option:
    * start the game
    * about the game
    * exit
    * draw the music picture
    *
    */




    window.draw(m_background);
    window.draw(m_namegame);
    window.draw(m_donegame);
    window.draw(m_start);
    window.draw(m_charecter);
    window.draw(m_info);
    window.draw(m_name);

  

}
void MenuGame::setTextInfo(sf::Text& text_ic)
{
    for (int i = 0; i < 3; i++)
    {

        text_ic.setFont(*Texture::instance().getFont());
        text_ic.setStyle(sf::Text::Bold);
        text_ic.setColor(sf::Color::White);
        text_ic.setOutlineColor(sf::Color::Black);
        text_ic.setOutlineThickness(4);

        text_ic.setCharacterSize(90);
        text_ic.setOutlineColor(sf::Color::Red);
    }

}
=======


bool MenuGame:: handleclick(sf::RenderWindow& window, sf::Text rec)
{
    /*
    * 
    * cheack out if the player click on one of the postion
    * 
    */


    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = rec.getPosition().x;
    float btnPosY = rec.getPosition().y;

    float btnxPosWidth = rec.getPosition().x + rec.getLocalBounds().width;
    float btnyPosHeight = rec.getPosition().y + rec.getLocalBounds().height;

    if (mouseX <btnxPosWidth && mouseX>btnPosX && mouseY <btnyPosHeight && mouseY> btnPosY)
        return true;

    return false;
}

>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9

void MenuGame::setColorText(sf::RenderWindow& window, sf::Text& m_menu1, sf::Vector2f LocationMouseMoved)
{
    /*
    *
    * cheack if the player click or was in one of the three option
    * change the colot if the out line depends of the user click there
    * or no
    *
<<<<<<< HEAD
    * */



    if (handleclick1(window, m_menu1))
=======
    */


    if (handleclick(window, m_menu1))
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
    {
        m_menu1.setOutlineThickness(8);

        m_menu1.setOutlineColor(sf::Color::Red);

        window.draw(m_menu1);
    }
    else
    {
        m_menu1.setOutlineThickness(4);
        m_menu1.setOutlineColor(sf::Color::Blue);
        window.draw(m_menu1);
    }

}
<<<<<<< HEAD
bool MenuGame::handleclick1(sf::RenderWindow& window, sf::Text rec)
{
    /*
    *
    * cheack out if the player click on one of the postion
    *

    */

    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;
    if (rec.getGlobalBounds().contains(sf::Vector2f(mouseX, mouseY)))
        return true;
    else
        return false;
}
bool MenuGame::handleclick(sf::RenderWindow& window, sf::Sprite rec)
{
    /*
    *
    * cheack out if the player click on one of the postion
    *

    */

  

    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;
    if (rec.getGlobalBounds().contains(sf::Vector2f(mouseX, mouseY)))
        return true;
    else
        return false;

}



void MenuGame::aboutTheGame(sf::RenderWindow& window)
{
    sf::Vector2f location;
    int i = 0;


    while (window.isOpen())
    {
        window.clear();
        window.draw(m_aboutheGame);
     
        window.draw(m_aboutheGame);
        window.draw(m_closeButtom);
        if (i < 3)
            window.draw(m_NextButtom);
        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:

                if (i < 3 && handleclick(window, m_NextButtom))
                    m_aboutheGame.setTexture(*Texture::instance().getAboutTheGame(++i));

                if (handleclick(window, m_closeButtom))
                    return;

                break;
            case sf::Event::MouseMoved:
                break;
            }


        }
        window.display();

    }


}



void MenuGame::chosePlayer(sf::RenderWindow& window)
{

    while (!chose) {
        window.clear();
        window.draw(m_chose);

        window.draw(m_player1);
        window.draw(m_player2);
        window.draw(m_player3);
        window.draw(m_player4);
        window.draw(m_name);

        // window.draw(m_ss);
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:

                if (handleclick(window, m_player1)) {
                    Texture::instance().set_player("mplayer1.png");
                    
                    chose = true;
                    return;
                }

                else if (handleclick(window, m_player2)) {
                    Texture::instance().set_player("mplayer2.png");
                    
                    chose = true;
                    return;
                }
                else if (handleclick(window, m_player3)) {
                    Texture::instance().set_player("mplayer3.png");
                   
                    chose = true;
                    return;
                }
                else if (handleclick(window, m_player4)) {
                    Texture::instance().set_player("mplayer4.png");
               
                    chose = true;
                    return;
                }

                break;
            }

        }
    }

}


=======

void MenuGame::setTextInfo(sf::Text& text_ic)
{
    text_ic.setFont(*Texture::instance().getFont());
    text_ic.setStyle(sf::Text::Bold);
    text_ic.setColor(sf::Color::White);
    text_ic.setOutlineColor(sf::Color::Black);
    text_ic.setOutlineThickness(4);
}


void MenuGame::draw(sf::RenderWindow& window)
{
    /*
    * draw the background of the menu game
    * draw the three option:
    * start the game 
    * about the game
    * exit
    * draw the music picture 
    * 
    */

 
    window.draw(m_background);
    for (int i = 0; i < 2; i++)
        window.draw(m_menu[i]);

   
   
}
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
