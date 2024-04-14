/*Korisnik sa tastature unosi osam realnih brojeva koji predstavljaju mjerenja temperature 
tokom jednog dana (temperatura se mjeri svaka 3 sata). Napišite program koji treba ispisati 
najveću temperaturu tokom jednog dana te prosječnu temperaturu.

Primjer ulaza i izlaza programa:
	Unesite temperature: 10 11 14 18 20 16 12 11
    Maksimalna temperatura: 20.0
	Prosjecna temperatura: 14.0

Ovaj zadatak riješite tako što ćete napraviti dvije funkcije:
Funkcija maxtemp() koja vraća maksimalnu vrijednost niza. Prototip:
float maxtemp(float p[8]);

Funkcija prtemp() koja vraća prosječnu vrijednost elemenata niza. Prototip:
float prtemp(float p[8]);
*/
#include <stdio.h>
#include <math.h>

float maxtemp(float p[8]){
    float*q,max;/*pokazivac max cuva adresu na kojoj je vrijednost maksimalne temperature*/
    q=p;
    max=*p;
    while(q<p+8){
        if(*q>max) max=*q;
        q++;
    }
    return max;
}

float prtemp(float p[8]){
    float*q, suma=0, prtemp;
    q=p;
    while(q<p+8){
        suma=suma+*q;
        q++;
    }
    prtemp=suma/8;
    return prtemp;
}

int main() {
    float niz_temp[8], max_temp, prosjecna_temp;
    int i;
	printf("Unesite temperature: ");
    for(i=0; i<8; i++) scanf("%f", &niz_temp[i]);
    
    max_temp=maxtemp(niz_temp);
    prosjecna_temp=prtemp(niz_temp);
    printf("Maksimalna temperatura: %.1f",max_temp);
    printf("\nProsjecna temperatura: %.1f",prosjecna_temp);
	return 0;
}
