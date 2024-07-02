#include "../assets.h"
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include "../init.h"
#include "../../config.h"
#include "../../entities/entities.h"
#include <stdio.h>
void draw_car_v1(char direction, float dx, float dy){
    assets_t * cars_collection = get_cars_assets();
    int random;
    random = (direction == 1 ? car3r : car1l); 
    float sx = cars_collection[random].sx;
    float sy = cars_collection[random].sy;
    float sw = cars_collection[random].sw;
    float sh = cars_collection[random].sh;

    al_draw_scaled_bitmap(general_information.bitmap,sx,sy,sw,sh,dx,dy, REZISE(sw), REZISE(sh), 0);
    free(cars_collection);
    return;
}
void draw_car_v2(char direction, float dx, float dy){
    assets_t * cars_collection = get_cars_assets();
    int random;
    random = (direction == 1 ? car4r : car2l); 
    float sx = cars_collection[random].sx;
    float sy = cars_collection[random].sy;
    float sw = cars_collection[random].sw;
    float sh = cars_collection[random].sh;

    al_draw_scaled_bitmap(general_information.bitmap,sx,sy,sw,sh,dx,dy, REZISE(sw), REZISE(sh), 0);
    free(cars_collection);
    return;
}
void draw_log(int size, float dx, float dy){
    assets_t * logs = get_log_assets();
    al_draw_scaled_bitmap(general_information.bitmap, logs[start_log].sx, logs[start_log].sy, logs[start_log].sw, logs[start_log].sh, dx, dy, REZISE(logs[start_log].sw), REZISE(logs[start_log].sh), 0);
    int i;
    for (i = 1; i<=size;i++){
        al_draw_scaled_bitmap(general_information.bitmap, logs[log].sx, logs[log].sy, logs[log].sw, logs[log].sh, dx + i * REZISE(logs[log].sw), dy, REZISE(logs[log].sw), REZISE(logs[log].sh), 0);
    }    
    al_draw_scaled_bitmap(general_information.bitmap, logs[2].sx, logs[2].sy, logs[2].sw, logs[2].sh, dx + i * REZISE(logs[log].sw), dy, REZISE(logs[2].sw), REZISE(logs[2].sh), 0);
    free(logs);
    return;
}
void draw_snake(object_t * snake, float dx, float dy){
    assets_t * snakes = get_snakes_assets();
    int i = snake1;
    float sx = snakes[i].sx;
    float sy = snakes[i].sy;
    float sw = snakes[i].sw;
    float sh = snakes[i].sh;
    
    al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx, dy, REZISE(sw), REZISE(sh), 0);
    free(snakes);
    return;
}
void draw_bus(char direction, float dx, float dy){
    assets_t * bus = get_cars_assets();
    float sx = (bus+trackl)->sx;
    float sy = (bus+trackl)->sy;
    float sw = (bus+trackl)->sw;
    float sh = (bus+trackl)->sh;
    //printf("BUS DRAWED%f\n", sw);
    al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx, dy, REZISE(sw), REZISE(sh), 0);
    free(bus);
    return;
}
void draw_final_frog(float dx, float dy){
    //assets_t * final_frog = get_special_assets() + spaecial
}
void draw_frog(independent_object_t * frog, float dx, float dy){
    assets_t * frogs_assets = get_frog_assets();
    float sx = frogs_assets->sx;
    float sy = frogs_assets->sy;
    float sw = frogs_assets->sw;
    float sh = frogs_assets->sh;

    al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx , dy + REZISE(SHORT_SIZE), REZISE(sw), REZISE(sh), 0);
    free(frogs_assets);
}