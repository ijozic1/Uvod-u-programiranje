#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, rezultat;
    /*Treba unijeti tri cijela broja razdvojena razmakom*/
    scanf("%d %d %d", &a, &b, &c);

    rezultat=(a+b)*c;
    printf("Rezultat operacije je (%d+%d)*%d=%d.", a, b, c, rezultat);
    return 0;
}