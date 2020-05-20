#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesServicios.h"

void mostrarServicios(eServicio servicios[], int tamServ){
    system("cls");
    printf("\n************ Servicios ************\n\n");
    printf("Id   Servicio\n");

    for(int i=0; i<tamServ; i++){
    printf("%d  %10s    \n",servicios[i].id, servicios[i].descripcion);

    }
    printf("\n");
}

int buscarServicio(int id, eServicio vec[], int tam){
    int indice=-1;
    for(int i=0; i<tam; i++){
        if(vec[i].id==id){
            indice=i;
            break;
        }
    }
    return indice;
}
