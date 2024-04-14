/*Data je sljedeća struktura:

	struct Vrijeme {
		int sati;
		int minute;
		int sekunde;
	};

Napišite funkciju unos_vremena koja omogućuje unos vrijednosti tipa 
struct Vrijeme, a zatim funkciju proteklo koja određuje koliko sekundi 
je proteklo između dva vremena koja prima kao parametre v1 i v2. 
Obratite pažnju da ako je v1 ispred ili iza v2 funkcija treba u oba 
slučaja vratiti pozitivan broj sekundi. U mainu treba omogućiti unos 
dva vremena, a zatim ispisati koliko sekundi je proteklo između njih 
koristeći navedene dvije funkcije. 

Primjer ulaza i izlaza:
	Unesite prvo vrijeme (h m s): 1 15 30
	Unesite drugo vrijeme (h m s): 2 30 15
	Izmedju dva vremena je proteklo 4485 sekundi.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Vrijeme{
    int sati;
    int minute;
    int sekunde;
};

/*Funkcija za unos vremena*/
struct Vrijeme unos_vremena(int parametar){
    struct Vrijeme v;
    if(parametar==1){
        printf("Unesite prvo vrijeme (h m s): ");
        scanf("%d %d %d", &v.sati, &v.minute, &v.sekunde);
    }
    else if(parametar==2){
        printf("\nUnesite drugo vrijeme (h m s): ");
        scanf("%d %d %d", &v.sati, &v.minute, &v.sekunde);
    }
    return v;
}

/*Funkcija koja racuna koliko je vremena proslo*/
int proteklo(struct Vrijeme v1, struct Vrijeme v2){
    int sekunde1, sekunde2, proteklo;
    sekunde1=v1.sati*3600+v1.minute*60+v1.sekunde;
    sekunde2=v2.sati*3600+v2.minute*60+v2.sekunde;
    proteklo=abs(sekunde1-sekunde2);
    return proteklo;
}

int main() {
    struct Vrijeme v1;
    struct Vrijeme v2;
    int proslo, i=1;
    v1=unos_vremena(i++);
    v2=unos_vremena(i);
    proslo=proteklo(v1,v2);
    printf("\nIzmedju dva vremena je proteklo %d sekundi.", proslo);
	return 0;
}
