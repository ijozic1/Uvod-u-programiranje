#include <stdio.h>
#include <math.h>

int main(){
    int n,i;
    double x, suma=0;
    printf("Unesite broj x: ");
    scanf("%lf", &x);
    do{
        printf("Unesite broj clanova sume: ");
        scanf("%d", &n);
        if(n<=0){
            printf("Pogresan unos!\n");
        }
    }while(n<=0);
    
    for(i=1; i<=n; i++){
        suma=suma+(pow(x,2*i-1)/(2*i-1));
    }

    printf("Suma je: %g", suma);
    return 0;
}