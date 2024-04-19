#include <ctype.h>
#include <stdio.h>

int generisi_tablice(const char *prethodna, char *nova) {
  int i;
  /*FORMAT: X00-X-000*/
  /*Provjera formata*/
  if (prethodna[0] != 'A' && prethodna[0] != 'E' && prethodna[0] != 'J' &&
      prethodna[0] != 'K' && prethodna[0] != 'M' && prethodna[0] != 'O' &&
      prethodna[0] != 'T')
    return -1;
  if (!isdigit(*(prethodna + 1)))
    return -1;
  if (!isdigit(*(prethodna + 2)))
    return -1;
  if (*(prethodna + 3) != '-')
    return -1;
  if (prethodna[4] != 'A' && prethodna[4] != 'E' && prethodna[4] != 'J' &&
      prethodna[4] != 'K' && prethodna[4] != 'M' && prethodna[4] != 'O' &&
      prethodna[4] != 'T')
    return -1;
  if (*(prethodna + 5) != '-')
    return -1;
  if (!isdigit(*(prethodna + 6)))
    return -1;
  if (!isdigit(*(prethodna + 7)))
    return -1;
  if (!isdigit(*(prethodna + 8)))
    return -1;
  if (prethodna[9] != '\0')
    return -1;
  /*Ako je format odgovarajuci, treba kreirati novu*/
  if (*(prethodna + 8) < '9') {
    for (i = 0; i < 8; i++) {
      nova[i] = prethodna[i];
    }
    nova[8] = /*(char)*/ (*(prethodna + 8) + 1);
    nova[9] = '\0';
    return 1;
  } else if (*(prethodna + 8) == '9' && *(prethodna + 7) < '9') {
    for (i = 0; i < 7; i++) {
      nova[i] = prethodna[i];
    }
    nova[7] = /*(char)*/ (*(prethodna + 7) + 1);
    nova[8] = '0';
    nova[9] = '\0';
    return 1;
  } else if (*(prethodna + 8) == '9' && *(prethodna + 7) == '9' &&
             *(prethodna + 6) < '9') {
    for (i = 0; i < 6; i++) {
      nova[i] = prethodna[i];
    }
    nova[6] = (*(prethodna + 6) + 1);
    nova[7] = '0';
    nova[8] = '0';
    nova[9] = '\0';
    return 1;
  } else if (*(prethodna + 8) == '9' && *(prethodna + 7) == '9' &&
             *(prethodna + 6) == '9' /*&& *(prethodna+4)<='T'*/) {
    nova[5] = '-';
    nova[6] = '0';
    nova[7] = '0';
    nova[8] = '0';
    nova[9] = '\0';
    for (i = 0; i < 4; i++) {
      nova[i] = prethodna[i];
    }
    if (prethodna[4] == 'A') {
      nova[4] = 'E';
      return 1;
    } else if (prethodna[4] == 'E') {
      nova[4] = 'J';
      return 1;
    } else if (prethodna[4] == 'J') {
      nova[4] = 'K';
      return 1;
    } else if (prethodna[4] == 'K') {
      nova[4] = 'M';
      return 1;
    } else if (prethodna[4] == 'M') {
      nova[4] = 'O';
      return 1;
    } else if (prethodna[4] == 'O') {
      nova[4] = 'T';
      return 1;
    } else if (prethodna[4] == 'T') {
      nova[4] = 'A';
      if (nova[2] < '9') {
        nova[2] = nova[2] + 1;
        return 1;
      } else {
        nova[2] = '0';
        if (nova[1] < '9') {
          nova[1] = nova[1] + 1;
          return 1;
        } else {
          nova[1] = '0';
            if (nova[0] == 'A') {
              nova[0] = 'E';
              return 1;
            } else if (nova[0] == 'E') {
              nova[0] = 'J';
              return 1;
            } else if (nova[0] == 'J') {
              nova[0] = 'K';
              return 1;
            } else if (nova[0] == 'K') {
              nova[0] = 'M';
              return 1;
            } else if (nova[0] == 'M') {
              nova[0] = 'O';
              return 1;
            } else if (nova[0] == 'O') {
              nova[0] = 'T';
              return 1;
            } else if (nova[0] == 'T') {
              nova[0] = 'A';
              return 0;
            }
          }
        }
      }
    }
  return 0;
}

int main() {
  const char tablica[] = "A00-A-999";
  char nova[10];
  printf("%d", generisi_tablice(tablica, nova));
  return 0;
}
