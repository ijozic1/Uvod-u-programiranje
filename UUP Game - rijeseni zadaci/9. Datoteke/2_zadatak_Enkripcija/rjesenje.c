#include <stdio.h>

void Enkripcija(int pomak) {
    FILE *ulaz1;
    FILE *ulaz;
    char znak;
    int broj=0;
    pomak = pomak % 26;
    ulaz = fopen("Ulaz.txt", "r");
    if (ulaz == NULL) {
        printf("Greska pri pristupanju datoteci Ulaz.txt");
    } 
    else {
        ulaz1 = fopen("EnkriptovanaPoruka.txt", "w");
        if (ulaz1 == NULL) {
            fclose(ulaz);
            printf("Greska pri pristupanju datoteci EnkriptovanaPoruka.txt");
        }

        else {
            do {
                znak = fgetc(ulaz);
                if (znak != EOF && pomak == 0) {
                    fputc(znak, ulaz1);
                } 
                else if (znak != EOF) {
                    if (znak >= 'A' && znak <= 'Z') {
                        znak = znak - 65;
                        znak = znak + pomak;
                        if (znak % 26 < 0) znak = znak % 26 + 52;
                        znak = znak % 26;
                        znak = znak + 65;
                    } 
                    else if (znak >= 'a' && znak <= 'z') {
                        znak = znak - 97;
                        znak = znak + pomak;
                        if (znak % 26 < 0) znak = znak % 26 + 52;
                        znak = znak % 26;
                        znak = znak + 97;
                    }
                    fputc(znak, ulaz1);
                }
                if (ferror(ulaz) || ferror(ulaz1)) {
                    printf("Greska!");
                    break;
                }
            } while (znak != EOF);
            fclose(ulaz1);
            fclose(ulaz);
        }
    }
}

void Dekripcija(int pomak) {
    FILE *ulaz;
    FILE *ulaz1;
    int broj;
    char znak;
    pomak = pomak % 26;
    ulaz = fopen("EnkriptovanaPoruka.txt", "r");
    if (ulaz == NULL) {
        printf("Greska pri pristupanju datoteci EnkriptovanaPoruka.txt");
    }  
    else {
        ulaz1 = fopen("DekriptovanaPoruka.txt", "w");
        if (ulaz1 == NULL) {
            printf("Greska pri pristupanju datoteci DekriptovanaPoruka.txt");
            fclose(ulaz);
        } 
        else {
            do {
                znak = fgetc(ulaz);
                if (znak != EOF && pomak == 0) fputc(znak, ulaz1);
                else if (znak != EOF) {
                    if (znak >= 'A' && znak <= 'Z') {
                        znak = znak - 65;
                        znak = znak - pomak;
                        if (znak % 26 < 0) znak = znak % 26 + 52;
                        znak = znak % 26;
                        znak = znak + 65;
                    } 
                    else if (znak >= 'a' && znak <= 'z') {
                        znak = znak - 97;
                        znak = znak - pomak;
                        if (znak % 26 < 0) znak = znak % 26 + 52;
                        znak = znak % 26;
                        znak = znak + 97;
                    }
                    fputc(znak, ulaz1);
                }
                if (ferror(ulaz) || ferror(ulaz1)) {
                    printf("Greska!");
                    break;
                }
            } while (znak != EOF);
            fclose(ulaz1);
            fclose(ulaz);
        }
    }
}

int main() {
    int korak;
    printf("Unesite korak: ");
    scanf("%d", &korak);
    Dekripcija(korak);

    return 0;
}