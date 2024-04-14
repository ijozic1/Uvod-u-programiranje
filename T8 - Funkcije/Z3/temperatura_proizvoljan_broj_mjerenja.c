/*Modificirati prethodni program (zadatak 2.) tako da broj mjerenja 
nije konstantan (osam) nego se unosi sa tastature.
Da bi se ove funkcije mogle koristiti i u drugim programima, 
trebate proslijediti funkcijama broj mjerenja kao parametar, 
npr. za funkciju maxtemp() prototip sada treba biti:
float maxtemp(float p[], int br);
*/
#include <stdio.h>
#include <math.h>

float maxtemp(float *p, long long vel){
    float*q,max;/*pokazivac max cuva adresu na kojoj je vrijednost maksimalne temperature*/
    q=p;
    max=*p;
    while(q<p+vel){
        if(*q>max) max=*q;
        q++;
    }
    return max;
}

float prtemp(float *p, long long vel){
    float*q, suma=0, prtemp;
    q=p;
    while(q<p+vel){
        suma=suma+*q;
        q++;
    }
    prtemp=suma/vel;
    return prtemp;
}

int main() {
    float niz_temp[10000], max_temp, prosjecna_temp;
    int i;
    long long vel;
    printf("Unesite broj mjerenja: ");
    scanf("%lld", &vel);
	printf("Unesite temperature: ");
    for(i=0; i<vel; i++) scanf("%f", &niz_temp[i]);
    
    max_temp=maxtemp(niz_temp,vel);
    prosjecna_temp=prtemp(niz_temp,vel);
    printf("Maksimalna temperatura: %.1f",max_temp);
    printf("\nProsjecna temperatura: %.1f",prosjecna_temp);
	return 0;
}

