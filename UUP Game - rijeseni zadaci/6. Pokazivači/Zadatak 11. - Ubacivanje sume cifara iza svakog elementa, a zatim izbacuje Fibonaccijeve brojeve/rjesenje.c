#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int ubaci(int *niz, int vel) {
  int *p = niz;
  int *i, suma = 0, broj;
  while (p < niz + vel) {
    broj = abs(*p);
    suma = 0;
    do {
      suma = suma + broj % 10;
      broj = broj / 10;
    } while (broj != 0);
    for (i = niz + vel; i > p + 1; i--) {
      *i = *(i - 1);
    }
    *(p + 1) = suma;
    vel++;
    p = p + 2;
  }
  *i = suma;
  return vel;
}

int Fibonacci(int proslijedjeni_br) {
  int fibonaccijev = 0;
  int i = 1, temp, Fibonacci = 1, broj = 0;
  while (Fibonacci <= proslijedjeni_br) {
    if (Fibonacci == proslijedjeni_br) {
      fibonaccijev = 1;
      break;
    }
    temp = Fibonacci;
    Fibonacci = broj + Fibonacci;
    broj = temp;
  }
  return fibonaccijev;
}

int izbaci(int *niz, int vel) {
  int *p = niz, *j;
  int fibonaccijev = 0;
  while (p < niz + vel) {
    fibonaccijev = Fibonacci(*p);
    /*Izbacimo element iz niza i izvrsimo prepisivanje ostalih*/
    if (fibonaccijev == 1) {
      for (j = p; j < niz + vel - 1; j++) {
        *j = *(j + 1);
      }
      vel--;
      p--;
    }
    p++;
  }
  return vel;
}

int main() {
  int niz[20], i, vel = 0;
  printf("Unesite niz od 10 brojeva: ");
  for (i = 0; i < 10; i++) {
    scanf("%d", &niz[i]);
    vel++;
  }
  vel = ubaci(niz, vel);
  vel = izbaci(niz, vel);
  if (vel == 0)
    printf("Prazan niz.");
  else {
    printf("Modificirani niz glasi: ");
    for (i = 0; i < vel; i++) {
      printf("%d", niz[i]);
      if (i < vel - 1)
        printf(", ");
      else
        printf(".");
    }
  }
  return 0;
}
