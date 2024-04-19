#include <stdio.h>
#include <math.h>

int main() {
    int n, uspjesan_unos, i, suma=0;
    printf("Unesite n: ");
    uspjesan_unos=scanf("%d", &n);
    if(!uspjesan_unos){
        printf("Nije unesen broj!");
    }
    else if(n<1){
        printf("Broj nije prirodan!");
    }
    else{
        for(i=1; i<=n; i++){
            suma=suma+pow(i,2);
        }
        printf("\nSuma je: %d", suma);
    }
    return 0;
}
