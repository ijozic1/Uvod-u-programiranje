#include <stdio.h>
#include <math.h>

struct Osoba{
    char ime[15];
    char prezime[20];
    int telefon;
};

void unesi_ime(char *ime, int velicina){
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        ime[i]=znak;
        i++;
        znak=getchar();
    }
    ime[i]='\0';
}

void unesi_prezime(char *prezime, int velicina){
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        prezime[i]=znak;
        i++;
        znak=getchar();
    }
    prezime[i]='\0';
}

struct Osoba unos_osobe(){
    struct Osoba osoba;
    printf("Unesite ime: ");
    unesi_ime(osoba.ime, 15);
    printf("Unesite prezime: ");
    unesi_prezime(osoba.prezime, 20);
    printf("Unesite broj telefona: ");
    scanf("%d", &osoba.telefon);
    return osoba;
}

void ispis_osobe(struct Osoba osoba){
    printf("%s %s, Tel: %d\n", osoba.ime, osoba.prezime, osoba.telefon);
}

int main() {
    struct Osoba imenik[100];
    int broj, i=0,j;
    do{
        printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
        scanf("%d", &broj);
        if(broj==1){
            imenik[i]=unos_osobe();
            i++;
        }
        else if(broj==2){
            for(j=0; j<i; j++){
               printf("%d. ",j+1);
               ispis_osobe(imenik[j]);
            }
        }
        else if(broj==0) break;
    }while(broj!=0);
    return 0;
}
