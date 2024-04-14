#include <stdio.h>
#include <math.h>

int main() {
    int k, i=1, predznak=1;
    double suma=0, clan, limit;
    do {
        printf("Unesite broj decimala: ");
        scanf("%d", &k);
    } while (k<=0 || k>7);

    limit = pow(10, -k-1);
    do {
        clan = (double)predznak/i;
        predznak = -predznak;
        i += 2;
        suma += clan;
    } while (clan>limit);

    suma *= 4;
    printf("Suma iznosi: %g", suma);
    return 0;
}

/*Moglo je i kroz for petlju

    for(i=1; i<=n; i++){
        suma=suma+(pow(-1,i-1)/(2*i-1));
    }
    suma=suma*4;
    
*/