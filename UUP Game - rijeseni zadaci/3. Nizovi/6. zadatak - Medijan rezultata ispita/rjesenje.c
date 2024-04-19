#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, min;
    double niz[500], medijan, temp;
    
    /*Prvo unosimo broj studenata koji su pristupili ispitu*/
    printf("Unesite broj studenata: ");
    do{
        scanf("%d", &n);
        if(n<1 || n>500)
            printf("Pogresan unos!\nUnesite broj studenata: ");
    }while(n<1 || n>500);

    /*Nakon sto smo unijeli broj studenata, trebamo unijeti njihove bodove*/
    printf("Unesite bodove na ispitu: ");
    for(i=0; i<n; i++){
        scanf("%lf", &niz[i]);
        if(niz[i]<0 || niz[i]>20){
            printf("Rezultat ispita nije u trazenom intervalu");
            return 0;
        }
    }

    /*Kada smo unijeli sve elemente potrebno je sortirati niz od najmanjeg do najveceg clana*/
    for(i=0; i<n; i++){
        min=i; /*Svaki put krenemo od elementa na kojem smo se zatekli*/
        for(j=i+1; j<n; j++){
            if(niz[j]<niz[min]){
                /*Ako je neki clan manji od onog od kojeg smo krenuli, potrebno je zapamtiti njegov indeks zbog zamjene mjesta*/
                min=j;
            }
        }
        /*Sada vrsimo zamjenu odgovarajucih clanova niza*/
        temp=niz[i];
        niz[i]=niz[min];
        niz[min]=temp;
    }

    /*Kada smo sortirali niz, potrebno je naci srednji element, tj. medijan*/
    /*Ako je broj clanova niza neparan, samo ispisujemo srednji clan*/
    if(n%2!=0){
        /*Posto indeksiranje krece od 0, a ne od 1, onda srednji clan od 5 clanova nema indeks 3 nego 2, pa je zato samo n/2, a ne n/2+1*/
        medijan=niz[(n/2)];
    }
    /*Ako niz ima paran broj elemenata, onda je medijan artimeticka sredina dva srednja clana*/
    else{
        /*Takodjer zbog indeksiranja od 0 srednji clanovi nisu n/2 i n/2+1 nego n/2-1 i n/2*/
        medijan=(niz[n/2-1]+niz[n/2])/2;
    }
    /*Sada jos treba isrintati vrijednost medijana*/
    printf("Medijan je: %g", medijan);
    return 0;
}
