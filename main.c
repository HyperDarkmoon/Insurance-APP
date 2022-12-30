#include "prototypes.h"


int main() {
    int x,in=0;
    int n=-1;
    adherent T[20];
    constat M[3][5];
    do {
        printf("*******************\n");
        printf("1-Ajouter adherent\n");
        printf("2-Afficher adherent\n");
        printf("3-Initialiser\n");
        printf("4-Ajouter constat\n");
        printf("5-Afficher constat\n");
        printf("6-Mettre A jour\n");
        printf("7-Statistiques\n");
        printf("0-Quitter\n");
        printf("*******************\n");
        scanf("%d",&x);
        switch (x) {
            case 1:
                ajouterAdherent(T,n);
                if (T[n+1].id!=0) {
                    n++;
                }
                break;
            case 2:
                if (n<=-1) {
                    printf("passer par la 1 er etapes :)\n");
                } else {
                    afficherAdherent(T,n);
                }
                break;
            case 3:
                in++;
                initializer(M);
                break;
            case 4:
                if (in==0) {
                    printf("passer par letape 3 :)\n");
                } else {
                    constat cc = saisirConstat(T,n);
                    ajouterconstat(M,cc);
                }
                break;
            case 5:
                if (in==0) {
                    printf("passer par l'etape 3+4 :)\n");
                } else {
                    afficherconstat(M);
                }
                break;
            case 6:
                mettreajour(M,T,n);
                break;
            case 7:
                statistiques(M);
                break;
        }
    } while ( (x!=0) && (x>=1) && (x<=7) );
    printf("vous avez quitter :)\n");
    printf("********Merci********\n");
    return 0;
}
