#include <allegro5/allegro5.h>
#include "components/text.h"
#include "assets.h"
#include "../config.h"
#include "string.h"
#include <unistd.h>
#include <stdio.h>
#include "../highScores/High_scores.h"
#include "audio/soundTrack.h"
void onceDead(char *str, int pts){
    //al_clear_to_color(al_map_rgb(0, 0, 0));
    //al_flip_display();
    assets_t * yellow_font = get_chars_assets('y');
    assets_t * red_font = get_chars_assets('r'); 
    
    //char score[11] = "SCORE";
    //strcpy(score + 7, str);
    text_t * score_text = create_text("SCORE", yellow_font, TOTAL_WIDTH / 2, TOTAL_HEIGHT / 4, REZISE(WALL_SIZE), CENTERED);
    text_t * points_text = create_text(str, red_font, TOTAL_WIDTH / 2, TOTAL_HEIGHT / 4 + REZISE(WALL_SIZE), REZISE(WALL_SIZE),CENTERED);

    
    short int allegro_loop = 1;
    ALLEGRO_EVENT event;
    char letters[3][2] = {"A", "A", "A"};
    char characters[4] = {'A', 'A', 'A', '\0'};

    text_t * c1 = create_text(letters[0], yellow_font, TOTAL_WIDTH / 2 - REZISE(NORMAL_SIZE), TOTAL_HEIGHT / 2, REZISE(NORMAL_SIZE), CENTERED);

    text_t * c2 = create_text(letters[1], yellow_font, TOTAL_WIDTH / 2, TOTAL_HEIGHT / 2, REZISE(NORMAL_SIZE), CENTERED);
    text_t * c3 = create_text(letters[2], yellow_font, TOTAL_WIDTH / 2 + REZISE(NORMAL_SIZE), TOTAL_HEIGHT / 2, REZISE(NORMAL_SIZE), CENTERED);
    char temp = 'A';
    short int counter = 0;
    short int selected = 0;
    looseLife(0);
    
    while(allegro_loop){
        //printf("%s\n", str);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        draw_text(score_text);
        draw_text(points_text);
        //twinkle(3, selected, yellow_font, red_font, c1, c2, c3);
        al_wait_for_event(general_information.queue, &event);
        switch (event.type){
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                free(c1);
                free(c2);
                free(c3);
                free(score_text);
                free(points_text);
                destroy_allegro();
                _exit(0);
                break;
            case ALLEGRO_EVENT_TIMER:{
                counter++;
                if (counter == 8){
                    twinkle(3, selected, yellow_font, red_font, c1, c2, c3);
                    printf("TIMER\n");
                    counter = 0;
                }    
                    
               
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (event.keyboard.keycode){
                    
                    case ALLEGRO_KEY_UP:{
                        
                        if (characters[selected] == 'A'){
                            characters[selected] = 'Z';
                        } else {
                            characters[selected]--;
                        }
                        letters[selected][0] = characters[selected]; 
                        break;
                    }
                    case ALLEGRO_KEY_RIGHT:{
                    
                        selected = selected + 1 <= 2 ? selected + 1 : selected; 
                        twinkle(3, selected, yellow_font, red_font, c1, c2, c3);
                        break;
                    }
                    case ALLEGRO_KEY_LEFT:{
                        
                        selected = selected - 1 >= 0 ? selected - 1 : selected;
                        twinkle(3, selected, yellow_font, red_font, c1, c2, c3);
                        break;
                    }
                    case ALLEGRO_KEY_DOWN:{
                        
                        if (characters[selected] == 'Z'){
                            characters[selected] = 'A';
                        } else {
                            characters[selected]++;
                        }
                        letters[selected][0] = characters[selected]; 
                        break;
                    }
                    case ALLEGRO_KEY_ENTER:{
                        allegro_loop = 0;
                    }
                }
            }            
            default:
                break;
            }
            
            draw_text(c1);
            draw_text(c2);
            draw_text(c3);
            al_flip_display();
    }
    writing_top(characters, pts);
    free(c1);
    free(c2);
    free(c3);
    free(score_text);
    free(points_text);
}