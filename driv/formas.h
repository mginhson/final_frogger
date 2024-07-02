#ifndef FORMAS_H
#define FORMAS_H

// Defino macro para acceder a las funciones del array.
#define LETTER(X) (X - 'A')
#define NUMBER(X) (X - '0')

void verticalLine (int n, dcoord_t coord);
void horizontalLine (int n, dcoord_t coord);
void horizontalLineOff (int n, dcoord_t coord);

void letterA(dcoord_t coord);
void letterB(dcoord_t coord);
void letterC(dcoord_t coord);
void letterD(dcoord_t coord);
void letterE(dcoord_t coord);
void letterF(dcoord_t coord);
void letterG(dcoord_t coord);
void letterH(dcoord_t coord);
void letterI(dcoord_t coord);
void letterJ(dcoord_t coord);
void letterK(dcoord_t coord);
void letterL(dcoord_t coord);
void letterM(dcoord_t coord);
void letterN(dcoord_t coord);
void letterO(dcoord_t coord);
void letterP(dcoord_t coord);
void letterQ(dcoord_t coord);
void letterR(dcoord_t coord);
void letterS(dcoord_t coord);
void letterT(dcoord_t coord);
void letterU(dcoord_t coord);
void letterV(dcoord_t coord);
void letterW(dcoord_t coord);
void letterX(dcoord_t coord);
void letterY(dcoord_t coord);
void letterZ(dcoord_t coord);


void numb1(dcoord_t coord);
void numb2(dcoord_t coord);
void numb3(dcoord_t coord);
void numb4(dcoord_t coord);
void numb5(dcoord_t coord);
void numb6(dcoord_t coord);
void numb7(dcoord_t coord);
void numb8(dcoord_t coord);
void numb9(dcoord_t coord);
void numb0(dcoord_t coord);

void emptyHeart (dcoord_t coord);
void fullHeart (dcoord_t coord);


// Hago un typedef para crear un arreglo con las funciones correspondientes a cada letra. 



typedef void (*function_t) (dcoord_t);

extern function_t funLetter[26];
extern function_t funNumb[10];

#endif