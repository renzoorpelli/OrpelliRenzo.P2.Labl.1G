#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "bibilotecaPersonal.h"

/*

 1) Cargar archivo: Se pedir� el nombre del archivo y se cargar� en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimir� por pantalla la tabla con los datos de las pel�culas.
3)  Asignar  rating:  Se  deber�  hacer  uso de  la  funci�n map. la cual  recibir�  el  linkedlist  y  una
funci�n  que  asignar�  a  la  pel�cula  un  valor  de  rating  flotante  entre  1  y  10  con  1  decimal
calculado de manera aleatoria se mostrar� por pantalla el mismo.
4) Asignar g�nero: Se deber� hacer uso de la funci�n map. la cual recibir� el linkedlist y una
funci�n que asignar� a la pel�cula un g�nero de acuerdo a un n�mero aleatorio entre 1 y 4.
5)  Filtrar  por  g�nero:  Se  deber�  generar  un  archivo  igual  al  original,  pero  donde  solo
aparezcan pel�culas del g�nero seleccionado.
6) Ordenar pel�culas: Se deber� mostrar por pantalla un listado de las pel�culas ordenadas por
g�nero y dentro de las del mismo g�nero que aparezcan ordenadas por rating descendente.
7) Guardar pel�culas: Se deber� guardar el listado del punto anterior en un archivo de texto.
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
