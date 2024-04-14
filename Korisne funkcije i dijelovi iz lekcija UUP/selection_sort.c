#include <stdio.h>

int main(){
    int niz[10], broj_el=10,i,j,min, temp;
    
    for(i=0; i<broj_el; i++){
        min=i;
        for(j=i+1; j<broj_el; j++){
            if(niz[j]<niz[min]){
                min=j;
            }
        }
        temp=niz[i];
        niz[i]=niz[min];
        niz[min]=temp;
    }
    return 0;
}