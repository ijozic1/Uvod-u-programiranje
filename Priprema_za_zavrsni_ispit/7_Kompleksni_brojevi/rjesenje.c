#include <stdio.h>
#include <math.h>
struct KompleksniA{
  double realni,imaginarni;
};

struct KompleksniE{
  double modul, argument;
};

void ispisiKompleksniA(struct KompleksniA c){
  printf("%lf + %lf * i",c.realni, c.imaginarni);
}
void ispisiKompleksniE(struct KompleksniE c){
  printf("%lf e^i * %lf", c.modul, c.argument);
}
int main(){

  FILE* ulaz = fopen("brojevi.txt","r");

  if(ulaz == NULL){
    printf("Greska");
    return 1;
  }

  struct KompleksniA kompleksni[200];
  int i = 0;
  while(i < 200 && fscanf(ulaz, "%lf %lf\n", &kompleksni[i].realni,&kompleksni[i].imaginarni) == 2){
    i++;
  }
  int velicina = i;

  fclose(ulaz);

  FILE* izlaz = fopen("brojevi.txt","w");

  double re,im,mod,arg;
  for(i = 0; i < velicina; i++){
    re = kompleksni[i].realni;
    im = kompleksni[i].imaginarni;
    mod = sqrt(re*re + im*im);
    arg = atan2(im, re);
    fprintf(izlaz,"%lf %lf %lf %lf\n",re,im, mod,arg);
  }

  fclose(izlaz);

  FILE* ispis = fopen("brojevi.txt","r");
  while(fscanf(ispis,"%lf %lf %lf %lf\n", &re, &im, &mod, &arg) == 4){
    printf("%lf %lf %lf %lf\n",re, im, mod, arg);
  }

  fclose(ispis);
  return 0;
}