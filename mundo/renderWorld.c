#include "renderWorld.h"
#include "../driv/disdrv.h"
#include "../driv/formas.h"
#include <stdio.h>
#include "../audio/soundTrack.h"

#define OFFSET(v) (11 - v)
#define OFFSET_y(v) (15 - v)
#define COORDENADA(x,y) ((dcoord_t) {x, y})

#define DIVISOR 4

int contador = 0;
int flag_parpadeo = 1;
int paso = 0;
int renderWorld (map_t * map, const independent_object_t * frog[], int size, int tiempoRestante){
    
    disp_clear();
    int contador = (tiempoRestante * 1000 * 16)/TIME_PER_LEVEL_MS;
    if(contador > 2 && contador <= 4 && !paso){
        timeSound();
        paso = 1;
    }
    if(contador <= 2 && paso){
        timeSound();
        paso = 0;
    }

    verticalLine(contador, COORDENADA(0, 16 - contador));
    verticalLine(contador, COORDENADA(15, 16 - contador));
    
    int aux, existe, position;
    
    horizontalLine(12, (dcoord_t) {2, 15});
    for(int row = 0; row < LANES_COUNT; row++){
        if(map->lanes[row].kind == &empty_object || map->lanes[row].kind == NULL){
            continue;
        }
        switch ((map->lanes[row]).background){
            case water:
                horizontalLine(LANE_X_PIXELS,COORDENADA(2, OFFSET_y(row)));
                break;
            case finish_line:
                horizontalLine(LANE_X_PIXELS,COORDENADA(2, OFFSET_y(row))); 
                break;
            default:
                horizontalLineOff(LANE_X_PIXELS,COORDENADA(2, OFFSET_y(row)) );
                break;
        }
        
        for(int p = 0; p < MAX_OBJECTS_PER_LANE; p++){
            // TAMAÑO DEL OBJETO SI ES QUE LO HAY
            existe = map->lanes[row].objects[p].doesExist;
            position = map->lanes[row].objects[p].position;
            aux = map->lanes[row].kind->hitbox_width;    

            switch ((map->lanes[row]).background){
                case finish_line:
                    if (!existe)
                    {
                        disp_write(COORDENADA(OFFSET(position) + 2,OFFSET_y(row)), D_OFF);
                    }
                    break;

                case water:
                    if(existe && position < 12){
                        for(int led = 0; led < aux; led++){
                            if((position + led < 12) && (position + led >= 0)){
                                disp_write(COORDENADA(OFFSET(position) - led + 2, OFFSET_y(row)), D_OFF);
                            }else if((position + led > 12)){
                                led = aux;
                            }
                        }
                    }
                    break;
                    
                default:
                    if(existe && position < 12){
                        for(int led = 0; led < aux; led++){
                            if((position + led < 12) && (position + led >= 0)){
                                disp_write(COORDENADA(OFFSET(position) + 2 - led, OFFSET_y(row)), D_ON);
                            }else if((position + led > 12)){
                                led = aux;
                            }
                        }
                    }
                    break;
            }
        }
    }

    if (frog == NULL){
    }else{
        for(int i = 0; i < size; i++){
            if(flag_parpadeo){
                disp_write((dcoord_t) {OFFSET(frog[i]->values.position + 2), OFFSET_y(frog[i]->y_position)}, D_ON);
            }else{
                disp_write((dcoord_t) {OFFSET(frog[i]->values.position + 2), OFFSET_y(frog[i]->y_position)}, D_OFF);
            }
            flag_parpadeo = !flag_parpadeo;
        } 
   
    
    }


    disp_update();
    return alive;
}