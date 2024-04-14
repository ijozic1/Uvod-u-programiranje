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
    int predmet, ocjena = 0, br_indeksa, n = 0, br_studenata = 0, i, opcija=-1;
    double prosjek = 0, prolaznost, br_ocjena = 0, uspjeh;
    int student, odslusano=0;
    double prosjek_studenta = 0, polozeno=0;
    char *p, *q;
    FILE *ulaz;
    FILE *predmeti;


    ulaz = fopen("ispiti.txt", "r");
    if (ulaz == NULL) {
        printf("Pogreska pri otvaranju datoteke ispiti.txt\n\n");
        return 1;
    }

    do{
        printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
        scanf("%d", &opcija);
        if(opcija==1){
            odslusano=0;
            polozeno=0;
            prosjek=0;
            printf("Unesite broj indexa: ");
            scanf("%d", &student);
            while (fscanf(ulaz, "%d %d %d\n", &br_indeksa, &predmet, &ocjena) == 3){
                if (student == br_indeksa) {
                    odslusano++;
                    if(ocjena>5){
                        polozeno++;
                        prosjek_studenta += ocjena;
                    }
                }
            }
            if(odslusano!=0){
                prosjek_studenta=prosjek_studenta/polozeno;
                prosjek_studenta=(round(prosjek_studenta*10)/10);
                uspjeh=(polozeno/odslusano)*100;
                uspjeh=round(uspjeh);
                printf("Student je slusao %d predmeta, a polozio %.0f (%g%%).\nProsjecna ocjena polozenih predmeta je %g\n", odslusano,polozeno,uspjeh,prosjek_studenta);
            }
            else printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!\n", student);
        }
        else if(opcija==2){
            n=0;
            prosjek=0;
            br_ocjena=0;
            br_studenata=0;
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
                if (*p == '\0' && *q == '\0') n = predmet;
            }
            fclose(predmeti);

            if (n == 0) {
                printf("Nepostojeci predmet!\n");
            }
            else{
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
                    printf("Zalimo, ali ne postoje podaci o predmetu %s!\n", naziv_predmeta);
                }
                else{
                    prosjek = prosjek / br_studenata;
                    prosjek = (round(prosjek * 100)) / 100;
                    prolaznost = (br_ocjena / br_studenata) * 100;
                    prolaznost = round(prolaznost);
                    printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%\n", prosjek, prolaznost);
                }
            }
        }
    }while(opcija!=0);  
    fclose(ulaz);
    return 0;
}