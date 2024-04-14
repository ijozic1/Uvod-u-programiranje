#include <stdio.h>

void unesi(char *niz, int vel) {
  int i = 0;
  char z = getchar();
  if (z == '\n') {
    z = getchar();
  }
  while (z != '\n' && i < vel - 1) {
    niz[i] = z;
    i++;
    z = getchar();
  }
  niz[i] = '\0';
}

/* Ovdje napisite funkciju periodican */
int periodican(const char *string) {
  int periodican = 1, period = 0;
  const char *pocetak = string;
  const char *kraj = string;
  const char*p,*q;
  string++;
  while (*string != '\0') {
    if (*string == *pocetak && (*(string+1)=='\0' || *(string + 1) == *(pocetak + 1)) && (*(string+1)=='\0' || *(string+2)=='\0' || *(string + 2) == *(pocetak + 2) && (*(string+1)=='\0' || *(string+2)=='\0' || *(string+3)=='\0' ||  *(string + 3) == *(pocetak + 3)))) {
      kraj = string;
      break;
    }
    string++;
  }
  if (kraj == pocetak) {
    period = 0;
    periodican = 0;
    return 0;
  } else {
    period = kraj - pocetak;
    while (*kraj != '\0') {
      if (*kraj == *pocetak)
        periodican = 1;
      else {
        periodican = 0;
        return 0;
      }
      kraj++;
      pocetak++;
    }
  }

  return period;
}
/* Kraj napisane funkcije */

int main() {
  char tekst[100];
  printf("Unesite neki tekst: ");
  unesi(tekst, 100);
  int period = periodican(tekst);
  if (period > 0) {
    printf("Tekst je periodican sa periodom %d.\n", period);
  } else {
    printf("Tekst nije periodican.\n");
  }
  return 0;
}