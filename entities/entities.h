#ifndef ENTITIES_H
#define ENTITIES_H
#include <stdint.h>
#include "../allegro/assets.h"
#include "../config.h"

#define LANE_ARQUETYPE_PIXELS ((LANE_X_PIXELS) * 3)

typedef struct {
    char is_animating;
    assets_t * animation_frame;
} animation_t;



typedef struct{

}object_graphics_t;

typedef struct{
   
    uint32_t canKill :1;
    uint32_t isEquippable :1;
    uint32_t canMove :1;
    uint32_t timer;
    uint8_t state;
}object_attributes_t;



typedef struct{

    const object_graphics_t graphics;
    const object_attributes_t attr;
    const uint32_t hitbox_width; //From left side, should correspond with graphics width!!!
    //On dependant objects, hitbox_height is the same as the LANE_HEIGHT
}object_kind_t;


typedef struct{
    int32_t position;
    animation_t animation;
    uint32_t doesExist :1;
    uint32_t lily_flag :1;
}object_t;

typedef struct{
    object_kind_t params;
    object_t values;
    int32_t y_position;
    const uint32_t hitbox_height; //SHOULD CORRESPOND WITH GRAPHICS HEIGHT!!!
    
}independent_object_t;

typedef enum{
    water,
    road,
    grass,
    finish_line,
}background_t;

typedef struct{
    int32_t ms_to_next; //Internal counter to know when to move
    int32_t ms_reload;  //ms per movement
    background_t background; //background
    const object_kind_t * kind; //all dependant objects on the lane are of the same kind
    uint32_t flag;
    object_t objects[MAX_OBJECTS_PER_LANE]; //every dependant object variable data
    int32_t virtual_lane_end; //True logic lane lenght, DOESN'T correspond to visible lane length in-game
    int32_t virtual_lane_start; //ALWAYS LESS THAN 0-.kind->hitbox_width
    enum{LEFT,RIGHT}direction; //Direction of movement of the lane, either LEFT or RIGHT
}lane_t;

typedef struct{
    lane_t lanes[LANES_COUNT];
}map_t;


extern const object_kind_t bus_object_kind;
extern const object_kind_t empty_object;

extern const object_kind_t car_object_kind_v1;
extern const object_kind_t car_object_kind_v2;

extern const object_kind_t small_log_object_kind;
extern const object_kind_t normal_log_object_kind;
extern const object_kind_t big_log_object_kind;

extern const object_kind_t snake_object_kind;


extern const object_kind_t final_frog_object_kind;
extern const object_kind_t lilypad_object_kind;
extern const object_kind_t freeSlot;

int32_t fillMap(map_t *_map,uint32_t _level);
void printMap(map_t *_map,int32_t a);
void printLaneObjects(lane_t *_lane,int32_t index);
#endif
