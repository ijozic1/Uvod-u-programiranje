#include <stdio.h>
#include <math.h>

struct Razlomak{
    int brojnik, nazivnik;
};

struct Razlomak unos(){
    struct Razlomak r;
    printf("Unesite razlomak (brojnik/nazivnik): ");
    scanf("%d/%d", &r.brojnik, &r.nazivnik);
    return r;
}

struct Razlomak skrati(struct Razlomak r){
    int nzd=1, i;
    for(i=2; i<=r.brojnik && i<=r.nazivnik; i++){
        if(r.brojnik%i==0 && r.nazivnik%i==0) nzd=i;
    }
    r.brojnik=r.brojnik/nzd;
    r.nazivnik=r.nazivnik/nzd;
    return r;
}

struct Razlomak SaberiRazlomke(struct Razlomak r1, struct Razlomak r2){
    struct Razlomak rezultat;
    rezultat.nazivnik=r1.nazivnik*r2.nazivnik;
    rezultat.brojnik=r1.brojnik*r2.nazivnik+r2.brojnik*r1.nazivnik;
    return skrati(rezultat);
}

struct Razlomak PomnoziRazlomke(struct Razlomak r1, struct Razlomak r2){
    struct Razlomak rezultat;
    rezultat.nazivnik=r1.nazivnik*r2.nazivnik;
    rezultat.brojnik=r1.brojnik*r2.brojnik;
    return skrati(rezultat);
}

int main() {
    struct Razlomak r1,r2;
    struct Razlomak proizvod, zbir;
    r1=unos();
    r2=unos();
    proizvod=PomnoziRazlomke(r1,r2);
    zbir=SaberiRazlomke(r1,r2);
    printf("Zbir unesenih razlomaka je %d/%d", zbir.brojnik, zbir.nazivnik);
    printf("Proizvod unesenih razlomaka je %d/%d", proizvod.brojnik, proizvod.nazivnik);
    return 0;
}
