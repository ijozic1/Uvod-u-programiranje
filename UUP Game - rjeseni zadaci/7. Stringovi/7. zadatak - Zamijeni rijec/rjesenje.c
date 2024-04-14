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

int duzina_rijeci(const char*p){
    int duzina=0;
    while(*p!='\0'){
        duzina++;
        p++;
    }
    return duzina;
}

char* zamijeni_rijec(char* str, const char *sta, const char *sa_cim, int cs){
    int duzina_za_mijenjanje=0, duzina_za_ubacivanje=0, razlika;
    char*poc=str, *kraj_str=str;
    char*pocetak=str, *kraj=str;
    const char*sta_mijenjamo, *sa_cime_mijenjamo;
    duzina_za_mijenjanje=duzina_rijeci(sta);
    duzina_za_ubacivanje=duzina_rijeci(sa_cim);
    if(cs==0){
        poc=str;
        if(duzina_za_mijenjanje==duzina_za_ubacivanje){
            poc=str;
            while(*poc!='\0'){
                sta_mijenjamo=sta;
                sa_cime_mijenjamo=sa_cim;
                if(*poc==*sta_mijenjamo || (*poc)-32==*sta_mijenjamo || (*poc)+32==*sta_mijenjamo){
                    pocetak=poc;
                    while(*poc!='\0' && *sta_mijenjamo!='\0' && (*poc==*sta_mijenjamo || (*poc)-32==*sta_mijenjamo || (*poc)+32==*sta_mijenjamo)){
                        poc++;
                        sta_mijenjamo++;
                    }
                    if(*sta_mijenjamo=='\0' && (pocetak==str || *(pocetak-1)==' ') && (*poc==' ' || *poc=='.' || *poc==',' || *poc=='!' || *poc=='?' || *poc=='\0')){
                        kraj=poc;
                        while(pocetak<kraj){
                            *pocetak=*sa_cime_mijenjamo;
                            pocetak++;
                            sa_cime_mijenjamo++;
                        }
                        poc=str-1;
                    }
                }
                poc++;
            }
        }
        if(duzina_za_mijenjanje>duzina_za_ubacivanje){
            poc=str;
            while(*poc!='\0'){
                sta_mijenjamo=sta;
                sa_cime_mijenjamo=sa_cim;
                if(*poc==*sta_mijenjamo || (*poc)-32==*sta_mijenjamo || (*poc)+32==*sta_mijenjamo){
                    pocetak=poc;
                    while(*poc!='\0' && *sta_mijenjamo!='\0' && (*poc==*sta_mijenjamo || (*poc)-32==*sta_mijenjamo || (*poc)+32==*sta_mijenjamo)){
                        poc++;
                        sta_mijenjamo++;
                    }
                    if(*sta_mijenjamo=='\0' && (pocetak==str || *(pocetak-1)==' ') && (*poc==' ' || *poc=='.' || *poc==',' || *poc=='!' || *poc=='?' || *poc=='\0')){
                        kraj=poc;
                        while(*sa_cime_mijenjamo!='\0'){
                            *pocetak=*sa_cime_mijenjamo;
                            pocetak++;
                            sa_cime_mijenjamo++;
                        }
                        while(*kraj!='\0'){
                            *pocetak=*kraj;
                            pocetak++;
                            kraj++;
                        }
                        poc=str-1;
                    }
                }
                poc++;
            }
        }
        if(duzina_za_mijenjanje<duzina_za_ubacivanje){
            razlika=duzina_za_ubacivanje-duzina_za_mijenjanje;
            poc=str;
            kraj_str=str;
            while(*kraj_str!='\0'){
                kraj_str++;
            }
            while(*poc!='\0'){
                sta_mijenjamo=sta;
                sa_cime_mijenjamo=sa_cim;
                if(*poc==*sta_mijenjamo || (*poc)-32==*sta_mijenjamo || (*poc)+32==*sta_mijenjamo){
                    pocetak=poc;
                    while(*poc!='\0' && *sta_mijenjamo!='\0' && (*poc==*sta_mijenjamo || (*poc)-32==*sta_mijenjamo || (*poc)+32==*sta_mijenjamo)){
                        poc++;
                        sta_mijenjamo++;
                    }
                    if(*sta_mijenjamo=='\0' && (pocetak==str || *(pocetak-1)==' ') && (*poc==' ' || *poc=='.' || *poc==',' || *poc=='!' || *poc=='?' || *poc=='\0')){
                        kraj=poc;
                        /*Novi kraj stringa*/
                        kraj_str=kraj_str+razlika;
                        poc=kraj_str;
                        /*Oslobodimo mjesta*/
                        while(poc>pocetak){
                            *poc=*(poc-razlika);
                            poc--;
                        }
                        while(*sa_cime_mijenjamo!='\0'){
                            *pocetak=*sa_cime_mijenjamo;
                            pocetak++;
                            sa_cime_mijenjamo++;
                        }
                        poc=str-1;
                    }
                }
                poc++;
            }
        }
    }
    else if(cs==1){
        poc=str;
        if(duzina_za_mijenjanje==duzina_za_ubacivanje){
            poc=str;
            while(*poc!='\0'){
                sta_mijenjamo=sta;
                sa_cime_mijenjamo=sa_cim;
                if(*poc==*sta_mijenjamo){
                    pocetak=poc;
                    while(*poc!='\0' && *sta_mijenjamo!='\0' && *poc==*sta_mijenjamo){
                        poc++;
                        sta_mijenjamo++;
                    }
                    if(*sta_mijenjamo=='\0' && (pocetak==str || *(pocetak-1)==' ') && (*poc==' ' || *poc=='.' || *poc==',' || *poc=='!' || *poc=='?' || *poc=='\0')){
                        kraj=poc;
                        while(pocetak<kraj){
                            *pocetak=*sa_cime_mijenjamo;
                            pocetak++;
                            sa_cime_mijenjamo++;
                        }
                        poc=str-1;
                    }
                }
                poc++;
            }
        }
        if(duzina_za_mijenjanje>duzina_za_ubacivanje){
            poc=str;
            while(*poc!='\0'){
                sta_mijenjamo=sta;
                sa_cime_mijenjamo=sa_cim;
                if(*poc==*sta_mijenjamo){
                    pocetak=poc;
                    while(*poc!='\0' && *sta_mijenjamo!='\0' && *poc==*sta_mijenjamo){
                        poc++;
                        sta_mijenjamo++;
                    }
                    if(*sta_mijenjamo=='\0' && (pocetak==str || *(pocetak-1)==' ') && (*poc==' ' || *poc=='.' || *poc==',' || *poc=='!' || *poc=='?' || *poc=='\0')){
                        kraj=poc;
                        while(*sa_cime_mijenjamo!='\0'){
                            *pocetak=*sa_cime_mijenjamo;
                            pocetak++;
                            sa_cime_mijenjamo++;
                        }
                        while(*kraj!='\0'){
                            *pocetak=*kraj;
                            pocetak++;
                            kraj++;
                        }
                        poc=str-1;
                    }
                }
                poc++;
            }
        }
        if(duzina_za_mijenjanje<duzina_za_ubacivanje){
            razlika=duzina_za_ubacivanje-duzina_za_mijenjanje;
            poc=str;
            kraj_str=str;
            while(*kraj_str!='\0'){
                kraj_str++;
            }
            while(*poc!='\0'){
                sta_mijenjamo=sta;
                sa_cime_mijenjamo=sa_cim;
                if(*poc==*sta_mijenjamo){
                    pocetak=poc;
                    while(*poc!='\0' && *sta_mijenjamo!='\0' && *poc==*sta_mijenjamo){
                        poc++;
                        sta_mijenjamo++;
                    }
                    if(*sta_mijenjamo=='\0' && (pocetak==str || *(pocetak-1)==' ') && (*poc==' ' || *poc=='.' || *poc==',' || *poc=='!' || *poc=='?' || *poc=='\0')){
                        kraj=poc;
                        /*Novi kraj stringa*/
                        kraj_str=kraj_str+razlika;
                        poc=kraj_str;
                        /*Oslobodimo mjesta*/
                        while(poc>pocetak){
                            *poc=*(poc-razlika);
                            poc--;
                        }
                        while(*sa_cime_mijenjamo!='\0'){
                            *pocetak=*sa_cime_mijenjamo;
                            pocetak++;
                            sa_cime_mijenjamo++;
                        }
                        poc=str-1;
                    }
                }
                poc++;
            }
        }

    }
    return str;;
}

int main() {
	char str[1000], sta[100], sa_cim[100];
    char*p;
    int cs;
    printf("Unesite string u kojem zelite nesto mijenjati: ");
    unesi(str,1000);
    printf("Unesite ono sto zelite zamijeniti: ");
    unesi(sta,100);
    printf("Unesite ono cime zelite zamijeniti: ");
    unesi(sa_cim, 100);
    printf("Da li radimo case sensitive: ");
    scanf("%d", &cs);
    p=zamijeni_rijec(str, sta, sa_cim, cs);
    printf("Nakon zamjene, string glasi:\n%s", str);
	return 0;
}