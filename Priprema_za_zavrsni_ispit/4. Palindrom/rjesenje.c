#include <stdio.h>
#include <string.h>
#include <ctype.h>

// radar, abba
// ana voli milovana, aba ba
void palindrom(char *s) {

    int duzina = strlen(s);
    int i, pocetakPalindrom,krajPalindrom, maxDuzina=0, start=0, brojac=0, finalSpace=0;

    for(i=0; i<duzina; i++) {

        // 1. slucaj
        pocetakPalindrom=i;
        krajPalindrom=i;
        brojac=0;
        while(pocetakPalindrom>=0 &&  krajPalindrom<duzina && 
          (tolower(s[pocetakPalindrom])==tolower(s[krajPalindrom]) 
            || s[pocetakPalindrom]==' ' || s[krajPalindrom]==' ')) {

          if(krajPalindrom-pocetakPalindrom+1-brojac>maxDuzina) {
            maxDuzina=krajPalindrom-pocetakPalindrom+1-brojac;
            start=pocetakPalindrom;
            finalSpace=brojac;
          }

          if((s[pocetakPalindrom]==' ' && s[krajPalindrom]==' ') ||  (s[pocetakPalindrom]!=' ' && s[krajPalindrom]!=' ')) {
            pocetakPalindrom--;
            krajPalindrom++;
          }
          else if(s[pocetakPalindrom]==' ') { 
            pocetakPalindrom--;
            brojac++;
          }
          else if(s[krajPalindrom]==' ') {
            krajPalindrom++;
            brojac++;
          }
        }

        // 2. slucaj
        pocetakPalindrom=i;
        krajPalindrom=i+1;
        brojac=0;
        while(pocetakPalindrom>=0 &&  krajPalindrom<duzina && 
          (tolower(s[pocetakPalindrom])==tolower(s[krajPalindrom]) 
            || s[pocetakPalindrom]==' ' || s[krajPalindrom]==' ')) {

          if(krajPalindrom-pocetakPalindrom+1-brojac>maxDuzina) {
            maxDuzina=krajPalindrom-pocetakPalindrom+1-brojac;
            start=pocetakPalindrom;
            finalSpace=brojac;
          }

          if((s[pocetakPalindrom]==' ' && s[krajPalindrom]==' ') ||  (s[pocetakPalindrom]!=' ' && s[krajPalindrom]!=' ')) {
            pocetakPalindrom--;
            krajPalindrom++;
          }
          else if(s[pocetakPalindrom]==' ') { 
            pocetakPalindrom--;
            brojac++;
          }
          else if(s[krajPalindrom]==' ') {
            krajPalindrom++;
            brojac++;
          }
        }


    }
    for(i=start; i<start+maxDuzina+finalSpace; i++)
      printf("%c", s[i]);
}


int main() {

  palindrom("yxypxst");
  return 0;
}