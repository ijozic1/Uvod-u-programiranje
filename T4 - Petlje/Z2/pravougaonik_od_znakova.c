/*Napravite program koji na ekranu iscrtava pravougaonik pri čemu su date stranice a i b
pravougaonika. Za iscrtavanje koristite znakove:
● minus (-) za vodoravne linije,
● pipe (|) za uspravne i
● plus (+) za ćoškove.
*/

#include <stdio.h>

int main() {
	int i,j, a,b;
    printf("Unesite stranice pravougaonika a,b: ");
    scanf("%d,%d", &a, &b);

    for(i=1; i<=b; i++){
        for(j=1; j<=a; j++){
            if((i==1 || i==b) && (j==1 || j==a)) printf("+");
            else if((i==1 || i==b) && (j>1 && j<a)) printf("-");
            else if((i>1 && i<b) && (j==1 || j==a)) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
	return 0;
}
