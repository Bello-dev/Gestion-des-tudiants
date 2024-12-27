#include "fonction_bell.h"

// Fonction pour générer un matricule unique
void generer_matricule_BE(char* matricule_BE) {
    static int compteur_BE = 0; // Compteur pour garantir l'unicité
    char lettre_BE = 'A' + (rand() % 26); // Lettre aléatoire entre A et Z
    int nombre_BE = rand() % 10000;       // Nombre aléatoire entre 0000 et 9999
    snprintf(matricule_BE, 10, "24%c%04d", lettre_BE, nombre_BE + compteur_BE);
    compteur_BE++; // Incrémenter pour éviter les doublons
}

// Fonction de hachage
int fonction_hachage_BE(const char* matricule_BE) {
    int partie_numerique_BE = atoi(&matricule_BE[2]); // Convertir les 4 chiffres en entier
    int partie_caractere_BE = matricule_BE[1];       // Valeur ASCII de la lettre
    return (partie_numerique_BE + partie_caractere_BE) % TAILLE_TABLE_BE;
}

// Fonction d'insertion
void inserer_etudiant_BE(const char* nom_BE, const char* prenom_BE, int age_BE) {
    char matricule_BE[10];
    generer_matricule_BE(matricule_BE); // Génération du matricule

    int indice_BE = fonction_hachage_BE(matricule_BE);
    Etudiant_BE* nouvel_etudiant_BE = (Etudiant_BE*)malloc(sizeof(Etudiant_BE));
    strcpy(nouvel_etudiant_BE->matricule_BE, matricule_BE);
    strcpy(nouvel_etudiant_BE->nom_BE, nom_BE);
    strcpy(nouvel_etudiant_BE->prenom_BE, prenom_BE);
    nouvel_etudiant_BE->age_BE = age_BE;
    nouvel_etudiant_BE->suivant_BE = table_hachage_BE[indice_BE];
    table_hachage_BE[indice_BE] = nouvel_etudiant_BE;
    printf("Étudiant ajouté avec succès. Matricule généré : %s\n", matricule_BE);
}

// Fonction de recherche
Etudiant_BE* rechercher_etudiant_BE(const char* matricule_BE) {
    int indice_BE = fonction_hachage_BE(matricule_BE);
    Etudiant_BE* courant_BE = table_hachage_BE[indice_BE];
    while (courant_BE) {
        if (strcmp(courant_BE->matricule_BE, matricule_BE) == 0) {
            return courant_BE;
        }
        courant_BE = courant_BE->suivant_BE;
    }
    return NULL;
}

// Fonction de suppression
void supprimer_etudiant_BE(const char* matricule_BE) {
    int indice_BE = fonction_hachage_BE(matricule_BE);
    Etudiant_BE* courant_BE = table_hachage_BE[indice_BE];
    Etudiant_BE* precedent_BE = NULL;

    while (courant_BE) {
        if (strcmp(courant_BE->matricule_BE, matricule_BE) == 0) {
            if (precedent_BE) {
                precedent_BE->suivant_BE = courant_BE->suivant_BE;
            } else {
                table_hachage_BE[indice_BE] = courant_BE->suivant_BE;
            }
            free(courant_BE);
            printf("Étudiant supprimé avec succès.\n");
            return;
        }
        precedent_BE = courant_BE;
        courant_BE = courant_BE->suivant_BE;
    }
    printf("Étudiant non trouvé.\n");
}

// Fonction pour afficher les étudiants
void afficher_table_BE() {
    for (int i = 0; i < TAILLE_TABLE_BE; i++) {
        if (table_hachage_BE[i]) {
            Etudiant_BE* courant_BE = table_hachage_BE[i];
            printf("Index %d:\n", i);
            while (courant_BE) {
                printf("  Matricule: %s, Nom: %s, Prénom: %s, Âge: %d\n",
                       courant_BE->matricule_BE, courant_BE->nom_BE, courant_BE->prenom_BE, courant_BE->age_BE);
                courant_BE = courant_BE->suivant_BE;
            }
        }
    }
}