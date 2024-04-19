#include <stdio.h>
#include <math.h>

int main() {
    char spol;
    double visina, visina_inc, masa, imm, imz, pm, pz;
    printf("Unesite spol (M/Z): ");
    scanf("%c",&spol);
    printf("Unesite visinu (u cm): ");
    scanf("%lf", &visina);
    visina_inc=visina/2.54;
    printf("Unesite trenutnu masu: ");
    scanf("%lf",&masa);

    if(spol=='m' || spol=='M'){
        imm=50+2.3*(visina_inc-60);
        if(masa>imm+3){
            printf("Potrebno je da smrsate %.4f kilograma",masa-imm);
        }
        else if(masa<imm-3){
            printf("Potrebno je da se ugojite %.4f kilograma",imm-masa);
        }
        else{
            printf("Vasa masa je uredu");
        }
    }
    if(spol=='z' || spol=='Z'){
        imm=45.5+2.3*(visina_inc-60);
        if(masa>imm+3){
            printf("Potrebno je da smrsate %.4f kilograma",masa-imm);
        }
        else if(masa<imm-3){
            printf("Potrebno je da se ugojite %.4f kilograma",imm-masa);
        }
        else{
            printf("Vasa masa je uredu");
        }
    }
    return 0;
}
