#ifndef FONCTION_BELL
#define FONCTION_BELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TAILLE_TABLE_BE 10000

// Structure pour représenter un étudiant
typedef struct Etudiant_BE {
    char matricule_BE[10];
    char nom_BE[50];
    char prenom_BE[50];
    int age_BE;
    struct Etudiant_BE* suivant_BE; // Gestion des collisions avec une liste chaînée
} Etudiant_BE;

// Table de hachage
extern Etudiant_BE* table_hachage_BE[TAILLE_TABLE_BE];

void generer_matricule_BE(char* matricule_BE);
int fonction_hachage_BE(const char* matricule_BE);
void inserer_etudiant_BE(const char* nom_BE, const char* prenom_BE, int age_BE);
Etudiant_BE* rechercher_etudiant_BE(const char* matricule_BE);
void supprimer_etudiant_BE(const char* matricule_BE);
void afficher_table_BE();

#endif