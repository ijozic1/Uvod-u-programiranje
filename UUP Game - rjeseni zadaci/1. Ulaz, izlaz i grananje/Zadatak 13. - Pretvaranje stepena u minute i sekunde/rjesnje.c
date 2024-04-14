#include <stdio.h>

int main() {
    double ugao, ugao1, minute;
    int stepen, minute1, sekunde;
    /*Unos stepeni u zadatom intervalu [-1000, 1000]*/
    printf("Unesite stepene: ");
    scanf("%lf", &ugao);

    /*Ako unos nije ispravan ispisujemo poruku*/
    if(ugao<(-1000.) || ugao>1000.){
        printf("Unos nije ispravan!");
    }
    /*Ako je ugao ispravan, moze biti negativan ili pozitivan, a ako je negativan potrebno ga je vratiti u osnosvni interval [0, 360]*/
    else{
        if(ugao<0){
            /*Uvodimo varijablu koja nam cuva vrijednost unesenog ugla s obzirom da nam treba prilikom ispisa, a moramo vrsiti izmjene nad njom*/
            ugao1=ugao;
            /*Vracanje ugla u osnovni interval*/
            while(ugao1<0){
                ugao1+=360;
            }
            /*Pretvaranje u stepene, minute i sekunde*/
            stepen=(int) ugao1;
            minute=ugao1*60-stepen*60;
            minute1=(int) minute;
            sekunde=minute*60-minute1*60;
            printf("%g = %d^ %d' %d''", ugao, stepen, minute1, sekunde);
        }
        /*Ako je uneseni ugao pozitivan, potrebno ga je svesti na osnovni interval i pretvoriti u stepene, minute i sekunde*/
        else{
            ugao1=ugao;
            while(ugao1>360){
                ugao1-=360;
            }
            stepen=(int) ugao1;
            minute=ugao1*60-stepen*60;
            minute1=(int) minute;
            sekunde=minute*60-minute1*60;
            printf("%g = %d^ %d' %d''", ugao, stepen, minute1, sekunde);
        }
    }
    return 0;
}
