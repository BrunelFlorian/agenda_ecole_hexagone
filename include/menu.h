#ifndef MENU_T
#define MENU_T

#include "event.h"

/*
* Affiche le menu principal
* @param agenda : l'agenda
*/
void printMenu(event_t *agenda);

/*
* Demande à l'utilisateur de choisir une date
* @param int *date : la date choisie par l'utilisateur
*/
void requestDate(int *date);

/*
* Demande à l'utilisateur de choisir une heure
* @return int : l'heure choisie par l'utilisateur
*/
void requestHour(int *hour);

/*
* Demande à l'utilisateur de choisir un commentaire
* @param char *comment : le commentaire choisi par l'utilisateur
*/
void requestComment(char *comment);

/*
* Demande à l'utilisateur de choisir un nom de fichier
* @param char *filename : pointeur vers le nom de fichier choisi par l'utilisateur
* @param bool load : true si l'utilisateur souhaite charger un fichier, false sinon
*/
void requestFilename(char *filename, bool load);

#endif