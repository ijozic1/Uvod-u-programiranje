#include <stdio.h>

int main(){
    int x=5;
    int y=x++; /*postfiksni*/
    x=5;
    int z=++x; /*prefiksni*/
    
    printf ("%d %d", y, z);

    return 0;
}