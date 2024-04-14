#include <math.h>
#include <stdio.h>

int daj_prost() {
  int static prost = 2;
  int prost_br = prost;
  int i;
  for (i = 2; i < prost_br; i++) {
    if (prost_br % i == 0) {
      prost_br = 0;
      break;
    }
  }
  /*Zelimo da nam se iz funkije svaki put vrati prost broj a ne nula*/
  while(prost_br==0){
    prost++;
    prost_br=prost;
    for (i = 2; i < prost_br; i++) {
        if (prost_br % i == 0) {
            prost_br = 0;
            break;
        }
    }
  }
  prost++;
  /*printf("%d\n", prost_br);*/
  return prost_br;
}

int main() {
  int A, B, i, suma_do_B = 0, t = 0, m;
  do {
    printf("Unesite brojeve A i B: ");
    scanf("%d %d", &A, &B);
    if (A < 1)
      printf("A nije prirodan broj.\n");
    else if (A >= B)
      printf("A nije manje od B.\n");
  } while (A < 1 || B < 1 || A >= B);

  while (t < A) {
    t = daj_prost();
  }
  m = t;
  while (m < B) {
    if (m>A && m == t)
      suma_do_B += m;
    m = daj_prost();
    if (m < B && m != t)
      suma_do_B += m;
  }
   
  printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma_do_B);
  return 0;
}
