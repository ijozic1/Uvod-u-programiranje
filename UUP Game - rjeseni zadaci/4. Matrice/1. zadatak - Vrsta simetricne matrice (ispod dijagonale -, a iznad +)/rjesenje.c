#include <stdio.h>

int main() {
    int matrica[50][50], i, j, n;
    
    printf("Unesite n: ");
    scanf("%d",&n);

    /* === OVDJE UBACITI KOD === */
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j){
                /*Elementi na glavnoj dijagonali su nule*/
                matrica[i][j]=0;
            }
            else{
                /*Ostali elemnti su jednaki razlici j-i, ispod dijagonale ce oni biti negativni jer i>j, a iznad dijagonale pozitivni jer je i<j*/
                matrica[i][j]=j-i;
            }
        }
    }
    /* === KRAJ UBACENOG KODA ===*/

    printf("Matrica glasi:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%4d", matrica[i][j]);
        printf("\n");
    }
    return 0;
}
