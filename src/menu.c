#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/event.h"

/*
* Affiche le menu
* @param event_t *agenda : l'agenda à afficher
*/
void printMenu(event_t *agenda) {
    printf("\n------------------------------------------\n");
    if (agenda == NULL) {
        printf("Aucun événement dans l'agenda.\n");
    } else {
        printf("Événements dans l'agenda :\n");
        printAgenda(agenda);
    }
    printf("------------------------------------------\n");
    printf("\nVeuillez choisir une option :\n");
    printf("1 --> Ajouter un évènement\n");
    printf("2 --> Supprimer un évènement\n");
    printf("3 --> Sauvegarder l'agenda\n");
    printf("4 --> Charger un agenda\n");
    printf("0 --> Quitter\n");
}

/*
* Demande à l'utilisateur de choisir une date
* @param int *date : pointeur vers la date choisie par l'utilisateur
*/
void requestDate(int *date) {
    int valid = 0;
    while (valid == 0) {
        printf("\nVeuillez choisir la date (format YYYYmmjj)\n");
        if (scanf("%d", date) == 1) {
            valid = 1;
        } else {
            printf("\nSaisie invalide. Veuillez renseigner une date au format YYYYmmjj.\n");
            while (getchar() != '\n');
        }
    }
}

/*
* Demande à l'utilisateur de choisir une heure
* @param int *hour : pointeur vers l'heure choisie par l'utilisateur
*/
void requestHour(int *hour) {
    int valid = 0;
    while (valid == 0) {
        printf("\nVeuillez choisir l'heure (format hhmm)\n");
        if (scanf("%d", hour) == 1) {
            valid = 1;
        } else {
            printf("\nSaisie invalide. Veuillez renseigner une heure au format hhmm.\n");
            while (getchar() != '\n');
        }
    }
}

/*
* Demande à l'utilisateur de choisir un commentaire
* @param char *comment : pointeur vers le commentaire choisi par l'utilisateur
*/
void requestComment(char *comment) {
    printf("\nVeuillez entrer un commentaire\n");
    scanf(" %[^\n]", comment);
}

/*
* Demande à l'utilisateur de choisir un nom de fichier
* @param char *filename : pointeur vers le nom de fichier choisi par l'utilisateur
*/
void requestFilename(char *filename) {
    printf("\nVeuillez entrer le nom du fichier\n");
    scanf("%s", filename);
}