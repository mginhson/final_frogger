#include "input.h"
#include "../driv/joydrv.h"

#define MODULO(x) ((x) > 0 ? (x): -(x))
#define RANGE 80
dato_entrada input_reader (void){
    joyinfo_t action = joy_read();
    
    if (action.sw == J_PRESS){
        return _PAUSE;
    }

    else if(action.x < - RANGE){
        if(action.y > 0){
            if (MODULO(action.x) >= MODULO(action.y)){
                return _RIGHT;
            }else{
                return _DOWN;
            }
        }else{
            if (MODULO(action.x) >= MODULO(action.y)){
                return _RIGHT;
            }else{
                return _UP;
            }
        }
    }else if(action.x > RANGE){
        if(action.y > 0){
            if (MODULO(action.x) >= MODULO(action.y)){
                return _LEFT;
            }else{
                return _DOWN;
            }
        }else{
            if (MODULO(action.x) >= MODULO(action.y)){
                return _LEFT;
            }else{
                return _UP;
            }
        }
    }else{
        if (action.y > RANGE){
            return _DOWN;
        }else if( action.y < - RANGE){
            return _UP;
        }else{
            return _EMPTY;
        }
        
    }
}