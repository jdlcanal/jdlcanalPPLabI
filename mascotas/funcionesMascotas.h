#include "funcionesColores.h"
#include "funcionesTipos.h"

#ifndef FUNCIONESMASCOTAS_H_INCLUDED
#define FUNCIONESMASCOTAS_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

typedef struct{
int id;
char nombre[20];
int idTipo;
int idColor;
int edad;
eFecha fechaIngreso;
int isEmpty;
int idCliente;
}eMascota;

typedef struct{
int id;
char nombre[20];
char sexo;
int isEmpty;
}eCliente;


#endif // FUNCIONESMASCOTAS_H_INCLUDED

void inicializarMascotas(eMascota mascotas[], int tam);
int buscarLibre(eMascota mascotas[], int tam);
void mostrarMascota(eMascota mascotas, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);
void mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);
void cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam);
void cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam);
int altaMascota(int id, eMascota mascota[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipos, eCliente cliente[], int tamCliente, int idCliente);
void modificarMenu(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente);
void modificarTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente);
void modificarEdad(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente);
void bajaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente);
int buscarMascota(int id, eMascota vec[], int tam);
void inicializarClientes(eCliente cliente[], int tam);
int buscarLibreCliente(eCliente cliente[], int tam);
void cargarDescripcionCliente(char descripcion[], int id, eCliente cliente[], int tamCliente);
