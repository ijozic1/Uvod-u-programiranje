#include <math.h>
#include <stdio.h>

typedef struct {
  int im, re;
} Kompleksni;

int konjugovano_kompleksni(Kompleksni *p1, Kompleksni *p2, Kompleksni *rez) {
  int brojac = 0, postoji = 0;
  int vel = p2 - p1;
  Kompleksni *l, *pocetak_2;
  
  /*Inicijalizacija niza u koji upisujemo konjugovano kompleksne parove*/
  l = rez;
  pocetak_2 = rez;
  while (l < pocetak_2 + vel) {
    (*l).re = 0;
    (*l).im = 0;
    l++;
  }

  while (p1 < p2) {
    (*p1).im*=-1;
    l = pocetak_2;
    postoji = 0;
    /*Provjera da li se isti broj vec nalazi u nizu*/
    while (l < pocetak_2 + vel) {
        if ((*l).im == (*p1).im) {
            postoji = 1;
            break;
        }
        l++;
    }
    if (postoji == 0) {
        *rez = *p1;
        rez++;
        brojac++;
    }
    p1++;
  }
  return brojac;
}

int main() {
  /*Kompleksni niz1[5] = {{5, 5}, {3, 3}, {-5, -5}, {5, 5}, {-3, 3}};
  Kompleksni niz2[5];
  int vel = konjugovano_kompleksni(niz1, niz1 + 5, niz2);
  int i;
  for (i = 0; i < vel; i++)
    printf("(%d,%d) ", niz2[i].im, niz2[i].re);*/
  return 0;
}
