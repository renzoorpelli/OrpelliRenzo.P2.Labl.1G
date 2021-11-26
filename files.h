#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED
#include "LinkedList.h"


// CARGA DE ARCHIVOS
/** \brief Carga los datos del array desde el archivo csv.
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList);
/** \brief Carga los datos del array desde el archivo binario.
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayList);

// GUARDADO ARCHIVOS
/** \brief Guarda los datos de el array en modo csv.
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList);
/** \brief Guarda los datos del array en modo binario.
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayList);


#endif // FILES_H_INCLUDED
