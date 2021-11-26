#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

//FILTRO DE PELICULAS
/** \brief recibe un puntero a void y filtra las peliculas por genero drama
 *
 * \param void* pelicula
 * \param
 * \return 1 si todo ok 0 si error
 *
 */

int filtrar_PeliculasDrama(void* pelicula);
/** \brief recibe un puntero a void y filtra las peliculas por genero Comedia
 *
 * \param
 * \param
 * \return 1 si todo ok 0 si error
 *
 */

int filtrar_PeliculasComedia(void* pelicula);
/** \brief recibe un puntero a void y filtra las peliculas por genero accion
 *
 * \param
 * \param
 * \return 1 si todo ok 0 si error
 *
 */

int filtrar_PeliculasAccion(void* pelicula);
/** \brief recibe un puntero a void y filtra las peliculas por genero Terror
 *
 * \param
 * \param
 * \return v1 si todo ok 0 si error
 *
 */

int filtrar_PeliculasTerror(void* pelicula);

#endif // FILTROS_H_INCLUDED
