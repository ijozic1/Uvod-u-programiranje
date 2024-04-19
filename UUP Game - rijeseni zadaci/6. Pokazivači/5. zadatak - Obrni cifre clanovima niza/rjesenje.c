#include <stdio.h>

/* Ovdje napisite funkciju obrni_cifre */
void obrni_cifre(int*niz, int vel){
    int*p, broj, cifra, brojac_cifara, novi_broj, potencija=1,j, predznak;
    p=niz;
    while(p<niz+vel){
        if(*p>0) predznak=1;
        else predznak=-1;
        broj=*p*predznak;
        brojac_cifara=0;
        while(broj>0){
            broj=broj/10;
            brojac_cifara++;
        }
        broj=*p*predznak;
        novi_broj=0;
        while(brojac_cifara-1>=0){
            cifra=broj%10;
            broj=broj/10;
            potencija=1;
            for(j=0; j<brojac_cifara-1; j++) potencija*=10;
            novi_broj+=cifra*potencija;
            brojac_cifara--;
        }
        *p=novi_broj*predznak;
        p++;
    }
}
/* Kraj napisane funkcije */

int main() {
    int niz1[5] = {1,23,321,918,33};
    obrni_cifre(niz1, 5);
    int i;
    for(i=0; i<5; i++) printf("%d ", niz1[i]);
    return 0;
}
