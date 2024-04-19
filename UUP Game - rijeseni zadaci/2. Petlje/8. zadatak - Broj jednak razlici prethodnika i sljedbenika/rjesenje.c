#include <stdio.h>

int main() {
    int a, b, c, brojac=0, broj=0;
    do{
        /*Na pocetku je potrebno unijeti tri broja*/
        if(brojac==0){
            printf("Unesite brojeve (0 za kraj): ");
            scanf("%d\n%d", &a,&b);
        }
        /*U svakoj sljedecoj iteracji petlje se unosi samo po jedan broj*/
        scanf("%d", &c);
        if(c==0) break;
        else{
            /*Provjeravamo da li je broj jednak razlici prethodnika i sljedbenika*/
            if(b==a-c) {
            /*Ako jeste, onda povecavamo za 1 broj brojeva koji zadovoljavaju uslov*/
                broj ++;
            }
        
            /*Kad smo zavrsili sa provjerom, pomjerimo unesene brojeve za po jedno mjesto kako bismo omogucili unos novog broja*/
            a=b;
            b=c;
            brojac++;
        }
    } while(c!=0);
    /*Petlje se zavrsava unosom 0*/
    printf("\n");

    /*Sada namjestamo gramaticki ispis*/
    if(broj==0) printf("Niti jedan broj ne zadovoljava uslov.");
    else if(broj%10==1 && broj!=11) printf("%d broj zadovoljava uslov.", broj);
    else if((broj%10==2 || broj%10==3 || broj%10==4) && broj!=12 && broj!=13 && broj!=14) printf("%d broja zadovoljavaju uslov.", broj);
    else printf("%d brojeva zadovoljava uslov.", broj);

    return 0;
}
