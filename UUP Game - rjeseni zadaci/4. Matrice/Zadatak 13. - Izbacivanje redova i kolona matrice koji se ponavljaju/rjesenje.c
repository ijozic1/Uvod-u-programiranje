#include <math.h>
#include <stdio.h>

int main() {
  int matrica[200][200], i, j, t, k, M, N, ponavljanje;
  do {
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &M, &N);
    if (M < 1 || M > 200 || N < 1 || N > 200)
      printf("Brojevi nisu u trazenom opsegu.\n");
  } while (M < 1 || M > 200 || N < 1 || N > 200);

  printf("Unesite elemente matrice: ");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &matrica[i][j]);
    }
  }
  /*Sada trazimo redove koji se ponavljaju*/
  for (i = 0; i < M; i++) {
    for (j = i+1; j < M; j++) {
      ponavljanje = 0;
      if (matrica[j][0] == matrica[i][0]) {
        ponavljanje = 1;
        for (t = 0; t < N; t++) {
          if (matrica[j][t] == matrica[i][t])
            ponavljanje = 1;
          else {
            ponavljanje = 0;
            break;
          }
        }
        /*Ako su svi elementi isti, varijabla ponavljanje ce imati vrijdnost 1,
         * a varijabla t ce doci do N*/
        if (ponavljanje == 1 && t == N) {
          /*Petlja za prepisivanje elemenata*/
          for (t = j; t < M; t++) {
            for (k = 0; k < N; k++) {
              matrica[t][k] = matrica[t + 1][k];
            }
          }
          j--;
          M--;
        }
      }
    }
  }
  /*Sada trazimo kolone koje se ponavljaju*/
  for (i = 0; i < N; i++) {
    for (j = i+1; j < N; j++) {
      ponavljanje = 0;
      if (matrica[0][j] == matrica[0][i]) {
        ponavljanje = 1;
        for (t = 0; t < M; t++) {
          if (matrica[t][j] == matrica[t][i])
            ponavljanje = 1;
          else {
            ponavljanje = 0;
            break;
          }
        }
        /*Ako su svi elementi isti, varijabla ponavljanje ce imati vrijdnost 1,
         * a varijabla t ce doci do M*/
        if (ponavljanje == 1 && t == M) {
          /*Petlja za prepisivanje elemenata*/
          for (t = j; t < N; t++) {
            for (k = 0; k < M; k++) {
              matrica[k][t] = matrica[k][t + 1];
            }
          }
          j--;
          N--;
        }
      }
    }
  }
  /*Ostalo je jos da ispisemo matricu*/
  printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      printf("%5d", matrica[i][j]);
    }
    printf("\n");
  }
  return 0;
}
