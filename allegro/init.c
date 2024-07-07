#include "init.h"
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include "../config.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <unistd.h>
static void load_sounds(void);
static void destroy_sounds(void);
g_info_t general_information;

#define STEP "audio/src/step.wav"
#define LIFE "audio/src/looseLife.wav"
#define TIME "audio/src/runningOutOfTime.wav"
#define LEVEL "audio/src/nextLevel.wav"
#define MUSIC "audio/src/music.wav"
// Funcion que incializa allegro
void *init_allegro(void){
    // Inicialización de allegro
    al_init();
    // Instalación del teclado
    al_install_keyboard();
    // Inicialización mouse
    al_install_mouse();
    // Inicialización de la libreria para imagenes
    al_init_image_addon();
    // Incialización de la libreria para audio
    al_install_audio();
    printf("%d", al_init_acodec_addon());
    if (!al_init_primitives_addon()){
        printf("No se pudo INICIALIZAR");
    };
    // Creación del timer
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    // Creación de una cola de eventos
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    // Creación de un display
    
    ALLEGRO_DISPLAY* disp = al_create_display(TOTAL_WIDTH, TOTAL_HEIGHT);
    
    // Registramos los eventos de teclado, display y timer
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());
    // Guardamos la información en una variable global
    // Al crear una instancia de g_info_t, automaticamente se crea un ALLEGRO_EVENT
    //g_info_t * g_info = &general_information;
    
    general_information.timer = timer;
    general_information.queue = queue;
    general_information.disp = disp;
    // Empieza a correr el timer
    al_start_timer(general_information.timer);
    general_information.bitmap =  al_load_bitmap("assets.png");
    if ((general_information.bitmap) == NULL){
        return NULL;
    }
    load_sounds();
    
  
    //al_play_sample(general_information.audios[4], 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, 0);
    //sleep(1);
   al_play_sample_instance(general_information.song);
    return NULL;
}
// Funcion que cierra allegro
void destroy_allegro(void){
   // al_destroy_font(g_info->font);
    destroy_sounds();
    al_destroy_display(general_information.disp);
    al_destroy_timer(general_information.timer);
    al_destroy_event_queue(general_information.queue);
    al_destroy_bitmap(general_information.bitmap);
    al_uninstall_keyboard();
    al_uninstall_mouse();
    return;
}

static void load_sounds(void){
    al_reserve_samples(MAX_AUDIOS + 10);
    general_information.audios[0] = al_load_sample(STEP);
    general_information.audios[1] = al_load_sample(LIFE);
    general_information.audios[2] = al_load_sample(TIME);
    general_information.audios[3] = al_load_sample(LEVEL);
    general_information.audios[4] = al_load_sample(MUSIC);
    
    general_information.song = al_create_sample_instance(general_information.audios[4]);
    al_set_sample_instance_playmode(general_information.song, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(general_information.song, al_get_default_mixer());
    //al_play_sample_instance(general_information.song);
    //printf("%p\n", general_information.audios[3]);
    
    return;
}
static void destroy_sounds(void){
    int i;
    for (i = 0; i < MAX_AUDIOS; i++){
        al_destroy_sample(general_information.audios[i]);
    }
    al_destroy_sample_instance(general_information.song);
    return;
}