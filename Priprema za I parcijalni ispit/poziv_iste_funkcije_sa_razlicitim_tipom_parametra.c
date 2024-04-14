#include <stdio.h>
#include <math.h>

double suma(double x){
    return sqrt(x);
}

int suma(int n){
    return pow(n,2);
}

int main(){
    int a=25;
    double b=2.5;
    a=suma(a);
    b=suma(b);
    printf("a=%d\nb=%g",a,b);
    return 0;
}