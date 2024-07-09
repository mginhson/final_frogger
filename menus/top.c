#include "top.h"
#include "../driv/disdrv.h"
#include "../driv/joydrv.h"
#include "../driv/formas.h"
#include <unistd.h>
#include "../config.h"
static int reading (joyinfo_t * inputJ);
static void top (char * name, char * puntaje, char puesto);
static void top2 (char * name, char * puntaje, char puesto);

int topTen(bestPlayers_t bestPlayers){
    joyinfo_t inputJ = {0, 0, 0};
    int state = TOP1;
    int flag = 0;
    top(bestPlayers.name[0], bestPlayers.puntajes[0], '1');

    while(reading(&inputJ) && (inputJ.sw != J_PRESS)){
        switch (state)
        {
        case TOP1:
            if(inputJ.y > 100){
                state = TOP2;
                top(bestPlayers.name[1], bestPlayers.puntajes[1], '2');
            }
            break;
        case TOP2:
            if(inputJ.y < -100){
                state = TOP1;
                top(bestPlayers.name[0], bestPlayers.puntajes[0], '1');
            }else if(inputJ.y > 100){
                state = TOP3;
                top(bestPlayers.name[2], bestPlayers.puntajes[2], '3');
            }
            break;
        case TOP3:
            if(inputJ.y < -100){
                state = TOP2;
                top(bestPlayers.name[1], bestPlayers.puntajes[1], '2');
            }else if(inputJ.y > 100){
                state = TOP4;
                top(bestPlayers.name[3], bestPlayers.puntajes[3], '4');
            }
            break;
        case TOP4:
            if(inputJ.y < -100){
                state = TOP3;
                top(bestPlayers.name[2], bestPlayers.puntajes[2], '3');
            }else if(inputJ.y > 100){
                state = TOP5;
                top(bestPlayers.name[4], bestPlayers.puntajes[4], '5');
            }
            break;
        case TOP5:
            if(inputJ.y < -100){
                state = TOP4;
                top(bestPlayers.name[3], bestPlayers.puntajes[3], '4');
            }else if(inputJ.y > 100){
                state = TOP6;
                top(bestPlayers.name[5], bestPlayers.puntajes[5], '6');
            }
            break;
        case TOP6:
            if(inputJ.y < -100){
                state = TOP5;
                top(bestPlayers.name[4], bestPlayers.puntajes[4], '5');
            }else if(inputJ.y > 100){
                state = TOP7;
                top(bestPlayers.name[6], bestPlayers.puntajes[6], '7');
            }
            break;
        case TOP7:
            if(inputJ.y < -100){
                state = TOP6;
                top(bestPlayers.name[5], bestPlayers.puntajes[5], '6');
            }else if(inputJ.y > 100){
                state = TOP8;
                top(bestPlayers.name[7], bestPlayers.puntajes[7], '8');
            }
            break;
        case TOP8:
            if(inputJ.y < -100){
                state = TOP7;
                top(bestPlayers.name[6], bestPlayers.puntajes[6], '7');
            }else if(inputJ.y > 100){
                state = TOP9;
                top(bestPlayers.name[8], bestPlayers.puntajes[8], '9');
            }
            break;
        case TOP9:
            if(inputJ.y < -100){
                state = TOP8;
                top(bestPlayers.name[7], bestPlayers.puntajes[7], '8');
            }else if(inputJ.y > 100){
                state = TOP10;
            }
            break;
        case TOP10:
            if(inputJ.y < -100){
                state = TOP9;
                top(bestPlayers.name[8], bestPlayers.puntajes[8], '9');
            }else{
                if(!flag){
                    top(bestPlayers.name[9], bestPlayers.puntajes[9], '1');
                    
                }else{
                    top2(bestPlayers.name[9], bestPlayers.puntajes[9], '0');
                }
                flag = !flag;
                usleep(100000);
            }
            break;
        }
        usleep(100000);
    }
    return(1);
}
static int reading (joyinfo_t * inputJ){
    (*inputJ) = joy_read();
    return 1;
}
static void top (char * name, char * puntaje, char puesto){
    disp_clear();
    for(int i = 0; i < 3 && name[i] != '\0'; i++){
        funLetter[LETTER(name[i])]((dcoord_t){10 - i*4, 9});
    }for(int i = 0; i < 3 && puntaje[i] != '\0'; i++){
        funNumb[NUMBER(puntaje[i])]((dcoord_t){10 - i*4, 2});
    }
    funNumb[NUMBER(puesto)]((dcoord_t){15, 9});
    disp_update();
}
static void top2 (char * name, char * puntaje, char puesto){
    disp_clear();
    for(int i = 0; i < 3 && name[i] != '\0'; i++){
        funLetter[LETTER(name[i])]((dcoord_t){10 - i*4, 9});
    }for(int i = 0; i < 3 && puntaje[i] != '\0'; i++){
        funNumb[NUMBER(puntaje[i])]((dcoord_t){10 - i*4, 2});
    }
    funNumb[NUMBER(puesto)]((dcoord_t){15, 2});
    disp_update();
}