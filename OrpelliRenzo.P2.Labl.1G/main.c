#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "files.h"
#include "controller.h"
#include "peliculas.h"
#include "ctype.h"
#include "menu.h"
#include <time.h>
#include "bibilotecaPersonal.h"
#include <string.h>

int main()
{
    srand(time(NULL));
    char salir;
    char seguir = 's';
    LinkedList* listaPeliculas = ll_newLinkedList();
    char cadenaPathLoad[20];
    char cadenaPathGuardado[20];

    if (listaPeliculas == NULL)
    {
        printf("No se pudo crear el linkedList\n");
        exit(1);

    }
    do
    {
        switch(menu())
        {
        case 1:
            printf("CARGAR DATOS\n");
            printf("AGREGAR  .CSV AL FINAL DEL NOMBRE ASIGNADO\n");
            scanf("%s",cadenaPathLoad);
            while(!controller_loadFromText(cadenaPathLoad,listaPeliculas))
            {
                printf("Error durante la llamada, Ingrese (movies.csv)\n");
                printf("CARGAR DATOS\n");
                printf("AGREGAR  .CSV AL FINAL DEL NOMBRE ASIGNADO\n");
                scanf("%s",cadenaPathLoad);
            }
            break;
        case 2:
            if(!controller_ListPeliculas(listaPeliculas))
            {
                printf("Error al listar las peliculas\n");
            }
            break;
        case 3:
            if(!controller_mapRating(listaPeliculas))
            {
                printf("Error al asignar rating\n");
            }
            break;
        case 4:
            if(!controller_mapAsingarGenero(listaPeliculas))
            {
                printf("Error al asignar Genero peliculas\n");
            }
            break;
        case 5:
            if(!controller_filter(listaPeliculas))
            {
                printf("Error al filtrar por genero\n");
            }
            break;
        case 6:
            if(!controller_ordenarPeliculas(listaPeliculas))
            {
                printf("Error al ordenar peliculas\n");
            }
            break;
        case 7:
            printf("ASIGNAR NOMBRE ARCHIVO\n");
            scanf("%s",cadenaPathGuardado);
            strcat(cadenaPathGuardado, ".csv");
            controller_saveAsText(cadenaPathGuardado,listaPeliculas);
            break;
        case 8:
            printf("Esta seguro que quiere salir? S o N \n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
            printf("Ingrese otra opcion:\n");
        }
        system("pause");
    }
    while(seguir == 's');


    free(listaPeliculas);
}
