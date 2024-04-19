#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int br_studenata, dan, mjesec, godina, i, j, prestupna = 0;
  unsigned int niz[1000], dan_u_godini = 0;
  int niz_godina[1000];
  /*Korisnik nam prvo treba unijeti broj studenata cije datume rođenja cemo porediti*/
  do {
    printf("Unesite broj studenata: ");
    scanf("%d", &br_studenata);
    if (br_studenata < 1 || br_studenata > 1000)
      printf("Neispravan broj studenata\n");
  } while (br_studenata < 1 || br_studenata > 1000);

  /*Kada je unesen broj sudenata, trebamo unijeti njihove datume rodjenja*/
  for (i = 0; i < br_studenata; i++) {
    printf("Unesite datum rodjenja %d. studenta: ", i + 1);
    scanf("%d,%d,%d", &dan, &mjesec, &godina);
    if (godina < 0 || godina > 2022) {
      printf("Neispravan datum\n");
      i--;
    } else if (godina % 4 != 0) {
      prestupna = 0;
      niz_godina[i] = godina;
    } else if (godina % 4 == 0) {
      prestupna = 1;
      niz_godina[i] = godina;
      if (godina % 100 == 0 && godina % 400 == 0)
        prestupna = 1;
      else if (godina % 100 == 0 && godina % 400 != 0)
        prestupna = 0;
    }
    if ((mjesec < 1 || mjesec > 12)&& godina>0) {
      printf("Neispravan datum\n");
      i--;
    } else if(godina>0) {
      if (mjesec == 1) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          dan_u_godini = dan;
        }
      } else if (mjesec == 2) {
        if (dan < 1 || (prestupna == 0 && dan > 28) ||
            (prestupna == 1 && dan > 29)) {
          printf("Neispravan datum\n");
          i--;
        } else {
          dan_u_godini = 31 + dan;
        }
      } else if (mjesec == 3) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 31 + 28 + dan;
          else
            dan_u_godini = 31 + 29 + dan;
        }
      } else if (mjesec == 4) {
        if (dan < 1 || dan > 30) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 90 + dan;
          else
            dan_u_godini = 91 + dan;
        }
      } else if (mjesec == 5) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 120 + dan;
          else
            dan_u_godini = 121 + dan;
        }
      } else if (mjesec == 6) {
        if (dan < 1 || dan > 30) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 151 + dan;
          else
            dan_u_godini = 152 + dan;
        }
      } else if (mjesec == 7) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 181 + dan;
          else
            dan_u_godini = 182 + dan;
        }
      } else if (mjesec == 8) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 212 + dan;
          else
            dan_u_godini = 213 + dan;
        }
      } else if (mjesec == 9) {
        if (dan < 1 || dan > 30) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 243 + dan;
          else
            dan_u_godini = 244 + dan;
        }
      } else if (mjesec == 10) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 273 + dan;
          else
            dan_u_godini = 274 + dan;
        }
      } else if (mjesec == 11) {
        if (dan < 1 || dan > 30) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 304 + dan;
          else
            dan_u_godini = 305 + dan;
        }
      } else if (mjesec == 12) {
        if (dan < 1 || dan > 31) {
          printf("Neispravan datum\n");
          i--;
        } else {
          if (prestupna == 0)
            dan_u_godini = 334 + dan;
          else
            dan_u_godini = 335 + dan;
        }
      }
      /*Kada je uneseni datum ispravan i datum rodjenja pretvoren u broj dana u godini, mozemo taj podatak unijeti u niz*/
      if (dan_u_godini > 0) {
        niz[i] = dan_u_godini;
      }
    }
  }
  /*Kada smo unijeli podatke u niz, mozemo provjeravati da li je razlika datuma rodjenja 100 dana*/
  for (i = br_studenata - 1; i >= 0; i--) {
    for (j = 0; j < br_studenata; j++) {
      if (niz[i] - niz[j] == 100 && (niz_godina[i] - niz_godina[j] == 0 || abs(niz_godina[i] - niz_godina[j]) == 1))
        printf("Student %d. je rodjen tacno 100 dana prije studenta %d.\n", j + 1, i + 1);
      /*Za slucaj kada je jedan student rodjen na kraju jedne, a drugi na pocetku sljedece godine*/
      else if (abs(niz_godina[i] - niz_godina[j]) == 1 && abs(niz[i] - niz[j] == 265))
        printf("Student %d. je rodjen tacno 100 dana prije studenta %d.\n", i + 1, j + 1);
    }
  }
  return 0;
}
