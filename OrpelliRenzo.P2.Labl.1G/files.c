#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "parser.h"
#include "peliculas.h"


int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int todoOk = 0;
    FILE* pFile;

    if ( path != NULL && pArrayList != NULL )
    {

        pFile = fopen( path, "r");
        if ( pFile == NULL )
        {
            printf("ERROR NO SE PUDO ABRIR EL ARCHIVO\n");
        }
        else
        {
            if (parser_DataFromText( pFile, pArrayList ))
            {
                printf( "LA CARGA FUE EXITOSA\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}



int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int todoOk = 0;
    FILE* pFile;

    if ( path != NULL && pArrayList != NULL )
    {
        system("cls");
        printf("CARGA DE DATOS DESDE ARCHIVO BINARIO\n");

        pFile = fopen( path, "rb");
        if ( pFile == NULL )
        {
            printf("ERROR NO SE PUDO ABRIR EL ARCHIVO\n");
        }
        else
        {
            if ( parser_DataFromBinary( pFile, pArrayList ) )
            {
                printf( "LA CARGA FUE EXITOSA\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

// GUARDADO DE ARCHIVOS
int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int todoOk = 0;
    FILE* pFile;
    ePelicula* auxPelicula;
    int id;
    char titulo[50];
    char genero[50];
    float rating;

    if ( path != NULL && pArrayList != NULL )
    {
        system("cls");
        printf("GUARDADO EL ARCHIVO EN MODO CSV EXITOSO...\n");

        pFile = fopen(path, "w"); // abro el archivo
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");

        }

        fprintf( pFile, "id,titulo,nombre,rating\n" );

        for (int i = 0; i < ll_len(pArrayList); i++)
        {
            auxPelicula = ll_get(pArrayList, i);
            if ( pelicula_getId(auxPelicula, &id) &&
                pelicula_getTitulo(auxPelicula, titulo) &&
                pelicula_getGenero(auxPelicula, genero) &&
                pelicula_getRating(auxPelicula, &rating)
               )
            {
                fprintf(pFile, "%d,%s,%s,%.1f\n", id, titulo, genero, rating);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}



int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    int todoOk = 0;
    FILE* pFile;

    ePelicula* auxPelicula;

    if ( path != NULL && pArrayList != NULL )
    {
        system("cls");
        printf("GUARDADO ARCHIVOS DESDE BINARIO...\n");

        pFile = fopen(path, "wb");
        if ( pFile == NULL )
        {
            printf("ERROR AL ABRIR EL ARCHIVO\n");

        }

        for (int i = 0; i < ll_len(pArrayList); i++)
        {
            auxPelicula = ll_get(pArrayList, i);

            if ( (auxPelicula) != NULL )
            {
                fwrite( auxPelicula, sizeof(ePelicula), 1, pFile );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
