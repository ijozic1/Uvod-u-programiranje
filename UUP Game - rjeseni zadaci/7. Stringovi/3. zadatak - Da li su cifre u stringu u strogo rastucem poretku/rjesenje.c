#include <stdio.h>

void unesi(char niz[], int velicina){
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

int srce(const char*s){
    int srce=-1, broj=-1;
    while(*s!='\0'){
        if(*s>=48 && *s<=57){
            if(*s>broj){
                broj=*s;
                srce=1;
            }
            else{
                srce=0;
                break;
            }
        }
        s++;
    }
    return srce;
}
int main() {
    char string[20];
    printf("Unesite jedan string (ENTER za kraj): ");
    unesi(string,20);
    if(srce(string)==1) printf("Brojevi u stringu su u strogo rastucem poretku.");
    else if(srce(string)==0) printf("Brojevi u stringu nisu u strogo rastucem poretku");
    else printf("String ne sadrži brojeve.");
    return 0;
}
