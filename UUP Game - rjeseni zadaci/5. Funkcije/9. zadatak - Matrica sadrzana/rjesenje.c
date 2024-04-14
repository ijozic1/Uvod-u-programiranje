#include <math.h>
#include <stdio.h>

int matrica_sadrzana(int mat1[100][100], int V1, int S1, int mat2[100][100], int V2, int S2) {
  int sadrzana = 0, i, j, t, k;
  if (V1 < V2 || S1 < S2)
    sadrzana = 0;
  else {
      /*Vanjske petlje su prije isle do V1 i S1 - Problem je što prisupate elementu matrice sa [i+t][j+k], tako da ako i
      dođe do npr v1-1, a t do v2-1 izlazite iz opsega mat1. 
      Moj savjet je da ograničite i i j petlje da idu do v1-v2 odnosno s1-s2 uključivo */
    for (i = 0; i <= V1-V2; i++) {
      for (j = 0; j <= S1-S2; j++) {
        if (mat1[i][j] == mat2[0][0]) {
          sadrzana = 1;
          for (t = 0; t < V2; t++) {
            for (k = 0; k < S2; k++) {
              if (mat2[t][k] != mat1[i + t][j + k]) {
                sadrzana = 0;
                break;
              }
            }
            if (sadrzana == 0)
              break;
          }
        }
        if (sadrzana == 1)
          break;
      }
      if (sadrzana == 1)
        break;
    }
  }
  return sadrzana;
}

int main() {
  int matA[100][100], matB[100][100];
  int Va, Vb, Sa, Sb, i, j, sadrzana;
  /*Inicijalizacija matrice A*/
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      matA[i][j] = -1;
    }
  }

  /*Inicijalizacija matrice B*/
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      matB[i][j] = -3;
    }
  }

  do {
    printf("Unesite dimenzije matrice A: ");
    scanf("%d %d", &Va, &Sa);
    if (Va < 1 || Va > 100 || Sa < 1 || Sa > 100)
      printf("Pogresne dimenzije matrice A!\n");
  } while (Va < 1 || Va > 100 || Sa < 1 || Sa > 100);
  do {
    printf("Unesite dimenzije matrice B: ");
    scanf("%d %d", &Vb, &Sb);
    if (Vb < 1 || Vb > 100 || Sb < 1 || Sb > 100)
      printf("Pogresne dimenzije matrice B!\n");
  } while (Vb < 1 || Vb > 100 || Sb < 1 || Sb > 100);

  /*Unos elemenata matrica*/
  printf("Unesite elemente matrice A:\n");
  for (i = 0; i < Va; i++) {
    for (j = 0; j < Sa; j++) {
      scanf("%d", &matA[i][j]);
    }
  }
  printf("Unesite elemente matrice B:\n");
  for (i = 0; i < Vb; i++) {
    for (j = 0; j < Sb; j++) {
      scanf("%d", &matB[i][j]);
    }
  }

  sadrzana = matrica_sadrzana(matA, Va, Sa, matB, Vb, Sb);

  if (sadrzana == 1)
    printf("Matrica B je sadrzana u matrici A.");
  else if (sadrzana==0)
    printf("Matrica B nije sadrzana u matrici A.");

  return 0;
}
