#include <stdio.h>

int main() {
    int i, j, n;
    printf("Unesite n: ");
    scanf("%d", &n);

    if(n<2){
        printf("Neispravan unos");
    }
    
    else{
        /*Oblik printamo pomocu for petlje - mozemo ga podijeliti na 4 kvadrata stranice n*/
        for(i=1; i<=2*n; i++){
            for(j=1; j<=2*n+1; j++){
                /*Gornji lijevi kvadrat*/
                if(i<=n && j<=n){
                    if(i>=j) printf("*");
                    else printf(" ");
                }
                /*Gornji desni kvadrat*/
                else if(i<=n && j>n){
                    if(i+j>2*n+1) printf("*");
                    else printf(" ");
                }
                /*Donji lijevi kvadrat*/
                else if(i>n && j<=n){
                    if((i-n)+j<n+1) printf("*");
                    else printf(" ");
                }
                /*Ostaje jos donji desni kvadrat*/
                else{
                    if(i<j-1) printf("*");
                    else printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
