#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Puissance 4.h"
#include <windows.h> // Temps de chargement(4000)
#define CLEAR fflush(stdin);

typedef struct {
    char id[20];
    char nom[50];
    char mots_passe[50];
    int victoire;
    int defaite;
    int egalite;
} joueur;

int i, j, N;
joueur T[100];
joueur connectes[100];
int nb_connectes = 0;
int jeux_joues = 0;
int dernier_joueur = -1;

void creation() {
    char cpy_mp[20], cpy_nom[20];
    printf("Saisir le nombre de joueurs : ");
    do {
        scanf("%d", &N);
    } while (N <= 0);

    for (i = 0; i < N; i++) {
        CLEAR;
        printf("\nSaisir le nom du joueur %d : ", i + 1);
        scanf ("%s",&T[i].nom);

        CLEAR;
        printf("Saisir le mot de passe du joueur %d : ", i + 1);
        scanf("%s",T[i].mots_passe);

        strncpy(cpy_nom, T[i].nom, 3);
        strncpy(cpy_mp, T[i].mots_passe, 3);
        sprintf(T[i].id, "Gamer-%s-%s", cpy_nom, cpy_mp);
        printf("L'ID du joueur %d est %s\n", i + 1, T[i].id);

        for (j = 0; j < i; j++) {
            if (strcmp(T[i].id, T[j].id) == 0) {
                printf("Cette ID existe deja, veuillez entrer de nouvelles informations :\n");
                i--;
                break;
            }
        }

        T[i].victoire = 0;
        T[i].defaite = 0;
        T[i].egalite = 0;
    }
}

void connecter() {
    int choix;
    char password[50];
    nb_connectes = 0;

    for (i = 0; i < N; i++) {
        printf("\nJoueur %d : %s voulez-vous vous connecter ? \n", i + 1, T[i].nom);
        printf("Choisir 0 pour oui et 1 pour non : ");
        do {
            scanf("%d", &choix);
        } while (choix != 0 && choix != 1);

        if (choix == 0) {
            do {
                printf("Veuillez entrer le mot de passe : ");
                CLEAR;
                scanf("%s",&password);

                if (strcmp(T[i].mots_passe, password) != 0) {
                    printf("\nLe mot de passe saisi est invalide. Veuillez reessayer.\n");
                }
            } while (strcmp(T[i].mots_passe, password) != 0);

            printf("Le joueur %d : %s est connecte !\n", i + 1, T[i].nom);
            connectes[nb_connectes] = T[i];
            nb_connectes++;
            if (nb_connectes==2) {
                printf("\nDeux joueurs sont connectes, la partie peut commencer\n");
                jeux ();
                return;
            }
        }
    }
}

#define L 6
#define C 7

void afficher_plateau(char plateau[L][C]) {
    for (int l = 0; l < L; l++) {
        printf("+---+---+---+---+---+---+---+\n");
        for (int c = 0; c < C; c++) {
            printf("| %c ", plateau[l][c]);
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+\n");
}

//int plateau_rempli_a_80(char plateau[L][C]) {
//    int count = 0;
//    for (int l = 0; l < L; l++) {
//        for (int c = 0; c < C; c++) {
//            if (plateau[l][c] != ' ') {
//                count++;
//            }
//        }
//    }
//    return (count >= 80);
//}

void jeux() {
    char plateau[L][C];
    int joueur_courant = 0;
    int l, c;
    int fin_jeu = 0;
    int plateau_plein = 0;

    for (l = 0; l < L; l++) {
        for (c = 0; c < C; c++) {
            plateau[l][c] = ' ';
        }
    }

    while (!fin_jeu) {
        afficher_plateau(plateau);

        printf("\n%s, entrez le numéro de la colonne (1-7) ou vous voulez placer votre piece : ", connectes[joueur_courant].nom);
        scanf("%d", &c);
        c--;

        for (l = L - 1; l >= 0; l--) {
            if (plateau[l][c] == ' ') {
                break;
            }
        }

        if (l < 0) {
            printf("\nCette colonne est pleine. Veuillez essayer a nouveau.\n");
            continue;
        }

        plateau[l][c] = (joueur_courant % 2 == 0) ? 'X' : 'O';

        // victoire horizontale
        for (l = 0; l < L; l++) {
            for (c = 0; c < C - 3; c++) {
                if (plateau[l][c] != ' ' &&
                    plateau[l][c] == plateau[l][c + 1] &&
                    plateau[l][c] == plateau[l][c + 2] &&
                    plateau[l][c] == plateau[l][c + 3]) {
                    fin_jeu = 1;
                    break;
                }
            }
            if (fin_jeu) break;
        }

        // victoire verticale
        for (l = 0; l < L - 3; l++) {
            for (c = 0; c < C; c++) {
                if (plateau[l][c] != ' ' &&
                    plateau[l][c] == plateau[l + 1][c] &&
                    plateau[l][c] == plateau[l + 2][c] &&
                    plateau[l][c] == plateau[l + 3][c]) {
                    fin_jeu = 1;
                    break;
                }
            }
            if (fin_jeu) break;
        }

        // diagonale (de gauche à droite)
        for (l = 0; l < L - 3; l++) {
            for (c = 0; c < C - 3; c++) {
                if (plateau[l][c] != ' ' &&
                    plateau[l][c] == plateau[l + 1][c + 1] &&
                    plateau[l][c] == plateau[l + 2][c + 2] &&
                    plateau[l][c] == plateau[l + 3][c + 3]) {
                    fin_jeu = 1;
                    break;
                }
            }
            if (fin_jeu) break;
        }

        // diagonale (de droite à gauche)
        for (l = 0; l < L - 3; l++) {
            for (c = 3; c < C; c++) {
                if (plateau[l][c] != ' ' &&
                    plateau[l][c] == plateau[l + 1][c - 1] &&
                    plateau[l][c] == plateau[l + 2][c - 2] &&
                    plateau[l][c] == plateau[l + 3][c - 3]) {
                    fin_jeu = 1;
                    break;
                }
            }
            if (fin_jeu) break;
        }

        plateau_plein = 1;
        for (l = 0; l < L; l++) {
            for (c = 0; c < C; c++) {
                if (plateau[l][c] == ' ') {
                    plateau_plein = 0;
                    break;
                }
            }
            if (!plateau_plein) break;
        }
        if (plateau_plein) {
            fin_jeu = 1;
        }

        if (fin_jeu) {
            break;
        }

        joueur_courant = (joueur_courant + 1) % nb_connectes;
    }

    afficher_plateau(plateau);

    if (plateau_plein) {
        printf("\nLe jeu est un match nul.\n");
        for (i = 0; i < nb_connectes; i++) {
            connectes[i].egalite++;
        }
    } else {
        printf("\n%s gagne !\n", connectes[joueur_courant].nom);
        connectes[joueur_courant].victoire++;
        for (i = 0; i < nb_connectes; i++) {
            if (i != joueur_courant) {
                connectes[i].defaite++;
            }
        }
    }

    jeux_joues++;

//    if (plateau_rempli_a_80(plateau)) {
//        dernier_joueur = joueur_courant;
//    }

    for (i = 0; i < nb_connectes; i++) {
        if (i != joueur_courant) {
            for (j = 0; j < N; j++) {
                if (strcmp(connectes[i].id, T[j].id) == 0) {
                    T[j].defaite = connectes[i].defaite;
                    T[j].egalite = connectes[i].egalite;
                    break;
                }
            }
        } else {
            for (j = 0; j < N; j++) {
                if (strcmp(connectes[i].id, T[j].id) == 0) {
                    T[j].victoire = connectes[i].victoire;
                    T[j].egalite = connectes[i].egalite;
                    break;
                }
            }
        }
    }
}


void statistiques() {
    int meilleur_vainqueur = 0, pire_perdant = 0;

    for (i = 1; i < N; i++) {
        if (T[i].victoire > T[meilleur_vainqueur].victoire) {
            meilleur_vainqueur = i;
        }
        if (T[i].defaite > T[pire_perdant].defaite) {
            pire_perdant = i;
        }
    }
    printf("\nStatistiques des joueurs :\n");
    for (i = 0; i < N; i++) {
        printf("Joueur %s : %d victoires, %d defaites, %d egalites\n", T[i].nom, T[i].victoire, T[i].defaite, T[i].egalite);
    }
    printf("Meilleur vainqueur : %s avec %d victoires\n", T[meilleur_vainqueur].nom, T[meilleur_vainqueur].victoire);
    printf("Pire perdant : %s avec %d defaites\n", T[pire_perdant].nom, T[pire_perdant].defaite);
}

void quitter() {
    int sortir;

    do {
        printf("\nVoulez-vous quitter le jeu ? (0 pour oui, 1 pour non) : ");
        scanf("%d", &sortir);
    } while (sortir != 0 && sortir != 1);

    if (sortir == 0) {
        statistiques();
        printf("\nMerci d'avoir joue !\n");
        exit(0);
    }   else {
        system("cls");
            menu();
        }
}

void menu(){
int choix;
    printf("\n\n");
    printf("  ######  ##   ##   ####     #####    #####     ##     ##   ##    ####   #######              ###\n");
    printf("  ##  ##  ##   ##    ##     ##   ##  ##   ##   ####    ###  ##   ##  ##   ##   #             ####     ##       ##\n");
    printf("  ##  ##  ##   ##    ##     #        #        ##  ##   #### ##  ##        ## #              ## ##     ##       ##\n");
    printf("  #####   ##   ##    ##      #####    #####   ##  ##   ## ####  ##        ####             ##  ##   ######   ######\n");
    printf("  ##      ##   ##    ##          ##       ##  ######   ##  ###  ##        ## #             #######    ##       ##\n");
    printf("  ##      ##   ##    ##     ##   ##  ##   ##  ##  ##   ##   ##   ##  ##   ##   #               ##     ##       ##\n");
    printf("  ####     #####    ####     #####    #####   ##  ##   ##   ##    ####   #######               ##\n\n");

    Sleep(4000);

    do {
        printf("\n1. Creer des joueurs\n");
        printf("2. Connecter des joueurs\n");
        printf("3. Jouer\n");
        printf("4. Afficher les statistiques\n");
        printf("5. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creation();
                system("cls");
                printf("\nCreation de joueur reussi ! Passez a la prochaine etape.\n");

                break;
            case 2:
                connecter();
                //system("cls");
                printf("\nConnexion des joueurs reussi!. Avanceeel\n");
                break;
            case 3:
                system("cls");
                statistiques();

                //if (nb_connectes > 1) {
                //    jeux();
                  //  reinitialiser();
                //} else {
                //    printf("Vous devez avoir au moins deux joueurs connectes pour jouer.\n");
                //}
                break;
            case 4:
                statistiques();
                break;
            case 5:
                quitter();
                break;
            default:
                printf("Option invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

   return 0;
}

