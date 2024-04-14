/*Modificirajte prethodni program tako da umjesto while 
petlje koristite for petlju*/
#include <stdio.h>

int main(){
    int broj, suma=0;
    for(suma=0;suma<=100;){
        printf("Unesite broj: ");
        scanf("%d", &broj);
        suma+=broj;
    }

    printf("Suma je: %d", suma);
    return 0;
}