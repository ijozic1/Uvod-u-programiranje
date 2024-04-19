#include <stdio.h>
#include <math.h>

typedef struct{
    double x,y,z;
}Vektor3d;

Vektor3d unos(){
    Vektor3d v;
    scanf("%lf %lf %lf", &v.x, &v.y, &v.z);
    return v;
}

Vektor3d vektorski_proizvod(Vektor3d v1, Vektor3d v2){
    Vektor3d v;
    v.x=v1.y*v2.z-v1.z*v2.y;
    v.y=v1.z*v2.x-v1.x*v2.z;
    v.z=v1.x*v2.y-v1.y*v2.x;
    return v;
}

int main() {
    Vektor3d v1, v2,v;
    printf("Unesite vektor v1: ");
    v1=unos();
    printf("Unesite vektor v2: ");
    v2=unos();
    v=vektorski_proizvod(v1,v2);
    printf("Vektorski proizvod vektora v1 i v2 je: (%g,%g,%g)", v.x, v.y, v.z);
    return 0;
}
