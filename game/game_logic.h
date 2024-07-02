#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <stdint.h>
#include "../config.h"
int gameTick(int32_t ms_since_last_tick);
void initializeGameLogic(void);
enum juego_avance {NONE, PAUSAA, MENU};
 
#endif