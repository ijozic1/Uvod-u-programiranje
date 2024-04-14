/*Napišite funkciju max_slovo koja prima string a vraća (veliko) slovo 
koje se najviše puta pojavljuje u stringu. Funkcija ne treba razlikovati 
velika i mala slova. Ukoliko se više slova ponavlja isti broj puta, 
treba vratiti najmanje takvo slovo. Znakovi koji nisu slova nas ne zanimaju.

Primjer: Ako string glasi:
	"Ovo je probni primjer."
Funkcija treba vratiti slovo O jer se ono pojavljuje tri puta u stringu a 
manje je od slova R koje se također pojavljuje tri puta.
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

/*char max_slovo(char*s){
    char*q;
    char*r,*m;
    char*p;*/
    /*p ce nam cuvati slovo*/
    /*int max_brojac=0, brojac=0;
    if(*s>='a' && *s<='z') *s-=32;
    q=s; p=s; s++;*/
    /*Prvo pretvorimo sva slova u stringu u velika slova*/
    /*while(*s!='\0'){
        if(*s>='a' && *s<='z')*s-=32;
    }
    while(*q!='\0'){
        brojac=0;
        m=q;*//*m nam cuva trenutno slovo*/
        /*r=q;*//*Pomocu r prodjemo do kraja niza*/
        /*while(*r!='\0'){
            if(*r==*m) brojac++;
        }
        if(brojac>=max_brojac){
            if(brojac==max_brojac && *m<*p){
                max_brojac=brojac;
                *p=*m;
            }
            else {
                max_brojac=brojac;
                *p=*m;
            }
        }
        q++;
    }
    return *p;
}*/
char max_slovo(char*s){
    int brojaci[26]={0},i, max=0, max_i;
    char slovo;
    char*q;
    if(*s>='a' && *s<='z') *s-=' ';/*Space ima ASCII vrijednost 32*/
    q=s;
    while(*s!='\0'){
        if(*s>='a' && *s<='z') *s-=' ';/*Space ima ASCII vrijednost 32*/
        s++;
    }
    while(*q!='\0'){
        if(*q>='A' && *q<='Z'){
            brojaci[((int)*q)-65]++;
        }
        q++;
    }
    for(i=0; i<26; i++){
        if(brojaci[i]>max){
            max=brojaci[i];
            max_i=i;
        }    
    }
    slovo=max_i+'A';/*ASCII A je 65*/
    return slovo;
}

int main() {
	char a[80],c;
	printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
	unesi(a, 80);
	printf("%c",max_slovo(a));
	
	return 0;
}
