#ifndef BUTTON
#define BUTTON
#include <stdint.h>
#include "../assets.h" 
#include "../init.h"
#define NOT_CENTERED 0
#define CENTERED 1


typedef struct {
    uint8_t was_clicked;
    char*text;  
    assets_t * font;
    float x; 
    float y;  
    int font_size;
    int centered;
} text_t;
text_t * create_text(char* text, assets_t * font, float x, float y, int font_size, int centered);
void draw_text(text_t *text);
void destroy_text(text_t * text);
int text_was_selected(text_t * text, int x, int y);
void twinkle(int amount, int selected, assets_t * normal_font, assets_t *selected_font, ...);
#endif