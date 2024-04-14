#include <stdio.h>

/* Ovdje napisite vasu funkciju */
int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3) {
  int i, j, t, m, ponavljanje12, ponavljanje23, ponavljanje13, ponavljanje123,
      brojac = 0;
  /*Trebaju nam elementi koji se pojavljuju u dva od tri niza, prvo poredimo
   * prvi i drugi niz*/
  for (i = 0; i < vel1; i++) {
    ponavljanje12 = 0;
    ponavljanje123 = 0;
    for (j = 0; j < vel2; j++) {
      if (niz1[i] == niz2[j]) {
        ponavljanje12 = 1;
        for (t = 0; t < vel3; t++) {
          if (niz1[i] == niz3[t]) {
            ponavljanje123 = 1;
            break;
          }
        }
        break;
      }
    }
    /*Trebamo provjeriti da li smo ranije vec provjeravali isti broj da ga ne
     * brojimo dva puta*/
    if (ponavljanje12 == 1) {
      for (m = 0; m < i; m++) {
        if (niz1[m] == niz1[i]) {
          ponavljanje12 = 0;
          break;
        }
      }
    }
    if (ponavljanje12 == 1 && ponavljanje123 == 0) {
      brojac++;
      /*printf("%d ", niz1[i]);*/
    }
  }
  /*Slicno trebamo uraditi i za nizove 2 i 3*/
  for (i = 0; i < vel2; i++) {
    ponavljanje23 = 0;
    ponavljanje123 = 0;
    for (j = 0; j < vel3; j++) {
      if (niz2[i] == niz3[j]) {
        ponavljanje23 = 1;
        for (t = 0; t < vel1; t++) {
          if (niz2[i] == niz1[t]) {
            ponavljanje123 = 1;
            break;
          }
        }
        break;
      }
    }
    /*Provjerimo da li smo ranije imali istio element*/
    if (ponavljanje23 == 1) {
      for (m = 0; m < i; m++) {
        if (niz2[m] == niz2[i]) {
          ponavljanje23 = 0;
          break;
        }
      }
    }
    if (ponavljanje23 == 1 && ponavljanje123 == 0) {
      brojac++;
      /*printf("%d ", niz2[i]);*/
    }
  }
  /*Ostalo je jos da provjerimo za prvi i treci niz*/
  for (i = 0; i < vel1; i++) {
    ponavljanje13 = 0;
    ponavljanje123 = 0;
    for (j = 0; j < vel3; j++) {
      if (niz1[i] == niz3[j]) {
        ponavljanje13 = 1;
        for (t = 0; t < vel2; t++) {
          if (niz1[i] == niz2[t]) {
            ponavljanje123 = 1;
            break;
          }
        }
        break;
      }
    }
    /*Provjerimo da li smo vec imali isti element*/
    if (ponavljanje13 == 1) {
      for (m = 0; m < i; m++) {
        if (niz1[i] == niz1[m]) {
          ponavljanje13 = 0;
          break;
        }
      }
    }
    if (ponavljanje13 == 1 && ponavljanje123 == 0) {
      brojac++;
      /*printf("%d ", niz1[i]);*/
    }
  }
  /*printf("\n\nVelicina1 %d\nVelicina2 %d\nVelicina3 %d\n", vel1, vel2, vel3);*/
  return brojac;
}
/* Kraj napisane funkcije */

int main() {
  int A[100], B[100], C[100], velA, velB, velC, i, rez;
  printf("Unesite niz A (-1 za kraj): ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &A[i]);
    if (A[i] == -1)
      break;
  }
  velA = i;
  printf("Unesite niz B (-1 za kraj): ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &B[i]);
    if (B[i] == -1)
      break;
  }
  velB = i;
  printf("Unesite niz C (-1 za kraj): ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &C[i]);
    if (C[i] == -1)
      break;
  }
  velC = i;

  rez = dva_od_tri(A, velA, B, velB, C, velC);

  printf("%d clanova se nalaze u dva od tri niza.", rez);
  return 0;
}
