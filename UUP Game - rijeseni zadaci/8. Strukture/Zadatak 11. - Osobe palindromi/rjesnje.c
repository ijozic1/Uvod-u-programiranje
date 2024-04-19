#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Datum {
  int dan, mjesec, godina;
};
struct Osoba {
  char ime[20], prezime[20];
  struct Datum datum_rodjenja;
};

int provjeri_je_li_string_palindrom(char *str) {
  char *kraj = str;
  int palindrom = 1;
  while (*kraj != '\0')
    kraj++;
  kraj = kraj - 1;
  while (kraj > str) {
    if (tolower(*kraj) == tolower(*str)) {
      palindrom = 1;
    } else {
      palindrom = 0;
      break;
    }
    str++;
    kraj--;
  }
  return palindrom;
}


int provjeri_je_li_broj_palindrom(struct Datum rodjendan) {
  int palindrom = 1, godina;
  int i=0, pozicija=0;
  char niz[7]="AAAAAA";
  int broj[4];
  char*p=niz;
  char*kraj=niz;
  broj[0] = rodjendan.dan;
  broj[1] = rodjendan.mjesec;
  godina=rodjendan.godina/10;
  broj[2]=godina%10;
  broj[3] = rodjendan.godina % 10;
  for(i=0; i<4; i++){
      pozicija+=sprintf(niz+pozicija, "%d", broj[i]);
  }
  /*printf("%s",niz);
  printf("\n");*/
  /*Sad kad imamo string mozemo provjeriti je li on palindrom*/
  kraj=niz;
  p=niz;
  while (*kraj != '\0')
    kraj++;
  kraj = kraj - 1;
  while (kraj > p) {
    if (*kraj == *p) {
      palindrom = 1;
    } else {
      palindrom = 0;
      break;
    }
    p++;
    kraj--;
  }
  return palindrom;
}
  
int izbaci_palindrome(struct Osoba *niz, int vel) {
  int ime_palindrom = 1, prezime_palindrom = 1, datum_palindrom = 1, i, j;
  for (i = 0; i < vel; i++) {
    ime_palindrom = provjeri_je_li_string_palindrom(niz[i].ime);
    prezime_palindrom = provjeri_je_li_string_palindrom(niz[i].prezime);
    datum_palindrom = provjeri_je_li_broj_palindrom(niz[i].datum_rodjenja);

    if (ime_palindrom == 1 || prezime_palindrom == 1 || datum_palindrom == 1) {
      for (j = i; j < vel - 1; j++) {
        niz[j] = niz[j + 1];
      }
      vel--;
      i--;
    }
  }
  return vel;
}

int main() {
  int i, vel = 3;
  struct Osoba osobe[4] = {{ "Pero", "Peric", { 3, 8, 1983} }, { "Anka", "Anic", { 30, 11, 2003} }, { "Meho", "Mehic", { 1, 12, 2011} }, { "Suljo", "Suljic", { 9, 7, 1979} } };
  vel = izbaci_palindrome(osobe, vel);
  for (i = 0; i < vel; i++) {
    printf("%s %s %d.%d.%d\n", osobe[i].ime, osobe[i].prezime,
           osobe[i].datum_rodjenja.dan, osobe[i].datum_rodjenja.mjesec,
           osobe[i].datum_rodjenja.godina);
  }
  return 0;
}