# agenda_ecole_hexagone
Calendrier en C

## Description
Ce projet est un calendrier en C. Il permet de gérer des événements et des tâches à faire.

## Fonctionnalités
* Ajouter un événement à l'agenda
* Supprimer un événement de l'agenda
* Sauvegarder l'agenda
* Charger un agenda
* Quitter

## Structure
```
.
├── bin (fichiers exécutables)
│   └── main
├── build (fichiers créés lors de la compilation)
│   ├── event.o
│   ├── main.o
│   ├── menu.o
│   └── tools.o
├── include/ (fichiers d'en-tête)
│   ├── event.h
│   ├── menu.h
│   └── tools.h
├── src (fichiers sources)
│   ├── event.c
│   ├── main.c
│   ├── menu.c
│   └── tools.c
├── Makefile (fichier de compilation)
└── save (fichier de sauvegarde)
```

## Langages
* [C](https://fr.wikipedia.org/wiki/C_(langage))

## Prérequis
* [GCC](https://gcc.gnu.org/) - GNU Compiler Collection
* [Make](https://www.gnu.org/software/make/) - GNU Make

## Installation
### Installer GCC
```
sudo apt-get install gcc
```

### Installer Make
```
sudo apt-get install make
```

## Builder le projet
À la racine du projet, lancer la commande suivante :
```
make
```

## Lancer le projet
À la racine du projet, lancer la commande suivante :
```
./bin/main
```

## Nettoyer le projet
À la racine du projet, lancer la commande suivante :
```
make clean
```

## Auteur
**Florian Brunel**

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
