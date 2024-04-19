#include <stdio.h>

int stepen_broja_dva(int n){
    int stepen=0;
    long long i;
    n=(long long)n;
    for(i=1; i<=n; i*=2){
        if(i==n) stepen=1;
    }
    if(stepen!=1) stepen=0;
    return stepen;
}

int main() {
    int x, stepen_dvojke;
    printf("Unesite n: ");
    scanf("%d", &x);
    if(stepen_broja_dva(x)==1) 
        printf("Broj %d je stepen dvojke.",x);
    else 
        printf("Broj %d nije stepen dvojke.",x);
    return 0;
}
