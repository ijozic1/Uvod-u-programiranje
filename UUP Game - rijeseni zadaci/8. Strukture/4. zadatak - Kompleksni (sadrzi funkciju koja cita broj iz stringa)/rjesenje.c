#include <math.h>
#include <stdio.h>

struct Kompleksni {
  int re, im;
};

int unesi(char niz[], int velicina) {
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
  return i+1;
}

struct Kompleksni Nadji_broj(char *niz, int vel) {
  int niz_br[10], j = 0, t, p=1, n1=1, n2=1;
  struct Kompleksni k;
  k.re = 0; k.im = 0;
  /*Petlja koja trazi realni dio*/
  while (*niz != '\0') {
      /*printf("%c\n", *niz);*/
      if(*niz=='-' && p==1) n1=-1;
      else if(*niz=='-' && p==0) n2=-1;
    j = 0;
    for(t=0; t<10; t++) niz_br[t]=0;
    while (p==1 && *niz>='0' && *niz <= '9') {
      niz_br[j++] = *niz - '0';
      niz++;
      if(*niz==',') p=0;
      /*printf("%c\n", *niz);*/
    }
    for (t =0; t<=j-1; t++) {
      niz_br[t] = niz_br[t] * pow(10, j-t);
      niz_br[t]/=10;
      k.re += niz_br[t];
    }

    j = 0;
    for(t=0; t<10; t++) niz_br[t]=0;
    while (p==0 && *niz >= '0' && *niz <= '9') {
      niz_br[j++] = *niz - '0';
      niz++;
    }
    for (t = 0; t<= j; t++) {
      niz_br[t] = niz_br[t] * pow(10, j-t);
      niz_br[t]/=10;
      k.im += niz_br[t];
    }
    niz++;
  }
  k.re*=n1;
  k.im*=n2;
  /*printf("Re %d\n",k.re);
  printf("Im %d\n", k.im);*/
  return k;
}

struct Kompleksni unesi_jedan() {
  struct Kompleksni k;
  char niz_k[20];
  int vel;
  k.re = 0; k.im = 0;
  printf("Unesite kompleksni broj: ");
  vel = unesi(niz_k, 20);
  k = Nadji_broj(niz_k, vel);
  return k;
}
struct Kompleksni unesi_dva() {
  struct Kompleksni k;
  char niz_k[20];
  int vel;
  int static i = 0;
  k.re = 0; k.im = 0;
  if (i == 0)
    printf("Unesite prvi kompleksni broj: ");
  else
    printf("Unesite drugi kompleksni broj: ");
  vel = unesi(niz_k, 20);
  k = Nadji_broj(niz_k, vel);
  i++;
  return k;
}

struct Kompleksni Stepenuj(struct Kompleksni k, int stepen) {
  struct Kompleksni rezultat;
  int i = 0, temp_re = 0, temp_im = 0;
  rezultat.re = 1; rezultat.im = 0;
  for (i = 0; i < stepen; i++) {
    /*Stepenovati cemo po binomnom obrsacu - Moavrova formula ne prolazi zato
     * sto ima puna castanja iz double u int*/
    temp_re = rezultat.re * k.re - rezultat.im * k.im;
    temp_im = rezultat.re * k.im + rezultat.im * k.re;
    rezultat.re = temp_re;
    rezultat.im = temp_im;
  }
  return rezultat;
}

struct Kompleksni Saberi(struct Kompleksni k1, struct Kompleksni k2) {
  struct Kompleksni k;
  k.re = 0; k.im = 0;
  k.re = k1.re + k2.re;
  k.im = k1.im + k2.im;
  return k;
}

struct Kompleksni Oduzmi(struct Kompleksni k1, struct Kompleksni k2) {
  struct Kompleksni k;
  k.re = 0; k.im = 0;
  k.re = k1.re - k2.re;
  k.im = k1.im - k2.im;
  return k;
}

int main() {
  char operator;
  struct Kompleksni k1, k2, k;
  int stepen = 0;
  k.re=0; k.im=0;
  k1.re = 0; k1.im = 0;
  k2.re = 0; k2.im = 0;
  printf("Unesite operator: ");
  operator= getchar();
  if (operator== '^') {
    k.re = 0; k.im = 0;
    k1.re = 0; k1.im = 0;
    k2.re = 0; k2.im = 0;
    k1 = unesi_jedan();
    printf("Unesite stepen: ");
    scanf("%d", &stepen);
    k = Stepenuj(k1, stepen);
  } 
  else if (operator== '+') {
    k.re = 0; k.im = 0;
    k1.re = 0; k1.im = 0;
    k2.re = 0; k2.im = 0;
    k1 = unesi_dva();
    k2 = unesi_dva();
    k = Saberi(k1, k2);
  } 
  else if (operator== '-') {
    k.re = 0; k.im = 0;
    k1.re = 0; k1.im = 0;
    k2.re = 0; k2.im = 0;
    k1 = unesi_dva();
    k2 = unesi_dva();
    k = Oduzmi(k1, k2);
  } 
  else {
    printf("Pogresan operator.");
    return 1;
  }
  if(k.re==0 && k.im==-1) printf("Rezultat: -i");
  else if (k.re == 0) printf("Rezultat: %di", k.im);
  else if (k.im == 0) printf("Rezultat: %d", k.re);
  else if (k.im == 1) printf("Rezultat: %d+i", k.re);
  else if (k.im == -1) printf("Rezultat: %d-i", k.re);
  else printf("Rezultat: %d%+di", k.re, k.im);
  return 0;
}
