#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define LANES_COUNT 16
#define MAX_OBJECTS_PER_LANE 5

#ifdef PC
    #define SHORT_SIZE 8
    #define NORMAL_SIZE 16
    #define BIG_SIZE 32
    #define GIGANT_SIZE 48
    #define WALL_SIZE 24
    #define BOTTOM_SIZE 32
    #define TOTAL_ROWS 16
    #define TOTAL_COLUMNS 12
    #define REZISE(x) (2.75*(x))
    #define TOTAL_WIDTH (REZISE(TOTAL_COLUMNS* NORMAL_SIZE))
    #define TOTAL_HEIGHT (REZISE(BOTTOM_SIZE + SHORT_SIZE + TOTAL_ROWS * NORMAL_SIZE))
    #define ROW(x) (REZISE(SHORT_SIZE + NORMAL_SIZE * (x)))
    #define LANE_X_PIXELS ((int32_t)TOTAL_WIDTH)
    #define LANE_Y_PIXELS ((int32_t)REZISE(NORMAL_SIZE * LANES_COUNT))
    #define MS_RANITA_MOVEMENT_COOLDOWN 20
    #define MS_BASE_OBJECT_SPEED 30
    #define TIME_PER_LEVEL_MS 30000
    #define TIME_MICROSECONDS 10000

#else
    #define LANE_X_PIXELS 12
    #define LANE_Y_PIXELS 16
    #define ENDSLOT_1 2
    #define ENDSLOT_2 4
    #define ENDSLOT_3 6
    #define ENDSLOT_4 8
    #define ENDSLOT_5 10
    #define LILYPAD_SIZE 1
    #define MS_RANITA_MOVEMENT_COOLDOWN 150
    #define MS_BASE_OBJECT_SPEED 1300
    #define TIME_PER_LEVEL_MS 60000

#endif



#define LANE_PIXEL_HEIGHT (LANE_Y_PIXELS/LANES_COUNT)

#endif
