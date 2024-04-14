/*Prepravite prethodni program tako da određuje koliko sati, 
minuta i sekundi je proteklo između dva vremena. Funkcija proteklo 
treba vraćati struct Vrijeme. Na primjer:

	Unesite prvo vrijeme (h m s): 1 15 30
	Unesite drugo vrijeme (h m s): 2 30 15
	Izmedju dva vremena je proteklo: 1 sati, 14 minuta i 45 sekundi.

Ponovo obratite pažnju na situaciju kada je drugo vrijeme ispred prvog.
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
struct Vrijeme proteklo(struct Vrijeme v1, struct Vrijeme v2){
    int sekunde1, sekunde2, proteklo;
    struct Vrijeme proslo;
    sekunde1=v1.sati*3600+v1.minute*60+v1.sekunde;
    sekunde2=v2.sati*3600+v2.minute*60+v2.sekunde;
    proteklo=abs(sekunde1-sekunde2);
    proslo.sati=(int)(proteklo/3600);
    proteklo=proteklo-3600*proslo.sati;
    proslo.minute=(int)(proteklo/60);
    proslo.sekunde=proteklo-60*proslo.minute;
    return proslo;
}

int main() {
    struct Vrijeme v1;
    struct Vrijeme v2;
    struct Vrijeme proslo;
    int i=1;
    v1=unos_vremena(i++);
    v2=unos_vremena(i);
    proslo=proteklo(v1,v2);
    printf("\nIzmedju dva vremena je proteklo: %d sati, %d minuta i %d sekundi.", proslo.sati, proslo.minute, proslo.sekunde);
	return 0;
}
