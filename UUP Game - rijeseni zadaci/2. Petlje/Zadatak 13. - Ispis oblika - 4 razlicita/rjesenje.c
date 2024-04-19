#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Unesite broj N: \n");
    scanf("%d", &n);
    do{
        if(n<8 ||n%4!=0){
            printf("Neispravno N!\n");
            printf("Unesite broj N: ");
            scanf("%d", &n);
        }
        else break;
    }while(n<8 || n%4!=0);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            /*Prvo printamo X*/
            if(i<=n/2 && j<=n/2){
                if(i==j) 
                    printf("\\");
                else if(i+j==n/2+1) 
                    printf("/");
                else 
                    printf(" ");
            }
            /*Zatim printamo gornji pravougaonik*/
            if(i<=n/2 && j>n/2){
                if(i==1 || i==n/2){
                    if(j==n/2+1 || j==n)
                        printf("+");
                    else 
                        printf("-");
                }
                if(i>1 && i<n/2){
                    if(j==n/2+1 || j==n)
                        printf("|");
                    else 
                        printf(" ");
                }
                
            }
            /*Sada pritamo donji pravougaonik*/
            if(i>n/2 && j<=n/2){
                if(i==n/2+1 || i==n){
                    if(j==1 || j==n/2)
                        printf("+");
                    else 
                        printf("-");
                }
                if(i>n/2+1 && i<n){
                    if(j==1 || j==n/2)
                        printf("|");
                    else 
                        printf(" ");
                }
                
            }
            /*Posljednji printamo plus*/
            if(i>n/2 && j>n/2){
                if(i!=(n/2+n/4) && i!=(n/2+n/4+1)){
                    if(j==(n/2+n/4) || j==(n/2+n/4+1))
                        printf("|");
                    else printf(" ");
                }
                else if(i==(n/2+n/4) || i==(n/2+n/4+1)){
                    if(j!=(n/2+n/4) && j!=(n/2+n/4+1))
                        printf("-");
                    else printf("+");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
