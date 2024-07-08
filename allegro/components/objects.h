#ifndef OBJECTS
#define OBJECTS
#include <stdlib.h>
#include "../../entities/entities.h"
void draw_car_v1(char direction, float dx, float dy);
void draw_car_v2(char direction, float dx, float dy);
void draw_log(int size, float dx, float dy);
void draw_snake(object_t *snake, float dx, float dy);
void draw_bus(char direction, float dx, float dy);
void draw_final_frog(float dx, float dy);
void draw_frog(float dx, float dy, int frame, int state);
void draw_turtle_squad(const object_t * p_turtles, float dx, float dy); 

#endif