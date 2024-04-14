#include <stdio.h>
#include <math.h>

int main() {
    int n, proizvod=1, i;
    printf("Unesite n: ");
    scanf("%d",&n);

    if(n<1){
        printf("Broj nije prirodan");
    }
    else{
        if(n==1) printf("\nProizvod je: 0");
        else{
            for(i=2;i<=n;i+=2){
                proizvod*=i;
            }
            printf("\nProizvod je: %d",proizvod);
        }
    }
    return 0;
}
