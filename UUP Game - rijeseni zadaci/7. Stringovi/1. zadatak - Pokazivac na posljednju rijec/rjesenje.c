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

/* Ovdje napisite funkciju posljednja_rijec */
const char* posljednja_rijec(const char*s){
    const char*s1=s;
    const char*p;
    while(*s1!='\0'){
        if(s1==s || (*(s1-1)==' ' && *s1!=' ')){
            p=s1;
        }
        s1++;
    }
    return p;
}
/* Kraj napisane funkcije */

int main() {
    char tekst[100];
    printf("Unesite neku recenicu: ");
    unesi(tekst, 100);
    printf("Posljednja rijec je: '%s'\n", posljednja_rijec(tekst));
    return 0;
}
