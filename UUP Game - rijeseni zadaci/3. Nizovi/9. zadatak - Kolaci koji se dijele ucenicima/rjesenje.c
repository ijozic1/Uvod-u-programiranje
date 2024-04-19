#include <stdio.h>
#include <math.h>

int main() {
    int i=0, n, niz[1000], brojac=0, br_kolaca, br_niz=0;
    /*n - broj kolaca za pojedinog ucenika
    br_kolaca - ukupan broj ispecenih kolaca
    br_niz - brojac elemenata u nizu
    brojac - izbrojati ce koliko ucenika je dobilo kolace*/
    
    
    /*printf("Unesite koliko kolaca ucenici zele: ");*/
    /*Prvo unosimo koliko kolaca zele ucenici*/
    do{
        scanf("%d", &n);
        niz[i]=n;
        if(n==-1) break;
        i++;
    }while (i<1000);
    /*Broj elemenata niza je jednak i, jer i krece od nula, a niz zavrsava sa -1 sto ne pripada nizu*/
    br_niz=i;

    /*Sada unosimo broj ispecenih kolaca*/
    /*printf("Unesite broj ispecenih kolaca: ");*/
    scanf("%d", &br_kolaca);

    /*Ostaje jos da prebrojimo koliko ucenika je dobilo kolace*/
    for(i=0; i<br_niz; i++){
        if(br_kolaca>0){
            br_kolaca=br_kolaca-niz[i];
            brojac++;
        }
    }

    /*sada jos treba ispisati koliko ucenika je dobilo kolace*/
    if(brojac==0){
        printf("Nijedan ucenik nije dobio kolace");
    }
    else if(brojac%10==1 && brojac!=11){
        printf("%d ucenik je dobio kolace", brojac);
    }
    else if((brojac%10==2 && brojac!=12) || (brojac%10==3 && brojac!=13)){
        printf("%d ucenika su dobila kolace", brojac);
    }
    else{
        printf("%d ucenika je dobilo kolace", brojac);
    }

    return 0;
}
