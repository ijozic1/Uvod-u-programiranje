#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int jednake_cifre(int a, int b) {
  int iste_cifre = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0,      a8 = 0, a9 = 0, a0 = 0;
  int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0,
      b0 = 0, cifraA, cifraB, cifra, broj;
  b = abs(b);
  a = abs(a);
  /*Mirsina ideja koja je padala na dva testa*/
  /*do {
    cifraB = b % 10;
    broj = a;
    do {
      cifraA = broj % 10;
      if (cifraA == cifraB) {
        iste_cifre = 1;
        break;
      } else
        iste_cifre = 0;
      broj = broj / 10;
    } while (broj != 0);
    if (iste_cifre == 0)
      break;
    b = b / 10;
  } while (b != 0);*/
  do {
    cifra = b % 10;
    b = b / 10;
    switch (cifra) {
    case 1:
      b1 = 1;
      break;
    case 2:
      b2 = 1;
      break;
    case 3:
      b3 = 1;
      break;
    case 4:
      b4 = 1;
      break;
    case 5:
      b5 = 1;
      break;
    case 6:
      b6 = 1;
      break;
    case 7:
      b7 = 1;
      break;
    case 8:
      b8 = 1;
      break;
    case 9:
      b9 = 1;
      break;
    case 0:
      b0 = 1;
      break;
    }
  } while (b != 0);
  do {
    cifra = a % 10;
    a = a / 10;
    switch (cifra) {
    case 1:
      a1 = 1;
      break;
    case 2:
      a2 = 1;
      break;
    case 3:
      a3 = 1;
      break;
    case 4:
      a4 = 1;
      break;
    case 5:
      a5 = 1;
      break;
    case 6:
      a6 = 1;
      break;
    case 7:
      a7 = 1;
      break;
    case 8:
      a8 = 1;
      break;
    case 9:
      a9 = 1;
      break;
    case 0:
      a0 = 1;
      break;
    }
  } while (a != 0);

  if (a1 == b1 && a2 == b2 && a3 == b3 && a4 == b4 && a5 == b5 && a6 == b6 &&
      a7 == b7 && a8 == b8 && a9 == b9 && a0 == b0)
    iste_cifre = 1;
  else
    iste_cifre = 0;

  return iste_cifre;
}

int izbaci_iste_cifre(int *nizA, int velA, int *nizB, int velB) {
  int *p = nizB;
  int *q, *r;
  int iste_cifre;
  while (p < nizB + velB) {
    q = nizA;
    iste_cifre = 0;
    while (q < nizA + velA) {
      iste_cifre = jednake_cifre(*q, *p);
      if (iste_cifre == 1) {
        break;
      }
      q++;
    }
    if (iste_cifre == 1) {
      r = p;
      while (r < nizB + velB - 1) {
        *r = *(r + 1);
        r++;
      }
      p--;
      velB--;
    }
    p++;
  }
  return velB;
}

int main() {
  int nizA[100], nizB[100], n, i = 0, velA, velB;
  printf("Unesite niz A: ");
  do {
    scanf("%d", &n);
    if (n != -1)
      nizA[i++] = n;
    else
      break;
  } while (n != -1 && i < 100);
  velA = i;
  printf("Unesite niz B: ");
  i = 0;
  do {
    scanf("%d", &n);
    if (n != -1)
      nizB[i++] = n;
    else
      break;
  } while (n != -1 && i < 100);
  velB = i;
  velB = izbaci_iste_cifre(nizA, velA, nizB, velB);
  for (i = 0; i < velB; i++) {
    printf("%d", nizB[i]);
    if (i != velB - 1)
      printf(",");
    else
      printf(".");
  }
  return 0;
}
