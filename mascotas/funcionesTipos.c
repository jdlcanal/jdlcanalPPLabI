#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesTipos.h"


void mostrarTipos(eTipo tipos[], int tamTipos){
    system("cls");
    printf("\n************ Tipos ************\n\n");
    printf("Id   Tipos\n");

    for(int i=0; i<tamTipos; i++){
    printf("%d  %10s    \n",tipos[i].id, tipos[i].descripcion);

    }
    printf("\n");
}

