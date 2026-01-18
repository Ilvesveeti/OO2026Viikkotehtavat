#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    Game game(40);
    game.play();
    game.printGameResult();

    return 0;
}
