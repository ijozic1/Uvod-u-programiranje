#include <stdio.h>
#include <math.h>

void prikazi_salu(int matrica[20][20], int visina, int sirina){
    int i, j;
    char znak='O';
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            if(matrica[i][j]==0) printf(" %c ", znak);
            else printf(" %c ", matrica[i][j]);
        }
        printf("\n");
    }
}

void prikazi_rezervacije(int matrica[20][20], int visina, int sirina){
    int i, j;
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            if(matrica[i][j]!=0) printf(" %d ", matrica[i][j]);
            else printf("   ");
        }
        printf("\n");
    }
}

int rezervacija_sjedista(int matrica[20][20], int visina, int sirina, int red, int sjediste){
    int uspjesno=0;
    if(matrica[red][sjediste]==0){
        matrica[red][sjediste]='X';
        uspjesno=1;
    }
    return uspjesno;
}

int otkazi_rezervaciju(int matrica[20][20],int visina, int sirina, int broj_rezervacije, int sala[20][20], int visina1, int sirina1){
    int i, j, otkazano=0;
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            if(matrica[i][j]==broj_rezervacije){
                matrica[i][j]=0;
                sala[i][j]=0;
                otkazano=1;
                break;
            }
        }
    }
    return otkazano;
}

int main() {
	int visina=0, sirina=0, sjediste_red=0, sjediste_kolona=0, akcija=0, rezervacija=0, broj_rezervacije=1, uspjesno=0;
    int i, j, br_rezervacije=0, otkazano=0;
    int sala[20][20]={{0}};
    int sala_rezervacije[20][20]={{0}};
    
    printf("Velicina sale:\n");
    printf("Broj redova: ");
    scanf("%d", &visina);
    printf("Broj sjedista: ");
    scanf("%d", &sirina);
    printf("\n   Izaberite akciju:\n");
    printf("[0] Rezervacija\n[1] Otkazivanje rezervacije\n[2] Prikazi salu\n[3] Prikazi rezervacije\n[4] Izlaz\n\n");
    do{
        printf("   Akcija: ");
        scanf("%d", &akcija);
        if(akcija==4){
            printf("Dovidjenja!");
        }
        else if(akcija==0){
            printf("Red: ");
            scanf("%d",&sjediste_red);
            printf("Sjediste: ");
            scanf("%d", &sjediste_kolona);
            
            if(sjediste_red>=visina || sjediste_kolona>=sirina){
                uspjesno=0;
            }
            else uspjesno=rezervacija_sjedista(sala,visina, sirina, sjediste_red, sjediste_kolona);
            
            if(uspjesno==1){
                sala_rezervacije[sjediste_red][sjediste_kolona]=broj_rezervacije;
                broj_rezervacije++;
                prikazi_salu(sala,visina,sirina);
            }
            else{
                printf("Nepostojeci red ili sjediste\n");
            }
        }
        else if(akcija==1){
            printf("Rezervacija: ");
            scanf("%d", &br_rezervacije);
            if(br_rezervacije>=broj_rezervacije){
                printf("Rezervacija ne postoji!\n");
            }
            else{
                otkazi_rezervaciju(sala_rezervacije, visina, sirina,br_rezervacije, sala, visina, sirina);
                printf("Rezervacija otkazana!\n");
                prikazi_salu(sala,visina,sirina);
            }
            /*Pozvati funkciju otkazivanje rezervacije, ona vrijednost koja je x treba ponovno postati 0*/
        }
        else if(akcija==2){
            prikazi_salu(sala, visina, sirina);
        }
        else if(akcija==3){
            prikazi_rezervacije(sala_rezervacije, visina, sirina);
        }
        else printf("Nepoznata akcija.\n");

        if(akcija!=4){
            printf("Izaberite akciju:\n");
            printf("[0] Rezervacija\n[1] Otkazivanje rezervacije\n[2] Prikazi salu\n[3] Prikazi rezervacije\n[4] Izlaz\n\n");
        }
    }while(akcija!=4);
    
	return 0;
}