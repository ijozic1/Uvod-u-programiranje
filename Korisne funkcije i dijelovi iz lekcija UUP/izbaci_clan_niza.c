#include <stdio.h>

int main(){
    int niz[10], broj_el=10,i,j;
    
    /*Ako smijemo naremetiti poredak*/
    for(i=0; i<broj_el; i++){
        if(/*uslov koji treba biti ispunjen*/ niz[i]%2!=0){
            niz[i]=niz[broj_el-1];
            broj_el--;
            i--;
        }
    }

    /*Ako trebamo ocuvati poredak clanova u nizu*/
    for(i=0; i<broj_el; i++){
        if(/*uslov koji treba biti ispunjen*/ niz[i]%2!=0){
            for(j=i+1; j<broj_el-1; j++){
                niz[j]=niz[j+1];
            }
            broj_el--;
            i--;
        }
    }
    return 0;
}