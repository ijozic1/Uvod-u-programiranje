#include <stdio.h>

int main(){
    int niz[10], broj_el=10,i,j, ubaceni;
    
    for(i=0; i<broj_el; i++){
        if(/*uslov koji treba biti ispunjen*/ niz[i]%2!=0){
            for(j=broj_el-1; j>i+1; j--){
                niz[j]=niz[j-1];
            }
            niz[i+1]=ubaceni;
            broj_el++;
        }
    }
    return 0;
}