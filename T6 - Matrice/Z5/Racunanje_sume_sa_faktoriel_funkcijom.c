/*Napravite funkciju "faktorijel" koja računa faktorijel datog broja. Zatim iskoristite ovu
funkciju za program koji računa sumu: S(x)=(suma od i=1 do n)(x/i!)*/
#include <stdio.h>
#include <math.h> 

int faktoriel(int a){
    int i, faktoriel=1;
    for(i=1; i<=a; i++){
        faktoriel=faktoriel*i;
    }
    return faktoriel;
}

int main() {
    int n, i;
    double x, suma=0;
	printf("Unesite broj n u intervalu [1, 12]: ");
    scanf("%d", &n);
    if(n<1 || n>12){
        printf("Pogresan unos!");
        return 0;
    }

    else{
        printf("Unesite realan broj x: ");
        scanf("%lf", &x);
        for(i=1; i<=n; i++){
            suma=suma+(x/faktoriel(i));
        }
        printf("Suma od 1 do %d za x = %.3lf je %.3lf", n, x, suma);
    }
	return 0;
}
