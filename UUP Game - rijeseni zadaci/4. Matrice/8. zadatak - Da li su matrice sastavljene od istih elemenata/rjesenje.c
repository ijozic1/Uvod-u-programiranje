#include <stdio.h>

int main() {
    int A[100][100], B[100][100], C[100][100], i, j, M, N;
    int isti_elementi = 0;
    do {
        printf ("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
    } while (M<1 || N<1 || M>100 || N>100);
    
    printf("Unesite clanove matrice A: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf("%d", &A[i][j]);
    printf("Unesite clanove matrice B: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf("%d", &B[i][j]);
      printf("Unesite clanove matrice C: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf("%d", &C[i][j]);
  
    /* === OVDJE UBACITI KOD === */
    int zbirA=0, proizvodA=1, zbirB=0, proizvodB=1, zbirC=0, proizvodC=1, isti_elementiB=0, isti_elementiC=0;
    double recA=0, recB=0, recC=0;
    /*Provjeriti cemo da li su proizvod i zbir elemenata, te zbir reciprocnih vrijednosti elemenata zadanih matrica jednaki*/
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            zbirA+=A[i][j];
            if(A[i][j]!=0){
                proizvodA*=A[i][j];
                recA+=1./A[i][j];
            }
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            zbirB+=B[i][j];
            if(B[i][j]!=0){
                proizvodB*=B[i][j];
                recB+=1./B[i][j];
            }
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            zbirC+=C[i][j];
            if(C[i][j]!=0){
                proizvodC*=C[i][j];
                recC+=1./C[i][j];
            }
        }
    }
    if(zbirA==zbirB && proizvodA==proizvodB && (recA-recB<0.001 || recB-recA<0.001)) 
        isti_elementiB=1;
    if(zbirA==zbirC && proizvodA==proizvodC && (recA-recC<0.001 || recC-recA<0.001))
        isti_elementiC=1;
    if(isti_elementiB==1 && isti_elementiC==1)
        isti_elementi=1;
    /*=== KRAJ UBACENOG KODA ===*/

    if (isti_elementi) printf("DA\n"); else printf("NE\n");
    return 0;
}
