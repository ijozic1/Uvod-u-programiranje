#include <stdio.h>
#include <math.h>

int obrnut(int x){
    int obrnut=0, broj, cifra, brojac=0,i;
    /*Kako se unosi pozitivan broj, to ne moramo provjeravati njegov predznak*/
    broj=x;
    do{
        cifra=broj%10;
        brojac++;
        broj=broj/10;
    }while(broj!=0);
    /*Sada kada znamo broj cifara u unesenom broju, mozemo okretati broj*/
    broj=x;
    for(i=0; i<brojac; i++){
        cifra=broj%10;
        broj=broj/10;
        obrnut+=cifra*pow(10,brojac-i-1);
    }
    return obrnut;
}

int main() {
    int n;
    printf("Unesite broj: ");
    scanf("%d", &n);
    printf("Broj %d okrenut naopako glasi %d.",n,obrnut(n));
    return 0;
}
