#include <stdio.h>

int main() {
    int i, j, p, q, r, s;
    int A[10][10], B[10][10], C[20][20];

    /* === OVDJE UBACITI KOD === */
    printf("Unesite dimenzije matrice A (p q): ");
    scanf("%d %d", &p, &q);
    /*Provjerimo da li su dimenzije matrice A odgovarajuce*/
    if(p<1 || q<1){
        printf("Neispravne dimenzije matrice!");
        return 0;
    }
    if(p>10 || q>10){
        printf("Matrica A je prevelika!");
        return 0;
    }

    printf("Unesite dimenzije matrice B (r s): ");
    scanf("%d %d", &r, &s);
    /*Provjeravamo da li su dimenzije matrice B odgovarajuce*/
    if(r<1 || s<1){
        printf("Neispravne dimenzije matrice!");
        return 0;
    }
    if(r>10 || s>10){
        printf("Matrica B je prevelika!");
        return 0;
    }

    /*Provjeravamo mogu li se matrice nadovezati*/
    if(q!=s){
        printf("Matrice nisu saglasne za konkatenaciju!");
        return 0;
    }

    /*Ako je unos ispravan moramo unijeti elemente matrica A i B*/
    printf("Matrica A: ");
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            if(j==0) printf("%d. red: ", i+1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Matrica B: ");
    for(i=0; i<r; i++){
        for(j=0; j<s; j++){
            if(j==0) printf("%d. red: ", i+1);
            scanf("%d", &B[i][j]);
        }
    }

    /*Sada krecemo sa vertikalnim spajanjem matrica*/
    /*Imamo q ili s kolona, i p+r redova*/
    for(i=0; i<p+r; i++){
        for(j=0; j<q; j++){
            if(i<p){
                C[i][j]=A[i][j];
            }
            else{
                C[i][j]=B[i-p][j];
            }
        }
    }
    /*=== KRAJ UBACENOG KODA ===*/

    /* Ispis matrice C na ekran */
    printf ("Matrica C:\n");
    for (i=0; i<p+r; i++) {
        for (j=0; j<q; j++) {
            printf ("%4d", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
