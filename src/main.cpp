#include "GameController.h"
int main()
{
    bool m_returntomenu = false;


    do {
         m_returntomenu = false;
        std::srand(static_cast<unsigned>(time(NULL)));
        GameController my_game;
        my_game.runTheGame(m_returntomenu);
    } while (m_returntomenu);
    
    return 0;
    
}
