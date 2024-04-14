#include <math.h>
#include <stdio.h>

int main() {
    int matrica[10][10], i, j, max, max_red, min, min_red, temp;
    printf("Unesite elemente matrice: ");
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            scanf("%d", &matrica[i][j]);
        }
    }
    /*Inicijalizirati cemo da su nam i najveci i najmanji element u prvom redu, a zatim proci kreoz matricu i pronaci najveci i najmenji element*/
    min=matrica[0][0];
    min_red=0;
    max=matrica[i][j];
    max_red=0;

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(matrica[i][j]<min){
                min=matrica[i][j];
                min_red=i;
            }
            if(matrica[i][j]>max){
                max=matrica[i][j];
                max_red=i;
            }
        }
    }
    
    /*Sada trebamo provjeriti da li se najveci i najmanji element nalaze u istom redi, te ako se ne nalaze zamijeniti ta dva reda*/
    if(min_red==max_red) printf("Najmanji i najveci element se nalaze u istom redu.");
    else{
        for(j=0; j<10; j++){
            temp=matrica[max_red][j];
            matrica[max_red][j]=matrica[min_red][j];
            matrica[min_red][j]=temp;
        }
        printf("Nakon zamjene matrica glasi:\n");
        for(i=0; i<10; i++){
            for(j=0; j<10; j++){
                printf("%3d", matrica[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
