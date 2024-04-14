/*Pokazivac na funkciju 
int kvadrat(int x) {
    return x*x;
}
...
int (*p)(int) = kvadrat;
k = (*p)(5); - argument koji proslijedjuemo funkciji
*/

#include <stdio.h>

long long faktorijal(int x){
    if(x==1) return 1;
    else return x * faktorijal(x-1);
}

int main(){
    faktorijal(3);
    return 0;
}