/*Napišite program koji sa tastature učitava neki pozitivan cijeli broj i jednu
cifru, a zatim iz broja izbacuje sva pojavljivanja unesene cifre. Također treba
ispisati broj pomnožen sa 2. Petljom do-while spriječite da se unose negativni
brojevi.
*/
#include <math.h>
#include <stdio.h>

int main() {
  int n, c, i, brojac = 0, cifra, broj, novi_broj=0,j=0;
    do{
        printf("Unesite broj: ");
        scanf("%d", &n);
    }while(n<0);
    do{
        printf("Unesite cifru: ");
        scanf("%d", &c);
    } while (c <0 || c > 9);
   
   broj=n;
  /*Provjerimo koliko broj ima cifara, da bismo formirali for petlju*/
  while (n > 0) {
    n = n / 10;
    brojac++;
  }
   /*Izbacimo cifru koju je korisnik unio*/
  for (i=0; i<brojac; i++){
        cifra=broj%10;
        broj=broj/10;
        if (cifra != c){
            novi_broj=novi_broj+cifra*pow(10,j);
            /*j je varijabla koja krece od 0 i daje nam potenciju broja 10*/
            j++;
        }
        else continue;
    }
  printf("Nakon izbacivanja broj glasi %d.\n", novi_broj);
  printf("Broj pomnozen sa dva glasi %d.", novi_broj*2);

  return 0;
}
