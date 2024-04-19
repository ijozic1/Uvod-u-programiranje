#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void oduzmi_cifre(int *niz, int vel) {
  /*Kreirati cemo pomocni niz u koji cemo smjestati pojedinacne cifre broja,
   * koje cemo kasnije oduzimati*/
  int niz_cifara[10] = {0}, i, j, vel_cifre, vel_broja = 0, broj, cifra,
      potencija, t;
  int *p = niz;
  while (p < niz + vel) {
    broj = abs(*p);
    vel_broja = 0;
    /*Hajdemo izbrojati koliko cifara ima svaki od brojeva*/
    do {
      broj = broj / 10;
      vel_broja++;
    } while (broj != 0);
    broj = abs(*p);
    /*Vratimo sve cifre na 0*/
    for (i = 0; i < 10; i++)
      niz_cifara[i] = 0;
    vel_cifre = 0;
    /*Sada kada znamo broj cifara, mozemo ih smjestiti u pomocni niz sa
     * ciframa*/
    for (i = vel_broja - 1; i >= 0; i--) {
      t = pow(10, i);
      cifra = broj / t;
      niz_cifara[vel_cifre++] = cifra;
      broj = broj % t;
    }
    /*Kada imamo kreiran niz cifara sada ih trebamo oduzeti*/
    /*Ako broj ima jednu cifru, onda nakon oduzimanja ona postaje 0*/
    if (vel_cifre == 1)
      niz_cifara[0] = 0;
    else {
      for (i = 0; i < vel_cifre - 1; i++) {
        niz_cifara[i] = abs(niz_cifara[i + 1] - niz_cifara[i]);
      }
      /*Kada izvrsimo oduzimanje cifara, broj ce imati jednu cifru manje*/
      vel_cifre--;
    }
    /*Ostalo je jos da prepravljeni broj smjestimo u pocetni niz*/
    broj = 0;
    for (i = 0; i < vel_cifre; i++) {
      potencija = pow(10,vel_cifre-1-i);
      broj = broj + niz_cifara[i] * potencija;
    }
    *p = broj;
    p++;
  }
}

int main() {
  int niz[100], n, vel = 0, i;
  printf("Unesite niz cifara (0 za kraj): ");
  do {
    scanf("%d", &n);
    if (n != 0)
      niz[vel++] = n;
  } while (n != 0 || vel >= 100);

  oduzmi_cifre(niz, vel);

  printf("Novi niz glasi: ");
  for (i = 0; i < vel; i++) {
    printf("%d", niz[i]);
    if (i != vel - 1)
      printf(", ");
  }
  return 0;
}
