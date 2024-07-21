

#include "Controller.h"

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    auto c = Controller();
    c.run();
    return EXIT_SUCCESS;
}