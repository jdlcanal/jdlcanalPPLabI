#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesColores.h"


void mostrarColores(eColor colores[], int tamCol){
    system("cls");
    printf("\n************ Colores ************\n\n");
    printf("Id   Color\n");

    for(int i=0; i<tamCol; i++){
    printf("%d  %10s    \n",colores[i].id, colores[i].nombreColor);

    }
    printf("\n");
}
