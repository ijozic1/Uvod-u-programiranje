#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
    double x, suma=0, ln, razlika;
    int n, i;
    printf("Unesite broj x: ");
    scanf("%lf", &x);
    /*Treba provjeriti da li su brojevi iz zadanog intervala*/
    /*Ako nisu, treba ponavljati unos dok ne budu*/
    while(x<=-1 || x>=1){
        printf("Greska.\n");
        printf("Unesite broj x: ");
        scanf("%lf", &x);
    }
    printf("Unesite broj n: ");
    scanf("%d", &n);
    while(n<1){
        printf("Greska.\n");
        printf("Unesite broj n: ");
        scanf("%d", &n);
    }
    /*Sumu po Tylorovom obrascu racunamo preko for petlje*/
        for(i=1; i<=n; i++){
            suma=suma+pow(-1,i-1)*(pow(x,i)/i);
        }
        
    /*Za prirodni logaritam uzimamo funkciju iz biblioteke*/
        ln=log(1+x);
        
    /*Ispisujemo dobivene vrijednosti*/
        printf("Izracunata vrijednost: %.6lf\n", suma);
        printf("Bibliotecna funkcija: %.6lf\n", ln);
        
    /*Uporedimo dobivene vrijednosti i ispisujemo razliku u postotcima*/
        if(ln==0) printf("Razlika u postotcima: 0.00%%");
        else{       
            razlika=suma/ln-1;
            razlika=(round(razlika*100*100)/100);
            printf("Razlika u postotcima: %.2lf%%", razlika);
        }

    return 0;
}
