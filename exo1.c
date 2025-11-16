#include <stdio.h>
#include <stdlib.h>

typedef struct Etudiant {
    int id;
    float moyenne;
    char nom[30];
    struct Etudiant *suiv;
} Etudiant;

// creeation de l'etudiant
Etudiant* creer() {
    Etudiant *etu = malloc(sizeof(Etudiant));

    printf("ID : ");
    scanf("%d", &etu->id);

    printf("Nom : ");
    scanf("%s", etu->nom);

    printf("Moyenne : ");
    scanf("%f", &etu->moyenne);

    etu->suiv = NULL;
    return etu;
}

// l'ajout en tete
void ajouter_tete(Etudiant **tete) {
    Etudiant *etu = creer();
    etu->suiv = *tete;
    *tete = etu;
}

// Ajouter après un ID donné 
void ajouter_apres(Etudiant *tete) {
    int id;
    printf("Ajouter apres ID : ");
    scanf("%d", &id);

    while (tete != NULL && tete->id != id)
        tete = tete->suiv;

    if (tete == NULL) {
        printf("ID non trouve.\n");
        return;
    }

    Etudiant *etu = creer();
    etu->suiv = tete->suiv;
    tete->suiv = etu;
}

//Supprimer par ID 
void supprimer(Etudiant **tete) {
    int id;
    printf("ID a supprimer : ");
    scanf("%d", &id);

    Etudiant *c = *tete, *prec = NULL;

    while (c != NULL && c->id != id) {
        prec = c;
        c = c->suiv;
    }

    if (c == NULL) {
        printf("ID non trouver.\n");
        return;
    }

    if (prec == NULL) *tete = c->suiv;
    else prec->suiv = c->suiv;

    free(c);
}

// Afficher  la liste 
void afficher(Etudiant *tete) {
    if (!tete) {
        printf("Liste vide.\n");
        return;
    }
    while (tete != NULL) {
        printf("ID:%d  Nom:%s  Moyenne:%.2f\n",
            tete->id, tete->nom, tete->moyenne);
        tete = tete->suiv;
    }
}

// la moy de l'etu
void moyenne(Etudiant *tete) {
    int count = 0;
    float somme = 0;

    while (tete != NULL) {
        somme += tete->moyenne;
        count++;
        tete = tete->suiv;
    }

    if (count == 0) printf("Aucun etudiant.\n");
    else printf("Moyenne generale: %.2f\n", somme / count);
}

// fonction pour supp
void supprimer_dernier(Etudiant **tete) {
    if (*tete == NULL) return;

    Etudiant *c = *tete, *prec = NULL;

    while (c->suiv != NULL) {
        prec = c;
        c = c->suiv;
    }

    if (prec == NULL) *tete = NULL;
    else prec->suiv = NULL;

    free(c);
}

// vider
void vider(Etudiant **tete) {
    Etudiant *c = *tete;
    while (c != NULL) {
        Etudiant *tmp = c;
        c = c->suiv;
        free(tmp);
    }
    *tete = NULL;
}



int main() {
    Etudiant *tete = NULL;
    int choix;

    do {
        printf("\n1.Ajouter en tete\n2.Ajouter apres\n3.Supprimer\n4.Afficher\n5.Moyenne\n6.Supprimer dernier\n7.Vider\n8.Quitter\nChoix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouter_tete(&tete); break;
            case 2: ajouter_apres(tete); break;
            case 3: supprimer(&tete); break;
            case 4: afficher(tete); break;
            case 5: moyenne(tete); break;
            case 6: supprimer_dernier(&tete); break;
            case 7: vider(&tete); break;
        }
    } while (choix != 8);

    return 0;
}