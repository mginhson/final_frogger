#ifndef CONFIG_H
#define CONFIG_H



#include <stdint.h>
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
#define LANES_COUNT 16
#define MAX_OBJECTS_PER_LANE 5

#define TIME_MICROSECONDS 10000

#if !defined(PC) && !defined(RPI)
    #define PC
#endif

#if defined(PC)
    #define LANE_X_PIXELS (TOTAL_WIDTH)
    #define LANE_Y_PIXELS ((int32_t)REZISE(NORMAL_SIZE * LANES_COUNT))
    #define MS_RANITA_MOVEMENT_COOLDOWN 20
    #define MS_BASE_OBJECT_SPEED 30
    #define TIME_PER_LEVEL_MS 30000
#elif defined(RPI)
    #define LANE_X_PIXELS 12
    #define LANE_Y_PIXELS 16
    #define MS_RANITA_MOVEMENT_COOLDOWN 100

#else
    #error "No platform defined"
#endif



#define LANE_PIXEL_HEIGHT (LANE_Y_PIXELS/LANES_COUNT)

#endif
