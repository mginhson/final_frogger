#include "../assets.h"
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include "../init.h"
#include "../../config.h"
#include "../../entities/entities.h"
#include <stdio.h>
#include <unistd.h>
//#define HITBOX_CORRECTION(x) ((x) +)

void draw_dead_animation(float dx, float dy){
    assets_t * death_collection = get_death_assets();
    int i;
    for (i = 3; i<DEATH_ASSETS; i++){
        usleep(100000);
        float sx = death_collection[i].sx;
        float sy = death_collection[i].sy;
        float sw = death_collection[i].sw;
        float sh = death_collection[i].sh;
        al_draw_scaled_bitmap(general_information.bitmap,sx,sy,sw,sh,dx,dy, REZISE(sw), REZISE(sh), 0);
        al_flip_display();
        usleep(100000);
    }
    free(death_collection);
}
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

    al_draw_scaled_bitmap(general_information.bitmap,sx,sy,sw,sh,dx, dy, REZISE(sw), REZISE(sh), 0);
    free(cars_collection);
    return;
}
void draw_log(int size, float dx, float dy){
    assets_t * logs = get_log_assets();
    dx -= REZISE(8);
    al_draw_scaled_bitmap(general_information.bitmap, logs[start_log].sx, logs[start_log].sy, logs[start_log].sw, logs[start_log].sh, dx, dy, REZISE(logs[start_log].sw), REZISE(logs[start_log].sh), 0);
    int i;
    
    for (i = 1; i<=size;i++){ 
        al_draw_scaled_bitmap(general_information.bitmap, logs[log].sx, logs[log].sy, logs[log].sw, logs[log].sh, dx + i * REZISE(logs[log].sw), dy, REZISE(logs[log].sw), REZISE(logs[log].sh), 0);
    }    
    al_draw_scaled_bitmap(general_information.bitmap, logs[2].sx, logs[2].sy, logs[2].sw, logs[2].sh, dx + i * REZISE(logs[2].sw), dy, REZISE(logs[2].sw), REZISE(logs[2].sh), 0);
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
    assets_t * special_assets = get_special_assets();
    float sx = special_assets[happy_frog].sx;
    float sy = special_assets[happy_frog].sy;
    float sw = special_assets[happy_frog].sw;
    float sh = special_assets[happy_frog].sh;
    printf("FINAL POSITION%f\n", dx);
    //sleep(12);
    al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx - REZISE(sw/2), dy, REZISE(sw), REZISE(sh), 0);
}
void draw_frog(float dx, float dy, int frame, int state){
    assets_t * all_frogs_assets = get_frog_assets();
    assets_t * all_death_assets = get_death_assets();
    
    assets_t * death_assets = all_death_assets + 3;
    assets_t * frogs_assets;
    if (state == alive){
        frogs_assets = &(all_frogs_assets[frog_top]);
    } else if (state == death){
        frogs_assets = &(death_assets[frame]);
    }
    /*
    switch (state)
    {
    case alive:
        frogs_assets = &(all_frogs_assets[frog_top]);
    case death1:
        frogs_assets = &(death_assets[death_1]);
        break;
    case death2:
        frogs_assets = &(death_assets[death_2]);
        break;
    case death3:
        frogs_assets = &(death_assets[death_3]);
        break;
    case death4:
        frogs_assets = &(death_assets[death_4]);
        break;
    case death5:
        frogs_assets = &(death_assets[death_5]);
        break;
    case death6:
        frogs_assets = &(death_assets[death_6]);
        break;
    case death7:
        frogs_assets = &(death_assets[death_7]);
        break;
    default:
        break;
    }*/
    float sx = frogs_assets->sx;
    float sy = frogs_assets->sy;
    float sw = frogs_assets->sw;
    float sh = frogs_assets->sh;

    al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx , dy + REZISE(sw/2), REZISE(sw), REZISE(sh), 0);
    free(all_frogs_assets);
    free(all_death_assets);
}

void draw_turtle_squad(const object_t * p_turtles, float dx, float dy){

    assets_t * turtle_assets = get_turtle_assets();
    float sx = turtle_assets[p_turtles->state + 2].sx;
    float sy = turtle_assets[p_turtles->state + 2].sy;
    float sw = turtle_assets[p_turtles->state + 2].sw;
    float sh = turtle_assets[p_turtles->state + 2].sh;
    int i;
    for (i = 0; i < 3; i++){
        al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx + i * REZISE(sw), dy,REZISE(sw), REZISE(sh), 0);
    }
    return; 
}