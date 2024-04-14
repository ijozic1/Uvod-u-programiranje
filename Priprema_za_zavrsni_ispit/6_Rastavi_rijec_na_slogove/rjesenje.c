#include <stdio.h>

int main() {
  FILE *ulaz = fopen("tekst.txt", "w");
  fputs("Hej vi hitri bijeli dani, bijeli dani tamne noci, dal ce moja pusta zelja ikada na red doci.", ulaz);
  fclose(ulaz);

  FILE *citac = fopen("tekst.txt", "r");
  if (citac == NULL) {
    printf("Greska prilikom otvaranja datoteke");
    return 1;
  }

  char tekst[500], slogovi[1000], *pok_tekst, *pok_slogovi;
  fgets(tekst, 500, citac);
  int broj_rijeci = 0;
  pok_slogovi = slogovi;
  pok_tekst = tekst;
  while (*pok_tekst != '\0') {
    if (*pok_tekst == ' ' || *pok_tekst == ',' || *pok_tekst == '.') {
      *pok_slogovi = *pok_tekst;
      pok_slogovi++;
      pok_tekst++;
      continue;
    } else {
      broj_rijeci++;
      if (broj_rijeci % 5 == 0) {
        while (*pok_tekst != '\0' && *pok_tekst != ' ' && *pok_tekst != ',' &&
               *pok_tekst != '.') {
          *pok_slogovi = *pok_tekst;
          pok_slogovi++;
          if (*pok_tekst == 'a' || *pok_tekst == 'e' || *pok_tekst == 'i' ||
              *pok_tekst == 'o' || *pok_tekst == 'u') {
            pok_tekst++;
            if (*pok_tekst != '\0' && *pok_tekst != ' ' && *pok_tekst != ',' &&
                *pok_tekst != '.') {
              *pok_slogovi = '-';
              pok_slogovi++;
            }
            continue;
          }
          pok_tekst++;
        }
      } else {
        while (*pok_tekst != '\0' && *pok_tekst != ' ' && *pok_tekst != ',' &&
               *pok_tekst != '.') {
          *pok_slogovi = *pok_tekst;
          pok_slogovi++;
          pok_tekst++;
        }
        continue;
      }
    }
  }
  *pok_slogovi = '\0';
  pok_slogovi = slogovi;
  FILE* upisi = fopen("tekst.txt","a");
  if(upisi == NULL){
    printf("Greska prilikom otvaranja datoteke");
    return 1;
  }
  fputc('\n',upisi);
  fputc('\n',upisi);
  fputs(slogovi,upisi);
  fclose(upisi);
  fclose(citac);
  return 0;
}