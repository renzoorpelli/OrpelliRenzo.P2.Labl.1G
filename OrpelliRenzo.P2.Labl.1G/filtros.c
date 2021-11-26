#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"

/*
1: drama
2: comedia
3: acción
4: terror

*/


int filtrar_PeliculasDrama(void* pelicula)
{
    int todoOk = 0;
    ePelicula* auxPelicula = NULL;
    if (pelicula != NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        if (strcmp(auxPelicula->genero, "Drama") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


int filtrar_PeliculasComedia(void* pelicula)
{
    int todoOk = 0;
    ePelicula* auxPelicula = NULL;
    if (pelicula != NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        if (strcmp(auxPelicula->genero, "Comedia") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrar_PeliculasAccion(void* pelicula)
{
    int todoOk = 0;
    ePelicula* auxPelicula = NULL;
    if (pelicula != NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        if (strcmp(auxPelicula->genero, "Accion") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


int filtrar_PeliculasTerror(void* pelicula)
{
    int todoOk = 0;
    ePelicula* auxPelicula = NULL;
    if (pelicula != NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        if (strcmp(auxPelicula->genero, "Terror") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
