#ifndef FUNCIONESCOLORES_H_INCLUDED
#define FUNCIONESCOLORES_H_INCLUDED

typedef struct{
int id;
char nombreColor[20];
}eColor;

#endif // FUNCIONESCOLORES_H_INCLUDED

void mostrarColores(eColor colores[], int tamCol);
