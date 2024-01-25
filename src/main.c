#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/event.h"
#include "../include/menu.h"
#include "../include/tools.h"

int main() {
    int choice, dateToAdd, hourToAdd, dateToDelete, hourToDelete;
    event_t *agenda = NULL;
    char comment[255], filename[255];

    do {
        printMenu(agenda);
        
        if (scanf("%d", &choice) != 1) {
            printf("\nSaisie invalide, veuillez renseigner un chiffre correspondant aux menus ci-dessus\n");
            while (getchar() != '\n');  // Vide le tampon d'entrée
            continue;
        }

        switch (choice) {
            case 1:
                // Ajouter un évènement
                {
                    // Choix date
                    do {
                        requestDate(&dateToAdd);
                    } while (!isValidDate(dateToAdd));

                    // Choix heure
                    do {
                        requestHour(&hourToAdd);
                    } while (!isValidHour(hourToAdd));

                    // Choix commentaire
                    do {
                        requestComment(comment);
                    } while (!isValidComment(comment));

                    agenda = addEvent(agenda, dateToAdd, hourToAdd, comment);
                }
                break;
            case 2:
                // Supprimer un évènement
                {
                    // Choix date
                    do {
                        requestDate(&dateToDelete);
                    } while (!isValidDate(dateToDelete));
                    
                    // Choix heure
                    do {
                        requestHour(&hourToDelete);
                    } while (!isValidHour(hourToDelete));

                    agenda = deleteEvent(agenda, dateToDelete, hourToDelete);
                }
                break;
            case 3:
                // Sauvegarder l'agenda
                {
                    requestFilename(filename);
                    saveAgenda(agenda, filename);
                }
                break;
            case 4:
                // Charger un agenda
                {
                    do {
                        requestFilename(filename);
                    } while (!fileExist(filename));

                    agenda = loadAgenda(filename);
                }
                break;
            case 0:
                // Quitter le programme
                freeAgenda(agenda);
                break;
            default:
                printf("\nChoix invalide, veuillez renseigner un chiffre correspondant aux menus ci-dessus\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
