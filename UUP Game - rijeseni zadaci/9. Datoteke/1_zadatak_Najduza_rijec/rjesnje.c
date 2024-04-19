#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE*ulaz;
    char znak, ime[255]="";
    char *p;
    int duzina_najduze_rijeci=0, duzina_rijeci=0, i;
    int pocetak_najduze=0, kraj_najduze=0, pocetak_trenutne=0, kraj_trenutne=0;
    printf("Unesite naziv datoteke: ");
    scanf("%s", ime);

    ulaz=fopen(ime, "r");
    if(ulaz==NULL){
        printf("Datoteka %s ne postoji", ime);
        return 1;
    }
    while(fscanf(ulaz,"%s",ime)==1){
        duzina_rijeci=strlen(ime);
        kraj_trenutne=pocetak_trenutne+duzina_rijeci;
        if(duzina_rijeci>duzina_najduze_rijeci){
            p=ime;
            while(*p!='\0'){
                if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) p++;
                else break;
            }
            if(*p=='\0'){
                duzina_najduze_rijeci=duzina_rijeci;
                pocetak_najduze=ftell(ulaz)-duzina_rijeci;
                kraj_najduze=ftell(ulaz);
            } 
        }
        pocetak_trenutne=kraj_trenutne+1;
    }
    
    fseek(ulaz,pocetak_najduze,SEEK_SET);
    while(((znak=fgetc(ulaz))>='A' && znak<='Z') || (znak>='a' && znak<='z')) printf("%c",znak);
    /*printf("%d\n", duzina_najduze_rijeci);
    printf("%d\n", pocetak_najduze);
    printf("%d\n", kraj_najduze);*/
    fclose(ulaz);
	return 0;
}