#include <stdio.h>
#include <math.h>

int main() {
    int rvh, rvm;
    float cijena;
    printf("Unesite trenutno vrijeme (hh:mm): ");
    scanf("%d:%d", &rvh, &rvm);

    if(rvh<8 || rvh>17) {
        printf("Uneseno vrijeme je van radnog vremena prodavnice.");
    }
    else{
        printf("Unesite cijenu robe (KM): ");
        scanf("%f", &cijena);
        if(cijena<15){
            cijena=cijena+0.15*cijena;
            printf("Cijena je uvecana za 15%% i iznosi %gKM.", cijena);
        }
        else if(cijena>=15 && cijena<=45){
            cijena=cijena-4;
            printf("Cijena je smanjena za 4KM i iznosi %gKM.", cijena);
        }
        else{
            cijena=cijena-0.12*cijena;
            printf("Cijena je smanjena za 12%% i iznosi %gKM.", cijena);
        }
    }    
    return 0;
}
