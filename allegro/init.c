#include "init.h"
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include "../config.h"
g_info_t general_information;
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
    
    return NULL;
}
// Funcion que cierra allegro
void destroy_allegro(void){
   // al_destroy_font(g_info->font);
    
    al_destroy_display(general_information.disp);
    al_destroy_timer(general_information.timer);
    al_destroy_event_queue(general_information.queue);
    al_destroy_bitmap(general_information.bitmap);
    al_uninstall_keyboard();
    al_uninstall_mouse();
    return;
}

