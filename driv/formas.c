#include "disdrv.h"
#include "formas.h"
void verticalLine (int n, dcoord_t coord);
void horizontalLine (int n, dcoord_t coord);

function_t funNumb[10] = {numb0, numb1, numb2, numb3, numb4, numb5, numb6, numb7, numb8, numb9};

function_t funLetter [26] = {letterA, letterB, letterC, letterD, letterE, letterF, letterG, letterH, letterI, letterJ,
                       letterK, letterL, letterM, letterN, letterO, letterP, letterQ, letterR, letterS, letterT,
                       letterU, letterV, letterW, letterX, letterY, letterZ};

void letterA(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(5, coord);
    coord.y += 2;
    horizontalLine(3, coord);
    coord.y += 2;
    horizontalLine(3, coord);
    disp_update();
}
void letterB(dcoord_t coord){
    dcoord_t aux = coord;
    aux.y += 4;
    verticalLine(5, coord);
    coord.x --;
    aux.x --;
    disp_write(coord, D_ON);
    disp_write(aux, D_ON);
    coord.y++;
    coord.x--;
    aux.y--;
    aux.x--;
    disp_write(coord, D_ON);
    disp_write(aux, D_ON);
    coord.x++;
    coord.y++;
    disp_write(coord, D_ON);

    disp_update();
}
void letterC(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -=2;
    horizontalLine(2, coord);
    coord.y +=4;
    horizontalLine(2, coord);
    disp_update();
}
void letterD(dcoord_t coord){
    verticalLine(5, coord);
    coord.x--;
    disp_write(coord, D_ON);
    coord.y+=4;
    disp_write(coord, D_ON);
    coord.y-=3;
    coord.x--;
    verticalLine(3, coord);
    disp_update();
}
void letterE(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    horizontalLine(2, coord);
    coord.y +=2;
    horizontalLine(2, coord);
    coord.y +=2;
    horizontalLine(2, coord);

    disp_update();
}
void letterF(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    coord.y +=2;
    horizontalLine(2, coord);
    coord.y +=2;
    horizontalLine(2, coord);
    disp_update();
}
void letterG(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    horizontalLine(2, coord);
    verticalLine(3, coord);
    coord.y +=4;
    horizontalLine(2, coord); 
// PUEDO BORRAR LO QUE SIGUE PARA HACERLA MÁS DIFERENTE A UN 6
// ************************* //
    // coord.x++;
    // coord.y-=2;
    // disp_write(coord, D_ON);
// ************************* //
    disp_update();
}
void letterH(dcoord_t coord){
    verticalLine(5, coord);
    coord.x-=2;
    verticalLine(5, coord);
    coord.y+=2;
    horizontalLine(3, coord);
    disp_update();
}
void letterI(dcoord_t coord){
    coord.x--;
    verticalLine(5, coord);
    // coord.x--;
    // horizontalLine(3, coord);
    // coord.y+=4;
    // horizontalLine(3, coord);
    disp_update();
}
void letterJ(dcoord_t coord){
    coord.x--;
    verticalLine(5, coord);
    horizontalLine(2, coord);
    coord.x--;
    coord.y+=4;
    horizontalLine(3, coord);
    disp_update();
}
void letterK(dcoord_t coord){
    verticalLine(5, coord);
    coord.x-=2;
    verticalLine(5, coord);
    coord.y+=2;
    disp_write(coord, D_OFF);
    coord.x++;
    disp_write(coord, D_ON);
    disp_update();
}
void letterL(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    horizontalLine(2, coord);
    disp_update();
}
void letterM(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(5, coord);
    coord.x++;
    coord.y += 3;
    disp_write(coord, D_ON);
    disp_update();
}
void letterN(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(4, coord);
    coord.x ++;
    coord.y+=4;
    disp_write(coord, D_ON);
   
    disp_update();
}
void letterO(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(5, coord);
    horizontalLine(3, coord);
    coord.y += 4; 
    horizontalLine(3, coord);
    disp_update();
}
void letterP(dcoord_t coord){
     verticalLine(5, coord);
     coord.x -= 2;
     coord.y += 2;
     horizontalLine(3, coord);
     coord.y++;
     disp_write(coord, D_ON);
     coord.y++;
     horizontalLine(3, coord);
     disp_update();
}
void letterQ(dcoord_t coord){
    coord.x -= 2;
    verticalLine(5, coord);
    coord.y ++;
    coord.x ++;
    disp_write(coord, D_ON);
    coord.y+=3;
    disp_write(coord, D_ON);
    coord.y-=3;
    coord.x++;
    verticalLine(4, coord);
    disp_update();    
}
void letterR(dcoord_t coord){
     verticalLine(5, coord);
     coord.x-=2;
     verticalLine(5, coord);
     coord.y+=2;
     disp_write(coord, D_OFF);
     coord.x++;
     disp_write(coord, D_ON);
     coord.y+=2;
     disp_write(coord, D_ON);
     disp_update();
}
void letterS(dcoord_t coord){
    verticalLine(5, coord);
    coord.x--;
    verticalLine(5, coord);
    coord.x--;
    verticalLine(5, coord);
    disp_write(coord, D_OFF);
    coord.y+=2;
    disp_write(coord, D_OFF);
    coord.y++;
    disp_write(coord, D_OFF);
    coord.x++;
    disp_write(coord, D_OFF);
    coord.y-=2;
    disp_write(coord, D_OFF);
    coord.x++;
    disp_write(coord, D_OFF);
    coord.y++;
    disp_write(coord, D_OFF);
    coord.y+=2;
    disp_write(coord, D_OFF);
    disp_update();
}
void letterT(dcoord_t coord){
    coord.x --;
    verticalLine(5, coord);
    coord.x--;
    coord.y+=4;
    horizontalLine(3, coord);
    disp_update();
}
void letterU(dcoord_t coord){
    verticalLine(5, coord);
    coord.x--;
    disp_write(coord, D_ON);
    coord.x--;
    verticalLine(5, coord);
    disp_update();
}
void letterV(dcoord_t coord){
    coord.y++;
    verticalLine(4, coord);
    coord.x -= 2;
    verticalLine(4, coord);
    coord.x++;
    coord.y--;
    disp_write(coord, D_ON);
    disp_update();
}
void letterW(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(5, coord);
    coord.x++;
    coord.y ++;
    disp_write(coord, D_ON);
    disp_update();
}
void letterX(dcoord_t coord){
    verticalLine(5, coord);
    coord.x-=2;
    verticalLine(5, coord);
    coord.y+=2;
    disp_write(coord, D_OFF);
    coord.x++;
    disp_write(coord, D_ON);
    coord.x++;
    disp_write(coord, D_OFF);
    disp_update();
}
void letterY(dcoord_t coord){
    coord.x--;
    verticalLine(4, coord);
    coord.y+=4;
    coord.x--;
    disp_write(coord, D_ON);
    coord.x+=2;
    disp_write(coord, D_ON);
    disp_update();
}
void letterZ(dcoord_t coord){
    coord.x-=2;
    horizontalLine(3, coord);
    coord.y+=3;
    disp_write(coord, D_ON);
    coord.y++;
    horizontalLine(3, coord);
    coord.x++;
    coord.y-=2;
    disp_write(coord, D_ON);
    coord.x++;
    coord.y--;
    disp_write(coord, D_ON);
    disp_update();
}
void numb1(dcoord_t coord){
    coord.x--;
    verticalLine(5, coord);
    coord.x--;
    horizontalLine(3, coord);
    coord.x += 2;
    coord.y +=3;
    disp_write(coord, D_ON);
    disp_update();
}
void numb2(dcoord_t coord){
    disp_write(coord, D_ON);
    coord.y++;
    disp_write(coord, D_ON);
    coord.y+=2;
    disp_write(coord, D_ON);
    coord.y++;
    coord.x--;
    disp_write(coord, D_ON);
    coord.y-=2;
    disp_write(coord, D_ON);
    coord.y-=2;
    disp_write(coord, D_ON);
    coord.x--;
    disp_write(coord, D_ON);
    coord.y+=3;
    disp_write(coord, D_ON);
    disp_update();
}
void numb3(dcoord_t coord){
    disp_write(coord, D_ON);
    coord.y+=4;
    disp_write(coord, D_ON);
    coord.x--;
    disp_write(coord, D_ON);
    coord.y-=2;
    disp_write(coord, D_ON);
    coord.y-=2;
    disp_write(coord, D_ON);
    coord.x--;
    coord.y++;
    disp_write(coord, D_ON);
    coord.y+=2;
    disp_write(coord, D_ON);
    disp_update();
}
void numb4 (dcoord_t coord){
    coord.y+=2;
    verticalLine(3, coord);
    coord.x -= 2;
    horizontalLine(3, coord);
    coord.y-=2;
    verticalLine(5, coord);
    disp_update();
}
void numb5 (dcoord_t coord){
    verticalLine(5, coord);
    coord.x--;
    verticalLine(5, coord);
    coord.x--;
    verticalLine(5, coord);
    coord.y+=3;
    disp_write(coord, D_OFF);
    coord.x++;
    disp_write(coord, D_OFF);
    coord.y-=2;
     disp_write(coord, D_OFF);
    coord.x++;
    disp_write(coord, D_OFF);
    disp_update();
}
void numb6(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    horizontalLine(2, coord);
    verticalLine(3, coord);
    coord.y +=4;
    horizontalLine(2, coord); 

    coord.x++;
    coord.y-=2;
    disp_write(coord, D_ON);
    disp_update();
}
void numb7(dcoord_t coord){
    coord.x -= 2;
    verticalLine(5, coord);
    coord.y+=2;
    horizontalLine(3, coord);
    coord.y+=2;
    horizontalLine(3, coord);
    disp_update();
}
void numb8(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(5, coord);
    horizontalLine(3, coord);
    coord.y += 2; 
    horizontalLine(3, coord);
    coord.y += 2; 
    horizontalLine(3, coord);
    disp_update();
}
void numb9(dcoord_t coord){
    coord.y+=2;
    verticalLine(3 ,coord);
    coord.y-=2;
    coord.x -= 2;
    verticalLine(5, coord);
    coord.y+=2;
    horizontalLine(3, coord);
    coord.y+=2;
    horizontalLine(3, coord);
    disp_update();
}
void numb0(dcoord_t coord){
    verticalLine(5, coord);
    coord.x -= 2;
    verticalLine(5, coord);
    horizontalLine(3, coord);
    coord.y += 4; 
    horizontalLine(3, coord);
    disp_update();
}
void verticalLine (int n, dcoord_t coord){
	for(int i = 0; i < n; i++){
		disp_write(coord, D_ON);
        coord.y++;
	}
}
void horizontalLine (int n, dcoord_t coord){
	for(int i = 0; i < n; i++){
		disp_write(coord, D_ON);
        coord.x++;
	}
}

void horizontalLineOff (int n, dcoord_t coord){
	for(int i = 0; i < n; i++){
		disp_write(coord, D_OFF);
        coord.x++;
	}
}

void emptyHeart (dcoord_t coord){
    coord.y+=2;
    disp_write(coord, D_ON);
    coord.y++;
    disp_write(coord, D_ON);
    coord.y++;
    coord.x --;
    disp_write(coord, D_ON);
    coord.y-=3;
    disp_write(coord, D_ON);
    coord.y--;
    coord.x--;
    disp_write(coord, D_ON);
    coord.y+=3;
    disp_write(coord, D_ON);
    coord.y++;
    coord.x--;
    disp_write(coord, D_ON);
    coord.y-=3;
    disp_write(coord, D_ON);
    coord.x--;
    coord.y++;
    disp_write(coord, D_ON);
    coord.y++;
    disp_write(coord, D_ON);
    disp_update();
}

void fullHeart (dcoord_t coord){
    coord.y+=2;
    verticalLine(2, coord);
    coord.y--;
    coord.x--;
    verticalLine(4, coord);
    coord.y--;
    coord.x--;
    verticalLine(4, coord);
    coord.y++;
    coord.x--;
    verticalLine(4, coord);
    coord.x--;
    coord.y++;
    verticalLine(2, coord);
    disp_update();
}