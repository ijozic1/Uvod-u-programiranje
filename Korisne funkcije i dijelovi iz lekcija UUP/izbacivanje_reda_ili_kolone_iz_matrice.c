/*Ako nije potrebno da ocuvamo redosljed onda samo zamijenimo sve elemente posljednjeg reda 
ili kolone sa onima koje treba izbaciti, smanjimo odgovarajucu dimenziju i vratimo i ili j za jedan*/

/*Ako trebamo ocuvati redosljed, onda špmjeramo elemente za po jedno mjesto unaprijed i smanjimo odgovarajucu dimenziju, vratimo i ili j*/

#include <stdio.h>

int main(){
    int matrica[10][10], sirina=10, visina=10, i, j, k;
    /*Nakon sto nadjemo indeks kolone k koju treba izbaciti*/
    for(i=0; i<visina; i++){
        matrica[i][k]=matrica[i][sirina-1];
    }
    sirina--;
    return 0;
}