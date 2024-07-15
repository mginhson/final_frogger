#include "render.h"
#include "../entities/entities.h"
#include "assets.h"
#include "init.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "../config.h"
#include "components/objects.h"
#include <stdio.h>
static void draw_lane(lane_t* lane, int row);
static void draw_lane_background(lane_t * lane, int row);
static void draw_lane_objects(lane_t * lane, int row);
static void draw_rectangle_timer(int time);
#define TIMER_SIZE 5.
// EL tiempo maximo es 60 y algo
void draw_rectangle_timer(int time){
    al_draw_filled_rectangle(WALL_SIZE, TOTAL_HEIGHT - WALL_SIZE, WALL_SIZE + (time * TIMER_SIZE) / 1000 ,TOTAL_HEIGHT - SHORT_SIZE, al_map_rgb(255, 255, 255));
    return;
}



int renderWorld(map_t *map, const independent_object_t* frog[], int size, int tiempo, int renderLives){
    static short int death_counter = 0;
    int i;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    
    for (i=0; i < LANES_COUNT; i++){
        draw_lane(&map->lanes[i], i);
    }
    //sleep(1);
    // La ranita esta muerta
    draw_frog(frog[0]->values.position, frog[0]->y_position, 0, alive);
    
    
    draw_rectangle_timer(tiempo);
    al_flip_display();
    return death_counter > 0 ? death : alive;
}
static void draw_lane(lane_t * lane, int row){
    draw_lane_background(lane, row);
    draw_lane_objects(lane, row);
    
}
static void draw_lane_objects(lane_t *lane, int row){
    // Accedo a los objetos de lane y los renderizo
    int i;
    if (lane->kind == &empty_object || lane->kind == NULL){
        return;
    }
    for (i = MAX_OBJECTS_PER_LANE - 1; i >= 0 ; i--){

        if ((lane->objects)[i].doesExist){
            float x = lane->objects[i].position;
            float y = ROW(row);
           
            
            if (lane->kind == &bus_object_kind){
                draw_bus(lane->direction, x, y);
            } else if (lane->kind == &car_object_kind_v1){
                draw_car_v1(lane->direction, x, y);
            } else if (lane->kind == &car_object_kind_v2){
                draw_car_v2(lane->direction, x, y);
            } else if (lane->kind == &small_log_object_kind){
                draw_log(1, x, y);
            } else if (lane->kind == &normal_log_object_kind){
                draw_log(2, x, y);
            } else if (lane->kind == &big_log_object_kind){
                draw_log(3, x, y);
            } else if (lane->kind == &snake_object_kind){
                draw_snake(&(lane->objects[i]), x, y); //checkear este acceso, .objects[j], no ->objects
            } else if (lane->kind == &lilypad_object_kind){
                printf("DRAW\n");
                draw_final_frog(x,y);
            } else if (lane->kind == &turtle_object_kind){
                draw_turtle_squad(&(lane->objects[i]), x, y);
            }
            
            
        } 
    }
}
static void draw_lane_background(lane_t * lane, int row){
    // Dibujamos el fondo dependiendo del fondo
    switch (lane->background){
        case water:{
            al_draw_filled_rectangle(0, ROW(row), TOTAL_WIDTH, ROW(row + 1), RIVER_COLOR);
            break;
        }
        case road: { 
            al_draw_filled_rectangle(0, ROW(row), TOTAL_WIDTH, ROW(row + 1), STREET_COLOR);
            break;
        }
        case grass: {
            draw_full_line(&(get_special_assets()[street]), ROW(row));
            break;
        }
        case finish_line:{
            al_draw_filled_rectangle(0, ROW(row), TOTAL_WIDTH, ROW(row + 1), RIVER_COLOR);
            draw_finish_line((get_wall_assets()));
            break;
        }
    }
}
void draw_full_line(assets_t * line, float y){
    int i;
    for (i = 0; i * REZISE(NORMAL_SIZE) < TOTAL_WIDTH; i++){
        float sx = line->sx;
        float sy = line->sy;
        float sw = line->sw;
        float sh = line->sh;

        float dw = REZISE(sw);
        float dh = REZISE(sh);
        float dy = y;
        float dx = i * dw;
        al_draw_scaled_bitmap(general_information.bitmap, sx, sy, sw, sh, dx, dy, dw, dh, 0);
    }
    return;

}
void draw_finish_line(assets_t * wall_assets){
    int i;
        for (i = 0; i* REZISE((BIG_SIZE + SHORT_SIZE)) < TOTAL_WIDTH; i++){
        float sxb = wall_assets[big_wall].sx;
        float syb = wall_assets[big_wall].sy;
        float swb = wall_assets[big_wall].sw;
        float shb = wall_assets[big_wall].sh;
        float dwb = REZISE(swb);
        float dhb = REZISE(shb);

        float sxs = wall_assets[small_wall].sx;
        float sys = wall_assets[small_wall].sy;
        float sws = wall_assets[small_wall].sw;
        float shs = wall_assets[small_wall].sh;
        float dws = REZISE(sws);
        float dhs = REZISE(shs);

        float dxb = (dws + dwb) * i;
        float dyb = 0;

        float dxs = (dws + dwb) * i + dwb;
        float dys = 0;

        al_draw_scaled_bitmap(general_information.bitmap,sxb,syb ,swb ,shb, dxb, dyb, dwb, dhb, 0);
        al_draw_scaled_bitmap(general_information.bitmap, sxs, sys, sws, shs, dxs, dys, dws, dhs, 0);
    }
}