#include <allegro5/allegro.h>
#include "init.h"
#include "assets.h"
#include "components/text.h"
#include "pause.h"
#include <stdio.h>
#include "../config.h"
int pause(void){
    al_clear_to_color(al_map_rgb(0, 0 ,0));
    assets_t * violet_font = get_chars_assets('v');
    assets_t * blue_font = get_chars_assets('b');
    
    text_t * pause_text = create_text("PAUSA",  violet_font,TOTAL_WIDTH / 2 ,ROW(2), 55, CENTERED);
    text_t * continue_text = create_text("CONTINUE", blue_font, TOTAL_WIDTH/2, ROW(5), 30, CENTERED);
    text_t * restart_text = create_text("RESTART",  blue_font, TOTAL_WIDTH/2, ROW(7), 30, CENTERED);
    //text_t * menu_text = create_text("MENU",  blue_font, TOTAL_WIDTH/2, ROW(9), 30, CENTERED);
    text_t * quit_text = create_text("MENU",  blue_font, TOTAL_WIDTH/2, ROW(9), 30, CENTERED);    
    
    draw_text(continue_text);
    draw_text(restart_text);
    //draw_text(menu_text);
    draw_text(quit_text);
    draw_text(pause_text);
    ALLEGRO_EVENT event_capture;
    al_flip_display();
    int return_value = 0;
    int selected = 0;
    int counter = 0;
    short int selected_change = 0;
    
    while (!return_value){
    // Leemos todos los eventos de la lista de espera
    al_wait_for_event(general_information.queue, &event_capture);
    printf("CA\n");
        switch (event_capture.type){
                    // En el caso de que hayamos hecho click, debemos ver si fue en alguno de los textos.
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                
                
                if (text_was_selected(continue_text, event_capture.mouse.x, event_capture.mouse.y)){
                    return_value = CONTINUE;
                } else if (text_was_selected(quit_text, event_capture.mouse.x, event_capture.mouse.y)){
                    return_value = QUIT;
                } else if (text_was_selected(restart_text, event_capture.mouse.x, event_capture.mouse.y)){
                    return_value = RESTART; 
                }
                        
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                counter++;
                printf("ES ACA\n");
                if (counter == 5 || selected_change){
                    
                    twinkle(3, selected,blue_font, violet_font , continue_text, restart_text, quit_text);
                
                    counter = 0;
                    selected_change = 0;
                    al_flip_display();
                }

                break;                
            }
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (event_capture.keyboard.keycode){
                    case ALLEGRO_KEY_ENTER:{
                        if (selected == 0){
                            return_value = CONTINUE;
                        } else if (selected == 1){
                            return_value = RESTART;
                        } else if (selected == 2){
                            return_value = QUIT;
                        } 
                        break;
                    }
                    case ALLEGRO_KEY_DOWN:{
                        selected = selected < 3 ? selected + 1: selected;
                        selected_change = 1;
                        break;
                    }
                    case ALLEGRO_KEY_UP:{
                        selected = selected > 0 ? selected - 1: selected;
                        selected_change = 1;
                        break;
                    }
                }
                break;
            } 
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                free(pause_text);
                free(continue_text);
                free(quit_text);
                free(restart_text);
                destroy_allegro();
                _exit(0);
                break;
            }       
        }
    }
    printf("OUT\n");
    free(pause_text);
    free(continue_text);
    free(quit_text);
    free(restart_text);
    //free(menu_text);
    
    return return_value;
}