#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i = 0, broj, cifra, razlika_cifri = 0, brojac = 0, brojac1 = 0, cifra1=0;

  /*Korisnik treba unijeti broj n sa tastature*/
  printf("Unesite broj: ");
  scanf("%d", &n);

  /*Ako je n negativan broj, trebamo uzeti njegovu apsolutnu vrijednost*/
  if (n < 0) {
    n = abs(n);
  }
  broj = n;

  /*While petljom izbrojimo koliko cifara ima broj n*/
  while (broj > 0) {
    broj = broj / 10;
    brojac++;
  }

  /*Ako je broj jednocifren, rezultat treba biti 0*/
  if (brojac == 1 || n == 0)
    printf("0");
  else {
    /*Preko for petlje izvlacimo novi broj*/
    for (i = brojac; i > 0; i--) {
      /*Prva cifra sa lijeve strane je jednaka kolicniku broja i potencije 10 na broj cifara*/
      cifra = n / pow(10, (i - 1));
      /*Ako se ne radi o prvoj cifri sa lijeve strane, onda trazimo ostatak pri djeljenju sa 10 da bismo izvukli cifru koja nam treba*/
      if (cifra > 9)
        cifra = cifra % 10;
      /*Ako je prva cifra sa lijeva, nju moramo oduzeti od druge cifre sa lijeva pa uvodimo brojac1 koji ce nam omoguciti da uvijek radimo sa dvije cifre*/
      if (brojac1 == 0){
        razlika_cifri -= cifra;
        brojac1++;
      }
      /*Ako se radi o drugoj cifri sa lijeva, nju dodajemo na negativnu prvu cifru*/
      else if (brojac1 == 1) {
        razlika_cifri += cifra;
        /*Treba nam apsolutna vrijednost razlike*/
        razlika_cifri = abs(razlika_cifri);
        /*Uvedemo varijablu preko koje cemo sprijeciti ispis 0 prije nekog veceg broja, koju ne ponistavamo kroz iteracije petlje*/
        cifra1+=razlika_cifri;
        /*Isprintamo cifru koju smo dobili, ako nije prva i jednaka nuli*/
        if(cifra1!=0)printf("%d", razlika_cifri);
        /*Ako je razlika svih cifri jednaka 0, dovoljno je isprintati samo jednu nulu u posljednjoj iteraciji petlje*/
        else if(cifra1==0 && i==1)printf("%d", razlika_cifri);
        /*A sada ponistimo vrijednost brojaca kako bismo posmatrali sljedece dvije cifre*/
        brojac1 = 0;
        /*Ponistimo i razliku cifara*/
        razlika_cifri = 0;
        /*Uvecamo i za jedan kako bismo ponovno razmatrali drugi broj sa lijeva, ali ovaj put sa trecim sa lijeva*/
        i++;
      }
    }
  }
  return 0;
}