#include <allegro5/allegro5.h>

#include "../entities/entities.h"
#include "render.h"
#include "components/objects.h"

void looseLife(int remainingLives, independent_object_t ** ranita){
    float y = ranita[0]->y_position;
    float x = ranita[0]->values.position;
    draw_dead_animation(x, y);
    return;
}