#include "assets.h"
#include <stdlib.h>
#include <stdio.h>
#include "../config.h"

// Funcion que carga la información para acceder a los assets de las ranas
assets_t * get_frog_assets(void){
    assets_t * assets = (assets_t *) malloc(sizeof(assets_t) * FROG_ASSETS_X * FROG_ASSETS_Y);
    int i;
    int j;
    /*
        EL objetivo es obtener cada elemento que sea una rana
        Se suma 1 ya que es el alejamiento del borde y se va sumando 
        2*j o 2*i porque es el espacio entre los sprites de ranas
    */
    for (i = 0; i < FROG_ASSETS_Y; i++){
        for(j = 0; j< FROG_ASSETS_X; j++){
            assets_t asset = {
                .sh = NORMAL_SIZE, 
                .sw = NORMAL_SIZE,
                .sx = j * NORMAL_SIZE + 2 * j + 1,
                .sy = i * NORMAL_SIZE + 2 * i + 1
            };
            assets[i * FROG_ASSETS_X + j] = asset;
        }

    }
    return assets;
}

assets_t * get_death_assets(void){
    assets_t* assets = (assets_t *) malloc(sizeof(assets_t) * DEATH_ASSETS);
    int i;
    for (i = 0; i < DEATH_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = NORMAL_SIZE,
            .sy = DEATH_Y,
            .sx = i * NORMAL_SIZE + 2 * i + 1
        };
        assets[i] = asset;
    }
    return assets;
}
assets_t * get_cars_assets(void){
    assets_t* assets = (assets_t*) malloc(sizeof(assets_t) * CAR_ASSETS);
    int i;
    for (i = 0; i < CAR_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = (i != CAR_ASSETS - 1 ) ? NORMAL_SIZE : BIG_SIZE,
            .sy = CAR_Y,
            .sx = i * NORMAL_SIZE + 2 * i + 1
        };
        assets[i] = asset;
    }
    return assets;
}
assets_t * get_life_assets(void){
    assets_t * assets = (assets_t *) malloc(sizeof(assets_t));
    assets_t asset = {
        .sh = SHORT_SIZE,
        .sw = SHORT_SIZE,
        .sx = 5 + NORMAL_SIZE * 2,
        .sy = LIFE_ASSET_Y
    }; 
    assets[0] = asset;
    return assets;
}
assets_t * get_snakes_assets(void){
    assets_t* assets = (assets_t *) malloc(sizeof(assets_t) * SNAKE_ASSETS);
    int i;
    for (i = 0; i < SNAKE_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = BIG_SIZE,
            .sy = SNAKE_Y,
            .sx = i * BIG_SIZE + 2 * i + 1
        };
        assets[i] = asset;
        
    }
    return assets;
}
assets_t * get_crocodrile_assets(void){
    assets_t* assets = (assets_t*) malloc(sizeof(assets_t) * CROCODRILE_ASSETS);
    int i;
    for (i = 0; i < CROCODRILE_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = GIGANT_SIZE,
            .sy = CROCODRILE_Y,
            .sx = CROCODRILE_X + i*GIGANT_SIZE + 2 * i
        };
        assets[i] = asset;
    }
    return assets;
}

assets_t * get_turtle_assets(void){
    assets_t* assets = (assets_t*) malloc(sizeof(assets_t) * TURTLE_ASSETS);
    int i;
    for(i = 0; i < TURTLE_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = NORMAL_SIZE,
            .sy = TURTLE_Y,
            .sx = NORMAL_SIZE * i + 2 * i + 1
        };
        assets[i] = asset;
    }
    return assets;
}

assets_t * get_log_assets(void){
    assets_t * assets = (assets_t*) malloc(sizeof(assets_t) * LOG_ASSETS);
    int i;
    for(i = 0; i < LOG_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = NORMAL_SIZE,
            .sy = LOG_Y,
            .sx = NORMAL_SIZE * i + 2 * i + 1
        };
        assets[i] = asset;
    }
    return assets;
}
assets_t * get_otter_assets(void){
    assets_t * assets = (assets_t *) malloc(sizeof(assets_t) * OTTER_ASSETS);
    int i;
    for(i = 0; i < OTTER_ASSETS; i++){
        assets_t asset = {
            .sh = NORMAL_SIZE,
            .sw = NORMAL_SIZE, 
            .sx = OTTER_X + i * 2 + i * NORMAL_SIZE,
            .sy = OTTER_Y
        };
        assets[i] = asset;
    }
    return assets;
}
assets_t * get_chars_assets(char color){
    int chars_y;
    switch (color) {
    case 'w':{
        chars_y = 250;
        break;
    }
    case 'y':{
        chars_y = 278;
        break;
    }
    case 'r':{
        chars_y = 306;
        break;
    }
    case 'v':{
        chars_y = 334;
        break;
    }
    case 'b':{
        chars_y = 362;
        break;
    }
    default:
        return NULL;
        break;
    }
    assets_t * assets = (assets_t*) malloc(CHARS_ASSETS * sizeof(assets_t));
    int i, j;

    for (i = 0; i < CHARS_ASSETS_Y; i++)
        for(j = 0; (j < CHARS_ASSETS_X) && (j + i * CHARS_ASSETS_X < CHARS_ASSETS); j++){
            assets_t asset = {
                .sx = j * SHORT_SIZE + j * 1 + 1,
                .sw = SHORT_SIZE,
                .sh = SHORT_SIZE,
                .sy = chars_y + i * SHORT_SIZE + i * 1 
            };
            
            assets[i * CHARS_ASSETS_X + j] = asset;
        }
    

    return assets;
}
assets_t *get_frog_chars_assets(void){
    assets_t * assets = (assets_t*) malloc(sizeof(assets_t) * FROG_CHARS_ASSETS);
    int i;
    for (i = 0; i < FROG_CHARS_ASSETS; i++){
        assets_t asset = {
            .sw = NORMAL_SIZE,
            .sh = NORMAL_SIZE,
            .sx = i * NORMAL_SIZE + i * 2 + 1,
            .sy = FROG_CHARS_ASSETS_Y
        };
        assets[i] = asset;
    }
    return assets;
}

assets_t * get_wall_assets(void){
    assets_t * assets = (assets_t*) malloc(sizeof(assets_t) * WALL_ASSETS);
    
    assets_t asset1 = {
        .sw = BIG_SIZE,
        .sh = WALL_SIZE,
        .sx = 1,
        .sy = WALL_ASSETS_Y
    };

    assets_t asset2 = {
        .sw = SHORT_SIZE,
        .sh = WALL_SIZE,
        .sx = BIG_SIZE + 1 + 2,
        .sy = WALL_ASSETS_Y
    };
    assets[0] = asset1;
    assets[1] = asset2;
    return assets;
}
assets_t * get_special_assets(void){
    assets_t *assets = (assets_t*) malloc(sizeof(assets_t) * SPECIAL_ASSETS);
    int i;
    for (i = 0; i < SPECIAL_ASSETS; i++){
        assets_t asset = {
            .sw = NORMAL_SIZE,
            .sh = NORMAL_SIZE,
            .sx = SPECIAL_ASSETS_X + i * 2 + NORMAL_SIZE * i,
            .sy = SPECIAL_ASSETS_Y
        };
        assets[i] = asset;
    }
    return assets;
}