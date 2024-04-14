/*Modificirajte prethodni program tako da on 
a)izracunava prosjek samo elemenata niza čija je vrijednost paran broj.
b)prepravite program tako da se u njemu koristi samo jedna petlja!
c)prepravite program tako da u unesenom nizu brojeva pronalazi najveći i najmanji element.
*/
#include <stdio.h>
#define BROJ_EL 10

int main() {
    int niz[BROJ_EL], suma=0, suma_parnih=0, i, brojac_parnih=0, min, maks;
    float prosjek, prosjek_parnih;

    /*Unos niza, i trazenje min i maks koje smo deklarisali kao prve clanove niza*/
    for(i=0; i<BROJ_EL; i++){
        printf("Unesite %d. cijeli broj: ", i+1);
        scanf("%d", &niz[i]);
        if(i==0){
            /*Kad smo unijeli prvi element mozemo min i maks dodijeliti njegovi vrijednost*/
            min=niz[i];
            maks=niz[i];
        }
        /*Svaki novi element dodajemo na sumu elemenata niza*/
        suma=suma+niz[i];
        /*Provjeravamo da li je element niza paran ili ne*/
        if(niz[i]%2==0){
            suma_parnih=suma_parnih+niz[i];
            brojac_parnih++;
        }
        if(niz[i]<min) min=niz[i];
        if(niz[i]>maks) maks=niz[i];
    }
    /*Ako nije unesen ni jedan parni element, onda cemo imati dijeljejne nulom sto nije definirano*/
    if(brojac_parnih==0) brojac_parnih=1;
    prosjek_parnih=(float)suma_parnih/brojac_parnih;
    prosjek=(float)suma/BROJ_EL;
    
    printf("Srednja vrijednost unesenih brojeva je %.2f.\n",prosjek);
    printf("Srednja vrijednost parnih brojeva je %.2f.\n",prosjek_parnih);
    printf("Najveci element je %d a najmanji %d.",maks, min);
	return 0;
}
