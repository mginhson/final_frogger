#include "renderWorld.h"
#include "../driv/disdrv.h"
#include "../driv/formas.h"
#include <stdio.h>
#include "../audio/soundTrack.h"

// UTILIZO OFFSETS POR COMO UTILIZO LA MATRIZ Y COMO ESTÁN DEFINIDAS SUS POSICIONES EN LA LIBRERÍA BRINDADA POR LA CÁTEDRA

#define OFFSET(v) (11 - v)
#define OFFSET_y(v) (15 - v)


#define COORDENADA(x,y) ((dcoord_t) {x, y})

#define DIVISOR 4

int contador = 0;
int flag_parpadeo = 1;
int flag_parpadeo2 = 0;
int paso = 0;
int renderWorld (map_t * map, const independent_object_t * frog[], int size, int tiempoRestante, int vidasRestantes, char * score){
    tiempoRestante = tiempoRestante / 1000; // Pasasje del tiempo a segundos
    disp_clear();
    int contador = (tiempoRestante * 1000 * 16)/TIME_PER_LEVEL_MS; // Hago un contador de cuantos segundos quedan dividido en la cantidad de leds
    // Suena el sonido de fin de tiempo cuando quedan 4 y 2 leds de tiempo
    if(contador > 2 && contador <= 4 && !paso){
        timeSound();
        paso = 1;
    }
    if(contador <= 2 && paso){
        timeSound();
        paso = 0;
    }
    
    verticalLine(contador, COORDENADA(0, 16 - contador)); // Dibujo ambas lineas de tiempo (verticales, en primera y ultima columna)
    verticalLine(contador, COORDENADA(15, 16 - contador));
    
    int aux, existe, position;
    
    horizontalLine(12, (dcoord_t) {2, 15});
    for(int row = 0; row < LANES_COUNT; row++){
        if(map->lanes[row].kind == &empty_object || map->lanes[row].kind == NULL){
            continue;
        }
        // Renderizo el fondo de cada lane
        //      AGUA --> ENCENDIDO
        //      FINISH LINE --> ENCENDIDO
        //      CALLE --> APAGADO
        
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
            existe = map->lanes[row].objects[p].doesExist; // Variable que almacena si un objeto existe o no
            position = map->lanes[row].objects[p].position; // Variable que almacena la posición en x de un objeto
            aux = map->lanes[row].kind->hitbox_width; // Variable que almacena el largo de cada objeto

            switch ((map->lanes[row]).background){
                
                case finish_line:
                    if (!existe)
                    {
                        disp_write(COORDENADA(OFFSET(position) + 2,OFFSET_y(row)), D_OFF); // Si es un punto de llegada, apago la posición
                    }
                    break;

                case water:
                    if(existe && position < 12){
                        for(int led = 0; led < aux; led++){
                            if((position + led < 12) && (position + led >= 0)){
                                disp_write(COORDENADA(OFFSET(position) - led + 2, OFFSET_y(row)), D_OFF); // Hay tronco --> apago el fondo
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
                                disp_write(COORDENADA(OFFSET(position) + 2 - led, OFFSET_y(row)), D_ON); // Hay auto, prendo el fondo
                            }else if((position + led > 12)){
                                led = aux;
                            }
                        }
                    }
                    break;
            }
        }
    }


    // RENDERIZO RANA

    // Los flags de parpadeo son para manjear que titile, y con la frecuencia que titila

    if (frog == NULL){
    }else{
        for(int i = 0; i < size; i++){
            if(flag_parpadeo){
                disp_write((dcoord_t) {OFFSET(frog[i]->values.position + 2), OFFSET_y(frog[i]->y_position)}, D_ON);
            }else{
                disp_write((dcoord_t) {OFFSET(frog[i]->values.position + 2), OFFSET_y(frog[i]->y_position)}, D_OFF);
            }
            if(flag_parpadeo2 == 5){
                flag_parpadeo = !flag_parpadeo;
                flag_parpadeo2 = 0;
            }else{
                flag_parpadeo2++;
            }
            
        } 
   
    
    }


    disp_update();
    return alive;
}