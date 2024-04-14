#include <stdio.h>

int main() {
    int matrica[10][10], i, j, min;

    /*Sada unosimo elemente matrice*/
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            scanf("%d", &matrica[i][j]);
        }
    }

    /*Ostalo je jos da pronadjemo najmanji element na glavnoj dijagonali*/
    min=matrica[0][0];
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(i==j && matrica[i][j]<min){
                min=matrica[i][j];
            }
        }
    }

    /*printf("Najmanji element na glavnoj dijagonali je %d", min);*/
    printf("%d", min);
    return 0;
}
