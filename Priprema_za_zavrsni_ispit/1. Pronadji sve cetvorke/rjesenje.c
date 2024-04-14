#include <stdio.h>

int main() {
  int niz[100], i, j, zbir, brElemenata, N, element, k, z;

  printf("Unesite broj elemenata niza: ");
  scanf("%d", &brElemenata);
  printf("Unesite N: ");
  scanf("%d", &N);
  printf("Unesi elemente: ");
  for(i = 0; i < brElemenata; i++)
    scanf("%d", &niz[i]);
  /* Realizacija glavnog dijela */
  for(i = 0; i < brElemenata; i++) {
    for(j = i + 1; j < brElemenata; j++) {
      for(k = j + 1; k < brElemenata; k++) {
        for(z = k + 1; z < brElemenata; z++) {
          if(niz[i] + niz[j] + niz[k] + niz[z] == N) {
            printf("%d %d %d %d\n",niz[i], niz[j], niz[k], niz[z]);
          }
        }
      }
    }
  }
  return 0;
}