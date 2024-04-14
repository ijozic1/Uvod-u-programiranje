#include <stdio.h>
#include <math.h>

int main() {
    int i, j, n, nul=1, jedinicna=1, dijagonalna=1, gornja_tro=1, donja_tro=1, s_dijagonalna=1;
    double matrica[100][100];
    /*Prvo unosimo dimenzije kvadratne matrice*/
    do{
        printf("Unesite broj N: ");
        scanf("%d", &n);
        if(n<1 || n>100){
            printf("Pogresan unos!\n");
        }
    }while(n<1 || n>100);
    /*Sada trebamo unijeti elemente matrice*/
    printf("Unesite elemente matrice: ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%lf",&matrica[i][j]);
        }
    }

    /*Sada prolazimo kroz matricu i provjeravamo koje je vrste*/
    /*Prvo provjerimo je li nul-matrica - svi elementi su joj 0*/
    for(i=0; i<n && nul; i++){
        for(j=0; j<n; j++){
            if(matrica[i][j]!=0){
                nul=0;
                break;
            }
        }
    }
    /*Sada provjerimo je li jedinicna - na glavnoj dijagonali 1, a ostali elementi 0*/
    for(i=0; i<n && jedinicna; i++){
        for(j=0; j<n; j++){
            if(i==j && matrica[i][j]!=1 || i!=j && matrica[i][j]!=0){
                jedinicna=0;
                break;
            }
        }
    }
    /*Sada provjerimo je li dijagonalna - u njoj su samo elementi na glavnoj dijagonali razliciti od 0*/
    for(i=0; i<n && dijagonalna; i++){
        for(j=0; j<n; j++){
            if(i!=j && matrica[i][j]!=0){
                dijagonalna=0;
                break;
            }
        }
    }
    /*Sada provjeravamo je li gornja trougaona - ona ima nule ispod glavne dijagonale*/
    for(i=0; i<n && gornja_tro; i++){
        for(j=0; j<n; j++){
            if(i>j && matrica[i][j]!=0){
                gornja_tro=0;
                break;
            }
        }
    }
    /*Provjeravamo je li matrica donja trougaona - ona iznad glavne dijagonale mora imati nule*/
    for(i=0; i<n && donja_tro; i++){
        for(j=0; j<n; j++){
            if(j>i && matrica[i][j]!=0){
                donja_tro=0;
                break;
            }
        }
    }
    /*Ostalo je jos da provjerimo je li sporedno dijagonalna - elementi na sporednoj dijagonali su razliciti od 0, a ostali su 0*/
    for(i=0; i<n && s_dijagonalna; i++){
        for(j=0; j<n; j++){
            if((i+j)!=n-1 && matrica[i][j]!=0){
                s_dijagonalna=0;
                break;
            }
        }
    }
    /*Sada je otalo jos da ispisemo koje je vrste matrica - ne moze biti dvije opcije odjednom, pa koristimo if else strukturu*/
    if(nul==1) printf("Nul-matrica");
    else if(jedinicna==1) printf("Jedinicna matrica");
    else if(dijagonalna==1) printf("Dijagonalna matrica");
    else if(gornja_tro==1) printf("Gornja trougaona matrica");
    else if(donja_tro==1) printf("Donja trougaona matrica");
    else if(s_dijagonalna==1) printf("Sporedna dijagonalna matrica");
    else printf("Nista od navedenog");
    
    return 0;
}
