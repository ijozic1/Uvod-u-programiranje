#include <math.h>
#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n')
    znak = getchar();
    int i = 0;
    while (i < velicina - 1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}

int main() {
    char naziv_predmeta[50];
    char Predmet[50];
    int predmet, ocjena = 0, br_indeksa, n = 0, br_studenata = 0, i;
    double prosjek = 0, prolaznost, br_ocjena = 0;
    char *p, *q;
    FILE *predmeti;
    FILE *ulaz;

    while(n==0){
    printf("Unesite predmet: ");
    unesi(naziv_predmeta, 50);

    predmeti = fopen("predmeti.txt", "r");
    if (predmeti == NULL) {
        printf("Pogreska pri otvaranju datoteke predmeti.txt\n\n");
        return 1;
    }
    while (fscanf(predmeti, "%d ", &predmet) == 1) {
        i = -1;
        do {
            if (i < 50) i++;
            Predmet[i] = fgetc(predmeti);
        }while (Predmet[i] != '\n' && Predmet[i] != EOF);
        Predmet[i] = '\0';
        /*Provjera da li se naziv podudara*/
        p = Predmet;
        q = naziv_predmeta;
        while (*q != '\0' && *p != '\0' && *p == *q) {
            p++;
            q++;
        }
        if (*p == '\0' && *q == '\0')
            n = predmet;
        }
        fclose(predmeti);

        if (n == 0) {
            printf("Nepostojeci predmet!\n");
        }
    }

    ulaz = fopen("ispiti.txt", "r");
    if (ulaz == NULL) {
        printf("Pogreska pri otvaranju datoteke ispiti.txt\n\n");
        return 1;
    }
    while (fscanf(ulaz, "%d %d %d\n", &br_indeksa, &predmet, &ocjena) == 3) {
        if (predmet == n) {
            if (ocjena > 5) {
                ++br_ocjena;
            }
            br_studenata++;
            prosjek += ocjena;
        }
    }
    
    if(br_studenata==0){
        printf("Zalimo, ali ne postoje podaci o predmetu %s!", naziv_predmeta);
        return 2;
    }
    prosjek = prosjek / br_studenata;
    /*prosjek = (round(prosjek * 100)) / 100;*/
    prolaznost = (br_ocjena / br_studenata) * 100;
    /*prolaznost = round(prolaznost);*/
    printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", prosjek, prolaznost);
    fclose(ulaz);
    return 0;
}