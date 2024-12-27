#include "fonction_bell.h"

Etudiant_BE* table_hachage_BE[TAILLE_TABLE_BE];

int main() {
    // Initialiser la table
    for (int i = 0; i < TAILLE_TABLE_BE; i++) {
        table_hachage_BE[i] = NULL;
    }

    srand(time(NULL)); // Initialiser la graine pour les nombres aléatoires

    int choix_BE;
    char nom_BE[50], prenom_BE[50];
    int age_BE;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Rechercher un étudiant\n");
        printf("3. Supprimer un étudiant\n");
        printf("4. Afficher tous les étudiants\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix_BE);

        switch (choix_BE) {
            case 1:
                printf("Entrez le nom : ");
                scanf("%s", nom_BE);
                printf("Entrez le prénom : ");
                scanf("%s", prenom_BE);
                printf("Entrez l'âge : ");
                scanf("%d", &age_BE);
                inserer_etudiant_BE(nom_BE, prenom_BE, age_BE);
                break;

            case 2:
                printf("Entrez le matricule de l'étudiant à rechercher : ");
                char matricule_BE[10];
                scanf("%s", matricule_BE);
                Etudiant_BE* etudiant_BE = rechercher_etudiant_BE(matricule_BE);
                if (etudiant_BE) {
                    printf("Étudiant trouvé :\n");
                    printf("  Matricule: %s, Nom: %s, Prénom: %s, Âge: %d\n",
                           etudiant_BE->matricule_BE, etudiant_BE->nom_BE, etudiant_BE->prenom_BE, etudiant_BE->age_BE);
                } else {
                    printf("Étudiant non trouvé.\n");
                }
                break;

            case 3:
                printf("Entrez le matricule de l'étudiant à supprimer : ");
                scanf("%s", matricule_BE);
                supprimer_etudiant_BE(matricule_BE);
                break;

            case 4:
                afficher_table_BE();
                break;

            case 5:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, réessayez.\n");
        }
    } while (choix_BE != 5);

    return 0;
}