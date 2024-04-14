#include <stdio.h>
#include <math.h>

int main() {
    double niz[100], temp;
    int n, i, j, min;
    
    /*do while petljom trazimo unos cijelog broja elemenata*/
    printf("Unesite broj elemenata niza: ");
    do{ 
        scanf("%d", &n);
        if(n<1 || n>100) 
            printf("Unos neispravan!\nUnesite broj elemenata niza: ");
    }while(n<1 || n>100);
    
    /*Nakon sto smo odredili broj clanova niza, sada te clanove treba i unijeti*/
    printf("Unesite %d brojeva: ", n);
    for(i=0; i<n; i++){
        scanf("%lf", &niz[i]);
    }

    /*Sada trebamo sortirati niz*/
    printf("\n{");
    for(i=0; i<n; i++){
        min=i; /*Svaki put krenemo od elementa na kojem se nadjemo*/
        for(j=i+1; j<n; j++){
            if(niz[j]<niz[min]){
                /*Ako je neki clan niza manji od onog od kojeg krecemo, trebamo zapamtiti njegov indeks*/
                min=j;
            }
        }
        temp=niz[i]; /*Pohranjujemo vrijednost trenutnog elementa koji nije najmanji*/
        niz[i]=niz[min]; /*Na mjesto trenutnog clana upisujemo najmanji*/
        niz[min]=temp; /*Na mjesto najmanjeg upisujemo vrijednost trenutnog clana*/

        /*Kada zavrsimo sa zamjenom poretka, trebamo ispisati clan*/ 
        printf("%g", niz[i]);
        /*Formatiranje trazenog ispisa*/
        if(i!=(n-1)) printf(", ");
        else printf("}");
    }
    return 0;
}
