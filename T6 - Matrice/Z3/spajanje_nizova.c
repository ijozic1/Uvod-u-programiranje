/*Napisati program koji najprije traži da se unesu dva niza pozitivnih cijelih brojeva A i B.
Unos niza se prekida kada korisnik unese broj -1, a maksimalan broj elemenata u nizovima je
10. Nakon unosa, nizove A i B je potrebno spojiti u novi niz C. Konačno, tako formirani niz C
treba ispisati na ekranu.
*/

#include <stdio.h>
#include <math.h>

int main() {
    int nizA[10], nizB[10], i=0, n, j, brojacA=0, brojacB=0;

	printf("Unesite elemente niza A: ");
    do{
        scanf("%d", &n);
        if(n!=(-1) && i<10){
            nizA[brojacA++]=n;
        }
        i++;
    }while(n!=(-1) && i<10);

    printf("Unesite elemente niza B: ");
    i=0; /*Moramo vratit i na 0 da upis clanova u B niz pocne od nulte pozicije*/
    do{
        scanf("%d", &n);
        if(n!=(-1) && i<10){
            nizB[brojacB++]=n;
        }
        i++;
    }while(n!=(-1) && i<10);

    /*Sada ispisujemo niz C*/
    printf("Niz C glasi: ");

    for(i=0; i<brojacA; i++){
        if(i==brojacA-1 && brojacB==0){
            printf("%d", nizA[i]);
        }
        else{
            printf("%d,", nizA[i]);
        }
    }

    for(i=0; i<brojacB; i++){
        if(i==brojacB-1){
            printf("%d", nizB[i]);
        }
        else{
            printf("%d,", nizB[i]);
        }
    }
	return 0;
}
