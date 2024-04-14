#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int br,d;
    int a=10, b=20;
    srand(time(0));
    br=rand()%100; /*Broj od 0 do 100*/
    br=a+rand()%d; /*Izmedju a i d=b-a*/
    /*ili br=rand()a%d;*/
    return 0;
}