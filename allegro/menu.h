#ifndef MENU_DRAW
#define MENU_DRAW
#include "init.h"
#include "assets.h"

#define FONT_TITLE_SIZE 50
int menu(void);
//void sprite_to_text(char * str, g_info_t * g_info,assets_t * font, float x, float y, float font_size);
void set_background( assets_t * wall_assets, assets_t * street_asset);
void set_title(assets_t *title_font, float x, float y);

enum options_principal {START = 1, TOP, END};
#endif