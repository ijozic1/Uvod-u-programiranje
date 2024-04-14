#include <stdio.h>
#include <math.h>
#define PI 3.14

int main() {
    float a,b,c,r,h,P,V;

    /*Unos dimenzija tijela sa tastature*/
	printf("Unesite stranice pravougaonika: ");
    scanf("%f, %f, %f",&a, &b, &c);
    printf("Unesite poluprecnik i visinu valjka: ");
    scanf("%f, %f",&r, &h);

    P=(2*(a*b+b*c+a*c)+2*pow(r,2)*PI+2*r*PI*h);
    /*Ako uzimamo da kvadar i kupa nisu fizicki odvojeni, tj. da na  gornjoj stranici kvadra postoji kruzni isjecak u obliku kruga
    i da valjku nedostaje donja baza, onda bi formula za povrsinu bila P=(2*(a*b+b*c+a*c)+2*pow(r,2)*PI+2*r*PI*h-2*pow(r,2)*PI), 
    tj. P=(2*(a*b+b*c+a*c)+2*r*PI*h) kada se izaz sredi*/
    V=(a*b*c+pow(r,2)*PI*h);

    /*Ispis povrsine i zapremine*/
    printf("\n Povrsina tijela sa slike je %.3f cm2",P);
    printf("\n Zapremina tijela sa slike je %.3f cm3",V);
	return 0;
}