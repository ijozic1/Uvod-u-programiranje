#include <stdio.h>

int main() {
    int i, j, n, zbir=0, brojac=0;
    printf("Unesite n: ");
    scanf("%d", &n);

    if(n<2){
        printf("Suma je 0");
    }

    else{
        for(i=2; i<=n; i++){
            for(j=2; j<=n; j++){
                if(i%j==0){
                    brojac++;
                }
            }
            if(brojac==1){
                printf("%d\n",i);
                zbir=zbir+i;
            }
            brojac=0;
        }
        printf("Suma je: %d", zbir);
    }
    return 0;
}
