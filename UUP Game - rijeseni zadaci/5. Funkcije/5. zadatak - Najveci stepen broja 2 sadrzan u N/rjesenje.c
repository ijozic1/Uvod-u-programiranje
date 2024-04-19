#include <stdio.h>

int vrati_najveci_stepen(int n){
    int i, stepen=-1;
    /*Stepen krece od -1 jer je 2^0=1 i to ce brojati kao prvi, a ne nulti stepen*/
    for(i=1; i<=n; i*=2){
        stepen++;
    }
    return stepen;
}

int main() {
    int N;
    printf("Unesite n: ");
    scanf("%d", &N);
    printf("Rezultat je %d.", vrati_najveci_stepen(N));
    return 0;
}
