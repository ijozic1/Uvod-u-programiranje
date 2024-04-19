#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int proste_sume(int *niz1, int vel1, int *niz2, int vel2) {
  int br_elemenata = 0, suma_broja, broj, cifra, i, j, prosta_suma = 1;
  int *p = niz1;
  int *q = niz2;
  while (p < niz1 + vel1) {
    suma_broja = 0;
    broj = abs(*p);
    if (broj < 2)
      prosta_suma = 0; /*Ako je broj manji od dva, ni suma ne moze biti prosta*/
    else
      prosta_suma = 1;
    /*Prvo trebamo izracunati sumu broja*/
    do {
      suma_broja = suma_broja + broj % 10;
      broj = broj / 10;
    } while (broj != 0);
    if(suma_broja<2) prosta_suma=0;/*Ako je suma manja od 2, ona ne moze biti prosta*/
    
    for (i = 2; i <= suma_broja; i++) {
      if (i < suma_broja && suma_broja % i == 0) {
        prosta_suma = 0;
        break;
      }
    }

    if (prosta_suma == 1 && q < niz2 + vel2) {
      *q = *p;
      br_elemenata++;
      q++;
    } else if (q >= niz2 + vel2)
      break;
    p++;
  }
  return br_elemenata;
}

int main() {
  /*int niz1[] = {10, 11, 12, 13, 14, 15, 16, 17};
  int niz2[4];
  int n1 = sizeof niz1 / sizeof *niz1, n2 = sizeof niz2 / sizeof *niz2;
  int vel = proste_sume(niz1, n1, niz2, n2), i;
  printf("niz1: ");
  for (i = 0; i < n1; ++i)
    printf("%d ", niz1[i]);
  printf("\nniz2: ");
  for (i = 0; i < vel; ++i)
    printf("%d ", niz2[i]);*/
  return 0;
}
