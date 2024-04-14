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

/*int duzina(const char*s2){
    int duzina=0;
    while(*s2!='\0'){
        duzina++;
        s2++;
    }
    return duzina+1;
}*/

int obrnut_podstring(const char *s1, const char*s2){
    int podstring=0,i;
    const char*q=s2;
    const char*t=s1;
    /*s1+=duzina(s2);*//*Da ne bismo izasli izvan opsega ako se odmah prvo slovo podudari*/
    while(*s1!='\0'){
        i=0;
        q=s2;/*Moramo sacuvati pocetak drugog stringa u slcaju da ne naidjemo iz prve na podstring*/
        if(/*s1!=t && */*s1==*q){
            while(*q!='\0'){
                    if(*(s1-i)==*q){
                        podstring=1;
                        i++;
                    }
                    else{
                        podstring=0;
                        break;
                    }
                q++;
            }
            if(podstring==1) break;
        }
        s1++;
    }
    return podstring;
}
int main() {
    char string1[30], string2[30], podstring;
    printf("\nUnesite prvi string (ENTER za kraj): ");
    unesi(string1,30);
    printf("\nUnesite drugi string (ENTER za kraj): ");
    unesi(string2, 30);
    podstring=obrnut_podstring(string1, string2);
    if(podstring==1) printf("\nDA");
    else printf("\nNE");
    return 0;
}
