#include <stdio.h>

int main(){
    /*Prvi ispis*/
    /*int i=0, j=2;
    while(++i){
        j=j-2;
        if(i%2) continue; 
        j++;
        if(i==10) break;
    }
    printf("j=%d", i+j);*/

    /*Drugi ispis*/
    /*int i;
    i=1,2,3;
    i/=2;
    printf("i = %d\n", i);*/

    /*Treci ispis*/
    float ft=2.5;
    while(ft--){
        printf("P");
        ft=ft+.5;
        if(ft==5) break;
    }

    return 0;
}