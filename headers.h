#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nom[15];
    char prenom[15];
    float plafond;
}adherent;
typedef struct {
    int type;
    int iid;
    int reff;
    float price;
}constat;

int verif(int x,adherent T[],int n);
adherent saisirAd();
void ajouterAdherent(adherent T[],int n);
void afficherAdherent(adherent T[],int n);
constat saisirConstat(adherent T[],int n);
void initializer(constat M[][5]);
void ajouterconstat(constat M[][5], constat cc);
void afficherconstat(constat M[][5]);
constat chercherconstat(int r,constat M[][5]);
int verifierRemboursement(int r,constat M[][5],adherent T[],int n);
void mettreajour(constat M[][5],adherent T[],int n);
void statistiques(constat M[][5]);
int verifSaturation(constat M[][5], int l);
