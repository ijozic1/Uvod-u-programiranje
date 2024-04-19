#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001

int main() {
    int i,j,t,brojac=0, vel1, vel2, vel3, ponavljanje12=0, ponavljanje23=0, ponavljanje13=0, ponavljanje123=0;
    double niz1[100], niz2[100], niz3[100], pomocni_niz[200];
    /*Unos velicine prvog niza*/
    do{
        printf("Unesite broj clanova prvog niza: ");
        scanf("%d",&vel1);
        if(vel1<0 || vel1>100) printf("Pogresan unos!\n");
    }while(vel1<0 || vel1>100);
    printf("Unesite prvi niz: ");
    /*Unos elemenata prvog niza*/
    for(i=0; i<vel1; i++){
        scanf("%lf",&niz1[i]);
    }
    /*Unos velicine drugog niza*/
    do{
        printf("Unesite broj clanova drugog niza: ");
        scanf("%d",&vel2);
        if(vel2<0 || vel2>100) printf("Pogresan unos!\n");
    }while(vel2<0 || vel2>100);
    printf("Unesite drugi niz: ");
    /*Unos elemenata drugog niza*/
    for(i=0; i<vel2; i++){
        scanf("%lf",&niz2[i]);
    }
    /*Unos velicine treceg niza*/
    do{
        printf("Unesite broj clanova treceg niza: ");
        scanf("%d",&vel3);
        if(vel3<0 || vel3>100) printf("Pogresan unos!\n");
    }while(vel3<0 || vel3>100);
    printf("Unesite treci niz: ");
    /*Unos elemenata treceg niza*/
    for(i=0; i<vel3; i++){
        scanf("%lf",&niz3[i]);
    }
    /*Sada trazimo elemente koji se ponavljaju u dva od tri niza*/
    /*Prvo provjerimo za prvi i drugi niz*/
    for(i=0; i<vel1; i++){
        ponavljanje12=0;
        ponavljanje123=0;
        for(j=0; j<vel2; j++){
            if(fabs(niz1[i]-niz2[j])<EPSILON){
                ponavljanje12=1;
                for(t=0; t<vel3; t++){
                    if(fabs(niz1[i]-niz3[t])<EPSILON){
                        ponavljanje123=1;
                        break;
                    }
                }
                break;
            }
        }
        if(ponavljanje12==1 && ponavljanje123==0) pomocni_niz[brojac++]=niz1[i];
    }
    /*Sada provjerimo za drugi i treci niz*/
    for(i=0; i<vel2; i++){
        ponavljanje23=0;
        ponavljanje123=0;
        for(j=0; j<vel3; j++){
            if(fabs(niz2[i]-niz3[j])<EPSILON){
                ponavljanje23=1;
                for(t=0; t<vel1; t++){
                    if(fabs(niz2[i]-niz1[t])<EPSILON){
                        ponavljanje123=1;
                        break;
                    }
                }
                break;
            }
        }
        if(ponavljanje23==1 && ponavljanje123==0) pomocni_niz[brojac++]=niz2[i];
    }
    /*Provjerimo i prvi i treci niz*/
    for(i=0; i<vel1; i++){
        ponavljanje13=0;
        ponavljanje123=0;
        for(j=0; j<vel3; j++){
            if(fabs(niz1[i]-niz3[j])<EPSILON){
                ponavljanje13=1;
                for(t=0; t<vel2; t++){
                    if(fabs(niz1[i]-niz2[t])<EPSILON){
                        ponavljanje123=1;
                        break;
                    }
                }
                break;
            }
        }
        if(ponavljanje13==1 && ponavljanje123==0) pomocni_niz[brojac++]=niz1[i];
    }
    /*Sada jos trebamo proci kroz niz i izbaciti elemente koji se eventualno ponavljaju*/
    for(i=0; i<brojac; i++){
        for(j=i+1; j<brojac; j++){
            if(fabs(pomocni_niz[i]-pomocni_niz[j])<EPSILON){
                for(t=j; t<brojac; t++){
                    pomocni_niz[t]=pomocni_niz[t+1];
                }
                j--;
                brojac--;
            }
        }
    }

    printf("U dva od tri niza se nalazi %d clanova.", brojac);
    return 0;
}
