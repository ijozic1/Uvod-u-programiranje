#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int iste_cifre(int a, int b) {
  int iste_cifre = 1, nizA[20], nizB[20], i, j, velA = 0, velB = 0, broj, min,
      temp;
  broj = abs(a);
  while (broj > 0) {
    nizA[velA++] = broj % 10;
    broj = broj / 10;
  }
  broj = abs(b);
  while (broj > 0) {
    nizB[velB++] = broj % 10;
    broj = broj / 10;
  }
  /*Izbacimo iz nizova brojeve koji se ponavljaju*/
  for (i = 0; i < velA; i++) {
    for (j = i + 1; j < velA; j++) {
      if (nizA[i] == nizA[j]) {
        nizA[j] = nizA[velA - 1];
        velA--;
        j--;
      }
    }
  }
  for (i = 0; i < velB; i++) {
    for (j = i + 1; j < velB; j++) {
      if (nizB[i] == nizB[j]) {
        nizB[j] = nizB[velB - 1];
        velB--;
        j--;
      }
    }
  }
  /*Sada cemo sortirati nizove i provjeriti jesu li jednaki*/
  for (i = 0; i < velA; i++) {
    min = i;
    for (j = i; j < velA; j++) {
      if (nizA[j] < nizA[min])
        min = j;
    }
    temp = nizA[i];
    nizA[i] = nizA[min];
    nizA[min] = temp;
  }
  for (i = 0; i < velB; i++) {
    min = i;
    for (j = i; j < velB; j++) {
      if (nizB[j] < nizB[min])
        min = j;
    }
    temp = nizB[i];
    nizB[i] = nizB[min];
    nizB[min] = temp;
  }
  if (velA != velB)
    iste_cifre = 0;
  /*Prodjemo kroz nizove i vidimo jessu li isti*/
  else {
    for (i = 0; i < velA; i++) {
      if (nizA[i] != nizB[i]) {
        iste_cifre = 0;
        break;
      }
    }
  }
  return iste_cifre;
}

int main() {
  int a, b;
  printf("Unesite broj a: ");
  scanf("%d", &a);
  printf("Unesite broj b: ");
  scanf("%d", &b);
  if (iste_cifre(a, b) == 1)
    printf("Brojevi a u b se sastoje od istih cifara.");
  else
    printf("Brojevi a i b se ne sastoje od istih cifara.");
  return 0;
}
