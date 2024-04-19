#include <stdio.h>

int pronadji_posljednji(const char *s1, const char *s2) {
  const char *posljednji = NULL, *poc = s1;
  int pozicija;
  while (*s1 != '\0') {
    const char *p = s1;
    const char *q = s2;
    while (*p==*q && *p!='\0'){
        p++;
        q++;
    }
    if (*q == '\0')
      posljednji = s1;
    s1++;
  }
  /*printf("%s", posljednji);*/
  if (posljednji != NULL)
    pozicija = (posljednji - poc);
  else if(posljednji==poc) pozicija=0;
  else
    pozicija = -1;
  return pozicija;
}

int main() {
  /*const char *n = "Danas je divan dan!";
  printf("%d", pronadji_posljednji(n, "an"));*/
  return 0;
}
