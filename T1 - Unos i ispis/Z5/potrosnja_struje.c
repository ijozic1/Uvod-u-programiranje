#include <stdio.h>
#include <math.h>

int main() {
    float MT,VT,Cm,Cv,pot,racun;
    int Uv,Um;

    /*Unos koordinata sa tastature*/
	printf("Unesite potrosnju VT: ");
    scanf("%f", &VT);
    printf("Unesite cijenu VT: ");
    scanf("%f", &Cv);
    printf("Unesite potrosnju MT: ");
    scanf("%f", &MT);
    printf("Unesite cijenu MT: ");
    scanf("%f", &Cm);

    pot=MT+VT;
    Um=(MT/pot)*100;
    Uv=(VT/pot)*100;
    racun=MT*Cm+VT*Cv;

    /*Ispis podataka*/
    printf("Ukupna potrosnja je %.2f kWh.",pot);
    printf("\nUdio velike tarife u ukupnoj potrosnji je %d%%.",Uv);
    printf("\nUdio male tarife u ukupnoj potrosnji je %d%%.",Um);
    printf("\nIznos racuna je %.2f KM.",racun);
	return 0;
}