#include <stdio.h>

void unesi (char* niz, int vel) {
    int i=0;
    char z=getchar();
    if (z=='\n') {z=getchar();}
    while (z!='\n' && i<vel-1) {
        niz[i]=z;
        i++;
        z=getchar();
    }
    niz[i]='\0';
}

/* Ovdje napisite funkciju velika */
char* velika(char *s){
    char*p=s;/*p nam cuva pocetak stringa*/
    while(*s!='\0'){
        if(*s>='a' && *s<='z') *s-=' '; /*Space ima ASCII vrijednost 32*/
        s++;
    }
    return p;
}
/*Kraj napisane funkcije*/

int main() {
    char tekst[100];
    printf("Unesite neki tekst: ");
    unesi(tekst, 100);
    printf("Velikim slovima: %s\n", velika(tekst));
    return 0;
}
