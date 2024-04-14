#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, suma=0, cifra, broj;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    broj=n;

    do{
        cifra=broj%10;
        broj=broj/10;
        suma+=cifra;
    }while(broj!=0);

    printf("Suma cifara broja %d je %d.", n, abs(suma));
    return 0;
}