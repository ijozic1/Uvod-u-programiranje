#include <stdio.h>
#include <math.h>

int main() {
    int p,q, i, j;
    double matrica[100][100], suma=0;
    
    /*Prvo od korisnika trazimo da unese dimenzije matrice*/
    do{
        printf("Unesite dimenzije matrice: ");
        scanf("%d %d", &p, &q);
        if(p<1 || p>100 || q<1 || q>100){
            printf("Neispravne dimenzije matrice!\n");
        }
    }while(p<1 || p>100 || q<1 || q>100);

    /*Kada su unesene ispravne dimenzije, korisnik unosi elemente matrice*/
    printf("Unesite elemente matrice: ");
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            scanf("%lf", &matrica[i][j]);
        }
    }

    /*Kada smo unijeli elemente u matricu, racunamo sumu elemenata na rubovima*/
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            if(i==0 || i==p-1){
                suma=suma+matrica[i][j];
            }
            else if(j==0 || j==q-1){
                suma=suma+matrica[i][j];
            }
        }
    }
    
    printf("Suma elemenata na rubu je %.2lf", suma);

    return 0;
}
