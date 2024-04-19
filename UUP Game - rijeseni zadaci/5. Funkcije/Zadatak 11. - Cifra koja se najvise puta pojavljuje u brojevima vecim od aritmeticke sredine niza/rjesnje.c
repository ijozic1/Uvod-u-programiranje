#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.0001

double aritmeticka(int *niz, int vel, int *max_cifra, int *min_cifra) {
  int *p = niz, *r;
  int niz_cifara[10] = {0}, broj, cifra, max_i = 0, min_i = 0, i;
  double aritmeticka = 0;
  /*prvo izracunajmo sumu clanova niza*/
  while (p < niz + vel) {
    aritmeticka = aritmeticka + (*p);
    p++;
  }
  /*Sada nadjemo aritmeticku vrijednost niza*/
  aritmeticka = aritmeticka / vel;
  /*Sada trebamo iz niza izbaciti sve clanove koji su manji ili jednaki
   * aritmetickoj sredini*/
  p = niz;
  while (p < niz + vel) {
    if (fabs(*p - aritmeticka) < EPSILON || *p < aritmeticka) {
      r = p;
      /*Izbacimo clanove koji neodgovaraju i smanjimo velicinu niza*/
      while (r < niz + vel - 1) {
        *r = *(r + 1);
        r++;
      }
      vel--;
      p--;
    }
    p++;
  }
  /*Ako u nizu nema elemenata vecih od aritmetcke sredine, onda treba zavrsiti
   * program*/
  {
    if (vel == 0) {
      *max_cifra = -1;
      *min_cifra = -1;
      return aritmeticka;
    }
  }
  /*Kada imamo sredjen niz, sada cemo u pomocni niz sa ciframa staviti sve cifre
   * kako bi smo pronasli onu koja se ponavlja najveci i najmanji broj puta*/
  p = niz;
  while (p < niz + vel) {
    broj = abs(*p);
    /*rastavljamo brojeve na cifre i spremamo ih u niz_cifara*/
    do {
      cifra = broj % 10;
      niz_cifara[cifra]++;
      broj /= 10;
    } while (broj != 0);
    p++;
  }
  /*Kada imamo kreiran niz sa brojacem cifara, ostaje jos da nadjemo cifre koje
   * se najvise i najmanje ponavljaju*/
  *max_cifra = niz_cifara[0];
  *min_cifra = 10;
  for (i = 0; i < 10; i++) {
    /*U varijable max_cifra i min_cifra nam se trebaju upisati cifre, a to su
     * nista drugo do indeksi iz niza_cifri*/
    if (niz_cifara[i] >= (*max_cifra)) {
      *max_cifra = niz_cifara[i];
      max_i = i;
    }
    if (niz_cifara[i] < (*min_cifra) && niz_cifara[i] != 0) {
      *min_cifra = niz_cifara[i];
      min_i = i;
    }
  }
  /*Kad smo prosli kroz niz, jos da u pokazivace spremimo cifru koja se ponavlja
   * najveci i najmanji broj puta*/
  /*printf("\nNajveca cifra max_i %d", max_i);*/
  *max_cifra = max_i;
  /*printf("\nNajveca cifra pokazivacem %d", *max_cifra);
  printf("\nNajmanja cifra min_i %d", min_i);*/
  *min_cifra = min_i;
  /*printf("\nNajmanja cifra pokazivacem %d\n\n", *min_cifra);*/
  return aritmeticka;
}

int main() {
  int niz[100], n, vel = 0, t=0, m=0;
  double Aritmeticka;
  int *Max_cifra, *Min_cifra, *p;
  Max_cifra = &t;
  Min_cifra = &m;
  p = niz;
  printf("Unesite clanove niza (0 za kraj): ");
  do {
    scanf("%d", &n);
    if (n != 0)
      niz[vel++] = n;
  } while (n != 0 || vel >= 100);
  Aritmeticka = aritmeticka(p, vel, Max_cifra, Min_cifra);
  printf("Najvise puta se ponavlja cifra %d a najmanje cifra %d.", *Max_cifra, *Min_cifra);
  return 0;
}