#include <stdio.h>

struct Datum{
    int dan, mjesec, godina;
};

struct Datum unesi_datum() {	
    struct Datum d;	
    printf("Unesite datum: ");
    scanf("%d%d%d", &d.dan, &d.mjesec, &d.godina);
    return d;
    }
    
void ispisi_datum(struct Datum d) {	
    printf("%d. %d. %d", d.dan, d.mjesec, d.godina);
}

int main(){
    struct Datum d;
    d=unesi_datum();
    return 0;
}