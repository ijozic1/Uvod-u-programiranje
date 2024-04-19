#include <math.h>
#include <stdio.h>

int izbaci_podniz(int *p1, int *p2, const int *q1, const int *q2) {
  int *trenutni,*kraj, *pocetak = p1;
  const int *pocetak_drugog;
  int br_izbacenih = 0;
  while (p1 < p2) {
    trenutni = p1;
    pocetak_drugog = q1;
    *trenutni=*p1;
    while (trenutni < p2 && pocetak_drugog < q2 && *trenutni == *pocetak_drugog) {
      trenutni++;
      pocetak_drugog++;
    }
    if (pocetak_drugog == q2) {
      kraj = trenutni;
      trenutni = p1;
      /*Trebamo prepisati niz*/
      while (kraj < p2) {
        /*Prepisivanje niza*/
        *trenutni = *kraj;
        trenutni++;
        kraj++;
      }
      br_izbacenih += q2 - q1;
      p2 -= q2 - q1;
      p1=pocetak-1;
    }
    p1++;
  }
  return br_izbacenih;
}
int main() {
  /*int niz1[12] = {1, 1, 2, 3, 2, 1, 2, 3, 3, 1, 2, 9};
  int niz2[1] = {9};
  int k = izbaci_podniz(niz1, niz1 + 12, niz2, niz2 + 1);
  int i;
  for (i = 0; i < 12 - k; i++)
    printf("%d ", niz1[i]);*/
  return 0;
}
