CC := gcc
CFLAGS := -Wall
DEFINE_ARGS := -D PC 
EXEC_NAME := frogger
MODULES :=onceDead.o High_scores.o menu_logic.o input.o game_logic.o frogger.o entities.o init.o assets.o menu.o util.o highscore.o text.o pause.o objects.o render.o soundTrack.o
ALLEGRO_INCLUDES := -lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec

all: pc

rpi: 
	-make -f Makefile_RPI clean
	make -f Makefile_RPI all
pc: ${MODULES}
	${CC} -o ${EXEC_NAME} ${MODULES} ${ALLEGRO_INCLUDES} ${CFLAGS} ${DEFINE_ARGS}

frogger.o: frogger.c game/game_logic.h
	${CC} -o frogger.o -c frogger.c ${CFLAGS} ${DEFINE_ARGS}

game_logic.o:  game/game_logic.c game/game_logic.h entities.o allegro/render.h
	${CC} -o game_logic.o -c game/game_logic.c	${DEFINE_ARGS} ${CFLAGS}

entities.o: entities/entities.c entities/entities.h config.h
	${CC} -o entities.o -c entities/entities.c ${CFLAGS} ${DEFINE_ARGS}
init.o: allegro/init.c allegro/init.h allegro/assets.h config.h
	gcc allegro/init.c -c ${DEFINE_ARGS}
assets.o: allegro/assets.c allegro/assets.h config.h
	gcc allegro/assets.c -c ${DEFINE_ARGS}
menu.o : allegro/menu.c allegro/init.h allegro/assets.h allegro/menu.h allegro/util.h allegro/components/text.h allegro/components/objects.h allegro/render.h config.h
	gcc allegro/menu.c -c ${DEFINE_ARGS}
util.o : allegro/util.c allegro/util.h allegro/init.h allegro/assets.h config.h
	gcc allegro/util.c -c ${DEFINE_ARGS}
text.o : allegro/components/text.c allegro/components/text.h allegro/init.h allegro/assets.h config.h
	gcc allegro/components/text.c -c ${DEFINE_ARGS}
highscore.o: allegro/highscore.c allegro/highscore.h allegro/components/text.h  allegro/init.h config.h allegro/util.h allegro/assets.h
	gcc allegro/highscore.c -c ${DEFINE_ARGS}
pause.o: allegro/pause.c allegro/pause.h allegro/components/text.h allegro/init.h config.h allegro/assets.h allegro/components/objects.h 
	gcc allegro/pause.c -c ${DEFINE_ARGS}
objects.o: allegro/components/objects.c  allegro/init.h allegro/assets.h allegro/components/objects.h config.h
	gcc allegro/components/objects.c -c ${DEFINE_ARGS}
render.o: allegro/render.c allegro/render.h entities/entities.h allegro/assets.h allegro/init.h config.h allegro/components/objects.h allegro/components/objects.h allegro/input/input.h allegro/audio/soundTrack.h
	gcc allegro/render.c -c ${DEFINE_ARGS}
input.o: allegro/input/input.c allegro/input/input.h allegro/init.h 
	gcc allegro/input/input.c -c ${DEFINE_ARGS}
soundTrack.o: allegro/audio/soundTrack.c allegro/audio/soundTrack.h allegro/init.h
	gcc allegro/audio/soundTrack.c -c ${DEFINE_ARGS}
menu_logic.o:config.h menu_logic/menu_logic.c allegro/menu.h allegro/highscore.h allegro/pause.h game/game_logic.h allegro/audio/soundTrack.h
	gcc menu_logic/menu_logic.c -c ${DEFINE_ARGS}
High_scores.o: highScores/High_scores.h highScores/High_scores.c allegro/highscore.h
	gcc -Wall -c highScores/High_scores.c ${DEFINE_ARGS}
onceDead.o: allegro/onceDead.c allegro/onceDead.h config.h allegro/assets.h allegro/components/text.h highScores/High_scores.h allegro/audio/soundTrack.h
	gcc -c allegro/onceDead.c ${DEFINE_ARGS}
clean:
	rm ${MODULES} ${EXEC_NAME} 
