#include <stdio.h>
int main() {
    int n = 5, i, j;
    for (i=1; i<=2*n-1; i++) {
        for (j=1; j<=n; j++) {
            if ((i<=n && i>=j) || (i>n && i+j<2*n+1))
                printf("*");
            else
            printf(" ");
        }
        for (j=n+1; j<=2*n+1; j++) {
            if ((i<=n && i+j>2*n+1) || (i>n &&i<j-1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
return 0;
}