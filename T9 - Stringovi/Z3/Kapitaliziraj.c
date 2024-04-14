/*Napišite funkciju sa prototipom:
char* kapitaliziraj(char *s);

koja u primljenom stringu svako početno slovo riječi koje je malo 
slova pretvara u veliko.  Pretpostavljamo da su riječi međusobno 
omeđene razmacima, početkom ili krajem stringa. 
Funkcija treba da vraća pokazivač na početak istog stringa koji je 
proslijeđen funkciji kao parametar.
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

char* kapitaliziraj(char*s){
    char *poc=s;
    while(*s!='\0'){
        if((s==poc || *(s-1)==' ') && *s>=97 && *s<=122) *s=*s-32;
        s++;
    }
    return poc;
}

int main() {
	char a[80],c;
	printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
	unesi(a, 80);
    kapitaliziraj(a);
	printf ("\n\n%s",a);
	
	return 0;
}

