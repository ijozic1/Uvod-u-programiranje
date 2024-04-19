#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001

struct Tacka {
    int x,y;
};
struct Trougao {
    struct Tacka A,B,C;
};

struct Trougao unesi(){
    struct Trougao t;
    printf("Unesite koordinate tjemena A: ");
    scanf("%d %d", &t.A.x, &t.A.y);
    printf("Unesite koordinate tjemena B: ");
    scanf("%d %d", &t.B.x, &t.B.y);
    printf("Unesite koordinate tjemena C: ");
    scanf("%d %d", &t.C.x, &t.C.y);
    return t;
}

int Pravougli(struct Trougao t){
    double a,b,c,a_kv, b_kv, c_kv;
    int pravougli=0;
    a=sqrt(pow((t.B.x-t.C.x),2)+pow((t.B.y-t.C.y),2));
    b=sqrt(pow((t.A.x-t.C.x),2)+pow((t.A.y-t.C.y),2));
    c=sqrt(pow((t.B.x-t.A.x),2)+pow((t.B.y-t.A.y),2));
    a_kv=pow(a,2);
    b_kv=pow(b,2);
    c_kv=pow(c,2);
    if(fabs(a_kv-(b_kv+c_kv))<EPSILON || fabs(b_kv-(a_kv+c_kv))<EPSILON || fabs(c_kv-(b_kv+a_kv))<EPSILON) pravougli=1;
    return pravougli;
}

int izbaci_pravougle(struct Trougao *niz, int vel){
    int i,j;
    int pravougli=0;
    for(i=0; i<vel; i++){
        pravougli=Pravougli(niz[i]);
        if(pravougli==1){
            for(j=i; j<vel-1; j++){
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
}

int main() {
    struct Trougao trouglovi[20];
    int vel, i;
    printf("Uneiste broj trouglova koje cete unijeti: ");
    scanf("%d", &vel);
    for(i=0; i<vel; i++){
        trouglovi[i]=unesi();
    }
    vel=izbaci_pravougle(trouglovi, vel);
    printf("Trouglovi koji nisu pravougli su: ");
    for(i=0; i<vel; i++){
        printf("Trougao %d: (%d,%d)-(%d,%d)-(%d,%d)\n",i+1, trouglovi[i].A.x, trouglovi[i].A.y, trouglovi[i].B.x, trouglovi[i].B.y, trouglovi[i].C.x, trouglovi[i].C.y);
    }
    return 0;
}
