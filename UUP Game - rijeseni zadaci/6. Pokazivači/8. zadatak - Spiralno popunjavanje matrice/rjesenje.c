#include <stdio.h>

int UOpsegu(int red, int kolona, int vel){
    if(red>=vel || red<0 || kolona>=vel || kolona<0) return 0;
    return 1;
}
void popuni(int mat1[100][100], int vel) {
  int red=vel -1, kolona=vel-1, n = 1,i=1;
  int j=0, k=0;
  for(j=0; j<vel; j++){
      for(k=0; k<vel; k++){
          mat1[j][k]=0;
      }
  }
  red = vel -1;
  kolona = vel-1;
  if(vel==1){
      mat1[0][0]=n;
      return;
  }

  while ((red+2*i) * (kolona+2*i)>=n) {
    /*Krenemo od donjeg desnog ugla*/
    /*Ako se pomijeramo ulijevo*/
    while (kolona > 0 && UOpsegu(red, kolona, vel) && mat1[red][kolona - 1] == 0) {
      mat1[red][kolona] = n++;
      kolona--;
    }
    /*Pomijeramo se gore*/
    while (red > 0&& UOpsegu(red, kolona, vel) && mat1[red - 1][kolona] == 0) {
      mat1[red][kolona] = n++;
      red--;
    }
    /*Pomjeramo se desno*/
    while (kolona < vel - 1 && UOpsegu(red, kolona, vel)&& mat1[red][kolona + 1] == 0) {
      mat1[red][kolona] = n++;
      kolona++;
    }
    /*Pomjerimo se dole*/
    while (red < vel-1 && UOpsegu(red, kolona, vel) && mat1[red + 1][kolona] == 0) {
      mat1[red][kolona] = n++;
      red++;
    }
    i++;
  }
  if(vel%2==0){
      mat1[vel/2-1][vel/2]=vel*vel;
    }
  else mat1[vel/2][vel/2]=vel*vel;

}

int main() {
  int matrica[100][100], i=0, j=0, M=1;
  do {
    printf("Unesite dimenzije matrice: ");
    scanf("%d", &M);
    if (M < 1 || M > 100)
      printf("Pogrešne dimenzije!\n");
  } while (M < 1 || M > 100);

  popuni(matrica, M);

  for (i = 0; i < M; i++) {
    for (j = 0; j < M; j++) {
      printf("%4d", matrica[i][j]);
    }
    printf("\n");
  }
  return 0;
}
