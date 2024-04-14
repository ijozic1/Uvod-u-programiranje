/*Dati program  sa predavanja sortira brojeve od manjih ka većim. 
Prepravite ga tako da ih slaže od većih ka manjim.*/

#include <stdio.h>
#define DUZINA 10

int main() {
	double niz[DUZINA], temp;
    int i, j, maks;
    /*Unos niza*/
    for(i=0; i<DUZINA; i++){
        printf("Unesite %d. realan broj: ", i+1);
        scanf("%lf", &niz[i]);
    }
    for(i=0; i<DUZINA; i++){
        maks=i;
        for(j=i+1; j<DUZINA; j++){
            if(niz[j]>niz[maks]) maks=j;}

        temp=niz[i];
        niz[i]=niz[maks]; 
        niz[maks]=temp;maks=j;   
    }

    /*Ispis niza*/
    printf("Sortiran niz:\n");
    for(i=0; i<DUZINA; i++){
        printf("%g ", niz[i]);
    }
    printf("\n");
	return 0;
}