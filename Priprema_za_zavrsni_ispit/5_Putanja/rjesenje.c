#include <stdio.h>
#include <math.h>

struct Pozicija{
  double x, y;
  int t;
};

void IspisiKarakteristike(double s, double vo, double v, double a, int t){
  printf("Karakteristike kretanju su: \n");
  printf("s=%.2lf ,v0=%.2lf, v=%.2lf, a=%.2lf, t=%d", s, vo, v, a, t);
}
int main(){
  FILE *ulaz;
  struct Pozicija tren, poc;
  double s=0, st=0, vo=0, vt=0, a=0;
  int dt=0, i=0, tu=0;

  if((ulaz=fopen("putanja.txt", "r"))==NULL){
    printf("Greska pri otvaranju datoteke!");
    return 1;
  }
  while((fscanf(ulaz, "%5lf%5lf%5d\n", &tren.x, &tren.y, &tren.t))==3){
    if(i==0){
      i++;
      poc=tren;
    }
    else{
      dt=tren.t-poc.t;
      st=sqrt((tren.x-poc.x)*(tren.x-poc.x)+(tren.y-poc.y)*(tren.y-poc.y));
      a=2*(st-vo*dt)/(dt*dt);
      vt=vo+a*dt;
      s+=st;
      tu+=dt;
      printf("(%.2lf, %.2lf) - (%.2lf, %.2lf)\n", poc.x, poc.y, tren.x, tren.y);
      IspisiKarakteristike(st, vo, vt, a, dt);
      printf("\n");
      poc=tren;
      vo=vt;
    }
  }
	fclose(ulaz);
  printf("Ukupno je preÄ‘en put %.2lf m za vrijeme %d s, Ĺˇto daje srednju brzinu %.2lf m/s.", s, tu, s/tu);
  return 0;
}