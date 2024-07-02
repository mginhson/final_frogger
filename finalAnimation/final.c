#include "../driv/disdrv.h"
#include "../driv/joydrv.h"
#include "../driv/formas.h"

#include "final.h"
#include <stdio.h>
#include <unistd.h>

#include "../highScores/High_scores.h"

static void finalAnimation(char * points);

static int reading (joyinfo_t * inputJ);

static char * signIn (void);

static void name (void);

void onceDead (char * points, int pts){

    finalAnimation(points);

    char * arr = signIn();
    for(int i = 0; i < 3; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
    writing_top(arr, pts);
    disp_clear();
    disp_update();
}

static void finalAnimation (char * points){
    disp_clear();
    int state = 0;
    for(int i = 0; i < 6; i++){
        if (!state){
            fullHeart((dcoord_t){4, 7});
            fullHeart((dcoord_t){9, 5});
            fullHeart((dcoord_t){14, 7});
        }else{
            emptyHeart((dcoord_t){4, 7});
            emptyHeart((dcoord_t){9, 5});
            emptyHeart((dcoord_t){14, 7});
        }
        disp_clear();
        state = !state; 
        usleep(750000);
    }
    disp_clear();
    usleep(750000);
    char pts[] = {'P', 'T', 'S'};
    for (int i = 0; i < 3; i++)
    {
        funNumb[NUMBER(points[i])]((dcoord_t){12 - i*4, 2});
        funLetter[LETTER(pts[i])]((dcoord_t){12 - i*4, 9});
    }
    
    usleep(2500000);
    disp_clear();
}

static char * signIn (void){
    char state;
    joyinfo_t inputJ = {0, 0, 0};
    static char arr[3];
    for(int i = 0; i < 3; i++){
        disp_clear();
        name();
        state = 'A';
        funLetter[LETTER(state)]((dcoord_t){8, 4});
        reading(&inputJ);
        while (reading(&inputJ) && (inputJ.sw != J_PRESS))
        {
            if (state == 'A'){
                if (inputJ.x < -100){
                    disp_clear();
                    name();
                    state++;
                    funLetter[LETTER(state)]((dcoord_t){8, 4});
                    
                }
            }else if(state == 'Z'){
                if (inputJ.x > 100){
                    disp_clear();
                    name();
                    state--;
                    funLetter[LETTER(state)]((dcoord_t){8, 4});
                    
                }
            }else{
                if (inputJ.x < -100){
                    disp_clear();
                    name();
                    state++;
                    funLetter[LETTER(state)]((dcoord_t){8, 4});
                    
                }else if(inputJ.x > 100){
                    disp_clear();
                    name();
                    state--;
                    funLetter[LETTER(state)]((dcoord_t){8, 4});
                }
            }
            usleep(100000);
        }
        arr[i] = state;
        usleep(150000);
    }
    return arr;
}

static int reading (joyinfo_t * inputJ){
    (*inputJ) = joy_read();
    return 1;
}

static void name (void){
    letterN((dcoord_t) {15, 11});
    letterA((dcoord_t) {11, 11});
    letterM((dcoord_t) {7, 11});
    letterE((dcoord_t) {3, 11});
}