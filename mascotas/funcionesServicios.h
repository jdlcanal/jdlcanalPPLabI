#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

typedef struct{
int id;
char descripcion[25];
int precio;
}eServicio;


#endif // FUNCIONESSERVICIOS_H_INCLUDED

void mostrarServicios(eServicio servicios[], int tamServ);
int buscarServicio(int id, eServicio vec[], int tam);
