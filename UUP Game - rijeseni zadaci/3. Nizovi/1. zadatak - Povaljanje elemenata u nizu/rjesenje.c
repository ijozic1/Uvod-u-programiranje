#include <stdio.h>
#include <math.h>

int main() {
  double niz[100]={0}; /*Sve elemente cemo na pocetku postaviti na 0*/
  int n, i, j, glavni_brojac=0, pomocni_brojac=0;
  printf("Unesite broj clanova niza: ");
  do {
    scanf("%d", &n);
    if (n < 0 || n > 100) {
      printf("Neispravan unos!\nUnesite broj clanova niza: ");
    }
  } while (n < 0 || n > 100);

  printf("Unesite niz: ");
  for (i = 0; i < n; i++) {
    scanf("%lf ", &niz[i]);
  }

  /*U ovoj petlji provjeravamo da li je se neki broj ponovno pojavljuje nakon sto se pojavi prvi put*/
  for(i=0; i<n; i++){
      /*Nama trebaju elementi koji se pojavljuju tacno dva puta, pa cemo za svaki element provjeriti koliko puta se ponavlja pomocu pomocnog brojaca – pri svakoj promjeni elementa njega vracamo na 0 jer se on odnosi na jedan konkretan clan niza*/
      pomocni_brojac=0; 
      for(j=i+1; j<n; j++){
          if(niz[i]==niz[j]){
              /*Povecavamo pomocni brojac svaki put kad se elemet ponovi*/
              pomocni_brojac++;
          }
      }
      /*Ako se element ponavlja tacno jedanput, trebamo povecati glavni brojac za 1*/
      if(pomocni_brojac==1){
          glavni_brojac++;
        }
  }
  /*Ukoliko se svaki element pojavljauje tacno dva puta, onda bi glavni brojac trebao imati vrijednost n/2, 
  naravno zavisi da li je broj elemenata paran ili nije. Ukoliko broj elemenata nije paran, samim tim se neki
  element ne moze pojaviti dva puta*/
   if(n%2==0 && glavni_brojac==n/2) printf("DA");
   else printf("NE");
    return 0;
  }
