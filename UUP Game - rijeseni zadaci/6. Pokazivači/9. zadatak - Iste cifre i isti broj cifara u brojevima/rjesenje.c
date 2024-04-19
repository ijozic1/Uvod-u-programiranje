#include <math.h>
#include <stdio.h>

int *istecifre(int *niz, int vel, int *p) {
  int *q = niz;
  int *r;
  int broj = *p;
  int niz_broj[10] = {0}, niz_niz[10] = {0}, iste_cifre = 0, i = 0, j, min = 0,
      velicina, vel_broj, temp;
  /*U niz_broj cemo staviti cifre broja, u niz_niz cemo stavlati brojke iz clanova niza*/
  do {
    niz_broj[i++] = broj % 10;
    broj = broj / 10;
  } while (broj != 0);
  vel_broj = i;
  /*Sada cemo sortirati niz_broj*/
  for (i = 0; i < vel_broj; i++) {
    min = i;
    for (j = i; j < vel_broj; j++) {
      if (niz_broj[j] < niz_broj[min]) {
        min = j;
      }
    }
    temp = niz_broj[i];
    niz_broj[i] = niz_broj[min];
    niz_broj[min] = temp;
  }
  /*Kada imamo sortiran niz_broj trebamo proci kroz clanove proslijedjenog niza i uporediti ima li iste cifre*/
  /*q=p;*/
  while (q < niz + vel) {
    broj = *q;
    /*Moramo incijalizirati pomocni niz na 0 da ne bi doslo do nekog slucajnog podudaranja*/
    for (i = 0; i < 10; i++)
      niz_niz[i] = 0;
    i = 0;
    do {
      niz_niz[i++] = broj % 10;
      broj = broj / 10;
    } while (broj != 0);
    velicina = i;
    /*Sada sortiramo niz_niz da bismo mogli porediti sa niz_broj*/
    for (i = 0; i < velicina; i++) {
      min = i;
      for (j = i; j < velicina; j++) {
        if (niz_niz[j] < niz_niz[min]) {
          min = j;
        }
      }
      temp = niz_niz[i];
      niz_niz[i] = niz_niz[min];
      niz_niz[min] = temp;
    }
    /*Ostalo je jos da uporedimo niz*/
    if (velicina != vel_broj) {
      iste_cifre = 0;
    } else {
      for (i = 0; i < velicina; i++) {
        if (niz_broj[i] == niz_niz[i] && p != q)
          iste_cifre = 1;
        else {
          iste_cifre = 0;
          break;
        }
      }
    }
    /*Ako su nizovi identicni, onda smo pronasli broj na koji trebamo vratiti pokazivac*/
    if (iste_cifre == 1 && i == velicina) {
      r = q;
      break;
    }
    /*A ako nismo, onda nastavljamo dalje kroz proslijedjenji niz*/
    else
      q++;
  }
  if (iste_cifre == 0)
    r = p;
  return r;
}

int main() {
  /*int niz[] = {1, 2, 3, 411, 4, 321, 144, 4141, 141, 6};
  int *p = istecifre(niz, 10, niz + 3);
  printf("Broj %d pozicija %d", *p, (int)(p - niz));*/
  return 0;
}
