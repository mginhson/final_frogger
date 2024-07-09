#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "assets.h"
#include "init.h"
#include "menu.h"
#include "util.h"
#include "components/text.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "components/objects.h"
#include "render.h"
#include "../config.h"
int menu(void){
    // En caso de que allegro no este instalado, lo inicializamos

    static int installed = 0;
    
    if (!installed){
        init_allegro();      
    }
   
    installed = 1;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    
    // Obtenemos un puntero  s a general_information que es una variable global con informacion del juego
    //g_info_t * g_info = &general_information;
   
    //assets_t * red_font = get_chars_assets('r');
    assets_t * frog_font = get_frog_chars_assets();
    assets_t * wall_assets = get_wall_assets();
    assets_t * special_assets = get_special_assets();
    assets_t * street_assets = &(special_assets[street]);
    assets_t * font = get_chars_assets('y');
    assets_t * selected_font = get_chars_assets('r');
    set_background(wall_assets, street_assets);
    // Ponemos el titulo
    set_title(frog_font, TOTAL_WIDTH / 2. - 3.5 * FONT_TITLE_SIZE, TOTAL_HEIGHT/6);
    text_t * play_text = create_text("Play",  font, TOTAL_WIDTH/2,REZISE(WALL_SIZE + 9.5*NORMAL_SIZE) ,REZISE(8), CENTERED);
    text_t * highscore_text = create_text("Highscores", font, TOTAL_WIDTH/2,REZISE(WALL_SIZE + 10.75*NORMAL_SIZE) ,REZISE(8), CENTERED);
    text_t * quit_text = create_text("Quit Game", font, TOTAL_WIDTH/2,REZISE(WALL_SIZE + 12.*NORMAL_SIZE) ,REZISE(8), CENTERED);
    
    // Prueba de dibujo de auto y tronco
    //draw_car('l', 100, 100);
    //draw_log(1, 150, ROW(12));

    draw_text(play_text);
    draw_text(highscore_text);
    draw_text(quit_text);
    /*
    sprite_to_text("Play", g_info, font, TOTAL_WIDTH/2,REZISE(WALL_SIZE + 9.5*NORMAL_SIZE) ,REZISE(8));
    sprite_to_text("Highscores", g_info, font, TOTAL_WIDTH/2,REZISE(WALL_SIZE + 10.75*NORMAL_SIZE) ,REZISE(8));
    sprite_to_text("Quit Game", g_info, font, TOTAL_WIDTH/2,REZISE(WALL_SIZE + 12.*NORMAL_SIZE) ,REZISE(8));
    */
    al_flip_display();
    ALLEGRO_EVENT event_capture;
    int return_value = 0;
    // Hasta que no cambie el valor de lo que devolvemos no retornamos nada
    int selected = 0;
    int counter = 0;
    short int selected_change = 0;
    while (return_value == 0){
        // Leemos todos los eventos de la lista de espera
        al_wait_for_event(general_information.queue, &event_capture);
        
        switch (event_capture.type){
                    // En el caso de que hayamos hecho click, debemos ver si fue en alguno de los textos.
            case ALLEGRO_EVENT_TIMER:{
                counter++;
                if (counter == 5 || selected_change){
                    twinkle(3, selected, font, selected_font, play_text, highscore_text, quit_text);
                    counter = 0;
                    selected_change = 0;
                    al_flip_display();
                }

                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                printf("Click\n");
                if (text_was_selected(play_text, event_capture.mouse.x, event_capture.mouse.y)){
                    return_value = START;
                } else if (text_was_selected(highscore_text, event_capture.mouse.x, event_capture.mouse.y)){
                    return_value = TOP;
                } else if (text_was_selected(quit_text, event_capture.mouse.x, event_capture.mouse.y)){
                    return_value = END;
                }
                        
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (event_capture.keyboard.keycode){
                    case ALLEGRO_KEY_ENTER:{
                        if (selected == 0){
                            return_value = START;
                        } else if (selected == 1){
                            return_value = TOP;
                        } else if (selected == 2){
                            return_value = END;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_DOWN:{
                        selected = selected < 2 ? selected + 1: selected;
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
                return_value = END;
            } 
                    
        }
    }

    

    // Ver eficiencia mas adelante porque continuamente alocamos y liberamos memoria
    free(play_text);
    free(highscore_text);
    free(quit_text);
    free(frog_font);
    free(wall_assets);
    free(special_assets);
    free(font);
    
    return return_value;
}


void set_title(assets_t *title_font,float x, float y){
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_f].sx, title_font[frog_f].sy, title_font[frog_f].sw, title_font[frog_f].sh, x + 0 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_r].sx, title_font[frog_r].sy, title_font[frog_r].sw, title_font[frog_r].sh, x + 1 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_o].sx, title_font[frog_o].sy, title_font[frog_o].sw, title_font[frog_o].sh, x + 2 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_g].sx, title_font[frog_g].sy, title_font[frog_g].sw, title_font[frog_g].sh, x + 3 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_g].sx, title_font[frog_g].sy, title_font[frog_g].sw, title_font[frog_g].sh, x + 4 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_e].sx, title_font[frog_g].sy, title_font[frog_e].sw, title_font[frog_e].sh, x + 5 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
    al_draw_scaled_bitmap(general_information.bitmap, title_font[frog_r].sx, title_font[frog_g].sy, title_font[frog_r].sw, title_font[frog_r].sh, x + 6 * FONT_TITLE_SIZE, y, FONT_TITLE_SIZE, FONT_TITLE_SIZE, 0);
}


void set_background( assets_t * wall_assets, assets_t * street_asset){
    int i;
    al_draw_filled_rectangle(0, 0, TOTAL_WIDTH, REZISE(WALL_SIZE + 7 * NORMAL_SIZE + 2), RIVER_COLOR);
    draw_finish_line(wall_assets);
    draw_full_line(street_asset, ROW(8));
    draw_full_line(street_asset, ROW(15));
    return;
}
