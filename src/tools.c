#include <stdio.h>
#include <stdbool.h>
#include "../include/tools.h"

/*
* Vérifie si la date est valide au format YYYYmmdd
* @param int date : la date à vérifier
* @return bool : true si la date est valide, false sinon
*/
bool isValidDate(int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    // Vérification des limites
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("\nDate hors limite, veuillez renseigner une date valide\n");
        return false;
    }

    // Vérification des mois avec 30 jours
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("\nLe mois spécifié ne contient pas autant de jours\n");
        return false;
    }

    // Vérification du mois de février avec années bissextiles
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                printf("\nLe mois de février (bissextile) ne contient que 29 jours\n");
                return false;
            }
        } else {
            if (day > 28) {
                printf("\nLe mois de février (non bissextile) ne contient que 28 jours\n");
                return false;
            }
        }
    }

    return true;
}

/*
* Vérifie si l'heure est valide au format hhmm
* @param int hour : l'heure à vérifier
* @return bool : true si l'heure est valide, false sinon
*/
bool isValidHour(int hour) {
    if (hour < 0 || hour >= 2400 || hour % 100 >= 60) {
        printf("\nHeure hors limite, veuillez renseigner une heure valide\n");
        return false;
    }

    return true;
}

/*
* Vérifie si un commentaire est valide (ne contient pas de guillemets doubles)
* @param const char *comment : commentaire à vérifier
* @return bool : true si le commentaire est valide, false sinon
*/
bool isValidComment(const char *comment) {
    while (*comment) {
        if (*comment == '\"') {
            printf("\nVotre commentaire de doit pas contenir de guillemets doubles\n");
            return false;
        }
        comment++;
    }
    return true;
}

/*
* Vérifie si un fichier existe
* @param const char *filename : nom du fichier à vérifier
* @return bool : true si le fichier existe, false sinon
*/
bool fileExist(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nLe fichier '%s' n'existe pas\n", filename);
        return false;
    }
    fclose(file);
    return true;
}