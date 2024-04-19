#include <math.h>
#include <stdio.h>

int broj_sadrzan(unsigned int a, unsigned int b) {
  int broj_sadrzan = 0, brojacA = 0, brojacB = 0, broj, i, j = 0, potencija;
  unsigned int nizA[10], nizB[10], cifra;
  unsigned int *p, *q, *r;
  /*prebrojimo koliko cifara ima a*/
  broj = a;
  do {
    broj /= 10;
    brojacA++;
  } while (broj != 0);
  /*rastavljamo a na cifre i smjestamo u niz*/
  broj = a;
  for (i = brojacA - 1; i >= 0; i--) {
    potencija = pow(10, i);
    cifra = broj / potencija;
    nizA[j++] = cifra;
    broj = broj % potencija;
  }
  /*Sada uradimo isto i za b*/
  broj = b;
  do {
    broj = broj / 10;
    brojacB++;
  } while (broj != 0);

  broj = b;
  j = 0;
  for (i = brojacB - 1; i >= 0; i--) {
    potencija = pow(10, i);
    cifra = broj / potencija;
    nizB[j++] = cifra;
    broj = broj % potencija;
  }
  /*Sada jos provjerimo da li su brojevi sadrzani jedan u drugom*/
  p = nizA;
  while (p < nizA + brojacA) {
    q = nizB;
    if (*p == *q) {
      r = p;
      while (q < nizB + brojacB && r < nizA + brojacA) {
        if (*q == *r) {
          broj_sadrzan = 1;
        } else {
          broj_sadrzan = 0;
          break;
        }
        r++;
        q++;
        /*ako r dodje do kraja, a u q je ostalo jos cifara, to znaci da broj nije sadrzan*/
        if(r==nizA+brojacA && q!=nizB+brojacB && broj_sadrzan==1) broj_sadrzan=0;
      }
    }
    /*Ako pronadjemo broj u broju, mozemo prekinuti petlju jer nema potrebe da idemo dalje*/
    if (broj_sadrzan == 1 && q == nizB + brojacB) break;
    p++;
  }
  return broj_sadrzan;
}

int main() {
  unsigned int a, b;
  printf("Unesite broj a: ");
  scanf("%u", &a);
  printf("Unesite broj b: ");
  scanf("%u", &b);
  if (broj_sadrzan(a, b))
    printf("ISTINA");
  else
    printf("NEISTINA");
  return 0;
}
