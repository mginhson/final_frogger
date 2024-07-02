#include "../driv/disdrv.h"
#include "../driv/joydrv.h"
#include "../driv/formas.h"
#include "pause.h"
#include <unistd.h>


static void cont(void);
static void restart(void);
static void quit(void);

static int reading (joyinfo_t * inputJ);

int pause(void){
    joyinfo_t inputJ = {0, 0, 0};
    int state = CONTINUE;
    cont();
    while(reading(&inputJ) && (inputJ.sw != J_PRESS)){
        switch(state){
            case CONTINUE:
                if(inputJ.y > 100){
                    restart();
                    state = RESTART;
                }
                break;
            case RESTART:
                if(inputJ.y < -100){
                    cont();
                    state = CONTINUE;
                }else if(inputJ.y > 100){
                    quit();
                    state = QUIT;
                }
                break;
            case QUIT:
                if(inputJ.y < -100){
                    restart();
                    state = RESTART;
                }
        }
        usleep(100000);
    }
    return state;
}

static int reading (joyinfo_t * inputJ){
    (*inputJ) = joy_read();
    return 1;
}

static void cont (void){
    disp_clear();

    letterC((dcoord_t){12, 9});
    letterO((dcoord_t){8, 9});
    letterN((dcoord_t){4,9});

    letterR((dcoord_t){12,2});
    letterE((dcoord_t){8,2});
    letterS((dcoord_t){4,2});

    verticalLine(3, (dcoord_t) {15, 10});
    verticalLine(3, (dcoord_t) {14, 10});

    disp_update();
}
static void restart (void){
    disp_clear();

    letterC((dcoord_t){12, 9});
    letterO((dcoord_t){8, 9});
    letterN((dcoord_t){4,9});


    letterR((dcoord_t){12,2});
    letterE((dcoord_t){8,2});
    letterS((dcoord_t){4,2});

    verticalLine(3, (dcoord_t) {15, 3});
    verticalLine(3, (dcoord_t) {14, 3});

    disp_update();
}
static void quit (void){
    disp_clear();

    letterQ((dcoord_t){12, 9});
    letterU((dcoord_t){8, 9});
    letterI((dcoord_t){5,9});
    letterT((dcoord_t){2,9});

    verticalLine(3, (dcoord_t) {15, 10});
    verticalLine(3, (dcoord_t) {14, 10});

    disp_update();
}