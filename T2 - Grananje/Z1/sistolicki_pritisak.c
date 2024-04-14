#include <stdio.h>
#define NSP1 90.0 /*Donja granica normalnog sistolockog (gornjeg) pritiska*/
#define NSP2 120.0 /*Gornja granica normalnog sistolockog (gornjeg) pritiska*/

int main() {
    float sp;
	printf("Unesite vrijednost sistolickog pritiska: ");
    scanf("%f", &sp);

    if(sp>=NSP1 && sp<=NSP2){
        printf("Sistolicki pritisak je normalan!\n");
    }
    else{
        printf("Sistolicki pritisak nije normalan!\n");
    }
	return 0;
}
