#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
/** \brief recibe un linkedlist y lo muestra
 *
 * \param pArrayListPeliculas
 * \return 1 si todo ok 0 si errors
 *
 */

int controller_ListPeliculas(LinkedList* pArrayListPeliculas);
/** \brief recibe un linkedlist y le asigna el rating a las peliculas de manera random
 *
 * \param pArrayListPeliculas
 * \return 1 si todo ok 0 si errors
 *
 */

int controller_mapRating(LinkedList* pArrayListPeliculas);
/** \brief recibe un linkedlist y le asigna el genero a las peliculas de manera random
 *
 * \param pArrayListPeliculas
 * \return 1 si todo ok 0 si errorss
 *
 */

int controller_mapAsingarGenero(LinkedList* pArrayListPeliculas);
/** \brief recibe un linkedlist y se encarga de filtrar la lista segun el genero que le pida el usuario
 *
 * \param pArrayListPeliculas
 * \param
 * \return 1 si todo ok 0 si errorss
 *
 */

int controller_filter(LinkedList* pArrayListPeliculas);
/** \brief recibe un linkedlist y se encarga de ordenar la lista segun genero y con rating de mayor a menor
 *
 * \param pArrayListPeliculas
 * \param
 * \return 1 si todo ok 0 si errorss
 *
 */

int controller_ordenarPeliculas(LinkedList* pArrayListPeliculas);


#endif // CONTROLLER_H_INCLUDED
