/*U prethodnom programu dodajte funkciju samoglasnici koja će prebrojati 
broj samoglasnika u zadatoj riječi. Prototip funkcije samoglasnici je:
int samoglasnici(char *s);

Ova funkcija treba uzimati u obzir i velika i mala slova. 
Zatim pri kraju main() funkcije umetnite poziv funkcije samoglasnici 
tako da program na standardnom izlazu pored dužine riječi i broja 
pojavljivanja nekog znaka ispiše i broj samoglasnika u unesenoj riječi.
*/

#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
/*Funkcija prebrojava samo one znakove koji su identicni unesenom - 
ako unesemo da se broji malo slovo, nece izbrojati ta velika slova ako naidje na njih*/
int prebroji(char* s, char znak) {
	int broj = 0;
	while (*s != '\0') {
		if (*s == znak)
			broj++;
		s++;
	}
	return broj;
}
int samoglasnici(char*s){
    int brojac=0;
    while(*s!='\0'){
        if(*s=='A' || *s=='a' || *s=='E' || *s=='e' || *s=='I' || *s=='i' || *s=='O' || *s=='o' || *s=='U' || *s=='u')
            brojac++;
        s++;
    }
    return brojac;
}

int main() {
	char a[80],c;
	printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
	unesi(a, 80);
	printf ("\nKoji znak treba prebrojati: ");
	scanf ("%c", &c);
	printf ("\nBroj znakova %c je: %d\n",c,prebroji(a,c));
    if(samoglasnici(a))
        printf("\nBroj samoglasnika je: %d",samoglasnici(a));
    else printf("\nUnesena rijec nema samoglasnika.");
	return 0;
}

