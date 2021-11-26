#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"



int parser_DataFromText(FILE* pFile , LinkedList* pArrayList)
{

    int todoOk = 0;
    ePelicula* auxPelicula;
    char id[50];
    char titulo[50];
    char genero[50];
    char rating[50];
    int cant;

    if ( pFile != NULL && pArrayList != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,titulo,genero, rating);

        do
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,titulo,genero, rating);
            if ( cant < 4)
            {
                break;
            }
            auxPelicula = pelicula_newParametros(id, titulo, genero, rating);
            if (auxPelicula != NULL)
            {
                ll_add(pArrayList, auxPelicula);
                auxPelicula =NULL;
                todoOk = 1;
            }

        }while(!feof(pFile));

    }

   return todoOk;
}



int parser_DataFromBinary(FILE* pFile , LinkedList* pArrayList)
{
    int todoOk = 0;
    ePelicula* auxPelicula;
    int cant;

    if ( pFile != NULL && pArrayList != NULL)
    {
        while (!feof(pFile))
        {
            auxPelicula = nueva_pelicula();
            if (auxPelicula !=NULL)
            {
                cant = fread(auxPelicula,sizeof(ePelicula),1,pFile);
                if(cant ==1)
                {
                    ll_add(pArrayList, auxPelicula);
                    auxPelicula = NULL;
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}

