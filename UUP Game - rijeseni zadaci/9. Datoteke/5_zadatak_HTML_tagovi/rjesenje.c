#include <stdio.h>

int main() {
  char znak;
  FILE *ulaz;
  FILE *izlaz;
  ulaz = fopen("index.html", "r");
  if (ulaz == NULL) {
    printf("Datoteka index.html ne postoji");
    return 1;
  }
  izlaz = fopen("index.txt", "w");
  if (izlaz == NULL) {
    printf("Izlazna datoteka ne postoji!");
    fclose(ulaz);
    return 1;
  }

  do {
    znak = fgetc(ulaz);
    if (znak != EOF) {
      if (znak == '<' || znak == '&') {
        do {
          znak = fgetc(ulaz);
        } while (znak != EOF && znak != '>' && znak != ';');
        if (znak != '<' && znak != '>' && znak != '&' && znak != ';') {
          fputc(znak, izlaz);
          /*printf("%c", znak);*/
        }
      } else{
        fputc(znak, izlaz);
        /*printf("%c", znak);*/
      }
    }
  } while (znak != EOF);
  
  fclose(izlaz);
  return 0;
}