#include <stdio.h>

int korijen(int a){
    int i, korijen=-1;
    for(i=0; i<=a; i++){
        if(i*i==a){
            korijen=i;
            break;
        }
    }
    return korijen;
}

int main() {
    int n, korijen_n;
    printf("Unesite n: ");
    scanf("%d",&n);
    korijen_n=korijen(n);
    if(korijen_n!=-1){
        printf("Korijen broja %d je %d.",n,korijen_n);
    }
    else printf("Korijen broja %d nije cijeli broj.", n);
    return 0;
}
