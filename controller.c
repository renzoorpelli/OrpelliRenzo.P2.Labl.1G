#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "peliculas.h"
#include "files.h"
#include "filtros.h"
#include "menu.h"

int controller_ListPeliculas(LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;
    ePelicula* auxPelicula = NULL;
    if(ll_isEmpty(pArrayListPeliculas)== 0)
    {
        printf("**************************************************************************************************************\n");
        printf("ID                             TITULO                                   GENERO                       RATING\n");
        printf("***************************************************************************************************************\n");
        for( int i = 0; i < ll_len(pArrayListPeliculas); i++)
        {
            auxPelicula = (ePelicula*) ll_get(pArrayListPeliculas, i);
            mostrarPeliculas(auxPelicula);
        }
        printf("\n\n");
        todoOk = 1;
    }
    else
    {
        printf("LA LISTA ESTA VACIA\n");
    }
    return todoOk;
}

int controller_mapRating(LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;
    pArrayListPeliculas = ll_map(pArrayListPeliculas, asignarRatingPelicula);
    if(pArrayListPeliculas != NULL)
    {
        controller_ListPeliculas(pArrayListPeliculas);
        printf("ESTADISTICAS ASINGADAS CON EXITO\n");
        todoOk = 1;
    }
    return todoOk;
}


int controller_mapAsingarGenero(LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;
    pArrayListPeliculas = ll_map(pArrayListPeliculas, asignarGeneroPelicula);
    if(pArrayListPeliculas != NULL)
    {
        controller_ListPeliculas(pArrayListPeliculas);
        printf("GENEROS ASIGNADOS CON EXITO\n");
        todoOk = 1;
    }
    return todoOk;
}


int controller_filter(LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;
    char auxCadenaPath[20];
    if (pArrayListPeliculas != NULL)
    {

        switch(menuGeneros())
        {
        case 1:
            printf("FILTRANDO...\n");//DRAMA
            pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_PeliculasDrama);
            strcpy(auxCadenaPath, "dataDrama.csv");
            break;
        case 2:
            printf("FILTRANDO...\n");//COMEDIA
            pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_PeliculasComedia);
            strcpy(auxCadenaPath, "dataComedia.csv");
            break;
        case 3:
            printf("FILTRANDO...\n");//Accion
            pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_PeliculasAccion);
            strcpy(auxCadenaPath, "dataAccion.csv");
            break;
        case 4:
            printf("FILTRANDO...\n");//Terror
            pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_PeliculasTerror);
            strcpy(auxCadenaPath, "dataTerror.csv");
            break;
        default:
            printf("Opcion invalida\n");
            printf("Ingrese otra opcion:\n");
        }

        if(pArrayListPeliculas != NULL)
        {
            controller_ListPeliculas(pArrayListPeliculas);
            system("pause");
            controller_saveAsText(auxCadenaPath, pArrayListPeliculas);
            todoOk = 1;
        }

    }
    return todoOk;
}


int controller_ordenarPeliculas(LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;

    if (pArrayListPeliculas != NULL)
    {
        ll_sort(pArrayListPeliculas, compararPeliculasGeneroRating, 1);
        system("cls");
        controller_ListPeliculas(pArrayListPeliculas);
        printf("Peliculas ordenados con exito\n");
        todoOk = 1;
    }
    return todoOk;
}
