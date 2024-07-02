#include "../driv/disdrv.h"
#include "../driv/joydrv.h"
#include "../audio/audio.h"
//#include <SDL2/SDL.h>

void inicialization (void){
    joy_init();

    disp_init();
    disp_clear();
    disp_update();

    if(initAudio() == NO_INIT){
        fprintf(stderr, "Audio not initialized.\n");
        endAudio();
    }


}