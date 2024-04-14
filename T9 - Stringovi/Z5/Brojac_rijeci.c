/*Napišite funkciju sa prototipom:
int prva_rijec(char *s);
koja string zamjenjuje prvom riječi u stringu. Npr. ako je dat string:
"Danas je lijep dan."
funkcija ga treba pretvoriti u:
"Danas"
Funkcija vraća broj riječi u polaznom stringu (prije odsijecanja ostalih riječi).
Radi jednostavnosti zadatka, pretpostavite da je riječ bilo koji niz znakova razdvojen znakom
razmak. Za vježbu možete napraviti složenija pravila za riječi uzimajući u obzir znakove
interpunkcije.*/

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

int prva_rijec(char*s){
    int br_rijeci=0;
    char*q=s;
    char *p;
    while(*s!='\0'){
        if(s==q && *s!=' ' || *s!=' ' && *(s-1)==' ') br_rijeci++;
        s++;
    }
    while(*q!='\0'){
        if(*q!=' ') {
            p=q;
            while(*p!='\0'){
                if(*p==' '){
                    *p='\0';
                    break;
                }
                p++;
            }
        }
        q++;
    }
    return br_rijeci;
}


int main() {
	char a[80],c;
	printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
	unesi(a, 80);
	printf("Pocetni string ima %d rijeci",prva_rijec(a));
    printf("\nPrva rijec je: %s", a);
	
	return 0;
}
