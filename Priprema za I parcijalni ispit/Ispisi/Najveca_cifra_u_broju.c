#include <stdio.h>
#include <math.h>

int main(){
    int n, cifra, broj, max=0;
    /*Ovako moze ako nam se ne trazi nista drugo u zadatku sa tim brojem*/
    printf("Unesite broj n: ");
    scanf("%d", &n);
    broj=n;

    do{
        cifra=broj%10;
        broj=broj/10;
        if(cifra>=max) max=cifra;
    }while (broj!=0);

    printf("Najveca cifra u broju je: %d", max);
    return 0;
}