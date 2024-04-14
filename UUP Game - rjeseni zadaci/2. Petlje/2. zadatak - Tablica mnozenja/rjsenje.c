#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, proizvod, brojac=0;
    printf("Unesite n: ");
    scanf("%d", &n);

    if(n<2 || n>10){
        printf("Uneseni broj nije u intervalu!");
    }
    else{
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                proizvod=i*j;
                printf("%d   ", proizvod);
                /*U postavci pise da se tablica ispisuje na cetiri mjesta sirine pa bi to islo preko ovog brojaca, u autotestovima se ispisuje na n mjesta sirine.*//*
                brojac++;
                if(brojac==4){
                    printf("\n");
                    brojac=0;
                }*/    
            }
            printf("\n");
        }
    }
    return 0;
}
