#include <stdio.h>

int main() {
    int n, i, j;
    do{
        printf("Unesite N:\n");
        scanf("%d", &n);
        if(n<1) printf(" N je manje od 1!\n");
        else if(n%2==0) printf(" N je parno!\n");
    } while(n%2==0 || n<1);
    
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i!=(n/2)+1 && j==(n/2)+1) 
                printf("|");
            else if(i==(n/2)+1 && (j==1)) 
                printf("<");
            else if(i==(n/2)+1 && j!=(n/2)+1 && j!=1 && j!=n) 
                printf("-");
            else if(i==(n/2)+1 && (j==n)) 
                printf(">");
            else if(i==(n/2)+1 && j==(n/2)+1) 
                printf("+");
            else if(j<(n/2+1))
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
