#include "assets.h"
#include "init.h"
#include "allegro5/allegro.h"
#include "../config.h"
#define IS_NUMBER(x) ((x) <= '9' && (x) >= '0')
#define IS_LETTER(x) (((x) <= 'z' && (x) >= 'a') || ((x) <= 'Z' && (x) >= 'A'))
// Escribe texto y letras en minusculas o mayusculas siempre centrado
void sprite_to_text(char * str,assets_t * font, float x, float y, float font_size, int centered){
    int i;
    for (i = 0; str[i] != '\0'; i++){
        int j;
        if (IS_NUMBER(str[i])){
            j = str[i] - '0';
            al_draw_scaled_bitmap(general_information.bitmap, font[j].sx, font[j].sy, font[j].sw, font[j].sh, x + font_size * i, y, font_size, font_size, 0);
        } else if (IS_LETTER(str[i])){
            // Sumamos 9 ya que las letras empiezan a partir del 9
            if (str[i] < 'a'){
                j = str[i] + '9' - '0' - 'A' + 1;
            } else {
                j = str[i] + '9' - '0' - 'a' + 1;         
            }
            al_draw_scaled_bitmap(general_information.bitmap, font[j].sx, font[j].sy, font[j].sw, font[j].sh, x + font_size * i, y, font_size, font_size, 0);
        } 
        // Cualquier cosa que no se pueda escribir, se tomara como un espacio ' '
        
        
    }
    return;
}

