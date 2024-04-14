#include <stdio.h>

int provjeri_duzine(char *s, int *niz, int vel) {
  int ispunjen = 1, duzina = 0, i = 0, br_rijeci=0;
  char *pocetak = s, *kraj = s;
  while (*s != '\0') {
    pocetak = s;
    while (*s != '\0' && ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
       s++;
    }
    kraj = s;

    if (kraj - pocetak > 0){
      duzina = kraj - pocetak;
      br_rijeci++;
    }
    else
      duzina = 0;

    if (i<vel && niz[i] == duzina) {
      ispunjen = 1;
      i++;
    } else if (duzina != 0) {
      ispunjen = 0;
      break;
    }
    if(*s!='\0')s++;
    else break;
  }
  if(ispunjen==1 && br_rijeci!=vel) ispunjen=0;
  return ispunjen;
}

int main() {
  int ispunjen = 0, i = 0, vel = 5;
  char s[100] = "Ovo je neki primjer teksta";
  int niz[5] = {3, 2, 4, 7, 6};
  
  ispunjen = provjeri_duzine(s, niz, vel);
  printf("%d", ispunjen);
  return 0;
}