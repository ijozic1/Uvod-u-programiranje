#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.001

int main() {
  int n, i, j, k, index;
  double matricaA[50][50] = {0}, multiplikator, pivoti[50], determinanta=1, vel_pivoti=0, temp;
  /*Unos dimenzija matrice*/
  do {
    printf("Unesite cijeli broj n koji je dimenzija kvadratne matrice: ");
    scanf("%d", &n);
    if (n < 2 || n > 50)
      printf("Pogresan unos, n<50!\n");
  } while (n < 2 || n > 50);
  /*Unos elemenata matrice*/
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j == 0)
        printf("Unesite elemente %d. reda: ", i + 1);
      scanf("%lf", &matricaA[i][j]);
    }
  }
  /*Vrsimo eliminaciju*/
  for (i = 0; i <n - 1; i++) {
    if (fabs(matricaA[i][i]-0.0)<EPSILON) {
      printf("Pivot element je nula!\nUnesena matrica nije invertibilna\n\n");
      return 0;
    }
    for (j = i + 1; j < n; j++) {
      multiplikator = matricaA[j][i] / matricaA[i][i];

      for (k = i; k < n ; k++) {
        matricaA[j][k] = matricaA[j][k] - multiplikator * matricaA[i][k];
      }
    }
  }
  /*Kada smo zavrsili eliminaciju, trbamo odrediti pivote i izracunati determinantu*/
  for(i=0; i<n; i++){
        if(fabs(matricaA[i][i]-0.0)>EPSILON){
          pivoti[i]=matricaA[i][i];
          vel_pivoti++;
        }
        determinanta*=matricaA[i][i];
    }
   /*Trebamo sortirati niz pivota po velicini*/
   for(i=0; i<vel_pivoti; i++){
       index=i;
       for(j=i; j<vel_pivoti; j++){
           if(pivoti[j]<pivoti[index]){
               index=j;
           }
       }
       temp=pivoti[i];
       pivoti[i]=pivoti[index];
       pivoti[index]=temp;
   }
  /*Sada jos treba ispisati matricu U, pivote i determinantu*/
  printf("Gornja trogaona matrica koju dobijemo od matrice A glasi: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%5g", matricaA[i][j]);
    }
    printf("\n");
  }
  printf("Pivot elementi su p={");
  for(i=0; i<vel_pivoti; i++){
      printf("%g",pivoti[i]);
      if(i!=vel_pivoti-1) printf(", ");
      else printf("}");
  }
  printf("\n");
  printf("Determinanta unesene matrice je D=%g", determinanta);
  return 0;
}
