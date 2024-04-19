#include <stdio.h>
#include <math.h>

void sekunde2hms(int sec, int*h, int*min, int*Sec){
    int sati, minute;
    sati=sec/3600;
    *h=sati;
    sec=sec-sati*3600;
    minute=sec/60;
    *min=minute;
    sec=sec-minute*60;
    *Sec=sec;
}

int main() {
    int s, H, M, S;
    printf("Unesite sekunde: ");
    scanf("%d",&s);
    if(s<0) return 0;
    sekunde2hms(s,&H, &M, &S);
    printf("%02d:%02d:%02d",H,M,S);
    return 0;
}
