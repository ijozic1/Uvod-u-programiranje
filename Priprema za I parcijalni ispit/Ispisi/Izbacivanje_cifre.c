#include <stdio.h>
#include <math.h>

int main(){
    int n, cifra, broj, izbacivanje, brojac=0, i;
    
    printf("Unesite broj n: ");
    scanf("%d", &n);
    broj=n;
    /*Moramo prebrojati cifre*/
    do{
        cifra=broj%10;
        broj=broj/10;
        brojac++;
    }while (broj!=0);
    
    printf("Unesite cifru koju zelite izbaciti: ");
    scanf("%d", &izbacivanje);

    printf("Broj bez cifre %d je: ", izbacivanje);
    broj=n;
    for(i=brojac-1; i>=0; i--){
        cifra=broj/pow(10,i);
        cifra=cifra%10;
        if(cifra!=izbacivanje) printf("%d", cifra);
    }
    return 0;
}