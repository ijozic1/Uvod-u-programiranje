#include <math.h>
#include <stdio.h>

/* Ovdje napisite vase funkcije */
#include <stdlib.h>
#define EPSILON 0.0001

double stepen(double x) {
  int static pozivanje = 1;
  int static stepen = 1;
  double a;
  double static broj;
  if (pozivanje == 1) {
    broj = x;
  } else if (pozivanje > 1 && fabs(broj - x) > EPSILON) {
    stepen = 1;
    broj = x;
  }
  a = pow(broj, stepen);
  stepen++;
  pozivanje++;

  return a;
}

void stepenuj_niz(double A[], int s[], int duzina) {
  double x, broj;
  double m=1.0;
  int potencija;
  double *p = A;
  int *q = s;
  while (p < A + duzina) {
    x = *p;
    potencija = *q;
    while (potencija != 0) {
      broj = stepen(x);
      potencija--;
    }
    /*Pomocu sljedeceg poziva funkcije ce nam se funkcija stepenuj svaku put sigurno resetovati na prvi stepen*/
    stepen(m);
    *p = broj;
    p++;
    q++;
  }
}
/* Kraj napisanih funkcija */

int main() {
  int n, i, niz2[10000];
  double niz[10000];
  printf("Unesite velicinu za oba niza: ");
  scanf("%d", &n);
  printf("Unesite niz realnih brojeva: ");
  for (i = 0; i < n; i++) {
    scanf("%lf", &niz[i]);
  }
  printf("Unesite niz cijelih brojeva: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &niz2[i]);
  }
  stepenuj_niz(niz, niz2, n);
  printf("Nakon stepenovanja niz je: \n");
  for (i = 0; i < n; i++) {
    printf("%g ", niz[i]);
  }

  return 0;
}
