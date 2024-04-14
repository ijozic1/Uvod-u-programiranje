#include <stdio.h>

int main(){
    int i, j, n;
    printf("Unesite n: ");
    scanf("%d", &n);

    for(i=1; i<=2*n; i++){
        for(j=1; j<=2*n; j++){
            if(i<=n && j<=n){
                if(i>=j) printf("*");
                else printf(" ");
            }
            else if(i<=n && j>n){
                if(i+j>2*n) printf("*");
                else printf(" ");
            }
            else if(i>n && j<=n){
                if((i-n)+j<n+1) printf("*");
                else printf(" ");
            }
            else{
                if(i<j) printf("*");
                else printf(" ");
            }
            }
            printf("\n");
    }
    return 0;
}