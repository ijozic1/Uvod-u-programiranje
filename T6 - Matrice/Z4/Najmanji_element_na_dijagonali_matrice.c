/*Napisati program koji učitava matricu cijelih brojeva dimenzija 10x10 te pronalazi najmanji
element na glavnoj dijagonali.*/
#include <stdio.h>
#include <math.h>

int main() {
    int matrica[10][10], i, j, min;
	printf("Unesite elemente matrice: ");
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            scanf("%d", & matrica[i][j]);
        }
    }

    min=matrica[0][0];
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(i==j && matrica[i][j]<min){
                min=matrica[i][j];
            }
        }
    }

    printf("Najmanji element na glavnoj dijagonali je: %d", min);
	return 0;
}
