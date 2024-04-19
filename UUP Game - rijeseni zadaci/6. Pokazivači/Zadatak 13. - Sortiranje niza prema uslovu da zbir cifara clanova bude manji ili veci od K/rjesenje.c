#include <stdio.h>

/* === OVDJE UBACITI KOD === */
#include <math.h>
#include <stdlib.h>

void zaokruzi1(double *niz, int vel) {
  double *p = niz;
  while (p < niz + vel) {
    *p = round((*p) * 10);
    *p = *p / 10;
    p++;
  }
}
int suma_cifara(double broj) {
  /*Znamo da nam je svaki broj zaokruzen na jednu decimalu,
  pa ako ga pomnozimo sa 10, dobivamo cijeli broj kojem mozemo
  racunati zbir cifara*/
  int suma = 0, int_br;
  int_br = (int)(broj * 10);
  int_br = abs(int_br);
  do {
    suma = suma + (int_br % 10);
    int_br = int_br / 10;
  } while (int_br != 0);
  return suma;
}
void preslozi(double *niz, int vel, int k) {
  double *p = niz, *r, *q;
  double temp;
  int suma, suma_veca;
  zaokruzi1(niz, vel);
  while (p < niz + vel) {
    suma = suma_cifara(*p);
    if(suma<k){
        suma_veca=0;
        r=p;
        while(suma_veca<k && r<niz+vel){
            suma_veca=suma_cifara(*r);
            if(suma_veca>=k) break;
            r++;
        }
        if(suma_veca>=k){
            temp=*r;
            q=r;
            while(q>p){
                *q=*(q-1);
                q--;
            }
            *p=temp;
        }
    }
    p++;
  }
}
/* === KRAJ UBACENE FUNKCIJE ===*/

int main() {
  int i, vel, k;
  double niz[100];

  printf("Unesite broj elemenata niza: ");
  scanf("%d", &vel);
  printf("Unesite clanove niza: ");
  for (i = 0; i < vel; i++)
    scanf("%lf", &niz[i]);
  printf("Unesite broj k: ");
  scanf("%d", &k);

  preslozi(niz, vel, k);

  printf("Nakon poziva funkcije preslozi niz glasi:\n");
  for (i = 0; i < vel; i++)
    printf("%g ", niz[i]);
  return 0;
}
