#include <stdio.h>
#include <stdlib.h>
#include "game/game_logic.h"
#include <time.h>
#if defined(RPI)
    #include "mundo/renderWorld.h"
    #include "inicialization/inicialization.h"
    #include "menus/menu.h"
    #include "audio/soundTrack.h"
    
#elif defined(PC)
    #include "allegro/init.h"
    #include "config.h"
#endif
#include "menu_logic/menu_logic.h"
int main(int argc, char **argv)
{
    
    #if defined(RPI)
        inicialization();
        puts("frogger");
        open_menu_1();
    #elif defined(PC)
        open_menu_1();
        puts("frogger");
        init_allegro();
        initializeGameLogic();   
        while(1)
        {
            gameTick(10);
            usleep(TIME_MICROSECONDS);
        }

    #endif

    return 0;
}
