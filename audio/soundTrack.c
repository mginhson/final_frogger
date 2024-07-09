#include <SDL2/SDL.h>
#include "audio.h"
#include "soundTrack.h"

#define STEP "audio/src/step.wav"
#define LIFE "audio/src/looseLife.wav"
#define TIME "audio/src/runningOutOfTime.wav"
#define LEVEL "audio/src/nextLevel.wav"
#define MUSIC "audio/src/music.wav"

void music (void){
    playMusic(MUSIC, SDL_MIX_MAXVOLUME /10 * 7);
}
void levelSound (void){
    playSound(LEVEL, SDL_MIX_MAXVOLUME);
}
void timeSound (void){
    playSound(TIME, SDL_MIX_MAXVOLUME);
}
void lifeSound (void){
    playSound(LIFE, SDL_MIX_MAXVOLUME);
}
void stepSound (void){
    playSound(STEP, SDL_MIX_MAXVOLUME);
}