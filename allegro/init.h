#ifndef IN_ALLEGRO
#define IN_ALLEGRO
#include "assets.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define STREET_COLOR (al_map_rgb(0, 0, 0)) 
#define RIVER_COLOR (al_map_rgb(2, 11, 88))
#define MAX_AUDIOS 5

/*
    Estructura que guarda la información general del juego al renderizar.
 */
typedef struct {
    ALLEGRO_TIMER*timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* disp;
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP* bitmap;
    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_SAMPLE * audios[MAX_AUDIOS];
    ALLEGRO_SAMPLE_INSTANCE *song;
} g_info_t;

extern g_info_t general_information;

void *init_allegro(void);
void destroy_allegro(void);

#endif