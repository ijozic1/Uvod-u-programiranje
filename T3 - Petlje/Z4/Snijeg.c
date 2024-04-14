/*Napravite program "Snijeg" koji, za uneseni broj n, na ekranu iscrtava uzorak od n×n
zvjezdica koja su naizmjenično razmaknute sa po jednim razmakom.*/
#include <stdio.h>
#include <math.h>

int main(){
    int n,i,j;
    printf("Unesite n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1; j<=n; j++){
            if(i%2==1) printf("* ");
            else printf(" *");
        }
        printf("\n");
    }
    return 0;
}