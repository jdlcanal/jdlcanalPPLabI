#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesMascotas.h"
#include "funcionesColores.h"
#include "funcionesTipos.h"
#include "funcionesServicios.h"
#include "funcionesTrabajo.h"


#define TAM 10
#define TAMTIPOS 5
#define TAMCOLORES 5
#define TAMSERVICIOS 3
#define TAMTRABAJOS 10
#define TAMCLIENTES 10

int menu();
void menuInformes(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);
void informarMascotaXColor(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);
void informarMascotaXTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);
void informarMascotaXTipoYColor(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);
void informarCantidadMascotasColorYTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente);


int main()
{
    char seguir='s';
    char confirm;
    int idProxMascota=1;
    int idProxTrabajo=1;
    int idProxCliente=1;
    int primeraVez=0;

    eMascota mascotas[TAM];
    eCliente cliente[TAMCLIENTES];
    eTrabajo trabajos[TAMTRABAJOS];
    eColor colores[TAMCOLORES]={{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eTipo tipos[TAMTIPOS]={{1000,"Ave"},{1001,"Perro"},{1002,"Gato"},{1003,"Roedor"},{1004,"Pez"}};
    eServicio servicios[TAMSERVICIOS]={{20000,"Corte",250},{20001,"Desparasitado",300},{20002,"Castrado",400}};

    inicializarMascotas(mascotas, TAM);
    inicializarTrabajos(trabajos, TAMTRABAJOS);
    inicializarClientes(cliente, TAMCLIENTES);

    do{
        switch(menu()){
    case 1:
        if(altaMascota(idProxMascota, mascotas, TAM, colores, TAMCOLORES, tipos, TAMTIPOS, cliente, TAMCLIENTES, idProxCliente)){
            idProxMascota++;
            idProxCliente++;
            primeraVez=1;
        }
        break;
    case 2:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            modificarMenu(mascotas, TAM, tipos, TAMTIPOS, colores, TAMCOLORES, cliente, TAMCLIENTES);
        }
        break;
    case 3:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            bajaMascota(mascotas,TAM,tipos,TAMTIPOS,colores,TAMCOLORES, cliente, TAMCLIENTES);
        }
        break;
    case 4:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            mostrarMascotas(mascotas, TAM, tipos, TAMTIPOS, colores, TAMCOLORES, cliente, TAMCLIENTES);
        }
        break;
    case 5:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            mostrarTipos(tipos, TAMTIPOS);
        }
        break;
    case 6:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            mostrarColores(colores, TAMCOLORES);
        }
        break;
    case 7:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            mostrarServicios(servicios, TAMSERVICIOS);
        }
        break;
    case 8:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            altaTrabajo(idProxTrabajo, trabajos, TAMTRABAJOS, mascotas, TAM, tipos, TAMTIPOS, colores, TAMCOLORES, servicios, TAMSERVICIOS, cliente, TAMCLIENTES);
            idProxTrabajo++;
        }
        break;
    case 9:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
            mostrarTrabajos(trabajos, TAMTRABAJOS, mascotas, TAM, servicios, TAMSERVICIOS);
        }
        break;
    case 10:
        if(primeraVez==0){
            printf("ERROR!!! Primero debes ingresar una mascota!!!\n\n");
        } else{
        menuInformes(mascotas,TAM,tipos,TAMTIPOS,colores,TAMCOLORES,cliente,TAMCLIENTES);
        }
        break;
    case 11:
        printf("Confirma Salida? s/n: ");
        fflush(stdin);
        scanf("%c", &confirm);
        if(confirm=='s'){
            seguir='n';
            }
        break;
        }
        system("pause");

    }while(seguir=='s');

    return 0;
}

int menu(){
    int opcion;
    system("cls");
    printf("*******Gestion de Mascotas*******\n\n");
    printf("1. Alta Mascota\n");
    printf("2. Modificar Mascota\n");
    printf("3. Baja Mascota\n");
    printf("4. Listar Mascotas\n");
    printf("5. Listar Tipos\n");
    printf("6. Listar Colores\n");
    printf("7. Listar Servicios\n");
    printf("8. Alta Trabajo\n");
    printf("9. Listar Trabajos\n");
    printf("10. Informes\n");
    printf("11.Salir\n\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void menuInformes(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente){
    char opcion;
    system("cls");
    printf("*******Informes*******\n\n");
    printf("a. Informar Mascota por Color\n");
    printf("b. Informar Mascota por Tipo\n");
    printf("c. Informar Mascota por Tipo Y Color\n");
    printf("d. Informar Cantidad de Mascotas por Tipo Y Color\n");
    printf("s. Salir\n\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    switch(opcion){
    case 'a':
        informarMascotaXColor(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        break;
    case 'b':
        informarMascotaXTipo(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        break;
    case 'c':
        informarMascotaXTipoYColor(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        break;
    case 'd':
        informarCantidadMascotasColorYTipo(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
    default :
        break;
    }

}

void informarMascotaXColor(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente){
    int color;
    int flag=0;

    system("cls");

    printf("************ Mascotas Por Color ************\n");
    mostrarColores(colores,tamCol);
    printf("Ingrese Color: ");
    scanf("%d", &color);

    for(int i=0; i<tam; i++){
        if(mascotas[i].isEmpty==0 && mascotas[i].idColor==color){
            mostrarMascota(mascotas[i], tipos, tamTipos,colores, tamCol, cliente, tamCliente);
            flag=1;
        }
        }
    if(flag==0){
        printf("\n*** No hay mascotas ***\n");
    }
    printf("\n\n");
}

void informarMascotaXTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente){
    int tipo;
    int flag=0;

    system("cls");

    printf("************ Mascotas Por Tipo ************\n");
    mostrarTipos(tipos,tamTipos);
    printf("Ingrese Tipo: ");
    scanf("%d", &tipo);

    for(int i=0; i<tam; i++){
        if(mascotas[i].isEmpty==0 && mascotas[i].idTipo==tipo){
            mostrarMascota(mascotas[i], tipos, tamTipos,colores, tamCol, cliente, tamCliente);
            flag=1;
        }
        }
    if(flag==0){
        printf("\n*** No hay mascotas ***\n");
    }
    printf("\n\n");

}

void informarMascotaXTipoYColor(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente){
    int tipo;
    int color;
    int flag=0;

    system("cls");

    printf("************ Mascotas Por Tipo y Color ************\n");
    mostrarTipos(tipos,tamTipos);
    printf("Ingrese Tipo: ");
    scanf("%d", &tipo);
    mostrarColores(colores,tamCol);
    printf("Ingrese Color: ");
    scanf("%d", &color);

    for(int i=0; i<tam; i++){
        if(mascotas[i].isEmpty==0 && mascotas[i].idTipo==tipo && mascotas[i].idColor==color){
            mostrarMascota(mascotas[i], tipos, tamTipos,colores, tamCol, cliente, tamCliente);
            flag=1;
        }
        }
    if(flag==0){
        printf("\n*** No hay mascotas ***\n");
    }
    printf("\n\n");

}

void informarCantidadMascotasColorYTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol,eCliente cliente[], int tamCliente){
    int tipo;
    int color;
    int cantidad=0;
    int flag=0;

    system("cls");

    printf("************ Cantidad de Mascotas Por Tipo y Color ************\n");
    mostrarTipos(tipos,tamTipos);
    printf("Ingrese Tipo: ");
    scanf("%d", &tipo);
    mostrarColores(colores,tamCol);
    printf("Ingrese Color: ");
    scanf("%d", &color);

    for(int i=0; i<tam; i++){
        if(mascotas[i].isEmpty==0 && mascotas[i].idTipo==tipo && mascotas[i].idColor==color){
            cantidad++;
            flag=1;
        }
        }
    if(flag==0){
        printf("\n*** No hay mascotas ***\n");
    }
    printf("Hay %d animales", cantidad);
    printf("\n\n");

}
