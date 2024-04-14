#include <stdio.h>

int main() {
  double niz[100];
  int i, vel;

  printf("Unesite broj clanova niza: ");
  scanf("%d", &vel);
  printf("Unesite clanove niza: ");
  for (i = 0; i < vel; i++)
    scanf("%lf", &niz[i]);

  /* === OVDJE UBACITI KOD === */
  int brojac=0, brojac_max=0,j, predznak, predznak_element;
  double element=niz[0];
  /*Prvo nadjimo koji element se najvise puta ponavlja*/
  for(i=0; i<vel; i++){
      brojac=0;
      for(j=0; j<vel; j++){
          if(niz[i]-niz[j]<0.0001 && niz[j]-niz[i]<0.0001) brojac++;
      }
      if(brojac>=brojac_max){
          /*Posto nemamo funkciju abs da poredimo brojeve po apsolutnoj, moramo improvizirati sa predznacima*/
          if(niz[i]<0) predznak=-1;
          else predznak=1;
          if(element<0) predznak_element=-1;
          else predznak_element=1;
          brojac_max=brojac;
          if(niz[i]<element || niz[i]*predznak<element*predznak_element) element=niz[i];
      }
  }
  /*Sada cemo izbaciti sve elemente vece od onog ciji je brojac najveci*/
  for(i=0; i<vel; i++){
      if(niz[i]>element){
          for(j=i; j<vel-1; j++){
              niz[j]=niz[j+1];
          }
          vel--;
          i--;
      }
  }
  /*=== KRAJ UBACENOG KODA ===*/

  printf("Nakon izbacivanja niz glasi:\n");
  for (i = 0; i < vel; i++)
    printf("%g ", niz[i]);
  return 0;
}
