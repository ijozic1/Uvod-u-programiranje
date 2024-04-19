#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.0001

int main() {
  int M, N, i, j, k, t;
  double matrica[100][100]={0}, sr_vrijednost = 0, sr_vr_red = 0, sr_vr_kol = 0;
  do {
    printf("Unesite vrijednosti M i N: ");
    scanf("%d %d", &M, &N);
    if (M < 1 || M > 100 || N < 1 || N > 100)
      printf("Vrijednosti su van opsega!\n");
  } while (M < 1 || M > 100 || N < 1 || N > 100);

  printf("Unesite clanove matrice: \n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      scanf("%lf", &matrica[i][j]);
      sr_vrijednost += matrica[i][j];
    }
  }
  sr_vrijednost = sr_vrijednost / (M * N);
  /*Sada treba proci kroz redove i izbaciti sve one koji imaju vecu sumu od
   * prosjecne sume svih clanova*/
  for (i = 0; i < M; i++) {
    sr_vr_red = 0;
    for (j = 0; j < N; j++) {
      sr_vr_red += matrica[i][j];
    }
    sr_vr_red = sr_vr_red / N;
    /*Ako je srednja suma reda veca od srednje sume elementa, treba izbaciti
     * red*/
    if (sr_vrijednost <sr_vr_red) {
      for (t = i; t < M ; t++) {
        for (k = 0; k < N; k++) {
          matrica[t][k] = matrica[t + 1][k];
        }
      }
      M--;
      i--;
    }
  }
  /*Sada provjerimo da li je ostala kolona koja ima srednju vrijdnost vecu od
   * srednje vrijednosti elemenata matrice*/
  for (i = 0; i < N; i++) {
    sr_vr_kol = 0;
    for (j = 0; j < M; j++) {
      sr_vr_kol += matrica[j][i];
    }
    sr_vr_kol = sr_vr_kol / M;
    /*Ako je srednja suma kolone veca od srednje sume elementa, treba izbaciti
     * kolonu*/
    if (sr_vrijednost <sr_vr_kol) {
      for (t = i; t < N; t++) {
        for (k = 0; k < M; k++) {
          matrica[k][t] = matrica[k][t + 1];
        }
      }
      N--;
      i--;
    }
  }
  /*Ostalo je jos da ispisemo matricu*/
  printf("Nakon izbacivanja matrica glasi:\n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      /*Zaokruzimo element prije ispisivanja*/
      matrica[i][j] = round(matrica[i][j] * 10) / 10;
      printf("%6.1lf", matrica[i][j]);
    }
    printf("\n");
  }
  return 0;
}
