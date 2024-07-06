#define STEP "../../audio/src/step.wav"
#define LIFE "../../audio/src/looseLife.wav"
#define TIME "../../audio/src/runningOutOfTime.wav"
#define LEVEL "../../audio/src/nextLevel.wav"
#define MUSIC "../../audio/src/music.wav"

#include "../init.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "soundTrack.h"

#define STEP "../../audio/src/step.wav"
#define LIFE "../../audio/src/looseLife.wav"
#define TIME "../../audio/src/runningOutOfTime.wav"
#define LEVEL "../../audio/src/nextLevel.wav"
#define MUSIC "../../audio/src/music.wav"

void load_sounds(void){
    general_information.audios[0] = al_load_sample(STEP);
    general_information.audios[1] = al_load_sample(LIFE);
    general_information.audios[2] = al_load_sample(TIME);
    general_information.audios[3] = al_load_sample(LEVEL);
    general_information.audios[4] = al_load_sample(MUSIC);

    general_information.song = al_create_sample_instance(general_information.audios[4]);
    al_set_sample_instance_playmode(general_information.audios[4], ALLEGRO_PLAYMODE_LOOP);
    al_reserve_samples(MAX_AUDIOS);
    al_attach_sample_instance_to_mixer(general_information.song, al_get_default_mixer());
    al_play_sample_instance(general_information.song);
    return;
}
void destroy_sounds(void){
    int i;
    for (i = 0; i < MAX_AUDIOS; i++){
        al_destroy_audio(general_information.audios[i]);
    }
    al_destroy_sample_instance(general_information.song);
    return;
}
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