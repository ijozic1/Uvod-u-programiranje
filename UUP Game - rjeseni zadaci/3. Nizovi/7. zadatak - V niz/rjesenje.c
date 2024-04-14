#include <math.h>
#include <stdio.h>

int main() {
  int n, i = 0, min, minI, niz[100], brojac = 0, prije=1, poslije=1;

  /*Korisnik nam treba unijeti clanove niza*/
  /*printf("Unesite clanove niza: ");*/
  do {
    scanf("%d", &n);
    /*Ako je korisnik unio manje od 3 broja, a unese -1, trebamo prekinuti
     * program*/
    if (n == (-1) && brojac < 3) {
      printf("Nedovoljno elemenata");
      return 0;
    } 

    else if (n != (-1)) {
      /*Pohranjujemo unesene elemente u niz*/
      niz[i] = n;
      /*Brojacem kontrolisemo broj unesenih elemenata*/
      brojac++;
      /*Svaki put povecavamo i*/
      i++;
    }
  } while (brojac < 100 && n != (-1));

  /*Kada smo unijeli elemente niza potrebno je proci kroz niz i pronaci
   * minimum*/
  min = niz[0];
  minI = 0;
  for (i = 0; i < brojac; i++) {
    if (niz[i] < min) {
      min = niz[i];
      minI = i;
    }
  }
  /*Sada trebamo ponovno proci kroz niz i vidjeti da li vaze uslovi za V niz*/

  for (i = 0; i < minI; i++) {
    /*Prvo provjeravamo da li su clanovi u nizu prije minimuma opadajuci*/
    if (niz[i] <= niz[i + 1]) {
      prije = 0;
      /*Kada naidjemo na prvi clan koju narusava monotonost mozemo prekinuti
       * provjeru*/
      break;
    }
  }
  /*printf("Prije %d", prije);*/

  /*Sada provjeravamo da li su clanovi poslije minimuma rastuci i da li je
   * minimum manji od njih, zato od minI*/
   /*petlja ide do brojac-1 jer posljednji element koji ima indeks (brojac-1) nemamo s cim uporediti, ako ga pokusamo uporediti sa sljedecim elementom, 
   poredi nam ga sa nekom divljom vrijednosti iz memorije za koju nikad ne mozemo znati sta je*/
  for (i = minI; i < brojac-1; i++) {
    if (niz[i] >= niz[i + 1]) {
      poslije = 0;
      break;
    }
  }
  /*printf("Poslije %d", poslije);*/

  /*Sada jos trebamo ispisati da li je niz V ili nije*/
  if (prije != 0 && poslije != 0)
    printf("Niz je v-niz");
  else
    printf("Niz nije v-niz");

  return 0;
}
