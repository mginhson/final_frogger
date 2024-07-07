#define STEP "../../audio/src/step.wav"
#define LIFE "../../audio/src/looseLife.wav"
#define TIME "../../audio/src/runningOutOfTime.wav"
#define LEVEL "../../audio/src/nextLevel.wav"
#define MUSIC "../../audio/src/music.wav"

#include "../init.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "soundTrack.h"

void levelSound (void){
    al_play_sample(general_information.audios[3],1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
    return;
}
void timeSound(void){
    al_play_sample(general_information.audios[2],1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
    return;
}
void lifeSound (void){
    al_play_sample(general_information.audios[1],1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
    return;
}
void stepSound (void){
    al_play_sample(general_information.audios[0],1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
    return;
}
void music (void){
    al_play_sample(general_information.audios[4], 1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
    return;
}