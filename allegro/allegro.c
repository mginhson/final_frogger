#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include "assets.h"
#include "init.h"
#include "menu.h"
#include "highscore.h"
#include "pause.h"
#include <unistd.h>
char *nombres[10] = {"Sosa", "Santi P", "Wainer", "Ginhson", "Mechi>God", "Magliola", "Bauti", NULL};
char *puntajes[10] = {"123", "100", "19", "12", "3", "0", "0",NULL};
bestPlayers_t list;

int main(void){
    int i;
    
    for (i = 0; i<10 || (nombres[i]) != NULL; i++){
        list.name[i] = nombres[i];
        list.puntajes[i] = puntajes[i];
    }
    int state = 1;
    while (1){
        switch (state){
            case 1:{
                state = menu();
                break;    
            }
            case 3:{
                state = pause();
               
                break;
            }
            case 2: {
                topTen(list);
                state = 1;
               
                break;
            }
            default:{
                break;
            }
        }   
        
        usleep(10000);
        //sleep(1);
    } 
    return 0;
}