/*U prethodnom programu dodajte novu strukturu Pravougaonik, 
a zatim dodajte funkcije obim_pravougaonika i povrsina_pravougaonika, 
te funkciju tacka_u_pravougaoniku koja vraća logičku istinu (1) ako se 
tačka nalazi u pravougaoniku ili na rubu pravougaonika, 
a u suprotnom logičku neistinu (0). 
Radi jednostavnosti pretpostavićemo da su stranice pravougaonika 
poravnate sa koordinatnim osama (za vježbu možete probati uraditi ž
zadatak bez ove pretpostavke). Ovakav pravougaonik može biti opisan 
preko dvije tačke (koordinate donjeg lijevog i gornjeg desnog ugla*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

/* Definicija tacke i kruznice i pravougaonika*/
struct Tacka {
	double x,y;
};

struct Pravougaonik{
    struct Tacka dole_lijevo;
    struct Tacka gore_desno;
    struct Tacka gore_lijevo;
    struct Tacka dole_desno;
    double a,b;
};

/* Funkcije za unos */
struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("Unesite koordinate tacke (x, y): ");
	scanf ("%lf,%lf", &t.x, &t.y);
	return t;
}


/* Funkcija za udaljenost izmedju dvije tacke */
float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

/*Funkcija za unos pravougaonika*/
struct Pravougaonik unos_pravougaonika(){
    struct Pravougaonik p;
    printf("Unesite koordinate tacke donjeg lijevog tjemena:\n");
    p.dole_lijevo=unos_tacke();
    printf("Unesite koordinate gornjeg desnog tjemena:\n");
    p.gore_desno=unos_tacke();
    /*Racunanje duzina stranica*/
    p.gore_lijevo.x=p.dole_lijevo.x;
    p.gore_lijevo.y=p.gore_desno.y;
    p.dole_desno.x=p.gore_desno.x;
    p.dole_desno.y=p.dole_lijevo.y;
    p.a=udaljenost(p.gore_desno, p.gore_lijevo);
    p.b=udaljenost(p.gore_desno, p.dole_desno);
    return p;
}

/*Provjera da li je tacka u pravougaoniku*/
int tacka_u_pravougaoniku(struct Pravougaonik p, struct Tacka t){
    int nalazi=0;
    if(t.x>=p.dole_lijevo.x && t.x<=p.gore_desno.x && t.y<=p.gore_desno.y && t.y>=p.dole_lijevo.y) nalazi=1;
    return nalazi;
}

/*Funkcija za racunanje obima pravougaonika*/
double obim_pravougaonika(struct Pravougaonik p){
    double obim;
    obim=2*(p.a+p.b);
    return obim;
}

/*Funkcija za racunanje povrsine pravougaonika*/
double povrsina_pravougaonika(struct Pravougaonik p){
    double povrsina;
    povrsina=p.a*p.b;
    return povrsina;   
}

/* Glavni program: Da li je tacka unutar pravougaonika*/
int main() {
	struct Tacka t1;
    struct Pravougaonik p;
	double obim_p, povrsina_p;

    printf("Unesite pravougaonik:\n");
    p=unos_pravougaonika();
	printf ("\nUnesite neku tacku:\n");
	t1 = unos_tacke();

    /*Tacka se nalazi unutar pravougaonika ako se nalazi unutar njegove 
    unutrasnje oblasti, tj ako su joj koordinate unutar odgovarajucig granica*/
    if(tacka_u_pravougaoniku(p,t1)) printf("\nTacka se nalazi unutar oblasti unesenog pravougaonika.");
    else printf("\nTacka se ne nalazi u oblati pravougaonika");
    
    /*Obim i povrsina pravougaonika*/
    obim_p=obim_pravougaonika(p);
    obim_p=round(obim_p*1000)/1000;
    povrsina_p=povrsina_pravougaonika(p);
    povrsina_p=round(povrsina_p*1000)/1000;

    printf("\nObim pravougaonika: %.3lf",obim_p);
    printf("\nPovrsina pravougaonika: %.3lf", povrsina_p);

	return 0;
}

