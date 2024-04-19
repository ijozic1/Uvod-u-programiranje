#include <stdio.h>
#include <math.h>

int*max_el(int*p1, int*p2){
    /*p1 pokazuje na pocetak niza, a p2 na kraj niza*/
    int*q;
    q=p1; /*q cuva adresu najveceg clana*/
    while(p1<p2){
        if(*p1>*q) q=p1;
        p1++;
    }
    return q;
}

int*min_el(int*p1, int*p2){
    int*q;
    q=p1;
    while(p1<p2){
        if(*p1<*q) q=p1;
        p1++;
    }
    return q;
}

int main() {
    int niz[100], vel, i;
    int*min, *max;
    do{
        printf("Unesite broj clanova niza: ");
        scanf("%d", &vel);
        if(vel<1 || vel>100) printf("Pogresan unos!\n");
    }while(vel<1 || vel>100);

    printf("Unesite clanove niza: ");
    for(i=0; i<vel; i++){
        scanf("%d", &niz[i]);
    }

    max=max_el(niz, niz+vel);
    min=min_el(niz, niz+vel);
    
    printf("Najveci element u nizu je %d, a najmanji %d.",*max, *min);
    return 0;
}
