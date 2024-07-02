#ifndef RENDERWORLD_H
#define RENDERWORLD_H

#include "../entities/entities.h"
#include "../config.h"

void renderWorld (map_t * map, independent_object_t * frog[],int size ,int tiempo);
extern int contador;

enum contadorTiempo {noChanges, nextStep, restart};

#endif