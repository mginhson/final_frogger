#include <stdlib.h>
#include <stdio.h>
#include "High_scores.h"
#include <string.h>

void writing_top (char* str, int ptj){
    FILE* pfile;
    pfile = fopen ("highScores/top10.txt", "r+");
    if (pfile == NULL){
        printf ("There was an error opening the file. We will try to fix it as soon as possible!\n");
    }
    else{
        printf ("The file was succesfully opened\n");
    }
    bestPlayers_t top10 = reading_top();
    char arr_puntos [10][3];
    int i, j;
    for (i=0; i<10; i++){
        for (j=0; j<3; j++){
            arr_puntos [i][j] = *((top10.puntajes)[i]+j);
    }
    }
    int topscores [10];
    int num, t,k;
    for (t=0; t<10; t++){
        num = 0;
        for (k=0; k<3; k++){
            num = (num*10 + (arr_puntos[t][k] - '0'));
        }
        topscores [t] = num;
    }
    char arr_nombres [10][3];
    for (i=0; i<10; i++){
        for (j=0; j<3; j++){
            arr_nombres [i][j] = *((top10.name)[i]+j);
    }
    }
    if (ptj > topscores[9]){
        int s, pos = 0;
        for (s=0; ptj<topscores[s]; s++){
            pos++;
        }
        int a, aux2, aux1=ptj;
        for (a=pos; a<10; a++){
            aux2 = topscores[a];
            topscores[a] = aux1;
            aux1 = aux2;
        }
        char aux2_arr [3];
        char aux1_arr [3];
        for (i=0; i<3;i++){
            aux1_arr [i] = str[i];
        }
        for (a=pos; a<10; a++){
            for (s=0; s<3; s++){
                aux2_arr [s] = arr_nombres[a][s];
            }
            for (s=0; s<3; s++){
                arr_nombres [a][s] = aux1_arr[s];
            }
            for (s=0; s<3; s++){
                aux1_arr [s] = aux2_arr[s];
            }
        }
        char arr_topscores [10][3];
        int arr_alpha [3];
        for (i=0; i<10; i++){
            int cont=0;
            int num_aux = topscores [i];
            for (j=0; num_aux>0; j++){
                arr_alpha [j] = (num_aux%10);
                num_aux /= 10;
                cont++;
            }
            switch (cont){
                case 3:
                    for (k=0; k<cont; k++){
                        arr_topscores [i][k] = arr_alpha[cont-1-k] + '0';
                    }
                    break;
                case 2:
                    arr_topscores [i][0] = '0';
                    for (k=1; k<=cont; k++){
                        arr_topscores[i][k] = arr_alpha [cont-k] + '0';
                    }
                    break;
                case 1:
                    arr_topscores [i][0] = '0';
                    arr_topscores [i][1] = '0';
                    arr_topscores [i][2] = arr_alpha[0] + '0';
                    break;
                    case 0:
                    arr_topscores [i][0] = '0';
                    arr_topscores [i][1] = '0';
                    arr_topscores [i][2] = '0';
                    break;
            }
        }
        for (i=0; i<10; i++){
            for (j=0; j<3; j++){
                fputc (arr_nombres[i][j], pfile);
            }
            for (j=0; j<3; j++){
                fputc (arr_topscores[i][j], pfile);
            }
            fputs ("\n", pfile);
        }
    }
    fclose (pfile);
}




bestPlayers_t reading_top (void){
    FILE* pfile;
    pfile = fopen ("highScores/top10.txt", "r");
    if (pfile == NULL){
        printf ("There was an error opening the file. We will try to fix it as soon as possible!\n");
    }
    else{
        printf ("The file was succesfully opened\n");
    }
    bestPlayers_t top10;
    static char arr_top10 [100];
    memset(arr_top10, '\0', sizeof(arr_top10)/sizeof(*arr_top10));
    char c, i, j, k;
    for (i=0; (i< (sizeof(arr_top10)/sizeof*arr_top10)) && (c = fgetc (pfile))!= EOF ; i++){
        arr_top10[i] = c;
    }
    for (j=0; j<10; j++){
        (top10.name)[j] = &(arr_top10[j*7]);
    }
    for (k=0; k<10; k++){
        (top10.puntajes)[k] = &(arr_top10 [3 + k*7]);
    }
    fclose (pfile);

    return top10;
}