#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.0001

int main() {
  int n, i, j, k;
  double matricaA[50][50] = {0}, multiplikator;
  /*Unos dimenzija matrice*/
  do {
    printf("Unesite cijeli broj n koji je dimenzija kvadratne matrice: ");
    scanf("%d", &n);
    if (n < 2 || n > 50)
      printf("Pogresan unos, n<50!\n");
  } while (n < 2 || n > 50);
  /*Unos elemenata matrice*/
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j == 0)
        printf("Unesite elemente %d. reda: ", i + 1);
      scanf("%lf", &matricaA[i][j]);
    }
  }
  /*Vrsimo eliminaciju*/
  for (i = 0; i <n - 1; i++) {
    if (fabs(matricaA[i][i]-0.0)<EPSILON) {
      printf("Pivot element je nula!\nUnesena matrica nije invertibilna");
      return 0;
    }
    for (j = i + 1; j < n; j++) {
      multiplikator = matricaA[j][i] / matricaA[i][i];

      for (k = i; k < n ; k++) {
        matricaA[j][k] = matricaA[j][k] - multiplikator * matricaA[i][k];
      }
    }
  }
  /*Sada jos treba ispisati matricu U*/
  printf("Gornja trogaona matrica koju dobijemo od matrice A glasi: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%5.2lf", matricaA[i][j]);
    }
    printf("\n");
  }
  return 0;
}
