#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Vrijeme{
    int sat, minuta, sekunda;
};

struct Cas{
    char predmet[20];
    enum{Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja} dan_u_sedmici;
    /*Ponedjeljak - 0, Utorak - 1, ...*/
    struct Vrijeme pocetak, kraj;
};

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

void dodaj_cas(struct Cas raspored[], int broj_casova, char* predmet, int trajanje){
    int uneseno=0,i, ponedjeljak=0, utorak=0, srijeda=0, cetvrtak=0, petak=0, ukupno_trajanje;
    struct Vrijeme trajanje_casa; 
    /*Ako ima mjesta za unos ova varijabla ce postati 1*/
    /*Trebali bismo proci kroz dosadadnji niz i pogledati ukupno trajanje dosadasnji predmeta po danima, pa onda vidjeti gdje moze stati*/
    for(i=0; i<broj_casova; i++){
        trajanje_casa.sat=abs(raspored[i].kraj.sat-raspored[i].pocetak.sat);
        trajanje_casa.minuta=abs(raspored[i].kraj.minuta-raspored[i].pocetak.minuta);
        trajanje_casa.sekunda=abs(raspored[i].kraj.sekunda-raspored[i].pocetak.sekunda);
        ukupno_trajanje=trajanje_casa.sat*60+trajanje_casa.minuta;

        if(raspored[i].dan_u_sedmici==0){
            ponedjeljak=ponedjeljak+ukupno_trajanje;
        }
        else if(raspored[i].dan_u_sedmici==1){
            utorak=utorak+ukupno_trajanje;
        }
        else if(raspored[i].dan_u_sedmici==2){
            srijeda=srijeda+ukupno_trajanje;
        }
        else if(raspored[i].dan_u_sedmici==3){
            cetvrtak=cetvrtak+ukupno_trajanje;
        }
        else if(raspored[i].dan_u_sedmici==4){
            petak=petak+ukupno_trajanje;
        }
    }
    /*Sada kada znamo koliko traje koji dan u rasporedu, mozemo razmotriti gdje bismo mogli upisati novi cas*/
    if(ponedjeljak<780 && ponedjeljak+trajanje<=780){
        raspored[broj_casova-1].dan_u_sedmici=0;
        uneseno=1;
        /*Ovdje bismo mogli odmah i upisati naziv predmeta*/
    }
    else if(utorak<780 && utorak+trajanje<=780){
        raspored[broj_casova-1].dan_u_sedmici=1;
        uneseno=1;
    }
    else if(srijeda<780 && srijeda+trajanje<=780){
        raspored[broj_casova-1].dan_u_sedmici=2;
        uneseno=1;
    }
    else if(cetvrtak<780 && cetvrtak+trajanje<=780){
        raspored[broj_casova-1].dan_u_sedmici=3;
        uneseno=1;
    }
    else if(petak<780 && petak+trajanje<=780){
        raspored[broj_casova-1].dan_u_sedmici=4;
        uneseno=1;
    }
    /*Sada bi trebalo proci kroz niz i vidjeti gdje ima prostora da se u odredjeni dan smjesti taj cas*/
    if(uneseno==1) printf("Cas je dodan u raspored.\n");
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova){
    /*Ova funkcija bi trebalo da prolazi kroz niz i da prvo nadje sve predmete koji
    su spremljeni na ponedjeljak, pa medju njima prvo ispise one koji pocinju najranije, i tako za svaki dan pojedinacno*/
    printf("PONEDJELJAK:\n");
    printf("8:00 - 18:00 Predmet 1\n");
    printf("18:00 - 19:40 Predmet 3\n");
    printf("UTORAK:\n");
    printf("8:00 - 18:00 Predmet 2\n");
}

int main() {
    int n, broj_casova=0, trajanje;
    struct Cas raspored[70];
    char naziv_predmeta[20];
    /*broj casova je broj clanova niza raspored*/
    do{
        printf("Izaberite opciju: 1 = dodavanje casa, 2 = ispis rasporeda, 0 = izlaz: ");
        scanf("%d", &n);
        if(n==1){
            broj_casova++;
            printf("Unesite naziv predmeta: ");
            unesi(naziv_predmeta,20);
            printf("Unesite trajanje u minutama: ");
            scanf("%d", &trajanje);
            printf("Cas je dodan u raspored.\n");
            /*dodaj_cas(raspored, broj_casova, naziv_predmeta, trajanje);*/
        }
        else if(n==2){
            ispis_rasporeda(raspored, broj_casova);
        }
    }while(n==1 || n==2);

    return 0;
}
