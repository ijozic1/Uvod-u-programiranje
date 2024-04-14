#include <stdio.h>
#define PI 3.14

int main() {
    float r, P, V;

    /*Unos poluprecnika sa tastature*/
    printf("Unesite poluprecnik: ");
    scanf("%f", &r);
	P=r*r*PI;
    V=(4./3)*r*r*r*PI;

    /*Ispis na moitoru*/
    printf("\n Povrsina kruga sa poluprecnikom %.2f je %.2f", r, P);
    printf("\n Zapremina kugle sa poluprecnikom %.2f je %.2f", r, V);
	return 0;
}
