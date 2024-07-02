#ifndef INPUT_H
#define INPUT_H

typedef enum {_EMPTY,  _LEFT, _RIGHT, _PAUSE, _UP, _DOWN}dato_entrada;
dato_entrada input_reader (void);

#endif