#include "prototypes.h"

int verif(int x, adherent T[], int n) {
    int i;
    i = 0;
    int find=0;
    do {
        if (T[i].id==x) {
            find=1;
        }
    } while ((find!=1)&&(i<n));
    return(find);
}

adherent saisirAd() {
    adherent x;
    printf("entrer l'id\n");
    scanf("%d", &x.id);
    printf("votre nom:\n");
    fflush(stdin);
    gets(x.nom);
    printf("votre prenom:\n");
    fflush(stdin);
    gets(x.prenom);
    printf("plafond de remboursement\n");
    scanf("%f", &x.plafond);
    return x;
}

void ajouterAdherent(adherent T[], int n) {
    adherent x;
    x = saisirAd();
    if (verif(x.id, T, n) == 1) {
        printf("adhérent exist déja \n");
    } else {
        T[n] = x;
        n = n + 1;
    }
    return(n);
}
void afficherAdherent(adherent T[], int n) {
    int i;
    for (i = 0; i <= n; i++) {
        printf("adherent num %d\n", i + 1);
        printf("%d\n", T[i].id);
        puts(T[i].nom);
        puts(T[i].prenom);
        printf("%f\n", T[i].plafond);
    }
}
constat saisirConstat(adherent T[], int n) {
    constat x;
    do {
        printf("choisir le type: \n");
        printf("0: accident de voiture \n");
        printf("1: incendie\n");
        printf("2: vol\n");
        scanf("%d", &x.type);
    } while ((x.type < 0) && (x.type > 2));
    do {
        printf("id\n");
        scanf("%d", &x.iid);
    } while (verif(x.iid, T, n) != 1);
    printf("référence\n");
    scanf("%d", &x.reff);
    printf("prix de remboursement\n");
    scanf("%f", &x.price);
    return x;
}
void initializer(constat M[][5]) {
    int i, j;
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 4; j++) {
            M[i][j].reff = 0;
        }
    }
}

int verifSaturation(constat M[][5], int l) {
    int saturation=1;
    constat c;
    int i;
    for (i=0;i<5;i++) {
        c=M[l][i];
        if (c.reff>0) {
            saturation=0;
        }
    }
    return(saturation);
}

void ajouterconstat(constat M[][5], constat cc) {
    int l=cc.type;
    int i=0;
    int check=0;
    constat c;
    if (verifSaturation(M,l)==1) {
        printf("Sature!!!");
    } else {
        do {
            if (M[l][i].reff==0) {
                M[l][i]=cc;
                check=1;
            } else {
                i++;
            }
        } while ( (i<5) && (check==1) );
    }
}

void afficherconstat(constat M[][5]) {
    int i,j;
    for (i=0;i<3;i++) {
        for(j=0;j<5;j++) {
            if(M[i][j].reff!=0) {
                printf("constat num %d\n",j+1);
                switch(M[i][j].type) {
                    case 0:
                         printf("accident de voiture\n");
                         break;
                    case 1:
                         printf("incendie \n");
                         break;
                    case 2:
                         printf("vol\n");
                         break;
                }
                printf("%d",M[i][j].reff);
                printf("%f",M[i][j].price);
            }
        }
    }
}

constat chercherconstat(int r,constat M[][5]) {
    constat x;
    int i,j;
    for(i=0;i<=2;i++){
        for(j=0;j<=4;j++){
            if(M[i][j].reff==r) {
                return M[i][j];
            }
        }
    }
    x.reff=-1;
    return x;
}

int verifierRemboursement(int r,constat M[][5],adherent T[],int n) {
    int i;
    constat x;
    x=chercherconstat(r,M);
    if(x.reff==-1){
       return 0;
    }
    i=0;
    while((T[i].id!=chercherconstat(r,M).iid)&&(i<=n)) {
        i++;
    }
    if(i>n) {
        return 0;
    } else {
        if(chercherconstat(r,M).price<=T[i].plafond){
             return 1;
        } else {
            return 0;
        }
    }
}

void mettreajour(constat M[][5],adherent T[],int n) {
    int i,r;
    printf("donner reference\n");
    scanf("%d",&r);
    if (verifierRemboursement(r,M,T,n)==0) {
        printf("!!!ERREUR!!!\n");
    } else {
        i=0;
        while((T[i].id!=chercherconstat(r,M).iid)&&(i<=n)) {
        i++;
        }
        T[i].plafond=T[i].plafond-((T[i].plafond*10)/100);
    }
}

void statistiques(constat M[][5]) {
    float r;
    int i,x;
    do {
        printf("choisir le type: \n");
        printf("0: accident de voiture \n");
        printf("1: incendie\n");
        printf("2: vol\n");
        scanf("%d",&x);
    } while(x>2&&x<0);
    r=0;
    for(i=0;i<=4;i++) {
        r=r+M[x][i].price;
    }
    printf("montant total des remboursemt %f \n",r);
}
