#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "entities.h"


const object_kind_t empty_object={
    .hitbox_width = 0,
};

const object_kind_t freeSlot;

const object_kind_t bus_object_kind = {
    .hitbox_width=REZISE(BIG_SIZE),
    .attr = {.canKill = 1, .isEquippable = 0, .canMove = 1},
};

const object_kind_t car_object_kind_v1 = {
    .hitbox_width=REZISE(NORMAL_SIZE),
    .attr = {.canKill = 1, .isEquippable = 0, .canMove = 1},
};
const object_kind_t car_object_kind_v2 = {
    .hitbox_width=REZISE(NORMAL_SIZE),
    .attr = {.canKill = 1, .isEquippable = 0, .canMove = 1},
};

const object_kind_t small_log_object_kind={
    .hitbox_width=REZISE(3* NORMAL_SIZE),
    .attr = {.canKill = 0, .isEquippable = 0, .canMove = 1},
};

const object_kind_t normal_log_object_kind = {
    .hitbox_width=REZISE(4 * NORMAL_SIZE),
    .attr = {.canKill = 0, .isEquippable = 0, .canMove = 1},
};

const object_kind_t big_log_object_kind = {
    .hitbox_width= REZISE(5 * NORMAL_SIZE),
    .attr = {.canKill = 0, .isEquippable = 0, .canMove = 1},
};

const object_kind_t snake_object_kind = {
    .hitbox_width=REZISE(BIG_SIZE),
    .attr = {.canKill = 1, .isEquippable = 0, .canMove = 1},
};

const object_kind_t lilypad_object_kind = {
    .hitbox_width=REZISE(NORMAL_SIZE),
    .attr = {.canKill = 1, .isEquippable = 0, .canMove = 0},
};



#if defined(PC)
    static const lane_t road_arquetypes[] = 
    {
        [0]=
        {
            .direction = RIGHT,
            .kind = &bus_object_kind,
            .background = road,
            .objects =
            {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            } 
        },
        [1]=
        {
            .direction = RIGHT,
            .kind = &car_object_kind_v1,
            .background = road,
            .objects =
            {
                [0]={.position=LANE_X_PIXELS*0.2,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.2,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.5,.doesExist=1}
            } 
        },
        [2]=
        {
            .direction = LEFT,
            .kind = &car_object_kind_v2,
            .background = road,
            .objects =
            {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            } 
        },
        [3]=
        {
            .direction = LEFT,
            .kind = &bus_object_kind,
            .background = road,
            .objects =
            {
                [0]={.position=LANE_X_PIXELS*0.2,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.6,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.8,.doesExist=1}
            } 
        },
        [4]=
        {
            .direction = RIGHT,
            .kind = &car_object_kind_v1,
            .background = road,
            .objects =
            {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.3,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.7,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            } 
        },
        [5]=
        {
            .direction = LEFT,
            .kind = &bus_object_kind,
            .background = road,
            .objects =
            {
                [0]={.position=LANE_X_PIXELS*0.3,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.7,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            } 
        },
    };

    static const lane_t water_arquetypes[] = {
        [0] = 
        {
            .direction = LEFT,
            .background = water,
            .kind = &normal_log_object_kind,
            .objects = {
                [0]={.position=LANE_X_PIXELS*0.1,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.75,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            }
        },
        [1] = 
        {
            .direction = LEFT,
            .background = water,
            .kind = &big_log_object_kind,
            .objects = {
                [0]={.position=-LANE_X_PIXELS * 0.5,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.6,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*1.2,.doesExist=1},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            }
        },
        [2] = 
        {
            .direction = LEFT,
            .background = water,
            .kind = &small_log_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.2,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.6,.doesExist=1}
            }
        },
        [3] = 
        {
            .direction = RIGHT,
            .background = water,
            .kind = &small_log_object_kind,
            .objects = {
                [0]={.position=-LANE_X_PIXELS*0.3,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.9,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            }
        },
        [4] = 
        {
            .direction = RIGHT,
            .background = water,
            .kind = &normal_log_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=-LANE_X_PIXELS*0.25,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*0.9,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.8,.doesExist=1}
            }
        },
        [5] = 
        {
            .direction = RIGHT,
            .background = water,
            .kind = &big_log_object_kind,
            .objects = {
                [0]={.position=-LANE_X_PIXELS*0.6,.doesExist=1},
                [1]={.position=-LANE_X_PIXELS*0.1,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=0},
                [3]={.position=LANE_X_PIXELS*1.6,.doesExist=1},
                [4]={.doesExist=0}
            }
        }
    };

    static const lane_t grass_arquetypes[] = 
    {
        [0] = 
        {
            .background = grass,
            .kind = &empty_object, //no enemies
            .objects = {
                [0]={.doesExist=0},
                [1]={.doesExist=0},
                [2]={.doesExist=0},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            }
        },
        [1] = 
        {
            
            .background = grass,
            .kind = &snake_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            }
        },
    };


    static const lane_t finish_line_arquetypes[] = 
    {
        [0] = 
        {
            .direction = RIGHT,
            .background = finish_line,
            .kind = &lilypad_object_kind, //why not lilypad here?
            .objects = {
                [0]={.position=REZISE(NORMAL_SIZE)*1,.doesExist=0,.lily_flag=1},
                [1]={.position=REZISE(NORMAL_SIZE)*3,.doesExist=0,.lily_flag=1},
                [2]={.position=REZISE(NORMAL_SIZE)*5,.doesExist=0,.lily_flag=1},
                [3]={.position=REZISE(NORMAL_SIZE)*7,.doesExist=0,.lily_flag=1},
                [4]={.position=REZISE(NORMAL_SIZE)*9,.doesExist=0,.lily_flag=1}
            }   
            
        }
    };
//________________________________________________________________
#elif defined(RPI)
static const lane_t road_arquetypes[] = 
    {
        [0]=
        {
            .direction = RIGHT,
            .kind = &bus_object_kind,
            .background = road,
            .objects =
            {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            } 
        },
        [1]=
        {
            .direction = RIGHT,
            .kind = &car_object_kind_v2,
            .background = road,
            .objects =
            {
                [0]={.position=LANE_X_PIXELS*0.2,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.2,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.5,.doesExist=1}
            } 
        },
        [2]=
        {
            .direction = LEFT,
            .kind = &car_object_kind_v1,
            .background = road,
            .objects =
            {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            } 
        },
        [3]=
        {
            .direction = LEFT,
            .kind = &bus_object_kind,
            .background = road,
            .objects =
            {
                [0]={.position=LANE_X_PIXELS*0.2,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.6,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.8,.doesExist=1}
            } 
        },
        [4]=
        {
            .direction = RIGHT,
            .kind = &car_object_kind_v1,
            .background = road,
            .objects =
            {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.3,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.7,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            } 
        },
        [5]=
        {
            .direction = LEFT,
            .kind = &bus_object_kind,
            .background = road,
            .objects =
            {
                [0]={.position=LANE_X_PIXELS*0.3,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.7,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            } 
        },
    };

    static const lane_t water_arquetypes[] = {
        [0] = 
        {
            .direction = LEFT,
            .background = water,
            .kind = &normal_log_object_kind,
            .objects = {
                [0]={.position=LANE_X_PIXELS*0.1,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.75,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [4]={.doesExist=0}
            }
        },
        [1] = 
        {
            .direction = LEFT,
            .background = water,
            .kind = &big_log_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.6,.doesExist=1},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            }
        },
        [2] = 
        {
            .direction = LEFT,
            .background = water,
            .kind = &small_log_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.2,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [4]={.position=LANE_X_PIXELS+1,.doesExist=1}
            }
        },
        [3] = 
        {
            .direction = RIGHT,
            .background = water,
            .kind = &small_log_object_kind,
            .objects = {
                [0]={.position=LANE_X_PIXELS*0.3,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.9,.doesExist=1},
                [3]={.position=LANE_X_PIXELS,    .doesExist=1},
                [4]={.position=0,                .doesExist=1}
            }
        },
        [4] = 
        {
            .direction = RIGHT,
            .background = water,
            .kind = &normal_log_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.25,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*0.9,.doesExist=1},
                [4]={.position=LANE_X_PIXELS*1.8,.doesExist=1}
            }
        },
        [5] = 
        {
            .direction = RIGHT,
            .background = water,
            .kind = &big_log_object_kind,
            .objects = {
                [0]={.position=LANE_X_PIXELS*0.25,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.4,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*0.8,.doesExist=1},
                [3]={.position=LANE_X_PIXELS*1.6,.doesExist=1},
                [4]={.doesExist=0}
            }
        }
    };

    static const lane_t grass_arquetypes[] = 
    {
        [0] = 
        {
            .background = grass,
            .kind = &empty_object, //no enemies
            .objects = {
                [0]={.doesExist=0},
                [1]={.doesExist=0},
                [2]={.doesExist=0},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            }
        },
        [1] = 
        {
            
            .background = grass,
            .kind = &snake_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=1},
                [1]={.position=LANE_X_PIXELS*0.5,.doesExist=1},
                [2]={.position=LANE_X_PIXELS*1.5,.doesExist=1},
                [3]={.doesExist=0},
                [4]={.doesExist=0}
            }
        },
    };


    static const lane_t finish_line_arquetypes[] = 
    {
        [0] = 
        {
            .direction = RIGHT,
            .background = finish_line,
            .kind = &lilypad_object_kind,
            .objects = {
                [0]={.position=0,.doesExist=0},
                [1]={.position=LANE_X_PIXELS*0.2,.doesExist=0},
                [2]={.position=LANE_X_PIXELS*0.4,.doesExist=0},
                [3]={.position=LANE_X_PIXELS*0.6,.doesExist=0},
                [4]={.position=LANE_X_PIXELS*0.8,.doesExist=0}
            }   
        }
    };
#endif

static const uint32_t water_arquetypes_elements = sizeof(water_arquetypes)/sizeof(*water_arquetypes);
static const uint32_t road_arquetypes_elements = sizeof(road_arquetypes)/sizeof(*road_arquetypes);
static const uint32_t grass_arquetypes_elements = sizeof(grass_arquetypes) / sizeof(*grass_arquetypes);
static const uint32_t finish_line_arquetypes_elements = sizeof(finish_line_arquetypes)/sizeof(*finish_line_arquetypes);


/*
    C is awesome
    1:09:35 explains why this syntax works
    https://www.youtube.com/watch?v=443UNeGrFoM&t=2328s&ab_channel=EskilSteenberg
*/
static const uint32_t lane_bound = sizeof(((map_t*)NULL)->lanes) /sizeof( *(((map_t*)NULL)->lanes));
static const uint32_t object_bound = sizeof(((lane_t*)NULL)->objects) / sizeof(((lane_t*)NULL)->objects[0]);
static void printLane(lane_t * _lane);



int32_t fillMap(map_t *_map, uint32_t _level)
{
    uint32_t i;
    static const uint32_t speeds[] = {MS_BASE_OBJECT_SPEED*0.3f,MS_BASE_OBJECT_SPEED*0.4f,
    MS_BASE_OBJECT_SPEED * 0.5f,MS_BASE_OBJECT_SPEED * 0.6f,MS_BASE_OBJECT_SPEED * 0.7f,
    MS_BASE_OBJECT_SPEED*0.8,MS_BASE_OBJECT_SPEED,MS_BASE_OBJECT_SPEED*1.2f};
    //printf("lane bound on fill map = %d\n",lane_bound);
    //printf("Available Arquetypes Element:\n\troad: %d\n\tgrass: %d\n\twater: %d\n\tfinish_line: %d\n\n"
    //,road_arquetypes_elements,grass_arquetypes_elements,water_arquetypes_elements,finish_line_arquetypes_elements);

    //Difficulty can be fine tuned here, by choosing harder arquetypes and modifying the .ms_reload
    for (i=0; i < lane_bound; i++)
    {

        switch(i)
        {
            case 0: //finish line
                _map->lanes[i] = finish_line_arquetypes[rand() % finish_line_arquetypes_elements];
                break;

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                _map->lanes[i] = water_arquetypes[rand() % water_arquetypes_elements];
                break;
            case 6:
            case 7:
                _map->lanes[i] = grass_arquetypes[rand() % grass_arquetypes_elements];
                #ifdef RPI
                    _map->lanes[i] = grass_arquetypes[0];
                #endif
                break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
                _map->lanes[i] = road_arquetypes[rand() % road_arquetypes_elements];
                break;
            case 14:
            case 15:
                _map->lanes[i] = grass_arquetypes[rand() % grass_arquetypes_elements];
                _map->lanes[i].kind = &empty_object; //Disable enemies on starting line
                break;
            default:
                printf("Couldn't find an arquetype for lane %d, defaulting to enemyless grass\n",i);
                _map->lanes[i] = grass_arquetypes[rand() % grass_arquetypes_elements];
                break;
        }
        _map->lanes[i].virtual_lane_start = -LANE_X_PIXELS;
        _map->lanes[i].ms_to_next= 10;
        _map->lanes[i].ms_reload = speeds[rand() % (sizeof(speeds)/sizeof(*speeds))] / (_level+1);
        _map->lanes[i].virtual_lane_end =LANE_X_PIXELS*2; //CAMBIAR ESTO, DEBERIA SER CONST Y PREDEFINIDO EN PATRON
    }
    //printMap(_map);
    return 0;
}


void printLaneObjects(lane_t *_lane,int32_t index)
{
    int32_t i;
    for (i=0;i<MAX_OBJECTS_PER_LANE;i++)
    {
        printf("lane[%d] object[%d]:\n\tposition = %d\n",index,i,_lane->objects[i].position);
    }
}


void printMap(map_t *_map,int32_t a)
{
    int32_t i,j;
    if(a) //print constant lane attributes
    {
        for(i=0; i < lane_bound;i++)
        {
            printf("Lane %d:\n",i);
            printLane(&(_map->lanes[i]));
            printf("\n");
        }
    }
    else //Print objects;
    {
        //printf("Map settings:\n\tLANE_X_PIXELS = %d\n\n",LANE_X_PIXELS);
        for(i=0; i < lane_bound;i++)
        {
            printf("Lane %d: direction = %d \n",i, _map->lanes[i].direction);
            for(j=0; j < object_bound;j++)
            {
                if(_map->lanes[i].objects[j].doesExist == 1)
                {
                    printf("\tObject %d: %d\n",j,_map->lanes[i].objects[j].position);
                }
            }
        }
    }
    
}


static void printLane(lane_t * _lane)
{
    static char * background_string[]=
    {[water] = "water",[road] = "road",[grass] = "grass",[finish_line]="finish_line"}; 
    
    printf("\tbackground: %s\n\t.kind points to %p\n",background_string[_lane->background],_lane->kind);
    
}



