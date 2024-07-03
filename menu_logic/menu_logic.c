#include <stdio.h>
#include "menu_logic.h"
#include "../menus/menu.h"
#include "../menus/top.h"
#include "../menus/pause.h"
#include <unistd.h>
#include "../game/game_logic.h" 
#include "../audio/soundTrack.h"
#include "../driv/disdrv.h"
#include "../highScores/High_scores.h"

// bestPlayers_t jugadores = {{"VIC","SAN","LOR","MAR","AGU","PAP","SOS","MAT","NOA","JOR"},{"202","100","089","076","067","043","025","010","007","003"}};


void menu_1 (int option){
    bestPlayers_t jugadores = reading_top(); 
    int state = NONE;
    switch (option){
        case START:
            music();
            usleep(100000);
            initializeGameLogic(); 
            while(state == NONE)
            {       
                state = gameTick(100);
                usleep(100000);
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
            disp_clear();
            disp_update();
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
                state = gameTick(100);
                usleep(100000);
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
                state = gameTick(100);
                usleep(100000);
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