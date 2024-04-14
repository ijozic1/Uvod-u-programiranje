#include <stdio.h>
int main() {
  char d = 'E', e = 'D';
  while (d++ < 'Z') {
    if (d % 5 == 0) {
      printf("%c", e);
    }
  }
  return 0;
}
