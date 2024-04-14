#include <stdio.h>
#include <math.h>

int main() {
    int d=0, h=0, min=0, s=0;
    printf("Unesite broj sekundi: ");
    scanf("%d", &s);

    if(s<0){
        s=s*(-1);}
    if(s>59){
        min=(s/60);
        s=s-min*60;
        if(min>59){
            h=(min/60);
            min=min-h*60;
            if(h>23){
                d=(h/24);
                h=h-d*24;
                }
            }
        }   
        printf("Pretvoreno: %dd %dh %dm %ds",d,h,min,s);    
    return 0;
}
