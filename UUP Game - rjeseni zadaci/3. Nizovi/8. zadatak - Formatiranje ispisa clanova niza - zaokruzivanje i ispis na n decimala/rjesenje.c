#include <stdio.h>
#include <math.h>

int main() {
    int i, n, z_dec, br_dec;
    double element, niz[20];
    printf("Unesite broj elemenata niza: ");
    /*Unosimo broj clanova niza, s tim da moramo provjeriti da li je korisnik unio broj izodgovarajuceg opsega*/
    do{
        scanf("%d", &n);
        if(n<1 || n>20){
            printf("Unos neispravan!");
            printf("\nUnesite broj elemenata niza: ");
        }
    }while(n<1 || n>20);
    
    /*Sada unosimo elemente niza*/
    printf("Unesite %d brojeva: ", n);
    for(i=0; i<n; i++){
        scanf("%lf", & element);
        niz[i]=element;
    }
    
    /*Od korisnika trazimo broj decimala za zaokruzivanje, a zatim zaokruzimo clanove*/
    printf("\nUnesite broj decimala za zaokruzivanje: ");
    scanf("%d", &z_dec);
    for(i=0; i<n; i++){
        niz[i]=round(niz[i]*pow(10,z_dec))/pow(10,z_dec);
    }

    /*Sada ispisujemo zaokruzene clanove niza na odgovarajuci broj decimala*/
    printf("Unesite broj decimala za ispis: ");
    scanf("%d", &br_dec);
    printf("{");
    for(i=0; i<n; i++){
        printf("%.*lf",br_dec, niz[i]);
        if(i!=n-1) printf(", ");
    }
    printf("}");

    return 0;
}
