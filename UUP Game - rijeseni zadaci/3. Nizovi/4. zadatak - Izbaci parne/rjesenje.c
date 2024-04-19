#include <stdio.h>

int main() {
    int niz[100], i, vel, suma;
    
    printf("Unesite broj elemenata niza: ");
    scanf("%d",&vel);
    printf("Unesite %d brojeva: ",vel);
    for(i=0; i<vel; i++)
        scanf("%d",&niz[i]);

    /* === OVDJE UBACITI KOD === */
    suma=0;
    int j;
    for(i=0; i<vel; i++){
        /*Moramo provjeriti da li je clan niza paran*/
        if(niz[i]%2==0){
            /*Ako jeste, onda na njegovo mjesto prepisujemo sljedeci clan niza, ali i sve ostale clanove niza premjestamo za pojedno mjesto unazad*/
            for (j=i; j<vel-1; j++){
                niz[j]=niz[j+1];
            }
            /*Moramo provjeriti da li je sljedeci clan koji smo prepisali paran, pa i vracamo jedan korak unazad*/
            i--;
            /*Takodjer moramo smanjiti velicinu niza, s obzirom da smo izbacili element iz niza*/
            vel--;
        }
        /*ako je clan neparan, sumu povecavamo za njegovu vrijednost*/
        else suma=suma+niz[i];
    }
    /* === KRAJ UBACENOG KODA === */

    printf("Niz je:\n");
    for (i=0; i<vel; i++)
        printf(" %d,", niz[i]);
    printf("\nSuma je: %d", suma);
    return 0;
}
