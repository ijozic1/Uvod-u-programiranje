#include <stdio.h>

int main() {
    int dan, mjesec;
	/*Unos datuma rodjenja*/
    printf("Dan: ");
    scanf("%d", &dan);
    printf("Mjesec: ");
    scanf("%d", &mjesec);

    if((dan<1 || dan>31)||(mjesec<1 || mjesec>12)){
        printf("Neispravan datum rodjenja!");
    }
    else{
        printf("Vas znak je ");
        switch(mjesec){
            case 1:
               if (dan <=19) printf("Jarac!");
               else printf("Vodolija!");
            break;
            case 2:
                if (dan <=18) printf("Vodolija!");
               else printf("Ribe!");
            break;
            case 3:
                if (dan <=20) printf("Ribe!");
               else printf("Ovan!");
            break;
            case 4:
                if (dan <=19) printf("Ovan!");
               else printf("Bik!");
            break;
            case 5:
                if (dan <=20) printf("Bik!");
               else printf("Blizanci!");
            break;
            case 6:
                if (dan <=20) printf("Blizanci!");
               else printf("Rak!");
            break;
            case 7:
                if (dan <=22) printf("Rak!");
               else printf("Lav!");
            break;
            case 8:
                if (dan <=22) printf("Lav!");
               else printf("Djevica!");
            break;
            case 9:
                if (dan <=20) printf("Djevica!");
               else printf("Vaga!");
            break;
            case 10:
                if (dan <=22) printf("Vaga!");
               else printf("Skorpija!");
            break;
            case 11:
                if (dan <=21) printf("Skorpija!");
               else printf("Strijelac!");
            break;
            case 12:
                if (dan <=21) printf("Strijelac!");
               else printf("Jarac!");
            break;
        }
    }
	return 0;
}
