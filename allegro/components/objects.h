#ifndef OBJECTS
#define OBJECTS
#include <stdlib.h>
#include "../../entities/entities.h"
void draw_car_v1(char direction, float dx, float dy);
void draw_car_v2(char direction, float dx, float dy);
void draw_log(int size, float dx, float dy);
void draw_snake(object_t *snake, float dx, float dy);
void draw_bus(char direction, float dx, float dy);
void draw_frog(independent_object_t * frog, float dx, float dy); 
//void draw_final_frog();
#endif