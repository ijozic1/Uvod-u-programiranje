#include <stdio.h>

/* Ovdje napisite funkciju udvostruci */
void udvostruci(int*niz, int vel){
    int*p;
    p=niz;
    while(p<niz+vel){
        *p=*p*2;
        p++;
    }
}
/* Kraj napisane funkcije */

int main() {
    int i,niz[3]={1,0,-2};
    udvostruci(niz,3);
    for(i=0;i<3;i++)
        printf("%d ", niz[i]);
    return 0;
}
