#ifndef RENDER
#define RENDER
#include "../entities/entities.h"

int renderWorld(map_t *map, const independent_object_t* frog[], int size, int tiempo, int lifeRemaining);
void draw_full_line( assets_t * line, float y);
void draw_finish_line(assets_t * wall_assets);

#endif