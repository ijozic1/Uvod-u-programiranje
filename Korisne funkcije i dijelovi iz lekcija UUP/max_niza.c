#include <stdio.h>

int main(){
    int niz[10], max, max_i, broj_el=10,i;
    
    max=niz[0];
    max_i=0;
    for(i=0; i<broj_el; i++){
        if(niz[i]>max){
            max=niz[i];
            max_i=i;
        }
    }
    return 0;
}