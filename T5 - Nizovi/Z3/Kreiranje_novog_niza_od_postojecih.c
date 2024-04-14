/*Napisati program koji učitava 5 elemenata dva niza realnih brojeva A i B, 
a zatim izračunava elemente trećeg niza C zadatog kao: C{ciℝ|ci=2ai+bi,aiA,biB}
Drugim riječima, svaki element ci skupa C jednak je sumi odgovarajućih elemenata 
ai i bi iz skupova A i B pri čemu je ai pomnožen sa dva.
Na kraju je potrebno ispisati elemente nizova A, B i C. */
#include <stdio.h>
#include <math.h>
#define BROJ_EL 5

int main() {
    double nizA[BROJ_EL], nizB[BROJ_EL], nizC[BROJ_EL];
    int i,j;
    /*Unosimo clanove niza A*/
    printf("Unesite clanove niza A: ");
    for(i=0; i<BROJ_EL; i++){
        scanf("%lf", &nizA[i]);
    }
    /*Unosimo clanove niza B*/
    printf("Unesite clanove niza B: ");
    for(i=0; i<BROJ_EL; i++){
        scanf("%lf", &nizB[i]);
    }
    /*Ispisujemo clanove niza A*/
    printf("Niz A glasi: ");
    for(i=0; i<BROJ_EL; i++){
        printf("%.2lf", nizA[i]);
        /*Formatiranje ispisa*/
        if(i!=BROJ_EL-1) printf(", ");
    }
    /*Ispisujemo clanove niza B*/
    printf("\nNiz B glasi: ");
    for(j=0; j<BROJ_EL; j++){
        printf("%.2lf", nizB[j]);
        /*Formatiranje ispisa*/
        if(j!=BROJ_EL-1) printf(", ");
    }
    /*Stvaramo i ispisujemo niz C*/
	printf("\nNiz C glasi: ");
    for (i=0; i<BROJ_EL; i++){
        for(j=0; j<BROJ_EL; j++){
            if(i==j){
                nizC[i]=2*nizA[i]+nizB[j];
                printf("%.2lf", nizC[i]);
                /*Formatiranje ispisa*/
                if(i!=BROJ_EL-1) printf(", ");

            }
        }
    }
	return 0;
}
