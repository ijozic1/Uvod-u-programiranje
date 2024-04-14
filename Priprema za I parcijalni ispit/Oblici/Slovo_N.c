#include <stdio.h>

int main(){
    int n, i,j;
    printf("Unesite cijeli broj n>4: ");
    do{
        scanf("%d",&n);
        if(n<5){
            printf("Pogresan unos!\nBroj treba biti veci od 4!\n");
            printf("Unesite cijeli broj n: ");
        }
    }while(n<5);
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j==0 || j==n-1 || i==j){
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}