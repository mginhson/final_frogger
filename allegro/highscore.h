#ifndef TOP_H
#define TOP_H
#define TOP_10 10
typedef struct {
    char * name[10];
    char * puntajes[10];
} bestPlayers_t;

void topTen(bestPlayers_t bestPlayers);
#endif