#include <stdio.h>

int main() {
    int dan, mjesec, godina;
    printf("Unesite dan, mjesec i godinu (razdvojite razmakom): ");
    scanf("%d %d %d", &dan, &mjesec, &godina);

    if(dan<1 || dan>31 || mjesec<1 || mjesec>12 || godina<1 || godina>4000){
        printf("Pogresni ulazni podaci!");
    }
    else{
        printf("Uneseni datum je %d. ", dan);
        switch(mjesec){
            case 1: 
                printf("januar ");
                break;
            case 2:
                printf("februar ");
                break;
            case 3: 
                printf("mart ");
                break;
            case 4:
                printf("april ");
                break;
            case 5: 
                printf("maj ");
                break;
            case 6:
                printf("juni ");
                break;
            case 7: 
                printf("jul ");
                break;
            case 8:
                printf("august ");
                break;
            case 9: 
                printf("septembar ");
                break;
            case 10:
                printf("oktobar ");
                break;
            case 11: 
                printf("novembar ");
                break;
            case 12:
                printf("decembar ");
                break;
        }
        printf("%d. godine", godina);
    }
    return 0;
}
