#include <stdio.h>
#include <stdlib.h>
#include "game/game_logic.h"
#include <time.h>
#include <unistd.h>
#include "allegro/init.h"
#include "config.h"
int main(int argc, char **argv)
{
    puts("frogger");
    init_allegro();
    initializeGameLogic();   
    while(1)
    {
        gameTick(10);
        usleep(TIME_MICROSECONDS);
    }
    return 0;
}
