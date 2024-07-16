#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "game_logic.h"
#include "../entities/entities.h"
#if defined(PC)
    #include "../allegro/audio/soundTrack.h"
    #include "../allegro/input/input.h"
    #include "../allegro/render.h"
   // #include "../allegro/animation.h"
    #include "../allegro/assets.h"
    #include "../allegro/onceDead.h"
#elif defined(RPI)
    #include "../input/input.h"
    #include "../finalAnimation/looseLife.h"
    #include "../finalAnimation/final.h"
    #include "../audio/soundTrack.h"
    #include "../mundo/renderWorld.h"

#else
    #error "No Platform Defined!"
#endif



static void updateMap(void);
static const object_kind_t * collisionAnalysis(void);
static void resetRanitaPosition(void);
static int32_t currentLane(void);

static uint32_t pasosAtras = 0;

typedef enum{RANITA_UP,RANITA_DOWN,RANITA_LEFT,RANITA_RIGHT}ranita_logic_direction_t;
static void triggerRanitaMovement(ranita_logic_direction_t _direction);
static char * intToString (int puntos);


static uint32_t remainingLives = 3;
static map_t map;
static uint32_t level;
static const uint32_t lane_bound = sizeof(map.lanes)/sizeof(map.lanes[0]);
static const uint32_t object_bound = sizeof(map.lanes[0].objects)/sizeof(map.lanes[0].objects[0]);
static int32_t time_left_on_level = TIME_PER_LEVEL_MS;
static uint32_t whichObjectCollisioned;


#if defined(PC)
    independent_object_t ranita = {
        .params = {
            .hitbox_width = REZISE(NORMAL_SIZE),
            .attr = {.canKill=0, .canMove=1, .isEquippable=0},
                    
        }, 
        .hitbox_height = REZISE(NORMAL_SIZE),
        .y_position = LANE_Y_PIXELS-1 - REZISE(NORMAL_SIZE) + 1,
        .values.position = 0,
        .values.state = alive
    };
#elif defined(RPI)
    independent_object_t ranita = {
    .params = {
        .hitbox_width = 1,
        .attr = {.canKill=0, .canMove=1, .isEquippable=0},
                
    }, 
    .hitbox_height = LANE_PIXEL_HEIGHT,
    .y_position = LANE_Y_PIXELS-1 - LANE_PIXEL_HEIGHT + 1,
    .values.position = 0,
    
};

#else 
    #error "No platform defined!"
#endif

static uint32_t pts = 0;


static const independent_object_t * iobjs[10] = {[0]=&ranita,NULL,NULL,NULL,NULL,NULL};




/*
    @BRIEF: gameTick
    -Check if the ranita moved
    -Check then for collisions  
    -Update the objects on the map
    -Check again for collisions
*/
int gameTick(int32_t ms_since_last_tick)
{
    uint32_t i,j;
    static int64_t ms_cooldown=MS_RANITA_MOVEMENT_COOLDOWN;
    int32_t start_object_x,end_object_x;
    const object_kind_t * collision ;

    ms_cooldown -= ms_since_last_tick;
    time_left_on_level -= ms_since_last_tick;
    
    if(time_left_on_level <= 0)
    {
        resetRanitaPosition();
        time_left_on_level = TIME_PER_LEVEL_MS;
        remainingLives--;

        
        
        looseLife(remainingLives);
        
        if(remainingLives == 0)
        {
            onceDead(intToString(pts), pts);
            
            return MENU;
        }
        resetRanitaPosition();
    }


    if(ms_cooldown <= 0) //we can check for movement again 
    {
        
        ms_cooldown = 0;
        dato_entrada a = input_reader();
       
        switch(a)
        {
            case _EMPTY:
                break;

            case _LEFT:
                
                triggerRanitaMovement(RANITA_LEFT);
                ms_cooldown = MS_RANITA_MOVEMENT_COOLDOWN;
                break;

            case _RIGHT:
                
                triggerRanitaMovement(RANITA_RIGHT);
                ms_cooldown = MS_RANITA_MOVEMENT_COOLDOWN;
                break;

            case _UP:
                
                triggerRanitaMovement(RANITA_UP);
                ms_cooldown = MS_RANITA_MOVEMENT_COOLDOWN;
                break;

            case _DOWN:
            
                triggerRanitaMovement(RANITA_DOWN);
                ms_cooldown = MS_RANITA_MOVEMENT_COOLDOWN;

                break;
                
            case _PAUSE:
                
                return PAUSAA;
                break;

            default:
                break;
        }
    }

    //Check for collisions after movement
    collision = collisionAnalysis();

    
    for(i=0; i < lane_bound; i++)
    {
        int32_t a = map.lanes[i].ms_to_next;
        map.lanes[i].ms_to_next = a - ms_since_last_tick;
        
        if(map.lanes[i].kind == &turtle_object_kind)
        {
            
            for(j=0; j<object_bound; j++)
            {
                
                map.lanes[i].objects[j].timer -= ms_since_last_tick;
                
                if(map.lanes[i].objects[j].timer <= 0)
                {
                    
                    map.lanes[i].objects[j].timer = map.lanes[i].ms_reload *10;
                    if(map.lanes[i].objects[j].canDisappear == 1)
                    {
                        
                        switch(map.lanes[i].objects[j].state)
                        {
                            case turtle_is_down:
                                map.lanes[i].objects[j].doesExist = 1;
                                map.lanes[i].objects[j].state = turtle_is_up;
                                map.lanes[i].objects[j].timer = map.lanes[i].ms_reload *100;
                                break;
                            case turtle_is_halfway:
                                map.lanes[i].objects[j].state = turtle_is_down;
                                map.lanes[i].objects[j].doesExist = 0;
                                map.lanes[i].objects[j].timer = map.lanes[i].ms_reload *60;
                                break;
                            case turtle_is_up:
                                map.lanes[i].objects[j].state = turtle_is_halfway;
                                map.lanes[i].objects[j].timer = map.lanes[i].ms_reload *30;
                                break;

                            default:
                                map.lanes[i].objects[j].state = turtle_is_up;
                                break;
                        }
                        
                    }
                } 
            }
        }
        
    
        if(map.lanes[i].ms_to_next <= 0) //Lane should move a pixel
        {
            map.lanes[i].flag = 1;
            while(map.lanes[i].ms_to_next <= 0)
                map.lanes[i].ms_to_next += map.lanes[i].ms_reload; //Reload the ms counter
            
            /*
                Now we will analyze if the object should move, and if it does, we have to check
                wether it went out of the lane bounds, and if so, reset it to the corresponding corner
                The .position attribute correspond to the leftmost side of an object.
            */
            
            if(map.lanes[i].kind == &empty_object) //No objects in the lane!!
            {
                continue;
            }
            for(j=0; j<object_bound; ++j)
            { 
                
                if(map.lanes[i].kind->attr.canMove == 0)
                {
                    continue;
                }   
                
                if(map.lanes[i].direction == RIGHT) //Move every object a pixel to the right
                {
                              
                    map.lanes[i].objects[j].position += 1;
                    
                    end_object_x = map.lanes[i].kind->hitbox_width - 1 + map.lanes[i].objects[j].position; //last pixel

                    if (end_object_x > map.lanes[i].virtual_lane_end)
                    {
                       
                        map.lanes[i].objects[j].position = map.lanes[i].virtual_lane_start;
                       
                    }
                }
                else //map.lanes[i].direction == LEFT
                {
                    map.lanes[i].objects[j].position -= 1;
                    
                    start_object_x = map.lanes[i].objects[j].position;
                    
                    if(start_object_x < map.lanes[i].virtual_lane_start)
                    {
                        
                        map.lanes[i].objects[j].position = map.lanes[i].virtual_lane_end - 1 - map.lanes[i].kind->hitbox_width;
                        
                    }
                }
               
            }
        }
        else
        {
            map.lanes[i].flag = 0;
        }
        
    }

    //If there had been a collision before, DON'T TEST AGAIN, because it could be overwritten
    if (collision == NULL) 
    {
        
        collision=collisionAnalysis();
        
    }
    
    //Now we analyze the collison
    if (collision != NULL && collision->attr.canKill && collision != &lilypad_object_kind)
    {
        
        if (--remainingLives == 0)
        {
            
            onceDead(intToString(pts), pts);
            
            return MENU;
        }
        else
        {
  
            
            looseLife(remainingLives);
            
            printf("Restando Vidas\n");
            
            resetRanitaPosition();
            time_left_on_level = TIME_PER_LEVEL_MS;
           // resetRanitaPosition();
        }
            
    }
    else if (collision == &turtle_object_kind|| collision == &small_log_object_kind || collision == &normal_log_object_kind || collision == &big_log_object_kind)
    {
        
        //Es un tronco
        
        if (map.lanes[ranita.y_position/LANE_PIXEL_HEIGHT].flag == 1)
        {
            if (map.lanes[ranita.y_position/LANE_PIXEL_HEIGHT].direction == RIGHT)
            {
                ranita.values.position += 1;
            }
            else
            {
                ranita.values.position-=1;
            }

            if(ranita.values.position < 0 || ranita.values.position+ranita.params.hitbox_width-1 >= LANE_X_PIXELS)
            {
                if(--remainingLives == 0)
                {
                    
                    onceDead(intToString(pts), pts);
                    
                    return MENU;
                }   
                else
                {
                    time_left_on_level = TIME_PER_LEVEL_MS;
                 
                    
                        looseLife(remainingLives);
                    
                    resetRanitaPosition();
                }
            }
        }   
        
    }
    else if(map.lanes[ranita.y_position / LANE_PIXEL_HEIGHT].background == water)
    {
        
        //Check if the ranita is on water!

        if(--remainingLives == 0)
        {
            
            onceDead(intToString(pts), pts);
            
            return MENU;
        }
        else
        {
            time_left_on_level = TIME_PER_LEVEL_MS;
           
            looseLife(remainingLives);
            
            resetRanitaPosition();
        }
    }
    else if(currentLane() == 0)
    {   
        if(collision != &lilypad_object_kind)
        {
             if(--remainingLives == 0)
            {
                
                onceDead(intToString(pts), pts);
                
                return MENU;
            }
            else
            {
                time_left_on_level = TIME_PER_LEVEL_MS;
                
                looseLife(remainingLives);
                
                
                resetRanitaPosition();
            }
        }
        else
        {
             
                
            if(map.lanes[0].objects[whichObjectCollisioned].doesExist == 1)
            {
                if(--remainingLives == 0)
                {
                    
                    onceDead(intToString(pts), pts);
                    
                    return MENU;
                }
                else
                {
                   
                    looseLife(remainingLives);
                    
                    resetRanitaPosition();
                    time_left_on_level = TIME_PER_LEVEL_MS;
                    
                }
            }
            else
            {
                map.lanes[0].objects[whichObjectCollisioned].doesExist = 1;
                int32_t check,z;
                for(z=0,check = 0; z < object_bound;z++)
                {
                    if (map.lanes[0].objects[z].doesExist == 0) 
                    {
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    updateMap();
                }
                else
                {
                    time_left_on_level = TIME_PER_LEVEL_MS;
                    resetRanitaPosition();
                }
                pts+=2;
            }
           
                
            
        }
        
    }
    else    //collision == NULL
    {
        
      //No collision, do nothing
    }
    
    
    renderWorld(&map, iobjs, 1, time_left_on_level, remainingLives, intToString(pts));
    

    
    return NONE;
}


/*
    @BRIEF: triggerRanitaMovement
        Updates the ranita based on keyboard/joystick movement
*/

static void triggerRanitaMovement(ranita_logic_direction_t _direction)
{
    //REMEMBER that the position is relative to the upper left corner
    int32_t temp, temp2;
    switch(_direction)
    {
        case RANITA_DOWN:            
            temp = ranita.y_position + ranita.hitbox_height - 1; //y position of the bottom
            //printf("%d %d\n",temp, temp+ranita.hitbox_height);
           
            if (temp + ranita.hitbox_height >= LANE_Y_PIXELS) //would go below map, set is as low as possible
            {
                ranita.y_position = LANE_Y_PIXELS  - 1 - ranita.hitbox_height + 1; //lowest pixel for the upper left corner
            }
            else
            {
                
                stepSound();
                
                ranita.y_position += ranita.hitbox_height;
                pasosAtras++;
            }
            break;


        case RANITA_UP:
            
            if (ranita.y_position  <= 0) //would go above map
            {
                ranita.y_position = 0;//uppermost pixel for the upper left corner
            }
            else
            {
                stepSound();
                
                ranita.y_position -= ranita.hitbox_height;
                if(pasosAtras == 0){
                    pts++;    
                }else{
                    pasosAtras--;
                }
                
            }

            break;


        case RANITA_LEFT:
            
            temp2 = ranita.values.position - ranita.params.hitbox_width;
            
            if (temp2 <= 0) //would go left from mapside
            {
                ranita.values.position = 0; //leftmost pixel for the upper left corner
            }
            else
            {
                
                    stepSound();
                
                ranita.values.position -= ranita.params.hitbox_width;
            }

            break;


        case RANITA_RIGHT:
            temp = ranita.values.position + ranita.params.hitbox_width - 1; //right corner uppermost pixel
            if((temp + ranita.params.hitbox_width) >= LANE_X_PIXELS) //would go right from mapside
            {
                ranita.values.position = LANE_X_PIXELS - ranita.params.hitbox_width;
            }
            else
            {
                
                stepSound();
                
                ranita.values.position+= ranita.params.hitbox_width;
            }
            break;

        default:
            printf("Unknown direction input at triggerRanitaMovement()\n");
            break;
    }
}



/*
    @BRIEF: collisionAnalysis
        Checks if the ranita collided with something that could kill her
        start_y->|------|
                 |      |
        end_y--->|------|
        start_x->        <--end_x 
*/
static const object_kind_t * collisionAnalysis(void)
{
    int32_t i,j,start_object_x,end_object_x,start_ranita_x,end_ranita_x,start_ranita_y,end_ranita_y;
    int32_t start_lane_y,end_lane_y;
   
    end_ranita_y = ranita.y_position + ranita.hitbox_height - 1;//Porque ranita.y_position ya tienen en cuenta el primer pixel
    
    start_ranita_y = ranita.y_position; 
    start_ranita_x = ranita.values.position;
    end_ranita_x = ranita.values.position + ranita.params.hitbox_width - 1; //Porque position tiene en cuenta el primer pixel
    end_ranita_y = ranita.y_position+ranita.hitbox_height-1;
   
    
    for(i=lane_bound-1;i>=0;i--)
    {
        if (map.lanes[i].kind == NULL || map.lanes[i].kind == &empty_object)
        {
            continue;
        }
        end_lane_y = (i+1)*LANE_PIXEL_HEIGHT - 1;
        start_lane_y = (i) * LANE_PIXEL_HEIGHT;
       
        //First,analyze if the ranita is on the y coordinate capable of interacting with the lane
        if  ((start_ranita_y>= start_lane_y\
            && start_ranita_y <= end_lane_y)\
            ||
            (end_ranita_y >= start_lane_y\
            && end_ranita_y <= end_lane_y))
        {

            for(j=0;j<object_bound;j++)
            {
                if (map.lanes[i].objects[j].doesExist == 0 && map.lanes[i].kind->lilyflag == 0) //Este objeto no existe en esta lane
                {
                    continue;
                }
                start_object_x = map.lanes[i].objects[j].position;
                end_object_x = map.lanes[i].objects[j].position + map.lanes[i].kind->hitbox_width - 1;
                
                
                if((start_ranita_x >= start_object_x && start_ranita_x <= end_object_x)\
                ||(end_ranita_x >= start_object_x && end_ranita_x <= end_object_x))
                {
                    whichObjectCollisioned = j;
                    return map.lanes[i].kind;
                }
                
            }
        }
    }
    //If no collision found, return NULLPTR
    
    return NULL;
}


static void updateMap(void)
{
    // pts += (10 * (level + 1));
    pts += (5 * (level + 1));
    animationLevel();
    
    fillMap(&map,++level);
    resetRanitaPosition();
    time_left_on_level = TIME_PER_LEVEL_MS;
    return ;
}

static void resetRanitaPosition(void)
{
    ranita.y_position = LANE_Y_PIXELS - 1 - ranita.hitbox_height + 1 ;
    ranita.values.position = (LANE_X_PIXELS-ranita.params.hitbox_width)/2;
    pasosAtras = 0;
}



void initializeGameLogic(void)
{
    pts = 0;
    srand(time(NULL));
    level = 0;
    remainingLives = 3;
    time_left_on_level = TIME_PER_LEVEL_MS;
    fillMap(&map,level);
    resetRanitaPosition();
    
}

static char * intToString (int puntos){
    int arr_alpha [3];
    static char arr_chars[4];// Cambie esto a 4
    int cont=0;
    int num_aux = puntos;
    if (puntos == 0){
        arr_chars[0] = '0';
        arr_chars[1] = '0';
        arr_chars[2] = '0';
    }
    for (int j = 0; num_aux > 0; j++){
        arr_alpha [j] = (num_aux%10);
        num_aux /= 10;
        cont++;
    }
    switch (cont){
        case 3:
            for (int k=0; k<cont; k++){
                arr_chars[k] = arr_alpha[cont-1-k] + '0';
            }
            break;
        case 2:
            arr_chars[0] = '0';
            for (int k=1; k<=cont; k++){
                arr_chars[k] = arr_alpha [cont-k] + '0';
            }
            break;
        case 1:
            arr_chars[0] = '0';
            arr_chars[1] = '0';
            arr_chars[2] = arr_alpha[0] + '0';
            break;
    }
    arr_chars[3] = '\0';
    return arr_chars;
}

static int32_t currentLane(void)
{
    int32_t i;
    int32_t start_lane_y,end_lane_y,start_ranita_y,end_ranita_y;
    
    
    start_ranita_y = ranita.y_position; 
    end_ranita_y = ranita.y_position+ranita.hitbox_height-1;

    
    for(i=lane_bound-1;i>=0;i--)
    {
        end_lane_y = (i+1)*LANE_PIXEL_HEIGHT - 1;
        start_lane_y = (i) * LANE_PIXEL_HEIGHT;
        
        if  ((start_ranita_y>= start_lane_y\
            && start_ranita_y <= end_lane_y)\
            ||
            (end_ranita_y >= start_lane_y\
            && end_ranita_y <= end_lane_y))
        {
            return i;
        }
    }
    return 0;
}