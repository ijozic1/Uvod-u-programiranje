#include <stdio.h>
#include <math.h>

int NZD(int x, int y){
    int manji, nzd=1, i, j;
    /*Nzd smo inicijalizirali na 1 u slucaju da su brojevi relativno prosti*/
    /*Najveci zajednici djelilac moze biti manji ili jednak manjem broju*/
    if(x>y) manji=y;
    else manji=x;
    /*For peljljom krenemo od broja dva (svaki broj je djeljiv sa 1, a nzd je inicijalizi-ran na 1 pa nema potrebe provjeravati) pa do manjeg i trazimo NZD*/
    for(i=2; i<=manji; i++){
        if(x%i==0 && y%i==0){
            nzd=i;
        }
    }
    return nzd;
}

int main() {
    int a, b;
    printf("Unesite a: ");
    scanf("%d", &a);
    printf("Unesite b: ");
    scanf("%d", &b);
    printf("NZD(%d,%d) je %d.", a, b, NZD(a,b));
    return 0;
}
