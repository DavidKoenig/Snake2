#include "Game.h"
#include <cstdlib>
#include <time.h>
#include <stdio.h>

int main( int argc, const char* argv[] )
{
    srand( time(NULL) );
    CGame* game = new CGame();
    game->runGame();
    delete game;

    getchar();
    return 0;
}