#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415 /*Pi se moze definisati kao 4*atan(1)*/
#define EPSILON 0.0001

int main() {
    double a, b, c, x1, x2, x3, y1, y2, y3, alfa, cosalfa, beta, cosbeta, gama, cosgama, max, minute, sekunde;
    /*double ka, kb, kc;*/
    int stepen, minute1, sekunde1;
    /*Unos koordinata tacaka*/
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &x3, &y3);

    /*Racunanje duzina stranica trugla*/
    a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
    c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    
    /*Racunanje uglova preko koeficijenta pravca pravih*/
    /*alfa=acos((pow(a,2)-pow(b,2)-pow(c,2))/(2*b*c));
    beta=acos((pow(b,2)-pow(a,2)-pow(c,2))/(2*a*c));
    gama=acos((pow(c,2)-pow(a,2)-pow(b,2))/(2*a*b));*/

    /*ka=((y2-y1)/(x2-x1));
    kb=((y3-y2)/(x3-x2));
    kc=((y1-y3)/(x1-x3));

    alfa=atan(abs((int)((kb-kc)/(1-kb*kc))));
    beta=atan(abs((int)((ka-kc)/(1-ka*kc))));
    gama=atan(abs((int)((kb-ka)/(1-kb*ka))));*/

    /*Provjeravanje o kojem se trouglu radi*/
    if(a+b>c && b+c>a && a+c>b){
        /*Racunanje uglova preko kosinusne teoreme*/
        cosalfa=(-pow(a,2)+pow(b,2)+pow(c,2))/(2*b*c);
        cosbeta=(-pow(b,2)+pow(a,2)+pow(c,2))/(2*a*c);
        cosgama=(-pow(c,2)+pow(a,2)+pow(b,2))/(2*a*b);

        alfa=acos(cosalfa)*(180/PI);
        beta=acos(cosbeta)*(180/PI);
        gama=acos(cosgama)*(180/PI);

        if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON && fabs(c-a)<EPSILON) printf("Jednakostranicni\n");
        if(fabs(0-cosalfa)<EPSILON || fabs(0-cosbeta)<EPSILON || fabs(0-cosgama)<EPSILON) printf("Pravougli\n");
        if((fabs(alfa-beta)<EPSILON && fabs(alfa-gama)>EPSILON) || (fabs(beta-gama)<EPSILON && fabs(beta-alfa)>EPSILON) || (fabs(gama-alfa)<EPSILON && fabs(gama-beta)>EPSILON)) printf("Jednakokraki\n");
        if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(c-a)>EPSILON) printf("Raznostranicni\n");

        /*Trazenje najveceg ugla*/
        max=alfa;
        if(beta>max) max=beta;
        if(gama>max) max=gama;
    }
    else {
        printf("Linija\n");
        max=180;
    }

    /*Pretvaranje najveceg ugla u stepene, minute i sekunde*/
    stepen=(int) max;
    minute=max*60-stepen*60;
    minute1=(int)minute;
    sekunde=minute*60-minute1*60;
    sekunde1=(int)sekunde;

    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minute1, sekunde1);
    return 0;
}
