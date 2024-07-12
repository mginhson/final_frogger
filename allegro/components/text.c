#include "text.h"
#include "../assets.h"
#include "../util.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "../../config.h"
text_t * create_text(char* text, assets_t * font, float x, float y, int font_size, int centered){
    if (centered){
        x -= (strlen(text) * font_size) / 2;
    }
    text_t new_text = {
        0, text, font, x, y, font_size, centered
    };
    text_t * p_to_text = malloc(sizeof(text_t));
    *p_to_text = new_text;
    return p_to_text;
    
}

void draw_text(text_t *text){
    sprite_to_text(text->text, text->font, text->x, text->y, text->font_size, text->centered);
    return;
}
int text_was_selected(text_t* text, int x, int y){
    /*printf("%f\n", (text->x));
    printf("%f\n", (text->x + strlen(text->text) * REZISE(SHORT_SIZE)));
    printf("%d\n", (text->y <= y));*/
    if ((text->x <= x )&& (text->x + strlen(text->text) * REZISE(text->font_size)) >= x  && (text->y <= y) && y <= (text->y + text->font_size)){
        return 1;
    }
    return 0;

}
void update_text(text_t * text, char * new_text){
    text->text = new_text;
    return;
}
void destroy_text(text_t * text){
    free(text);
}
void twinkle(int amount, int selected, assets_t * normal_font, assets_t *selected_font,...){
    va_list list;
    va_start(list, selected_font);
    int i;
    for (i = 0; i < amount; i++){
        text_t * text = va_arg(list, text_t *);
        if (i == selected){
            
            if (text->font == selected_font){
               text->font = normal_font;  
            } else {
                text->font = selected_font;
            }
            
        } else {
            text->font = normal_font;
        }
       
        draw_text(text);
    }
    va_end(list);
}