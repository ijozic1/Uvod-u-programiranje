#include <stdio.h>
#include <math.h>

int main() {
    double nizX[100], nizY[100], a,b,c;
    int i,j,n;
    
    /*Prvo trazimo unos realnih koeficijenata a, b, c*/
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    /*Sada treba unijeti broj n koji oznacava broj clanova niza*/
    printf("Unesite n: ");
    do{
        scanf("%d", &n);
        if(n<1 || n>100)
            printf("Pogresan unos!\nUnesite n: ");
    }while(n<1 || n>100);

    /*Kada nam je broj clanova niza postao poznat, trebamo i unijeti clanove tog niza*/
    printf("Unesite vrijednosti x: ");
    for(i=0; i<n; i++){
        scanf("%lf\n",&nizX[i]);
    }

    /*Kada smo unijeli vrijednosti za x, trebamo izracunati i ispisati vrijednosti y
    y=ax^2+bx+c*/
    for(i=0; i<n; i++){
        nizY[i]=a*pow(nizX[i],2)+b*nizX[i]+c;
        printf("y[%d]=%g\n",i,nizY[i]);
    }
    return 0;
}
