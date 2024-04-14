#include <stdio.h>

int main() {
    int n;
    printf("Unesite prirodan broj u intervalu [0, 9]: ");
    scanf("%d", &n);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i!=2){
                printf("*");
            }
            else {
                printf("* %d *\n",n);
                i++;
                j--;
            }
        }
        printf("\n");
    }
    return 0;
}
