#include <stdio.h>

int main() {
    int i, j, p, q, r, s;
    int A[10][10], B[10][10], C[20][20];

    /* === OVDJE UBACITI KOD === */
    /*Prvo se unose dimenzije matrice A*/
    printf("Unesite dimenzije matrice A (p q): ");
    scanf("%d %d", &p, &q);
    if(p<1 || q<1){
        printf("Neispravne dimenzije matrice!");
        return 0;
    }
    if(p>10 ||q>10){
        printf("Matrica A je prevelika!");
        return 0;
    }

    /*Ako su dimenzije matrice A ispravne, unosimo dimenzije matrice B*/
    printf("Unesite dimenzije matrice B (r s): ");
    scanf("%d %d", &r, &s);
    if(r<1 || s<1){
        printf("Neispravne dimenzije matrice!");
        return 0;
    }
    if(r>10 || s>10){
        printf("Matrica B je prevelika!");
        return 0;
    }
    
    /*Trebamo provjeriti jesu li matrice saglasne za nadovezivanje*/
    if(p!=r){
        printf("Matrice nisu saglasne za konkatenaciju!");
        return 0;
    }

    /*Ako su ispunjeni svi uslovi, krecemo sa unosom matrica A i B*/
    printf("Matrica A:\n");
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            if(j==0) printf("%d. red: ", i+1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Matrica B:\n");
    for(i=0; i<r; i++){
        for(j=0; j<s; j++){
            if(j==0) printf("%d. red: ", i+1);
            scanf("%d", &B[i][j]);
        }
    }

    /*Kada smo zavrsili sa unosom matrice, trebamo kreirati matricu C*/
    /*Matrica C ima p ili r redova, te q+s kolona*/
    for(i=0; i<p; i++){
        for(j=0; j<q+s; j++){
            if(j<q){
                C[i][j]=A[i][j];
            }
            else{
                C[i][j]=B[i][j-q];
            }
        }
    }

    /*=== KRAJ UBACENOG KODA ===*/

    /* Ispis matrice C na ekran */
    printf ("Matrica C:\n");
    for (i=0; i<p; i++) {
        for (j=0; j<q+s; j++) {
            printf ("%4d", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
