#include <stdio.h>
const int n=5;

/*int main(void){
    int i, smjerbrojanja=1, j=1;
    while(j<2*n){
        i=1;
        while(smjerbrojanja<=n && smjerbrojanja>=i || smjerbrojanja>n && j+i<2*n){
            printf("%d",i++);
        }
        if(smjerbrojanja<=n && smjerbrojanja<i || smjerbrojanja>n && smjerbrojanja<i+n){
            smjerbrojanja=smjerbrojanja+1;
        }
        j=smjerbrojanja;
    }
    return 0;
}*/

int main(void){
    int i, smjerbroja=1, j=1;
    while(j>0){
        i=1;
        while(i<=j){
            printf("%d", i++);
        }
        if(i==n+1){
            smjerbroja=-1;
        }
        j+=smjerbroja;
        printf("\n");
    }
    return 0;
}