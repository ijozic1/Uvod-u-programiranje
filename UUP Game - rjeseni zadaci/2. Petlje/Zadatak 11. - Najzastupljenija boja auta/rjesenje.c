#include <stdio.h>
#include <math.h>

int main() {
    int brojacC=0, brojacB=0, brojacS=0, brojacV=0, brojacP=0, brojac_auta=0, najpopularnije=0;
    double procenat;
    char automobil;
    
    printf("Unesite vozila: ");
    do{
        scanf("%c", &automobil);
        /*Nakon svakog unosa povecavamo broj boje automobila koji je unesen*/
        if(automobil=='c' || automobil=='C') brojacC++;
        else if(automobil=='b' || automobil=='B') brojacB++;
        else if(automobil=='s' || automobil=='S') brojacS++;
        else if(automobil=='v' || automobil=='V') brojacV++;
        else if(automobil=='p' || automobil=='P') brojacP++;
        else if(automobil=='k' || automobil=='K'){
            break;
        }
        else {
            printf("Neispravan unos\n");
            brojac_auta--;
            /*Kompajler i ovakav unos broji u ukupan broj automobila, pa zato vracamo brojac za 1*/
        }
        /*Pri svakom unosu povecavamo ukupan broj unesenih automobila*/
        brojac_auta++;
    }while(automobil!='k' || automobil!='K');

    printf("Ukupno evidentirano %d vozila.\n", brojac_auta);
    
    if(brojac_auta==0){
        printf("Najpopularnija boja je crna (0.00%%).");
    }
    else{
        /*Provjeravamo koja boja je najzastupljenija, poredeci ih sa varijablom najpopularnije*/
        if(brojacC>najpopularnije) najpopularnije=brojacC;
        if(brojacB>najpopularnije) najpopularnije=brojacB;
        if(brojacS>najpopularnije) najpopularnije=brojacS;
        if(brojacV>najpopularnije) najpopularnije=brojacV;
        if(brojacP>najpopularnije) najpopularnije=brojacP;

        /*Trebamo izracunati procenat najzastupljenih vozila i zaokruziti na dvije decimale*/
        procenat=(((double)najpopularnije/brojac_auta)*100)/100*100;

        if(najpopularnije==brojacC){
            printf("Najpopularnija boja je crna (%.2lf%%).",procenat);
        }
        else if(najpopularnije==brojacB){
            printf("Najpopularnija boja je bijela (%.2lf%%).",procenat);
        }
        else if(najpopularnije==brojacS){
            printf("Najpopularnija boja je siva (%.2lf%%).",procenat);
        }
        else if(najpopularnije==brojacV){
            printf("Najpopularnija boja je crvena (%.2lf%%).",procenat);
        }
        else{
            printf("Najpopularnija boja je plava (%.2lf%%).",procenat);
        }
    }
    return 0;
}
