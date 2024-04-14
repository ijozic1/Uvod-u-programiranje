#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
    int w, m, j, l;
    /*Integeri su nam sirina(w), broj decimalnih mjesta (m) i varijable za petlje*/
    double a, b, k, y,i;
    /*Varijable tipa double su nam granice intervala, korak, te vrijednost y koja mijenja x^2*/

    printf("Unesite interval [a b]: ");
    scanf("%lf %lf",&a,&b);
    printf("Unesite korak: ");
    scanf("%lf",&k);
    printf("Unesite sirinu ispisa: ");
    scanf("%d",&w);
    printf("Unesite broj decimala: ");
    scanf("%d",&m);
    
    /*U prvoj petlji ispisujemo formalni dio, tj. zaglavlje tabele*/
    for(l=0; l<2; l++){
        /*Koristili smo l umjesto i zato sto nam je zbog druge petlje i tipa double, a ovdje nam treba integer*/
        for(j=1; j<=2*w+1; j++){
            /*Broj kolona unutrasnje petlje nam je 2*w+1 jer nam 2w ode na ispis i jos jedna za |*/
            if(l==0){
                if(j==1) printf("X");
                else if(j==2*w-1) printf("X");
                else if(j==2*w) printf("^");
                else if(j==2*w+1) printf("2");
                else printf(" ");
            }
            else printf("-");
        }
        printf("\n");
    }
    for(i=a; i<=(b+EPSILON); i+=k){
        /*i smo postavili kao a zato sto odatle krenemo racunati x^2*/
        /*i<=(b+EPSILON) s obzirom da su realni brojevi pa moze doci do odtupanja u decimalama*/
        for(j=0; j<3; j++){
            /*Racunamo x^2*/
            y=pow(i,2);
            if(j==0) printf("%-*.*lf",w,m,i);
            else if(j==1) printf("|");
            else if(j==2) printf("%*.*lf",w,m,y);
        }
        printf("\n");
    }
    return 0;
}
