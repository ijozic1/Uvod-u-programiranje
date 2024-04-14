/*Napravite funkciju
int prost(int x)
koja vraća 1 (logička istina) ako je broj x prost, a 0 (logička neistina) ako x nije prost. Zatim
iskoristite ovu funkciju u programu koji ispisuje sve proste brojeve između 1 i 100 (svaki broj u
zasebnom redu).
*/
#include <stdio.h>
#include <math.h>

int prost(int x){
    int i, prost;
    /*djeljivost mozemo poceti provjeravati od dvice jer je svaki broj djeljiv sa 1*/
    for(i=2; i<=x; i++){
        if(i<x && x%i!=0) prost=1;
        else if(i<x && x%i==0){
            prost=0;
            break;
        }
    }
    if(prost==1) return 1;
    else return 0;
}

int main() {
    int i, prost_br;
	printf("Prosti brojevi između 1 i 100 su:\n");
    printf("2\n"); /*Iz nekog razloga ne zeli ispisati dvicu*/
    /*petlja moze krenuti od 2 jer 1 svakako nije prost broj*/
    for(i=2; i<=100; i++){
        prost_br=prost(i);
        if(prost_br==1) printf("%d\n", i);
    }
	return 0;
}
