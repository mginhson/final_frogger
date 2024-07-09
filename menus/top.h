#ifndef TOP_H
#define TOP_H

#include "../config.h"
typedef struct{
    char * name[10];
    char * puntajes[10];
}bestPlayers_t;

enum options_2{TOP1, TOP2,TOP3, TOP4,TOP5, TOP6,TOP7, TOP8, TOP9, TOP10, BACK};
int topTen(bestPlayers_t bestPlayers);


#endif