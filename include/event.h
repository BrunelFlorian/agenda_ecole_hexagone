#ifndef EVENT_T
#define EVENT_T

/*
* Structure d'un événement
* int hour : heure de l'événement
* int date : date de l'événement
* char[255] comment : commentaire de l'événement
* struct event *next_elem : pointeur vers le prochain événement
*/
typedef struct event {
    int date;
    int hour;
    char comment[255];
    struct event *next_elem;
} event_t;

/*
* Parcours l'agenda et affiche chaque événement
* @param event_t *agenda : l'agenda à afficher
*/
void printAgenda(event_t *agenda);

/*
* Ajoute un événement dans l'agenda
* @param event_t *agenda : l'agenda dans lequel ajouter l'événement
* @param int date : la date de l'événement
* @param int hour : l'heure de l'événement
* @param const char *comment : le commentaire de l'événement
* @return event_t * : l'agenda avec le nouvel événement ajouté
*/
event_t * addEvent(event_t *agenda, int date, int hour, const char *comment);

/*
* Supprime un(des) événement(s) de l'agenda si la date et l'heure correspondent
* @param event_t *agenda : l'agenda dans lequel supprimer l'événement
* @param int date : la date de l'événement à supprimer
* @param int hour : l'heure de l'événement à supprimer
* @return event_t * : l'agenda avec l'événement supprimé
*/
event_t *deleteEvent(event_t *agenda, int date, int hour);

/*
* Parcours l'agenda et sauvegarde chaque événement dans un fichier
* @param event_t *agenda : l'agenda à sauvegarder
* @param const char *filename : le nom du fichier dans lequel sauvegarder l'agenda
*/
void saveAgenda(event_t *agenda, const char *filename);

/*
* Charge un agenda depuis un fichier
* @param const char *filename : le nom du fichier à charger
* @return event_t * : l'agenda chargé depuis le fichier
*/
event_t *loadAgenda(const char *filename);

/*
* Parcours l'agenda et libère la mémoire allouée pour chaque événement
* @param event_t *agenda : l'agenda à libérer
*/
void freeAgenda(event_t *agenda);

#endif
