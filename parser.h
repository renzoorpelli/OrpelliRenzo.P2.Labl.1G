#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"


/** \brief Parsea los datos los datos de el array  desde el archivo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_DataFromText(FILE* pFile , LinkedList* pArrayList);


/** \brief Parsea los datos los datos de el array  desde el archivo binario (modo binario).
 *
 * \param path char*
 * \param pArrayListPeliculas LinkedList*
 * \return int
 *
 */
int parser_DataFromBinary(FILE* pFile , LinkedList* pArrayList);

#endif // PARSER_H_INCLUDED
