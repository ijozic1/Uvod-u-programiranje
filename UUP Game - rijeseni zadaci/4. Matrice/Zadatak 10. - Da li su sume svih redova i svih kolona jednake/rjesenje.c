#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001

int main() {
    int M, N, i, j, z_kolona=1, z_redova=1;
    double matrica[100][100], z_reda=0, z_kolone=0, niz_k[100], niz_r[100];
    /*Prvo unosimo dimenzije matrice*/
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M<0 || M>100 || N<0 || N>100) printf("Neispravan unos!\n");
    }while(M<0 || M>100 || N<0 || N>100);
    /*Sada unosimo elemente matrice*/
    printf("Unesite clanove matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%lf", &matrica[i][j]);
        }
    }
    /*Sada racunamo zbir redova, te vrijednost za svaki red smjestimo u niz_r*/
    for(i=0; i<M; i++){
        z_reda=0;
        for(j=0; j<N; j++){
            z_reda+=matrica[i][j];
            if(j==N-1) niz_r[i]=z_reda;
        }
    }
    /*Sada racunamo zbir kolona, te vrijednosti za svaku kolonu smjestamo u niz_k*/
    for(j=0; j<N; j++){
        z_kolone=0;
        for(i=0; i<M; i++){
            z_kolone+=matrica[i][j];
            if(i==M-1) niz_k[j]=z_kolone;
        }
    }
    /*Sada prodjemo kroz nizove i provjerimo da li su zbirovi jrednaki*/
    for(i=1; i<M; i++){
        if(fabs(niz_r[i]-niz_r[i-1])>EPSILON){
            z_redova=0;
            break;
        }
    }
    for(j=1; j<N; j++){
        if(fabs(niz_k[j]-niz_k[j-1])>EPSILON){
            z_kolona=0;
            break;
        }
    }
    /*Sada jos ispisemo da li su zbirovi jednaki ili ne*/
    if(z_redova==1) printf("DA\n");
    else printf("NE\n");
    if(z_kolona==1) printf("DA\n");
    else printf("NE\n");
    return 0;
}
