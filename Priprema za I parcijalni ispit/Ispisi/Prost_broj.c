#include <stdio.h>
#include <math.h>

int main(){
    int n, i, prost=1;
    printf("Unesite broj n: ");
    scanf("%d", &n);

    for(i=2; i<n; i++){
        if(n%i==0){
            prost=0;
            printf("Slozen");
            break;
        }
    }

    if(prost==1) printf("Prost");
    
    return 0;
}