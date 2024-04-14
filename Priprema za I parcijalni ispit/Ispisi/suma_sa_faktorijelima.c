#include <stdio.h>
#include <math.h>

int faktoriel(int n){
    int i, faktoriel=1;
    for(i=1; i<=n; i++){
        faktoriel=faktoriel*i;
    }
    return faktoriel;
}

int main(){
    int i,n;
    double suma=0,x;
    
    printf("Unesite realan broj x: ");
    scanf("%lf", &x);
    
    do{
        printf("Unesite broj clanova sume: ");
        scanf("%d", &n);
        if(n<1) printf("Pogresan unos!\n");
    }while(n<1);

    for(i=1; i<=n; i++){
        suma=suma+(double)(pow(x,i)/faktoriel(i));
    }

    printf("Suma je: %g", suma);
    return 0;
}