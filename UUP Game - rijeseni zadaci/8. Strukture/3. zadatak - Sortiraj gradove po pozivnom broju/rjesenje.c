#include <stdio.h>
#include <math.h>

struct Grad{
    char naziv[20];
    int pozivni_broj;
};

void unesi_naziv(char naziv[], int velicina){
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        naziv[i]=znak;
        i++;
        znak=getchar();
    }
    naziv[i]='\0';
}

struct Grad unesi(){
    struct Grad grad;
    printf("Unesite ime grada: ");
    unesi_naziv(grad.naziv,20);
    printf("Unesite pozivni broj: ");
    scanf("%d", &grad.pozivni_broj);
    return grad;
}

void preslozi_pozivni(struct Grad *niz, int vel, int pozivni_br){
    int i, j, k=0;
    struct Grad prebaci;
    for(i=0; i<vel; i++){
        if(niz[i].pozivni_broj==pozivni_br){
            prebaci=niz[i];
            for(j=i; j>k; j--){
                niz[j]=niz[j-1];
            }
            niz[k]=prebaci;
            k++;
        }
    }

}

int main() {
    struct Grad gradovi[100];
    int i=0, vel, pozivni;
    printf("Koliko gradova zelite unijeti: ");
    scanf("%d", &vel);
    for(i=0; i<vel; i++){
        gradovi[i]=unesi();
    }
    printf("Unesite neki pozivni broj: ");
    scanf("%d", &pozivni);
    preslozi_pozivni(gradovi,vel,pozivni);
    printf("Niz nakon preslaganja glasi:\n");
    for(i=0; i<vel; i++){
        printf("%s %03d\n", gradovi[i].naziv, gradovi[i].pozivni_broj);
    }
    return 0;
}
