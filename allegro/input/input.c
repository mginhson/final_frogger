#include "input.h"
#include "../init.h"
#include <allegro5/allegro5.h>

void input_flush(void){
    ALLEGRO_EVENT event;
    while(!al_is_event_queue_empty(general_information.queue)){
        al_get_next_event(general_information.queue, &event);
    }
    return;
}
dato_entrada input_reader(void){
    int return_value = _EMPTY;
    ALLEGRO_EVENT event_capture;
    
    //printf("%d\n", al_is_event_queue_empty());
    while(!al_is_event_queue_empty(general_information.queue) && return_value == _EMPTY){
       
        al_get_next_event(general_information.queue, &event_capture);
        switch (event_capture.type){
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (event_capture.keyboard.keycode){
                    case ALLEGRO_KEY_W:
                    case ALLEGRO_KEY_UP:{
                        return_value = _UP;
                        break;
                    }
                    case ALLEGRO_KEY_S:
                    case ALLEGRO_KEY_DOWN:{
                        return_value = _DOWN;
                        break;
                    }
                    case ALLEGRO_KEY_A:
                    case ALLEGRO_KEY_LEFT:{
                        return_value = _LEFT;
                        break;
                    }
                    case ALLEGRO_KEY_D:
                    case ALLEGRO_KEY_RIGHT:{
                        return_value = _RIGHT;
                        break;
                    }
                    case ALLEGRO_KEY_SPACE:{
                        return_value = _PAUSE;
                    }
                }
                break;
            }
            // case para mause en caso de tocar boton de pausa
        }
    }   
    return return_value; 
}