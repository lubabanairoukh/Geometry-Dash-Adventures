<<<<<<< HEAD
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
=======


#include "Controller.h"

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    auto c = Controller();
    c.run();
    return EXIT_SUCCESS;
}
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
