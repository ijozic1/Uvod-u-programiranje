#include <stdio.h>

/* Ovdje napisite vasu funkciju */
int drugi(int niz[100], int vel) {
  int max_1 = niz[0], prvi = 0, max_2, drugi = -1, min=niz[0], minI=0, i;
  /*Prvo pronadjimo najveci i najmanji clan u nizu*/
  for (i = 0; i < vel; i++) {
    if (niz[i] > max_1) {
      max_1 = niz[i];
      prvi = i;
    }
    if(niz[i]<min) {
        min=niz[i];
        minI=i;
    }
  }
  /*Sada trazimo element koji je manji od najveceg, a veci ili jednak minimumu*/
  max_2=min;
  for(i=0; i<vel; i++){
      if(niz[i]<max_1 && niz[i]>=max_2){
        max_2=niz[i];
        drugi=i;
      }
  }
  if (drugi == -1)
    return -1;
  else
    return drugi;
}
/* Kraj napisane funkcije*/

int main() {
  int niz[100], i, rez;
  printf("Unesite niz brojeva: ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &niz[i]);
    if (niz[i] == -1)
      break;
  }

  rez = drugi(niz, i);

  printf("Indeks drugog po velicini je: %d", rez);
  return 0;
}
