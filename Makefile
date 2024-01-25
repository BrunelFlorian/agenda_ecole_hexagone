# On purge la liste des suffixes utilis?s pour les r?les implicites
.SUFFIXES:

# On ajoute simplement les extensions dont l'on a besoin
.SUFFIXES:.c .o

# Nom de l'exécutable
EXEC=main

# Dossiers
INCLUDE_DIR=include
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

# Liste des fichiers sources séparés par des espaces
SOURCES=$(wildcard $(SRC_DIR)/*.c)
# Liste des fichiers objets
OBJETS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Compilateur et options de compilation
CCPP=gcc
LFLAGS= -O0 -Wall -Wextra -std=c99 -g
CFLAGS= -std=c99 -g -O0 -Wall -Wextra -I$(INCLUDE_DIR)

# R?le explicite de construction de l'ex?utable
$(BIN_DIR)/$(EXEC): $(OBJETS) Makefile
	$(CCPP) -o $@ $(OBJETS) $(LFLAGS)

# R?le implicite pour la construction des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CCPP) $(CFLAGS) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage des fichiers objets et de l'exécutable
clear: clean
	rm -f $(BIN_DIR)/$(EXEC)

# Génération des dépendances
depend:
	sed -e "/^#DEPENDANCIES/,$$ d" Makefile >dependances
	echo "#DEPENDANCIES" >> dependances
	$(CCPP) -MM $(SOURCES) | sed 's|^|$(OBJ_DIR)/|' >> dependances
	cat dependances >Makefile
	rm dependances

# Inclusion des dépendances
-include dependances
