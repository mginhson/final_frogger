#include <stdio.h>

#ifdef RPI

#include "../menus/menu.h"
#include "../menus/top.h"
#include "../menus/pause.h"

#include "../audio/soundTrack.h"
#include "../driv/disdrv.h"
#endif

#ifdef PC
#include "../allegro/menu.h"
#include "../allegro/pause.h"
#include "../allegro/highscore.h"
#include "../allegro/audio/soundTrack.h"
#endif
#include "../game/game_logic.h" 
#include <unistd.h>
#include "menu_logic.h"
#include "../config.h"
#include "../highScores/High_scores.h"
void menu_1 (int option){
    bestPlayers_t jugadores = reading_top(); 
    int state = NONE;
    switch (option){
        case START:
            #ifdef RPI
            music();
            #endif
            usleep(100000);
            initializeGameLogic(); 
            while(state == NONE)
            {
                       
                state = gameTick(10);
                usleep(10000);
            }
            usleep(100000);
            if (state == MENU)
            {
                open_menu_1();
            }else if(state == PAUSAA){
                open_menu_2();
            }
            
            break;
        case TOP:
            usleep(500000);
            for(int i = 0; i < 10; i++){

            }
            topTen(jugadores);
            usleep(500000);
            open_menu_1 ();
            break;
        case END:
            #ifdef RPI
            disp_clear();
            disp_update();
            #endif
            break;
    }

}


void menu_2 (int option){
    int state = NONE;
    switch (option){
        case CONTINUE:
            usleep(100000);
            while(state != MENU && state != PAUSAA)
            {       
                state = gameTick(10);
                usleep(10000);
            }
            usleep(100000);
            if (state == MENU)
            {
                open_menu_1();
            }else{
                open_menu_2();
            }
            break;
        case RESTART:
            usleep(100000);
            initializeGameLogic();
            while(state != MENU && state != PAUSAA)
            {       
                state = gameTick(10);
                usleep(10000);
            }
            usleep(100000);
            if (state == MENU)
            {
                open_menu_1();
            }else{
                open_menu_2();
            }
            break;
        case QUIT:
            open_menu_1();
            break;
    }

}


void open_menu_1 (void){
    int option = menu(); // Funcion de Wainer y Sosa que me entrega que se oprime en el menu principal
    usleep(100000);
    if (option){                    // Si recibo una opcion != 0 (osea que se oprimio una opcion)
        menu_1 (option);
    }
}


void open_menu_2 (void){
    int option = pause();     // Funcion de Wainer y Sosa que me entrega que se oprime en el menu de pausa
    usleep(100000);
    if (option){            // Si recibo una opcion != 0 (osea que se oprimio una opcion)
        menu_2 (option);
    }
}