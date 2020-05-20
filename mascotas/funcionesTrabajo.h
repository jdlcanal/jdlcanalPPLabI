#include "funcionesMascotas.h"
#include "funcionesServicios.h"

#ifndef FUNCIONESTRABAJO_H_INCLUDED
#define FUNCIONESTRABAJO_H_INCLUDED


typedef struct{
int id;
int idMascota;
int idServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;


#endif // FUNCIONESTRABAJO_H_INCLUDED

void altaTrabajo(int id, eTrabajo trabajo[], int tamTrabajo, eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eServicio servicios[], int tamServ,eCliente cliente[], int tamCliente);
void mostrarTrabjo(eTrabajo trabajo, eMascota mascota[], int tam, eServicio servicio[], int tamServ);
void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos, eMascota mascota[], int tam, eServicio servicio[], int tamServ);
void cargarDescripcionMascota(char descripcion[], int id, eMascota mascota[], int tam);
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicio[], int tam);
void inicializarTrabajos(eTrabajo trabajos[], int tamTrabajos);
int buscarLibreTrabajo(eTrabajo trabajo[], int tam);
