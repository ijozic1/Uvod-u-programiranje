#include <stdio.h>

int cifra(int n) {
  if (n == 0)
    return 0;
  else {
    return 1 + cifra(n / 10);
  }
}

int main() {
  int n;
  printf("Unesite neki broj n: ");
  scanf("%d", &n);
  printf("Broj cifara je: %d", cifra(n));
}