#ifndef FUNCIONESTIPOS_H_INCLUDED
#define FUNCIONESTIPOS_H_INCLUDED

typedef struct{
int id;
char descripcion[20];
}eTipo;


#endif // FUNCIONESTIPOS_H_INCLUDED

void mostrarTipos(eTipo tipos[], int tamTipos);

