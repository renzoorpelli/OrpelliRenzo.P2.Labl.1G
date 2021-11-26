#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "bibilotecaPersonal.h"

/*

 1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de las películas.
3)  Asignar  rating:  Se  deberá  hacer  uso de  la  función map. la cual  recibirá  el  linkedlist  y  una
función  que  asignará  a  la  película  un  valor  de  rating  flotante  entre  1  y  10  con  1  decimal
calculado de manera aleatoria se mostrará por pantalla el mismo.
4) Asignar género: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y una
función que asignará a la película un género de acuerdo a un número aleatorio entre 1 y 4.
5)  Filtrar  por  género:  Se  deberá  generar  un  archivo  igual  al  original,  pero  donde  solo
aparezcan películas del género seleccionado.
6) Ordenar películas: Se deberá mostrar por pantalla un listado de las películas ordenadas por
género y dentro de las del mismo género que aparezcan ordenadas por rating descendente.
7) Guardar películas: Se deberá guardar el listado del punto anterior en un archivo de texto.
8) Salir.


*/

int menu()
{
    int opcion = 0;
    system("cls");
    printf("    ***PELICULAS***\n");
    printf("1- Cargar los datos de movies.csv en modo csv\n");
    printf("2- Listar  Peliculas\n");
    printf("3- Asignar Rating peliculas\n");
    printf("4- Asignar genero peliculas\n");
    printf("5- Filtrar por genero\n");
    printf("6- OrdenarPeliculas\n");
    printf("7- Guardar Pelicilas\n");
    printf("8- Salir\n");
    fflush(stdin);
    validarEntero(&opcion,"Ingrese opcion: \n", "****ERROR***", 1,8, 20);

    return opcion;
}


int menuGeneros()
{
    int opcion = 0;
    system("cls");
    printf("FILTRAR POR GENERO Y GENERAR ARCHIVOS S/FILTRADO\n");
    printf("Seleccionar Genero\n");
    printf("1.DRAMA\n");
    printf("2.COMEDIA\n");
    printf("3.ACCION\n");
    printf("4.TERROR\n");
    fflush(stdin);
    validarEntero(&opcion,"Ingrese opcion: \n", "****ERROR***", 1,4, 20);
    return opcion;
}
