#include "../driv/disdrv.h"
#include "../driv/joydrv.h"
#include "../driv/formas.h"
#include "menu.h"
#include <unistd.h>


static void start(void);
static void top(void);
static void end(void);

static int reading (joyinfo_t * inputJ);

int menu(void){
    joyinfo_t inputJ = {0, 0, 0};
    int state = START;
    start();
    while(reading(&inputJ) && (inputJ.sw != J_PRESS)){
        switch(state){
            case START:
                if(inputJ.y > 100){
                    top();
                    state = TOP;
                }
                break;
            case TOP:
                if(inputJ.y < -100){
                    start();
                    state = START;
                }else if(inputJ.y > 100){
                    end();
                    state = END;
                }
                break;
            case END:
                if(inputJ.y < -100){
                    top();
                    state = TOP;
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

static void start (void){
    disp_clear();

    letterS((dcoord_t){12, 9});
    letterT((dcoord_t){8, 9});
    letterR((dcoord_t){4,9});

    letterT((dcoord_t){12,2});
    letterO((dcoord_t){8,2});
    letterP((dcoord_t){4,2});

    verticalLine(3, (dcoord_t) {15, 10});
    verticalLine(3, (dcoord_t) {14, 10});

    disp_update();
}
static void top (void){
    disp_clear();

    letterS((dcoord_t){12, 9});
    letterT((dcoord_t){8, 9});
    letterR((dcoord_t){4,9});


    letterT((dcoord_t){12,2});
    letterO((dcoord_t){8,2});
    letterP((dcoord_t){4,2});

    verticalLine(3, (dcoord_t) {15, 3});
    verticalLine(3, (dcoord_t) {14, 3});

    disp_update();
}
static void end (void){
    disp_clear();

    letterE((dcoord_t){12, 9});
    letterN((dcoord_t){8, 9});
    letterD((dcoord_t){4,9});

    verticalLine(3, (dcoord_t) {15, 10});
    verticalLine(3, (dcoord_t) {14, 10});

    disp_update();
}