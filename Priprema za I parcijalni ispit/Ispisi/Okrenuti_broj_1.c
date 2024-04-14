#include <stdio.h>
#include <math.h>

int main(){
    int n, cifra, broj, brojac=0, i, novi_br=0;
    /*Ovako ako nam okrenuti broj treba u zadatku*/
    printf("Unesite broj n: ");
    scanf("%d", &n);
    broj=n;

    /*Prebrojimo cifre u broju*/
    do{
        broj=broj/10;
        brojac++;
    }while (broj!=0);

    broj=n;

    /*Kad smo izbrojali cifre, mozemo kreirati obrnuti broj*/
    for(i=brojac-1; i>=0; i--){
        cifra=broj%10;
        broj=broj/10;
        novi_br=novi_br+cifra*pow(10,i);
    }

    printf("Okrenuti broj je: %d", novi_br);
    return 0;
}