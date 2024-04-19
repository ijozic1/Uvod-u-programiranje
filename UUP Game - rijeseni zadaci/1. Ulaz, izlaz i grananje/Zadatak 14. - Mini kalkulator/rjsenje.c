#include <stdio.h>
#include <math.h>

int main() {
    char znak;
    double broj1, broj2, rezultat;
    /*Ispis mogucih operacija kalkulatora*/
    printf("--- Moj mini kalkulator ---\n");
    printf("Sabiranje: +\n");
    printf("Oduzimanje: -\n");
    printf("Mnozenje: *\n");
    printf("Dijeljenje: /\n");
    printf("Kvadriranje: #\n");
    printf("Korjenovanje: &\n");
    printf("\n");
    /*Unos zeljene operacije*/
    printf("Odaberite operaciju: ");
    scanf("%c",&znak);
    /*Provjera o kojoj se operaciji radi*/
    if(znak=='+'){
        printf("Unesite prvi broj: ");
        scanf("%lf", &broj1);
        printf("Unesite drugi broj: ");
        scanf("%lf", &broj2);
        rezultat=broj1+broj2;
        printf("\nRezultat: %g + %g = %g", broj1, broj2, rezultat);
    }

    else if(znak=='-'){
        printf("Unesite prvi broj: ");
        scanf("%lf", &broj1);
        printf("Unesite drugi broj: ");
        scanf("%lf", &broj2);
        rezultat=broj1-broj2;
        printf("\nRezultat: %g - %g = %g", broj1, broj2, rezultat);
    }
    
    else if(znak=='*'){
        printf("Unesite prvi broj: ");
        scanf("%lf", &broj1);
        printf("Unesite drugi broj: ");
        scanf("%lf", &broj2);
        rezultat=broj1*broj2;
        printf("\nRezultat: %g * %g = %g", broj1, broj2, rezultat);
    }

    else if(znak=='/'){
        printf("Unesite prvi broj: ");
        scanf("%lf", &broj1);
        printf("Unesite drugi broj: ");
        scanf("%lf", &broj2);
        if(broj2==0) printf("GRESKA: Dijeljenje sa nulom!");
        else{
            rezultat=broj1/broj2;
            printf("\nRezultat: %g / %g = %g", broj1, broj2, rezultat);
        }
    }

    else if(znak=='#'){
        printf("Unesite broj: ");
        scanf("%lf", &broj1);
        rezultat=pow(broj1,2);
        printf("\nRezultat: %g^2 = %g", broj1, rezultat);
    }

    else if(znak=='&'){
        printf("Unesite broj: ");
        scanf("%lf", &broj1);
        if(broj1<0) printf("GRESKA: Korjenovanje negativnog broja nema smisla!");
        else{
            rezultat=sqrt(broj1);
            printf("\nRezultat: %g^(1/2) = %g", broj1, rezultat);
        }
    }

    else printf("GRESKA: Nepostojeca operacija!");

    return 0;
}
