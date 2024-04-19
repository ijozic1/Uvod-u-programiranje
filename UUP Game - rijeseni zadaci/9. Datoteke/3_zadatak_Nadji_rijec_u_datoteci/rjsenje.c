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

/* Ovdje napisite funkciju ime_u_datoteci */
int ime_u_datoteci(const char *datoteka, const char *ime) {
  int postoji = 0, trenutni=0;
  char znak;
  const char *p;
  FILE *ulaz;
  ulaz = fopen(datoteka, "r");
  if (ulaz == NULL) {
    printf("Datoteka ne postoji\n");
    return -1;
  } else {
    do {
      znak = fgetc(ulaz);
      trenutni=ftell(ulaz);
      if (znak != EOF) {
        p = ime;
        if (*p == znak) {
          while (*p != '\0' && *p == znak) {
            p++;
            znak = fgetc(ulaz);
          }
          if (*p == '\0') {
            postoji = 1;
            return postoji;
          }
        }
      }
      fseek(ulaz, trenutni, SEEK_SET);
    } while (znak != EOF);
  }
  fclose(ulaz);
  return postoji;
}
/* Kraj napisane funkcije*/

int main() {
  char datoteka[100], ime[100];
  printf("Unesite naziv datoteke: ");
  unesi(datoteka, 100);
  printf("Unesite trazeno ime: ");
  unesi(ime, 100);
  if (ime_u_datoteci(datoteka, ime))
    printf("Ime se nalazi u datoteci.\n");
  else
    printf("Ime se NE nalazi u datoteci.\n");
  return 0;
}
