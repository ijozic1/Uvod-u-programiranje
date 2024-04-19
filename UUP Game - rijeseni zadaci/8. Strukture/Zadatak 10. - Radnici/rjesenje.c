#include <math.h>
#include <stdio.h>
#define DAN 16
#define MJESEC 2
#define GODINA 2022
/* Datum ispita 16.02. 2022.*/

struct Datum {
  int dan, mjesec, godina;
};

struct Radnik {
  char ime_prezime[30];
  struct Datum datum_rodjenja;
  int plata[12];
};

/*Funkcija unesi bi nam trebala da imamo main dio programa*/
void unesi(char niz[], int velicina) {
  char znak = getchar();
  if (znak == '\n')
    znak = getchar();
  int i = 0;
  while (i < velicina - 1 && znak != '\n') {
    niz[i] = znak;
    i++;
    znak = getchar();
  }
  niz[i] = '\0';
}

char prvo_slovo_prezimena(char ime_prezime[]) {
  char prvo_slovo = 'A';
  /*Da ne bismo provjeravali neku vrijednost izvan stringa, a znamo da se ime i
   * prezime unose u ovom formatu*/
  ime_prezime++;
  while (*ime_prezime != '\0') {
    if (*(ime_prezime - 1) == ' ') {
      prvo_slovo = *ime_prezime;
      break;
    }
    ime_prezime++;
  }
  return prvo_slovo;
}

int izdvoji_radnike(struct Radnik niz[], int vel) {
  struct Radnik *p = niz;
  int broj_radnika = 0, i, razlika_godina;
  char prvo_slovo_prez = 'A';
  double prosjecna_plata = 0;
  while (p < niz + vel) {
    prosjecna_plata = 0;
    for (i = 0; i < 12; i++) {
      prosjecna_plata += (*p).plata[i];
    }
    prosjecna_plata /= 12;
    if (prosjecna_plata >= 1000 && prosjecna_plata <= 2000) {
      prvo_slovo_prez = prvo_slovo_prezimena((*p).ime_prezime);
      if (prvo_slovo_prez == 'R' || prvo_slovo_prez == 'r') {
        /*Treba provjeriti i datum rodjenja i onda uvecati broj_radnika*/
        razlika_godina = GODINA - (*p).datum_rodjenja.godina;
        if (razlika_godina > 30 && razlika_godina < 40)
          broj_radnika++;
        else if(razlika_godina==30){
            if((*p).datum_rodjenja.mjesec<MJESEC){
                broj_radnika++;
            }
            else if((*p).datum_rodjenja.mjesec==MJESEC){
               if((*p).datum_rodjenja.dan<=DAN) broj_radnika++;
            }
        }
        else if(razlika_godina==40 || razlika_godina==41){
            if((*p).datum_rodjenja.mjesec>MJESEC){
                broj_radnika++;
            }
            else if((*p).datum_rodjenja.mjesec==MJESEC){
               if((*p).datum_rodjenja.dan>=DAN) broj_radnika++;
            }
        }
      }
    }
    p++;
  }

  return broj_radnika;
}

int main() {
    /*struct Radnik niz[] = {
        { "Pero Peric", {1, 5, 1985}, {1200, 1300, 1300, 1200, 1300, 1200, 1100, 1150, 1200, 1200, 1250, 1200}},
        { "Samir Ribic", {1, 5, 1985}, {1200, 1300, 1300, 1200, 1300, 1200, 1100, 1150, 1200, 1200, 1250, 1200}},
        { "Ratko Ratkovic", {1, 5, 1975}, {1200, 1300, 1300, 1200, 1300, 1200, 1100, 1150, 1200, 1200, 1250, 1200}},
        { "Selma Rodic", {1, 5, 1995}, {1200, 1300, 1300, 1200, 1300, 1200, 1100, 1150, 1200, 1200, 1250, 1200}},
        { "Rahman Rahmanovic", {1, 5, 1988}, {900, 950, 990, 1200, 1000, 950, 900, 1000, 900, 1050, 990, 999}},
        { "Ramo Ramic", {1, 5, 1991}, {2000, 2200, 2100, 2020, 1900, 2300, 1950, 2010, 2050, 2100, 2000, 2000}}
    };
    printf("%d", izdvoji_radnike(niz, 6));*/
    return 0;
}
