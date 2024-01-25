#ifndef TOOLS_T
#define TOOLS_T

#include <stdbool.h>

/*
* Vérifie si la date est valide au format YYYYmmdd
* @param int date : la date à vérifier
* @return bool : true si la date est valide, false sinon
*/
bool isValidDate(int date);

/*
* Vérifie si l'heure est valide au format hhmm
* @param int hour : l'heure à vérifier
* @return bool : true si l'heure est valide, false sinon
*/
bool isValidHour(int hour);

/*
* @brief si une chaîne contient des guillemets doubles
* @param const char *str : chaîne à vérifier
* @return bool : true si la chaîne contient des guillemets doubles, false sinon
*/
bool isValidComment(const char *comment);

/*
* Vérifie si un fichier existe
* @param const char *filename : nom du fichier à vérifier
* @return bool : true si le fichier existe, false sinon
*/
bool fileExist(const char *filename);

#endif