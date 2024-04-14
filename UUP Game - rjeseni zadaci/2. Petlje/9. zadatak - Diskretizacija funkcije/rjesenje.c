#include <stdio.h>
#include <math.h>

int main() {
    int n=0,k=0,i,j,k1=0;
    double x=0,y=0,x1=0;
    printf("Unesite n: ");
    scanf("%d",&n);
    printf("Unesite korak diskretizacije: ");
    scanf("%d", &k);
    k1=k;
    printf("Unesite pocetnu vrijednost x: ");
    scanf("%lf", &x);
    x1=x;
    
    for(i=0; i<=n+1; i++){
        for(j=0; j<2; j++){
            /*Racunamo y po formuli datoj u zadatku*/
            y=pow(x1,3)+5*pow(x1,2)-7*x1+14;
            /*Prve dvije iteracije petlje su formalni dio*/
            if(i==0 && j==0) printf("x     ");
            else if(i==0 && j==1) printf("y=f(x)");
            else if(i==1 && (j==0 || j==1)) printf("------");
            /*Od trece iteracije dolazi do racunanja y i ispisa rezultata*/
            else if(j==0) printf("%.1lf   ",x1);
            else if (j==1) printf("%.2lf",y);
        }
        printf("\n");
        /*S obzirom da se u prve iteracije ne vrsi racunanje, to x koristimo tek od trece iteracije*/
        if(i>1) x1=x1+k1;
    }
    return 0;
}
