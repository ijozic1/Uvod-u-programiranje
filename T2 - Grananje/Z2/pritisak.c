/*Vas kucni ljekar*/
#include <stdio.h>
#define NSP1 90.0 /*Donja granica normalnog sistolockog (gornjeg) pritiska*/
#define NSP2 120.0 /*Gornja granica normalnog sistolockog (gornjeg) pritiska*/
#define NDP1 60.0 /*Donja granica normalnog diastolickog (donjeg) pritiska*/
#define NDP2 80.0 /*Gornja granica normalnog diastolickog (donjeg) pritiska*/
#define NP1 55.0 /*Donja granica normalnog pulsa*/
#define NP2 100.0 /*Gornja granica normalnog pulsa*/

int main() {
    float sp, dp, p;
    printf("Dobrodosli kod Vaseg kucnog ljekara!\n");
	printf("Unesite sistolicki, dijastolicki pritisak i puls: ");
    scanf("%f %f %f", &sp, &dp, &p);

    printf("SP: ");
    if(sp>=NSP1 && sp<=NSP2){
        printf("normalan\n");
    }
    else{
        printf("nije normalan\n");
    }

    printf("DP: ");
    if(dp>=NDP1 && dp<=NDP2){
        printf("normalan\n");
    }
    else{
        printf("nije normalan\n");
    }

    printf("Puls: ");
    if(p>=NP1 && p<=NP2){
        printf("normalan\n");
    }
    else{
        printf("nije normalan\n");
    }

	return 0;
}