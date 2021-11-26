#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "menu.h"
#include "ctype.h"



ePelicula* nueva_pelicula()
{
    ePelicula* nuevaPeli= (ePelicula*) malloc(sizeof(ePelicula));

    if(nuevaPeli != NULL)
    {
        nuevaPeli->id= 0;
        strcpy(nuevaPeli->genero, "");
        strcpy(nuevaPeli->titulo, "");
        nuevaPeli->rating = 0;
    }

    return nuevaPeli;
}


ePelicula* pelicula_newParametros(char* idStr,char* tituloStr, char* generoStr,char* ratingStr)
{
    ePelicula* nuevaPeli = nueva_pelicula();

    if (nuevaPeli !=  NULL)
    {
        if(!(pelicula_setId(nuevaPeli, atoi(idStr)) &&
                pelicula_setTitulo(nuevaPeli, tituloStr) &&
                pelicula_setGenero(nuevaPeli, generoStr)&&
                pelicula_setRating(nuevaPeli, atof(ratingStr))))
        {
            eliminar_pelicula(nuevaPeli);
            nuevaPeli = NULL;
        }
    }
    return nuevaPeli;
}

void eliminar_pelicula(ePelicula* pelicula)
{
    free(pelicula);
}


int pelicula_setId(ePelicula* pelicula,int id)
{
    int todoOk = 0;

    if ( pelicula != NULL && id > 0)
    {
        pelicula->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int pelicula_getId(ePelicula* pelicula,int* id)
{
    int todOk= 0;
    if ( pelicula != NULL && id != NULL)
    {
        (*id) = pelicula->id;
        todOk = 1;
    }
    return todOk;
}

int pelicula_setGenero(ePelicula* pelicula,char* genero)
{
    int todoOk = 0;
    char auxCadena[50];

    if ( pelicula != NULL && genero != NULL && strlen(genero)>0 && strlen(genero)< 20)
    {
        strcpy(auxCadena, genero);
        strcpy(pelicula->genero, auxCadena);
        todoOk = 1;
    }

    return todoOk;
}

int pelicula_getGenero(ePelicula* pelicula,char* genero)
{
    int todOk= 0;
    if ( pelicula != NULL && genero != NULL)
    {
        strcpy( genero,pelicula->genero);
        todOk = 1;
    }
    return todOk;
}


int pelicula_setTitulo(ePelicula* pelicula,char* titulo)
{
    int todOk= 0;
    char auxCadena[50];
    if ( pelicula != NULL)
    {
        strcpy(auxCadena, titulo);
        strcpy(pelicula->titulo, auxCadena);
        todOk = 1;
    }
    return todOk;
}

int pelicula_getTitulo(ePelicula* pelicula,char* titulo)
{
    int todOk= 0;
    if ( pelicula != NULL && titulo != NULL)
    {
        strcpy(titulo,pelicula->titulo);
        todOk = 1;
    }
    return todOk;
}

int pelicula_setRating(ePelicula* pelicula,float rating)
{
    int todOk= 0;
    if ( pelicula != NULL)
    {
        pelicula->rating = rating;;
        todOk = 1;
    }
    return todOk;
}

int  pelicula_getRating(ePelicula* pelicula,float* rating)
{
    int todOk= 0;
    if ( pelicula != NULL && rating != NULL)
    {
        *rating =  pelicula->rating;
        todOk = 1;
    }
    return todOk;
}

// FUNCION MOSTRAR


int mostrarPeliculas(ePelicula* pelicula)
{
    int todoOk = 0;
    int id;
    char titulo[60];
    char genero[60];
    float rating;

    if(pelicula != NULL)
    {
        if(
            pelicula_getId(pelicula, &id) &&
            pelicula_getTitulo(pelicula, titulo) &&
            pelicula_getGenero(pelicula, genero) &&
            pelicula_getRating(pelicula, &rating))
        {
            printf("%2d              %28s                     %16s                     %.1f\n", id,
                   titulo,
                   genero,
                   rating);
            todoOk =1;
        }
    }
    return todoOk;
}

// MAP
void* asignarRatingPelicula(void* pelicula)
{
    ePelicula* auxPelicula = NULL;
    float rating;
    if (pelicula != NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        rating = (float)(rand() % (10 - 1 + 1) + 1)/1;
        pelicula_setRating(auxPelicula, rating);
    }
    return auxPelicula;
}

/*
1: drama
2: comedia
3: acción
4: terror

*/
void* asignarGeneroPelicula(void* pelicula)
{
    ePelicula* auxPelicula = NULL;
    int genero;
    if (pelicula != NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        genero = rand() % (4 - 1 + 1) + 1;
        if(genero==4)
        {
            strcpy(auxPelicula->genero, "Terror");
        }
        else {
            if(genero == 3)
            {
                strcpy(auxPelicula->genero, "Accion");
            }
            else
            {
                if(genero==2)
                {
                    strcpy(auxPelicula->genero, "Comedia");
                }
                else
                {
                    strcpy(auxPelicula->genero, "Drama");
                }
            }
        }

    }
    return auxPelicula;

}


int compararPeliculasGeneroRating(void* pPeliA,void* pPeliB)
{
    int todoOk= 0;

    if(  ( strcmp( ((ePelicula*)pPeliA)->genero,  ((ePelicula*)pPeliB)->genero )  > 0 ) ||
       ( ( strcmp( ((ePelicula*)pPeliA)->genero,  ((ePelicula*)pPeliB)->genero )  == 0 ) &&
                   ((ePelicula*)pPeliA)->rating < ((ePelicula*)pPeliB)->rating )
           )
    {
        todoOk = 1;
    }
    if(  ( strcmp( ((ePelicula*)pPeliA)->genero,  ((ePelicula*)pPeliB)->genero )  < 0 ) ||
       ( ( strcmp( ((ePelicula*)pPeliA)->genero,  ((ePelicula*)pPeliB)->genero )  == 0 ) &&
                   ((ePelicula*)pPeliA)->rating > ((ePelicula*)pPeliB)->rating )
          )
    {
        todoOk = -1;
    }
    return todoOk;

}


