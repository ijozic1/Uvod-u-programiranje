#include <stdio.h>
#include <math.h>

int main(){
    int n, cifra, broj;
    /*Ovako moze ako nam se ne trazi nista drugo u zadatku sa tim brojem*/
    printf("Unesite broj n: ");
    scanf("%d", &n);
    broj=n;

    printf("Broj okrnut naopako je: ");
    do{
        cifra=broj%10;
        broj=broj/10;
        printf("%d",cifra);
    }while (broj!=0);
    return 0;
}