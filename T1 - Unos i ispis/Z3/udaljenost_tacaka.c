#include <stdio.h>
#include <math.h>

int main() {
    float x1,x2,y1,y2,z1,z2,d;

    /*Unos koordinata sa tastature*/
	printf("Unesite koodinate prve tacke: ");
    scanf("%f, %f, %f",&x1, &y1, &z1);
    printf("Unesite koodinate druge tacke: ");
    scanf("%f, %f, %f",&x2, &y2, &z2);

    d=sqrt(pow(x1-x2,2)+ pow(y1-y2,2)+pow(z1-z2,2));

    /*Ispis udaljenosti*/
    printf("\n Udaljenost tacaka t1(%.2f,%.2f,%.2f) i t2(%.2f,%.2f,%.2f) je %.2f",x1,y1,z1,x2,y2,z2,d);
	return 0;
}
