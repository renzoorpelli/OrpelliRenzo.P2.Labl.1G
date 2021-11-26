#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    char genero[20];
    char titulo[50];
    float rating;

}ePelicula;

//constructores
ePelicula* nueva_pelicula();
void eliminar_pelicula(ePelicula* pelicula);
ePelicula* pelicula_newParametros(char* idStr,char* tituloStr, char* generoStr,char* ratingStr);

//setters
int pelicula_setId(ePelicula* pelicula,int id);
int pelicula_setGenero(ePelicula* pelicula,char* genero);
int pelicula_setTitulo(ePelicula* pelicula,char* titulo);
int pelicula_setRating(ePelicula* pelicula,float rating);
//getters
int pelicula_getId(ePelicula* pelicula,int* id);
int pelicula_getGenero(ePelicula* pelicula,char* genero);
int pelicula_getTitulo(ePelicula* pelicula,char* titulo);
int  pelicula_getRating(ePelicula* pelicula,float* rating);
// mostrar
int mostrarPeliculas(ePelicula* pelicula);
void* asignarRatingPelicula(void* pelicula);
void* asignarGeneroPelicula(void* pelicula);
int compararPeliculasGeneroRating(void* pPeliA,void* pPeliB);




#endif // PELICULAS_H_INCLUDED
