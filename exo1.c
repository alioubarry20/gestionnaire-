#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Livre{
    int id;
    char titre[50];
    int annee;
    struct Livre* suivant;
}Livre;

typedef struct Liste
{
    Livre*premier;
    int nb_livres;
} Liste;



Liste* creer_liste(){
    Liste* liste = (Liste*)malloc(sizeof(Liste));

    liste->premier = NULL;
    liste->nb_livres = 0;
    return liste;
};

void insert_tete(Liste* liste, int id, const char* titre, int annee){
    if (liste==NULL)
    {
        exit(1);
    }
    Livre* nouveau = (Livre*)malloc(sizeof(Livre));
    
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    nouveau->id = id;
    strcpy(nouveau->titre, titre);
    nouveau->annee = annee;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    liste->nb_livres++;    

}

void insertFin(Liste *l,int id,char *titre,int annee){
    if (l==NULL)
    {
        exit(1);
    }
    Livre* nouveau = (Livre*)malloc(sizeof(Livre));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }

    nouveau->id=id;
    strcpy(nouveau->titre,titre);
    nouveau->annee=annee;
    nouveau->suivant=NULL;
    if(l->premier==NULL)
        l->premier=nouveau;
    else{
        Livre *tmp=l->premier;
        while(tmp->suivant) tmp=tmp->suivant;
        tmp->suivant=nouveau;
    }
    l->nb_livres++;

}








int main(int argc, char const *argv[])
{
    Liste *l= creer_liste();
    insert_tete(l,1,"Fable de la fontaine",1967);
    insertFin(l,2,"les miserable",1988);
    return 0;
}

