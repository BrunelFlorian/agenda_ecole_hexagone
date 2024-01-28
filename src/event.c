#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/event.h"

/*
* Parcours l'agenda et affiche chaque événement
* @param event_t *agenda : l'agenda à afficher
*/
void printAgenda(event_t *agenda) {
    event_t *currentEvent = agenda;

    printf("\n");
    while (currentEvent != NULL) {
        // Formatage de la date
        int year = currentEvent->date / 10000;
        int month = (currentEvent->date / 100) % 100;
        int day = currentEvent->date % 100;

        // Formatage de l'heure
        int hour = currentEvent->hour / 100;
        int minute = currentEvent->hour % 100;

        printf("Date: %02d/%02d/%04d, Heure: %02d:%02d, Commentaire: %s\n", day, month, year, hour, minute, currentEvent->comment);

        currentEvent = currentEvent->next_elem;
    }
}

/*
* Ajoute un événement dans l'agenda
* @param event_t *agenda : l'agenda dans lequel ajouter l'événement
* @param int date : la date de l'événement
* @param int hour : l'heure de l'événement
* @param const char *comment : le commentaire de l'événement
* @return event_t * : l'agenda avec le nouvel événement ajouté
*/
event_t *addEvent(event_t *agenda, int date, int hour, const char *comment) {
    event_t *newEvent = (event_t *)malloc(sizeof(event_t));
    event_t *prevEvent = NULL;
    event_t *currentEvent = agenda;

    // Vérification de l'allocation mémoire du nouvel événement
    if (newEvent == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    newEvent->date = date;
    newEvent->hour = hour;
    // sizeof(newEvent->comment) - 1 car on veut laisser une place pour le caractère de fin de chaîne
    strncpy(newEvent->comment, comment, sizeof(newEvent->comment) - 1);
    newEvent->next_elem = NULL;

    // Ajout de l'événement dans l'agenda s'il est vide ou s'il doit être placé en premier
    if (agenda == NULL || (date < agenda->date) || (date == agenda->date && hour < agenda->hour)) {
        newEvent->next_elem = agenda;
        return newEvent;
    }

    // Parcours de l'agenda jusqu'à trouver l'emplacement où insérer le nouvel événement
    while (currentEvent != NULL && (date > currentEvent->date || (date == currentEvent->date && hour >= currentEvent->hour))) {
        prevEvent = currentEvent;
        currentEvent = currentEvent->next_elem;
    }

    // Insérer l'événement à cet emplacement s'il a la même date et heure
    if (currentEvent != NULL && date == currentEvent->date && hour == currentEvent->hour) {
        // Insérer l'événement ici sans avancer dans la liste
        newEvent->next_elem = currentEvent;
        if (prevEvent != NULL) {
            prevEvent->next_elem = newEvent;
        } else {
            // Si prevEvent est NULL, cela signifie que le nouvel événement doit être le premier de la liste
            return newEvent;
        }
    } else {
        // Si les dates et heures sont différentes, continuer comme avant
        prevEvent->next_elem = newEvent;
        newEvent->next_elem = currentEvent;
    }

    return agenda;
}

/*
* Supprime un(des) événement(s) de l'agenda si la date et l'heure correspondent
* @param event_t *agenda : l'agenda dans lequel supprimer l'événement
* @param int date : la date de l'événement à supprimer
* @param int hour : l'heure de l'événement à supprimer
* @return event_t * : l'agenda avec l'événement supprimé
*/
event_t *deleteEvent(event_t *agenda, int date, int hour) {
    event_t *prevEvent = NULL;
    event_t *currentEvent = agenda;
    event_t *temp;
    bool eventFound = false;  // Flag pour savoir si un événement a été trouvé

    while (currentEvent != NULL) {
        if (currentEvent->date == date && currentEvent->hour == hour) {
            if (prevEvent != NULL) {
                prevEvent->next_elem = currentEvent->next_elem;
            } else {
                agenda = currentEvent->next_elem;
            }

            temp = currentEvent;
            currentEvent = currentEvent->next_elem;
            free(temp);
            eventFound = true; // Un événement a été trouvé
            printf("\nÉvénement supprimé avec succès.\n");
        } else {
            prevEvent = currentEvent;
            currentEvent = currentEvent->next_elem;
        }
    }

    if (!eventFound) {
        printf("Aucun événement trouvé à la date et l'heure spécifiées.\n");
    }

    return agenda;
}

/*
* Parcours l'agenda et sauvegarde chaque événement dans un fichier
* @param event_t *agenda : l'agenda à sauvegarder
* @param const char *filename : le nom du fichier dans lequel sauvegarder l'agenda
*/
void saveAgenda(event_t *agenda, const char *filename) {
    FILE *file = fopen(filename, "w");
    event_t *currentEvent = agenda;

    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    while (currentEvent != NULL) {
        fprintf(file, "%d,%d,\"%s\"\n", currentEvent->date, currentEvent->hour, currentEvent->comment);
        currentEvent = currentEvent->next_elem;
    }

    fclose(file);
    printf("\nAgenda sauvegardé dans le fichier '%s'\n", filename);
}

/*
* Charge un agenda depuis un fichier
* @param const char *filename : le nom du fichier à charger
* @return event_t * : l'agenda chargé depuis le fichier
*/
event_t *loadAgenda(const char *filename) {
    FILE *file = fopen(filename, "r");
    event_t *agenda = NULL;
    int date, hour;
    char comment[255];
    char line[255];
    bool correctFormat = true;

    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        // Supprimer le caractère de nouvelle ligne à la fin de la ligne lue
        line[strcspn(line, "\n")] = '\0';

        // Utiliser sscanf pour extraire les informations de la ligne
        if (sscanf(line, "%d,%d,\"%[^\"]\"", &date, &hour, comment) == 3) {
            // Ajouter chaque événement à l'agenda
            agenda = addEvent(agenda, date, hour, comment);
        } else {
            correctFormat = false;
            fprintf(stderr, "\nErreur de format dans le fichier %s\n", filename);
        }
    }

    fclose(file);

    if (correctFormat) {
        printf("\nAgenda chargé depuis le fichier %s\n", filename);
    }

    return agenda;
}

/*
* Parcours l'agenda et libère la mémoire allouée pour chaque événement
* @param event_t *agenda : l'agenda à libérer
*/
void freeAgenda(event_t *agenda) {
    event_t *currentEvent = agenda;

    while (currentEvent != NULL) {
        event_t *nextElem = currentEvent->next_elem;
        free(currentEvent);
        currentEvent = nextElem;
    }
}
