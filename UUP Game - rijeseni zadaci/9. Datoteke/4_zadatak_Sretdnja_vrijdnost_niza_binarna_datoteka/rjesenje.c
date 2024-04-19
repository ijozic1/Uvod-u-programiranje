#include <stdio.h>

/* Ovdje pisete funkcije unesi_niz i srednja_vrijednost */
int unesi_niz() {
  int velicina = 0, zapisano;
  double niz[100], n;
  FILE *ulaz;
  /*printf("Unesite clanove niza (-1 za kraj): ");*/
  do {
    scanf("%lf", &n);
    if (n != (-1) && velicina < 100) {
      niz[velicina] = n;
      velicina++;
    }
  } while (velicina < 100 && n != (-1));
  ulaz = fopen("niz.bin", "wb");
  if (ulaz == NULL) {
    return 0;
  } else {
    zapisano = fwrite(niz, sizeof(double), velicina, ulaz);
    if (ferror(ulaz)) {
      printf("Greska prilikom upisivanja u datoteku\n");
      printf("Zapisano je %d podatakata", zapisano);
      return 0;
    }
  }
  fclose(ulaz);
  return 1;
}

double srednja_vrijednost() {
  double srednja_vrijednost = 0;
  double niz[100];
  int ucitano = 0, i;
  FILE *ulaz;
  ulaz = fopen("niz.bin", "rb");
  if (ulaz == NULL) {
    return 0;
  } else {
    ucitano = fread(niz, sizeof(double), 100, ulaz);
    if (ucitano == 0) {
      return 0;
    }
    for (i = 0; i < ucitano; i++) {
      srednja_vrijednost += niz[i];
    }
  }
  srednja_vrijednost = srednja_vrijednost / ucitano;
  fclose(ulaz);
  return srednja_vrijednost;
}
/* Kraj napisanih funkcija */

int main() {
  unesi_niz();
  printf("%g\n", srednja_vrijednost());
  return 0;
}