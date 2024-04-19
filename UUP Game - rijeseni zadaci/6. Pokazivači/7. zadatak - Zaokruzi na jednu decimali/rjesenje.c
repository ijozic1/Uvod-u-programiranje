#include <stdio.h>

/* Ovdje napisite funkciju zaokruzi */
#include<math.h>
void zaokruzi(double *niz, int vel){
    double *p=niz;
    while(p<niz+vel){
        *p=*p*10;
        *p=round(*p);
        *p=*p/10;
        p++;
    }
}
/* Kraj napisane funkcije */

int main() {
    double niz[] = { 1.23, 3.47, 0, 1.23666 };
    zaokruzi(niz, 4);
    int i;
    for(i = 0; i < 4; i++) {
      printf("%g ", niz[i]);
    }
    return 0;
}
