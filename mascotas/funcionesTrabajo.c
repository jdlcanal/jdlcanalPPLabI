#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesTrabajo.h"

void inicializarTrabajos(eTrabajo trabajos[], int tamTrabajos){
    for(int i=0;i<tamTrabajos;i++){
        trabajos[i].isEmpty=1;
    }

}

int buscarLibreTrabajo(eTrabajo trabajo[], int tam){
    int indice=-1;

    for(int i=0; i<tam; i++){
        if(trabajo[i].isEmpty){
            indice=i;
            break;
        }
    }
    return indice;
}

void altaTrabajo(int id, eTrabajo trabajo[], int tamTrabajo, eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eServicio servicios[], int tamServ, eCliente cliente[], int tamCliente){
    int indice;
    int idMascota;
    int idServicio;
    eTrabajo auxTrabajo;

    mostrarMascotas(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
    printf("\nElegir una Mascota: ");
    scanf("%d", &idMascota);
    indice=buscarMascota(idMascota, mascotas, tam);

    if(indice==-1){
       printf("\nEl id (%d) que ingreso no existe\n",idMascota);
    }
    else{
        mostrarMascota(mascotas[indice], tipos, tamTipos, colores, tamCol, cliente, tamCliente);

        printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);

        mostrarServicios(servicios, tamServ);
        printf("\nElegir un Servicio: ");
        scanf("%d", &idServicio);
        indice=buscarServicio(idServicio, servicios, tamServ);


        if(indice==-1){
            printf("\nEl id (%d) que ingreso no existe\n",idServicio);
        }
        else{
            auxTrabajo.idMascota=idMascota;
            auxTrabajo.idServicio=idServicio;
            auxTrabajo.id=id;
            auxTrabajo.isEmpty=0;
            indice=buscarLibreTrabajo(trabajo, tamTrabajo);
            trabajo[indice]=auxTrabajo;
            printf("\nEl Trabajo ha sido cargado con exito!!!\n\n");
        }
    }
}

void mostrarTrabjo(eTrabajo trabajo, eMascota mascota[], int tam, eServicio servicio[], int tamServ){
    char nombreMascota[20];
    char descripcionServicio[20];
    int precioServicio;

    cargarDescripcionMascota(nombreMascota,trabajo.idMascota,mascota,tam);
    precioServicio=cargarDescripcionServicio(descripcionServicio,trabajo.idServicio,servicio,tamServ);

    printf("%d     %d %10s  %6s  %3d    %02d/%02d/%4d\n",trabajo.id,trabajo.idMascota,nombreMascota,descripcionServicio,precioServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos, eMascota mascota[], int tam, eServicio servicio[], int tamServ){
    system("cls");
    printf("\n************ Trabajos ************\n\n");
    printf("Id IdMascota  Mascota   Servicio  Precio   Fecha Ingreso\n");

    for(int i=0; i<tamTrabajos; i++){
        if(trabajos[i].isEmpty==0){
            mostrarTrabjo(trabajos[i],mascota,tam,servicio,tamServ);
        }
    }
    printf("\n");
}

void cargarDescripcionMascota(char descripcion[], int id, eMascota mascota[], int tam){
    for(int i=0; i<tam; i++){
        if(mascota[i].id==id){
            strcpy(descripcion, mascota[i].nombre);
        }
    }
}

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicio[], int tam){
    int precio;

    for(int i=0; i<tam; i++){
        if(servicio[i].id==id){
            strcpy(descripcion, servicio[i].descripcion);
            precio=servicio[i].precio;
        }
    }
    return precio;
}
