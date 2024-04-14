#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001

int main() {
    int i, j, n;
    double matrica[30][30], max_O1, max_O4, min_O2, min_O3, simetricna14=0, simetricna23=0;

    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n<3 || n>30){
        printf("Unos pogresan!");
        return 0;
    }
    /*Unos elemenata matrice*/
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j==0) printf("Unesite elemente %d. reda: ", i+1);
            scanf("%lf", &matrica[i][j]);
        }
    }
    max_O1=matrica[0][1];
    max_O4=matrica[n-1][1];
    min_O2=matrica[1][0];
    min_O3=matrica[1][n-1];
    /*Prodjemo kroz matricu i nadjemo odgovarajuce elemente*/
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(j>i && i+j<n-1){
                    if(matrica[i][j]>max_O1) max_O1=matrica[i][j];
                }
                else if(i>j && i+j<n-1){
                    if(matrica[i][j]<min_O2) min_O2=matrica[i][j];
                }
                else if(i>j && i+j>n-1){
                    if(matrica[i][j]>max_O4) max_O4=matrica[i][j];
                }
                else if(j>i && j+i>n-1){
                    if(matrica[i][j]<min_O3) min_O3=matrica[i][j];
                }
            }
        }
    if(fabs(max_O1-max_O4)<EPSILON) simetricna14=1;
    if(fabs(min_O2-min_O3)<EPSILON) simetricna23=1;

    if(simetricna14==1 && simetricna23==1) printf("Matrica je simetricna!\n");
    else printf("Matrica nije simetricna!\n");

    max_O1=round(max_O1*1000)/1000;
    max_O4=round(max_O4*1000)/1000;
    min_O2=round(min_O2*1000)/1000;
    min_O3=round(min_O3*1000)/1000;

    printf("Elementi: O1 = %.3lf, O2 = %.3lf, O3 = %.3lf, O4 = %.3lf", max_O1, min_O2, min_O3, max_O4);
    return 0;
}
