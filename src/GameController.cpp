#include "GameController.h"


GameController::GameController()
    :m_window(sf::RenderWindow(sf::VideoMode(1800, 800), "Geometry Dash", sf::Style::Close | sf::Style::Titlebar))
{
    m_level = "level1";
    m_attemp = 1;
}

void GameController::runTheGame(bool& returnthegame)
{
    PauseMenu m_pausemenu(m_menugame);

    initView();

    b2World m_world(b2Vec2(ZEROFLOAT, GRAVITYWORLD));


    initObjects(m_world);

    float time_step = 1.0f / 60.0f;
    int32 velocity_iterations = 8;
    int32 position_iterations = 3;


    Board m_board(m_world, m_level);


    OnCollision m_collision;
    m_world.SetContactListener(&m_collision);

    Player m_player(m_world, sf::Vector2f(ZERO, STARTPLAYERLOCATION));
    Music::instance().PlayMusic(m_level + ".ogg");







    while (m_window.isOpen())
    {
        if (Player::m_winGame) {
            WinTheGame().activateWinScreen(m_window, m_menugame, returnthegame);
            Player::m_winGame = false;
        }

        for (auto event = sf::Event{}; m_window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyReleased:
                m_player.resetVelocity();

                if (event.key.code == sf::Keyboard::P)
                    m_pausemenu.runPauseMenu(m_window, m_menugame, returnthegame);
                break;


            }
        }
        m_player.handleMovement();

        if (returnthegame)
            return;

        m_window.clear();

        m_world.Step(time_step, velocity_iterations, position_iterations);




        draw(m_player, m_board);
       



        //view
        sf::Vector2f position;
        position.x = m_player.getposition().x + 10 - (WIDTHWINDOW / TWO);
        if (position.x < ZERO)
            position.x = ZERO;

        m_view.reset(sf::FloatRect(position.x, position.y, WIDTHWINDOW, HEIGHTWINDOW));
        m_window.setView(m_view);

        if (Player::m_gameover) {
            resetGame(m_player);
            Player::m_gameover = false;
        }

        m_window.display();
    }


}


void GameController::initObjects(b2World& m_world)
{
    /*
    *
    * initializing private member of the game object
    *
    */

    m_menugame.menurun(m_window, m_level);


    int index = ZERO;

    m_background.resize(m_backgroundRepeated);



    for (auto& background : m_background)
    {
        background.setTexture(*Texture::instance().getGameBackGround(BLUE));
        background.setScale(sf::Vector2f((M_WidthWindow / background.getGlobalBounds().width),
            (M_HieghtWindow / background.getGlobalBounds().height)));
        background.setTextureRect(sf::IntRect(sf::Vector2i(ZERO, ZERO), sf::Vector2i(WIDTHWINDOW, HEIGHTWINDOW)));
        background.setPosition(M_WidthWindow * index, ZERO);

        index++;

    }

    m_attemped.setString("ATTEMPT     " + std::to_string(m_attemp));
    m_attemped.setFont(*Texture::instance().getFont());
    m_attemped.setCharacterSize(60);
    m_attemped.setPosition(50,400 );
    m_attemped.setFillColor(sf::Color::White);

    m_window.setVerticalSyncEnabled(true);
    m_world.SetAllowSleeping(true);

}

void GameController::draw(Player& player, Board& board)
{

    for (auto& background : m_background)
        m_window.draw(background);


    player.draw(m_window);
    board.draw(m_window);
    m_window.draw(m_attemped);
}
void GameController::initView()
{


    //view 

    m_view = m_window.getView();
    m_view.reset(sf::FloatRect(ZERO, ZERO, WIDTHWINDOW, HEIGHTWINDOW));

}

void GameController::resetGame(Player& m_player)
{


    m_player.setPosition(sf::Vector2f(ZERO, PLAYERPOSITIONRESET));
    if (Music::instance().getSoundStatus())
        Music::instance().PlayMusic(m_level + ".ogg");
    m_attemp += 1;
    m_attemped.setString("ATTEMPT     " + std::to_string(m_attemp));
}