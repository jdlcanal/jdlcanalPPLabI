#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesMascotas.h"

void inicializarMascotas(eMascota mascotas[], int tam){
    for(int i=0;i<tam;i++){
        mascotas[i].isEmpty=1;
    }

}

void inicializarClientes(eCliente cliente[], int tam){
    for(int i=0;i<tam;i++){
        cliente[i].isEmpty=1;
    }

}

int buscarLibre(eMascota mascotas[], int tam){
    int indice=-1;

    for(int i=0; i<tam; i++){
        if(mascotas[i].isEmpty){
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarLibreCliente(eCliente cliente[], int tam){
    int indice=-1;

    for(int i=0; i<tam; i++){
        if(cliente[i].isEmpty){
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarMascota(eMascota mascotas, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente){
    char descripcionColores[20];
    char descripcionTipos[20];
    char nombreCliente[20];

    cargarDescripcionColor(descripcionColores, mascotas.idColor, colores, tamCol);
    cargarDescripcionTipo(descripcionTipos, mascotas.idTipo, tipos, tamTipos);
    cargarDescripcionCliente(nombreCliente, mascotas.idCliente, cliente, tamCliente);

    printf("%d %10s      %6s %6s %2d      %02d/%02d/%4d   %d    %10s  \n", mascotas.id, mascotas.nombre, descripcionTipos, descripcionColores, mascotas.edad, mascotas.fechaIngreso.dia,mascotas.fechaIngreso.mes,mascotas.fechaIngreso.anio,mascotas.idCliente,nombreCliente);


}

void mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente){
    eMascota auxMascota;
    system("cls");
    printf("\n************ Mascotas ************\n\n");
    printf("Id     Mascota    Tipo   Color  Edad  Fecha Ingreso  IdCliente  Cliente    \n");

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(mascotas[i].idTipo>mascotas[j].idTipo){
                auxMascota=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=auxMascota;
            }
            else if(mascotas[i].idTipo==mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre)>0){
                auxMascota=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=auxMascota;
            }
        }
    }

    for(int i=0; i<tam; i++){
        if(mascotas[i].isEmpty==0){
            mostrarMascota(mascotas[i], tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        }
    }
    printf("\n");
}

int altaMascota(int id, eMascota mascota[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipos, eCliente cliente[], int tamCliente, int idCliente){
    int todoOk=0;
    int indice=buscarLibre(mascota, tam);
    int indiceCliente=buscarLibreCliente(cliente, tamCliente);
    eMascota auxMascota;
    eCliente auxCliente;

    system("cls");
    printf("******* ALTA MASCOTA *******\n\n");

    if(indice==-1){
        printf("Sistema Completo\n\n");
        } else{
            auxMascota.id=id;
            auxMascota.idCliente=idCliente;
            auxCliente.id=idCliente;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxMascota.nombre);

            printf("Ingrese edad: ");
            scanf("%d", &auxMascota.edad);

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxMascota.fechaIngreso.dia,&auxMascota.fechaIngreso.mes,&auxMascota.fechaIngreso.anio);

            mostrarTipos(tipos, tamTipos);
            printf("Ingrese el tipo: ");
            scanf("%d", &auxMascota.idTipo);

            mostrarColores(colores, tamCol);
            printf("Ingrese el color: ");
            scanf("%d", &auxMascota.idColor);

            printf("\n\nIngrese nombre del duenio: ");
            fflush(stdin);
            gets(auxCliente.nombre);

            printf("\nIngrese sexo del duenio: ");
            fflush(stdin);
            scanf("%c", &auxCliente.sexo);

            printf("\n\n");

            auxMascota.isEmpty=0;
            auxCliente.isEmpty=0;

            //-------------------
            mascota[indice]=auxMascota;
            cliente[indiceCliente]=auxCliente;

            todoOk=1;
            printf("Mascota Agregada con Exito!!!!\n\n");
        }
            return todoOk;

}

int buscarMascota(int id, eMascota vec[], int tam){
    int indice=-1;
    for(int i=0; i<tam; i++){
        if(vec[i].id==id && vec[i].isEmpty==0){
            indice=i;
            break;
        }
    }
    return indice;
}

void modificarMenu(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente){
    char opcion;
    system("cls");
    printf("******* Modificar *******\n\n");
    printf("a. Tipo\nb. Edad\nc. Volver\n\n");
    printf("Seleccione lo que desea modificar: ");
    fflush(stdin);
    scanf("%c", &opcion);

    switch(opcion){
    case 'a':
        modificarTipo(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        break;
    case 'b':
        modificarEdad(mascotas, tam, tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        break;
    default :
        break;
    }
}

void modificarTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente){
    int id;
    int indice;
    char confirma;
    int nuevoTipo;

    system("cls");
    printf("******* Modificar Tipo *******\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarMascota(id,mascotas,tam);

    if(indice==-1){
       printf("El id (%d) que ingreso no existe\n",id);
    }else{
        mostrarMascota(mascotas[indice], tipos, tamTipos, colores, tamCol,cliente, tamCliente);

        printf("\nConfirma Modificacion? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s'){
            mostrarTipos(tipos, tamTipos);
            printf("Ingrese Id Nuevo Tipo: ");
            scanf("%d", &nuevoTipo);
            printf("\n\n");
            mascotas[indice].idTipo=nuevoTipo;
            printf("Empleado Modificado con Exito!!!!\n\n");
        } else{
            printf("Se ha Cancelado la Modificacion\n\n");
        }
    }
}

void modificarEdad(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente){
    int id;
    int indice;
    char confirma;
    int nuevaEdad;

    system("cls");
    printf("******* Modificar Edad *******\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarMascota(id,mascotas,tam);

    if(indice==-1){
       printf("El id (%d) que ingreso no existe\n",id);
    }else{
        mostrarMascota(mascotas[indice], tipos, tamTipos, colores, tamCol, cliente, tamCliente);

        printf("\nConfirma Modificacion? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s'){
            printf("Ingrese Nueva Edad: ");
            scanf("%d", &nuevaEdad);
            printf("\n\n");
            mascotas[indice].edad=nuevaEdad;
            printf("Empleado Modificado con Exito!!!!\n\n");
        } else{
            printf("Se ha Cancelado la Modificacion\n\n");
        }
    }
}

void cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam){


    for(int i=0; i<tam; i++){
        if(colores[i].id==id){
            strcpy(descripcion, colores[i].nombreColor);
        }
    }
}
void cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam){


    for(int i=0; i<tam; i++){
        if(tipos[i].id==id){
            strcpy(descripcion, tipos[i].descripcion);
        }
    }
}

void cargarDescripcionCliente(char descripcion[], int id, eCliente cliente[], int tamCliente){
    for(int i=0; i<tamCliente; i++){
        if(cliente[i].id==id){
            strcpy(descripcion, cliente[i].nombre);
        }
    }
}

void bajaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamCol, eCliente cliente[], int tamCliente){
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("******* Baja Mascota *******\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarMascota(id,mascotas,tam);

    if(indice==-1){
       printf("El id (%d) que ingreso no existe\n",id);
    }else{
        mostrarMascota(mascotas[indice], tipos, tamTipos, colores, tamCol, cliente, tamCliente);
        printf("\nConfirma Baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s'){
            mascotas[indice].isEmpty=1;
            printf("Empleado Dado de Baja con Exito!!!!\n\n");
        } else{
            printf("Se ha Cancelado la Baja\n\n");
        }
    }
}
