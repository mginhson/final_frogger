#ifndef RENDERWORLD_H
#define RENDERWORLD_H

#include "../entities/entities.h"
#include "../config.h"

int renderWorld (map_t * map, const independent_object_t * frog[],int size ,int tiempo, int vidasRestantes);
extern int contador;

enum contadorTiempo {noChanges, nextStep, restart};

#endif