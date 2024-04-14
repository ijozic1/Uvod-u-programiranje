/*Igra pogađanja brojeva. Računar memoriše neki slučajno izabrani broj između 1 i 100, 
a zatim korisnik pogađa taj broj. Za svaki pokušaj, računar treba ispisati VECI 
ako je memorisani broj veći od unesenog, MANJI ili JEDNAK. Kada je broj jednak, 
igra se završava. Igrač može izaći iz igre prije kraja unosom broja -1.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int broj,slucajni_broj;
    slucajni_broj=rand()%100;
    printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz).\n\n");
    do{
        printf("Unesite broj: ");
        scanf("%d",&broj);
        if(broj==-1){
            printf("Kraj igre.");
            break;
        }
        else if(broj<slucajni_broj) printf("VECI\n");
        else if(broj>slucajni_broj) printf("MANJI\n");
        else if(broj==slucajni_broj){
            printf("JEDANAK\n");
            printf("Kraj igre.");
        }
    }while(broj!=slucajni_broj);
	return 0;
}