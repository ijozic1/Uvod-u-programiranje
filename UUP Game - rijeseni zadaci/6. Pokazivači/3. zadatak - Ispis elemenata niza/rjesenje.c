#include <stdio.h>

/* Ovdje napisite funkciju ispisi */
void ispisi(int*niz, int vel){
    int*p=niz;
    printf("{");
    while(p<niz+vel){
        printf("%d",*p);
        p++;
        if(p!=niz+vel) printf(", ");
    }
    printf("}");
}
/* Kraj napisane funkcije */

int main() {
    int niz1[] = {1, 3, 2};
    int niz2[10] = {0, 3, 2, 2, 2, 4, 6, 1, 9, 10};
    ispisi(niz1, 3);
    printf("\n");
    ispisi(niz2, 10);
    return 0;
}
