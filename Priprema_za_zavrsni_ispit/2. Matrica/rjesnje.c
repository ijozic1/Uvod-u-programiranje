#include <stdio.h>

int main()
{
  int n,matrica[100][100],i,j,x,y;
  printf("Molim Vas unesite dimenziju matrice: ");
  scanf("%d",&n);

  if(n<3 || n>100)
    {
      printf("Greska!");
      return 0;
    }

printf("\nUnesite x i y: ");
scanf("%d %d",&x,&y);

for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
  {
    if(i<j && i+j<n-1)
      matrica[i][j]=y;
    else if(i>j && i+j>n-1)
      matrica[i][j]=y;
    else 
      matrica[i][j]=x;
  }
}


for(int i=0;i<n;i++)
{
  for(int j=0;j<n;j++)
  {
    printf("%d",matrica[i][j]);
  }
  printf("\n");
}
}