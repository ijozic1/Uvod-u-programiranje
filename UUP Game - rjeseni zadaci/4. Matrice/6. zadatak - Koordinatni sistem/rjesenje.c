#include <stdio.h>

int main() {
    int tacka_i, tacka_j, i, j, t, l, n;
    int sistem[20][20]={{0}};
    do{
        printf("Unesite broj tacaka: ");
        scanf("%d", &n);
        if(n<1 || n>10) printf("Pogresan unos\n");
    }while(n<1 || n>10);

    /*Nakon sto smo unijeli odgovarajuci broj tacaka, trebamo unijeti njihove koordinate*/
    for(i=0; i<n; i++){
        printf("Unesite %d. tacku: ", i+1);
        scanf("%d %d", &tacka_i, &tacka_j);
        if(tacka_i<0 || tacka_i>19 || tacka_j<0 || tacka_j>19){
            printf("Pogresan unos\n");
            i--;
        }
        /*Ako su koordinate unutar zadanog rang-a, trebamo zapamtiti te koordinate u matrici koord. sistema*/
        else{
            for(j=0; j<20; j++){
                for(t=0; t<20; t++){
                    if(j==tacka_j && t==tacka_i){
                        sistem[j][t]=1;
                    }
                }
            }
        }
    }

    /*Sada trebamo ispisati tacke na odgovarajucim pozicijama*/
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            if(sistem[i][j]==1)
            printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
