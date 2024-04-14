#include <stdio.h>
#include <math.h>

int fibonacci(int x){
    int niz[100]={0,1}, fibonacci, i;
    for(i=2; i<100; i++){
        niz[i]=niz[i-1]+niz[i-2];
    }
    fibonacci=niz[x];
    return fibonacci;
}

int main() {
    int n;
    printf("Unesite broj: ");
    scanf("%d", &n);
    printf("%d-ti Fibonaccijev broj je %d.", n, fibonacci(n));
    return 0;
}
