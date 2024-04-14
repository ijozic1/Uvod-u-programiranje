#include <stdio.h>

int main() {
  int matrica[12][22]={0}, n, i, j, x = 0;
  do {
    printf("Crtat cemo funkciju y + x = n. Unesite n: ");
    scanf("%d", &n);
    if (n < 1 || n > 20)
      printf("Uneseni broj je izvan zadanog intervala!\n");
  } while (n < 1 || n > 20);

  /*Da bi smo mogli koristiti ostatak koda, moramo prvo popuniti posaljednji red odgovarajucim brojakama*/
  for(j=1;j<22; j++){
      matrica[11][j]=x++;
  }
  /*Sada mozemo krenuti sa popunjavanjem ostalog*/
  x=0;
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 22; j++) {
      /*Okvir koordinatnog sistema*/
      if (j == 0 && i < 11)
        matrica[i][j] = 10 - i;
      else if (j == 1 && i < 11)
        matrica[i][j] = '+';
      else if (i == 10 && j > 0)
        matrica[i][j] = '+';
      else if (i == 11 && j > 0)
        matrica[i][j] = x++;
      /*Popunjavanje koordinatnog*/
      else if (matrica[11][j] + matrica[i][0] == n)
        matrica[i][j] = '*';
      else
        matrica[i][j] = ' ';
    }
  }
  /*Ispis matrice*/
    for(i=0; i<12; i++){
        for(j=0; j<22; j++){
            if(matrica[i][j]=='*'){
                printf("%c", matrica[i][j]);
                break;
            }
            else if(j==0 && i<11) printf("%-2d", matrica[i][j]);
            else if(j==1 && i<10 && i>10-n) printf("%-3c", matrica[i][j]);
            else if(j==1 && i<10) printf("%c", matrica[i][j]);
            else if(i==10 && j==1) printf("%c", matrica[i][j]);
            else if(i==10 && j>1) printf("%3c", matrica[i][j]);
            else if(i==11 && j>0 && j!=10) printf("%-3d", matrica[i][j]);
            else if(i==11 && j==10) printf("%-2d", matrica[i][j]);
            else if(i==11 && j==0) printf("%2c", matrica[i][j]);
            else if(i<11-n && j>1) break;
            else printf("%-3c", matrica[i][j]);
        }
        printf("\n");
    }
  return 0;
}