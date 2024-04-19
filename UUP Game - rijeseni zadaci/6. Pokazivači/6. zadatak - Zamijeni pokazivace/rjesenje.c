#include <stdio.h>

void zamijeni_pokazivace(int **p1, int **p2){
    int *tmp;
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

int main() {
    int a, b;
    int*pok1=&a;
    int*pok2=&b;
    zamijeni_pokazivace(&pok1,&pok2);
    return 0;
}