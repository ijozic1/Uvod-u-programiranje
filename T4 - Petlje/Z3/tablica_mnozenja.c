/*Na ekranu ispišite tablicu množenja za sve brojeve od 1 do 10. Napravite zaglavlja tabele
koristeći znakove minus (-), pipe (|) i plus (+).*/
#include <stdio.h>
#include <math.h>

int main() {
    int i, j;
    for(i=(-1); i<=10; i++){
        for(j=(-1); j<=10; j++){
            if(i==-1){
                if(j==-1) printf("  X ");
                else if(j==0) printf("|");
                else printf("%3d ",j);
            }
            else if(i==0){
                if(j!=0)printf("----");
                else printf("+");
            }
            else{
                if(j==-1 && i>0) printf("%3d ",i);
                else if(j==0) printf("|");
                else if(j>=1) printf("%3d ",i*j);
            }
        }
        printf("\n");
    }
	return 0;
}
