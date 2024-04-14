#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.001

int main() {
    int i=0, j, t=0, brojac1=0, brojac2=0, brojac3=0;
    double niz1[50], niz2[50], niz3[50];

    printf("Unesite elemente 1.niza (-1 kraj): ");
    do{
        scanf("%lf", &niz1[i]);
        if(niz1[i]==-1) break;
        i++;
    }while(i<50 && niz1[i]!=-1);
    /*Niz ima i+1 elemenata, ali oni idu od 0 i na poziciji i se nalazi -1*/
    brojac1=i;

    printf("\nUnesite elemente 2.niza (-1 kraj): ");
    i=0;
    do{
        scanf("%lf", &niz2[i]);
        if(niz2[i]==-1) break;
        i++;
    }while(i<50 && niz2[i]!=-1);
    brojac2=i;

    /*Sada trazimo elemente koji se pojavljuju u oba niza */
    t=0;
    for(i=0; i<brojac1; i++){
        for(j=0; j<brojac2; j++){
            /*Za svaki element niza1 prodjemo kroz cijeli niz2 i trazimo da li imaju isti element, ako imaju, spremimo taj element u niz3*/
            if(fabs(niz1[i]-niz2[j])<EPSILON){
                /*Kada prvi put naidjemo na zajednicki element ne moramo dalje prolaziti kroz niz2*/
                niz3[t]=niz1[i];
                t++;
                break;
            }
        }
    }

    /*Treci niz nam ima t elemenata*/
    brojac3=t;

    /*Sada trebamo proci kroz niz i osigurati da nam se neki element ne pojavljuje dva puta*/
    for(i=0; i<brojac3; i++){
        for(j=i+1; j<brojac3; j++){
            if(fabs(niz3[i]-niz3[j])<EPSILON){
                for(t=j; t<brojac3; t++){
                    niz3[t]=niz3[t+1];
                }
                j--;
                brojac3--;
            }
        }
    }

    /*Sada kada u nizu nema ponovljenih elemenata, trebamo jos samo ispisati zajednicke elemente*/
    if(brojac3==0) printf("\nPresjek unesenih nizova je prazan skup!");
    else{
        printf("\nPresjek unesenih nizova je: ");
        for(i=0; i<brojac3; i++){
            printf("%g", niz3[i]);
            if(i!=brojac3-1) printf(", ");
        }
    }
    return 0;
}
