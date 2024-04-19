#include <stdio.h>

int main() {
    int matA[20][20], matB[20][20], matC[20][20], i, j, Va, Vb, Sa, Sb, Vc, Sc;
    int rotirana=1,temp;
    /*Unos dimenzija A*/
    do{
        printf("Unesite sirinu i visinu matrice A: ");
        scanf("%d %d", &Sa, &Va);
        if(Sa<1 || Sa>20 || Va<1 || Va>20) printf("Prekoracene dimenzije!\n");
    }while(Sa<1 || Sa>20 || Va<1 || Va>20);
    /*Unos elemenata A*/
    printf("Unesite clanove matrice A: ");
    for(i=0; i<Va; i++){
        for(j=0; j<Sa; j++){
            scanf("%d", &matA[i][j]);
        }
    }
    /*Unos dimenzija B*/
    do{
        printf("Unesite sirinu i visinu matrice B: ");
        scanf("%d %d", &Sb, &Vb);
        if(Sb<1 || Sb>20 || Vb<1 || Vb>20) printf("Prekoracene dimenzije!\n");
    }while(Sb<1 || Sb>20 || Vb<1 || Vb>20);
    /*Unos elemenata B*/
    printf("Unesite clanove matrice B: ");
    for(i=0; i<Vb; i++){
        for(j=0; j<Sb; j++){
            scanf("%d", &matB[i][j]);
        }
    }
    /*Provjeravamo da li su matrice saglasnih dimenzija da bi mogle biti rotirane*/
    if(Va!=Sb || Sa!=Vb){
        printf("NE\n");
        return 0;
    }
    /*Sada cemo kreirati matricu C koja ce biti rotirana matrica A, a zatim uporediti da li je C jednako B*/
    /*Prvo transponujemo A*/
    Vc=Sa;
    Sc=Va;
    for(i=0; i<Vc; i++){
        for(j=0; j<Sc; j++){
            matC[i][j]=matA[j][i];
        }
    }
    /*Sada jos rotiramo matricu C, tj, zamijenimo raspored kolona*/
    for(i=0; i<Vc; i++){
        for(j=0; j<Sc/2; j++){
            temp=matC[i][j];
            matC[i][j]=matC[i][Sc-j-1];
            matC[i][Sc-j-1]=temp;
        }
    }

    /*Usporedba da li je C jednako B*/
    if(Vc!=Vb || Sc!=Sb) rotirana=0;
    else{
        for(i=0; i<Vb; i++){
            for(j=0; j<Sb; j++){
                if(matC[i][j]!=matB[i][j]){
                    rotirana=0;
                    break;
                }
            }
            if(rotirana==0) break;
        }
    }
    /*Ostalo je jos da ispisemo da ili ne*/
    if(rotirana==1) printf("DA\n");
    else printf("NE\n");

    return 0;
}
