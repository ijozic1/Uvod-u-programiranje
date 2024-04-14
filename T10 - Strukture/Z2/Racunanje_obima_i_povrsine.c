/*U prethodnom programu dodajte funkcije obim_kruznice i 
povrsina_kruznice, a u main dodajte kod koji poziva ove funkcije i 
ispisuje njihov rezultat.*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
/* Definicija tacke i kruznice */
struct Tacka {
	double x,y;
};
struct Kruznica {
	struct Tacka centar;
	double poluprecnik;
};

/* Funkcije za unos */
struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("Unesite koordinate tacke (x, y): ");
	scanf ("%lf,%lf", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf ("Unesite centar kruznice:\n");
	k.centar = unos_tacke();
	printf ("\nUnesite poluprecnik kruznice: ");
	scanf("%lf", &k.poluprecnik);
	return k;
}

/* Funkcija za udaljenost izmedju dvije tacke */
float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

/*Funkcija za racunanje obima*/
float obim_kruznice(struct Kruznica k){
    float obim;
    obim=2*k.poluprecnik*PI;
    return obim;
}

/*Funkcija za racunanje povrsine*/
float povrsina_kruznice(struct Kruznica k){
    float povrsina;
    povrsina=pow(k.poluprecnik,2)*PI;
    return povrsina;
}

/* Glavni program: Da li je tacka unutar kruznice */
int main() {
	struct Kruznica k;
	struct Tacka t;
	double d,obim, povrsina;
	printf ("Unesite kruznicu:\n");
	k = unos_kruznice();
	printf ("\nUnesite neku tacku:\n");
	t = unos_tacke();

	/* Tacka se nalazi unutar kruznice ako je udaljenost tacke od centra
	kruznice manja od poluprecnika kruznice */
	d = udaljenost(t, k.centar);
	if (d<k.poluprecnik)
		printf("\nTacka je unutar kruznice.");
	else if (d==k.poluprecnik)
		printf("\nTacka je na kruznici.");
	else
		printf("\nTacka je izvan kruznice.");

    /*Obim i povrsina*/
    obim=obim_kruznice(k);
    obim=round(obim*1000)/1000;
    povrsina=povrsina_kruznice(k);
    povrsina=round(povrsina*1000)/1000;

    printf("\nObim kruznice: %.3lf",obim);
    printf("\nPovrsina kruznice: %.3lf", povrsina);
	return 0;
}
