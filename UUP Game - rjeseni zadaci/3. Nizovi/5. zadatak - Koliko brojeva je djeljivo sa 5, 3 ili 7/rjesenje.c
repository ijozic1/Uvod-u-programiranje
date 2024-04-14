#include <stdio.h>
#include <math.h>

int main() {
    int n, brojac=0, brojac5=0, brojac7=0, brojac11=0, i=0;
    int niz[1000];
    
    printf("Unesite brojeve: \n");

    do{
        scanf("%d\n", &n);
        if (n!=(-1)){
            /*Sada unesene elemente pohranjujemo u niz*/
            niz[i]=n;
            /*Brojacem kontrolisemo broj unesenih brojeva*/
            brojac++;
            /*Svaki put povecavamo i*/
            i++;
        }
        else break;
    }while(n!=(-1));/*Unos se prekida unosom -1*/

    /*Sada prolazimo kroz niz i trazimo djeljive sa 5, 7 ili 11*/
    for(i=0; i<brojac; i++){
        /*Ako je uneseni broj djeljiv sa nekim od brojeva, onda brojac tog broja povecavamo*/
        if(niz[i]%5==0) brojac5++;
        if(niz[i]%7==0) brojac7++;
        if(niz[i]%11==0) brojac11++;
    }

    /*Kada smo prosli kroz cijeli niz, ispisujemo koliko je djeljivih*/
    printf("Djeljivih sa 5: %d\n",brojac5);
    printf("Djeljivih sa 7: %d\n", brojac7);
    printf("Djeljivih sa 11: %d\n", brojac11);

    return 0;
}
