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

int izracunaj(const char *izraz) {
  int vrijednost = 0;
  int dozvoljeno = 1;
  const char *p = izraz;
  const char *q = izraz;
  const char *r=izraz;
  int broj[10]={-1};
  int i=0, br_cifara=0, Broj=0;
  /*Prvo obradimo rubne slucajeve - znakovi koji se ne smiju nalaziti u stringu*/
  while (*p != '\0') {
    if ((*p >= '(' && *p <= '+') || *p == '-' || (*p >= '/' && *p <= '9')) {
      dozvoljeno = 1;
      p++;
    } else {
      dozvoljeno = 0;
      break;
    }
  }
  if (dozvoljeno == 0) {
    printf("Greska! Zabranjen znak u izrazu!");
    return 1;
  } else {
    /*Provjerimo postojanje dijeljenja sa nulom i eventulane greske u operatorima*/
    while (*q != '\0') {
      if (q != izraz && (*q == '+' || *q == '*' || *q == '-' || *q == '/') &&
          (*(q - 1) == '+' || *(q - 1) == '*' || *(q - 1) == '-' ||
           *(q - 1) == '/')) {
        dozvoljeno = 0;
        printf("Greška u izrazu!");
        return 0;
      }
      if (q != izraz && *q == '0' && *(q - 1) == '/') {
        dozvoljeno = 0;
        printf("Dijeljenje s nulom!");
        return 0;
      }
      q++;
    }
    
    /*Ako smo prosli kroz cijeli string, a izraz formom odgovara trazenom, trebamo izvrsiti naznacene operacije*/
  while(*r!='\0'){
      for(i=0; i<10; i++) broj[i]=-1;
      i=0;
      br_cifara=0;
    while(*r>='0' && *r<=9){
        broj[i]=*r;
        r++;
        i++;
    }
    br_cifara=i;
    Broj=0;
    for(i=0; i<br_cifara; i++){
        Broj+=broj[i]*pow(10,br_cifara-1-i);
        /*Ovako mogu izvuci brojeve zasebno sada ostaje da vidim sta da radim sa izrazom*/
    }
    r++;
  }
  }
  printf("%d", vrijednost);
  return vrijednost;
}
int main() {
  char izraz[100];
  unesi(izraz, 100);
  izracunaj(izraz);
  return 0;
}