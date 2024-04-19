#include <ctype.h>
#include <stdio.h>
#include <string.h>

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

int broj_znakova(const char*str){
    int broj_znakova=0;
    while(*str!='\0'){
        if(isalnum(*str)) broj_znakova++;
        str++;
    }
    return broj_znakova;
}

int je_li_palindrom(const char *str) {
  int palindrom = 1;
  int br_znakova=0;
  const char *pocetak = str, *kraj = str;
  br_znakova=broj_znakova(str);
  while (*kraj != '\0')
    kraj++;
  kraj = kraj - 1;
  while (kraj > pocetak) {
    while (kraj >pocetak && !isalnum(*kraj)) kraj--;
    while (pocetak < kraj && !isalnum(*pocetak)) pocetak++;
    if(br_znakova%2==0 && br_znakova!=0){
        if ((isalnum(*kraj)|| *kraj==' ') && tolower(*kraj) == tolower(*pocetak)) palindrom = 1;
        else { 
            palindrom = 0;
            break;
        }
    }
    else{
        if (isalnum(*kraj) && tolower(*kraj) == tolower(*pocetak)) palindrom = 1;
        else { 
            palindrom = 0;
            break;
        }
    }
    pocetak++;
    kraj--;
  }
  return palindrom;
}

int main() {
  char str[100];
  int palindrom = 0;
  printf("Unesite neki string: ");
  unesi(str, 100);
  palindrom = je_li_palindrom(str);
  if (palindrom == 1)
    printf("Uneseni string je palindrom!");
  else
    printf("Uneseni string nije palindrom");
  return 0;
}