#include <math.h>
#include <stdio.h>

int main() {
  int niz_brojeva[100], niz_cifara[1000], i = 0, j, min, vel_cifre = 0, vel_broj = 0, broj, cifra, brojac_cifara = 0, temp;
  printf("Unesite brojeve:\n");
  /*Unosimo clanove niza*/
  do {
    scanf("%d", &broj);
    if (broj < 1)
      break;
    else if(vel_broj<100){
      niz_brojeva[vel_broj++] = broj;
    }
    else break;
  } while (broj > 1 || vel_broj < 100);

  /*Clanove niza smjestamo u niz sa ciframa*/
  for (i = 0; i < vel_broj; i++) {
    /*Prva while petlja nam broji cifre unutar broja*/
    broj = niz_brojeva[i];
    while (broj > 0) {
      broj = broj / 10;
      brojac_cifara++;
    }
    /*Druga while petlja unosi brojeve u pomocni niz*/
    broj = niz_brojeva[i];
    while (brojac_cifara - 1 >=0) {
      cifra = broj / pow(10, brojac_cifara - 1);
      cifra = cifra % 10;
      niz_cifara[vel_cifre++] = cifra;
      brojac_cifara--;
    }
  }
  /*Sada izbacimo cifre koje se ponavljaju iz niza*/
  for (i = 0; i < vel_cifre; i++) {
      for (j = i+1; j < vel_cifre; j++) {
          if (niz_cifara[i] == niz_cifara[j]) {
            niz_cifara[j] = niz_cifara[vel_cifre-1];
            j--;
            vel_cifre--;
        }
        
    }
  }
  /*Sada trebamo sortirati cifre*/
  for (i = 0; i < vel_cifre; i++) {
    min = i;
    for (j = i; j < vel_cifre; j++) {
      if (niz_cifara[j] < niz_cifara[min]) {
        min = j;
      }
    }
    temp = niz_cifara[i];
    niz_cifara[i] = niz_cifara[min];
    niz_cifara[min] = temp;
  }
  /*Ostalo je jos da ispisemo niz*/
  printf("Cifre: ");
  for (i = 0; i < vel_cifre; i++) {
    printf("%d", niz_cifara[i]);
    if (i != vel_cifre - 1) printf(",");
    else printf(".");
  }

  return 0;
}
