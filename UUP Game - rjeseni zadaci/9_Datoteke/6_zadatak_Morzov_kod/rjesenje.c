#include <stdio.h>

char vrati_slovo(char *pocetak, char *kraj) {
  char slovo = '!';
  char *q = pocetak;
  char *poc = pocetak;
  char sA[] = ".-";
  char sB[] = "-...";
  char sC[] = "-.-.";
  char sD[] = "-..";
  char sE[] = ".";
  char sF[] = "..-.";
  char sG[] = "--.";
  char sH[] = "....";
  char sI[] = "..";
  char sJ[] = ".---";
  char sK[] = "-.-";
  char sL[] = ".-..";
  char sM[] = "--";
  char sN[] = "-.";
  char sO[] = "---";
  char sP[] = ".--.";
  char sQ[] = "--.-";
  char sR[] = ".-.";
  char sS[] = "...";
  char sT[] = "-";
  char sU[] = "..-";
  char sV[] = "...-";
  char sW[] = ".--";
  char sX[] = "-..-";
  char sY[] = "-.--";
  char sZ[] = "--..";

  char s1[] = ".----";
  char s2[] = "..---";
  char s3[] = "...--";
  char s4[] = "....-";
  char s5[] = ".....";
  char s6[] = "-....";
  char s7[] = "--...";
  char s8[] = "---..";
  char s9[] = "----.";
  char s0[] = "-----";

  poc = pocetak;
  q = sA;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'A';
    return slovo;
  }

  poc = pocetak;
  q = sB;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'B';
    return slovo;
  }

  poc = pocetak;
  q = sC;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'C';
    return slovo;
  }

  poc = pocetak;
  q = sD;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'D';
    return slovo;
  }

  poc = pocetak;
  q = sE;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'E';
    return slovo;
  }

  poc = pocetak;
  q = sF;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'F';
    return slovo;
  }

  poc = pocetak;
  q = sG;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'G';
    return slovo;
  }

  poc = pocetak;
  q = sH;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'H';
    return slovo;
  }

  poc = pocetak;
  q = sI;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'I';
    return slovo;
  }

  poc = pocetak;
  q = sJ;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'J';
    return slovo;
  }

  poc = pocetak;
  q = sK;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'K';
    return slovo;
  }

  poc = pocetak;
  q = sL;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'L';
    return slovo;
  }

  poc = pocetak;
  q = sM;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'M';
    return slovo;
  }

  poc = pocetak;
  q = sN;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'N';
    return slovo;
  }

  poc = pocetak;
  q = sO;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'O';
    return slovo;
  }

  poc = pocetak;
  q = sP;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'P';
    return slovo;
  }

  poc = pocetak;
  q = sQ;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'Q';
    return slovo;
  }

  poc = pocetak;
  q = sR;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'R';
    return slovo;
  }

  poc = pocetak;
  q = sS;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'S';
    return slovo;
  }

  poc = pocetak;
  q = sT;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'T';
    return slovo;
  }

  poc = pocetak;
  q = sU;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'U';
    return slovo;
  }

  poc = pocetak;
  q = sV;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'V';
    return slovo;
  }

  poc = pocetak;
  q = sW;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'W';
    return slovo;
  }

  poc = pocetak;
  q = sX;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'X';
    return slovo;
  }

  poc = pocetak;
  q = sY;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'Y';
    return slovo;
  }

  poc = pocetak;
  q = sZ;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = 'Z';
    return slovo;
  }

  poc = pocetak;
  q = s1;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '1';
    return slovo;
  }

  poc = pocetak;
  q = s2;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '2';
    return slovo;
  }

  poc = pocetak;
  q = s3;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '3';
    return slovo;
  }

  poc = pocetak;
  q = s4;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '4';
    return slovo;
  }

  poc = pocetak;
  q = s5;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '5';
    return slovo;
  }

  poc = pocetak;
  q = s6;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '6';
    return slovo;
  }

  poc = pocetak;
  q = s7;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '7';
    return slovo;
  }

  poc = pocetak;
  q = s8;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '8';
    return slovo;
  }

  poc = pocetak;
  q = s9;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '9';
    return slovo;
  }

  poc = pocetak;
  q = s0;
  while (poc < kraj && *q != '\0' && *poc == *q) {
    poc++;
    q++;
  }
  if (poc == kraj && *q == '\0') {
    slovo = '0';
    return slovo;
  }
  return slovo;
}

void dekodiraj() {
  FILE *ulaz;
  FILE *izlaz;
  char morze[1000], novi_string[100];
  int i = 0;
  char *p = morze;
  char znak;
  char *pocetak, *kraj;
  ulaz = fopen("morze.txt", "r");
  if (ulaz == NULL) {
    printf("Problem sa otvaranjem datoteke morze.txt");
  } else {
    /*Stvorimo string sa kojim je lakse manipulisati*/
    do {
      znak = fgetc(ulaz);
      if (znak == '.' || znak == '-' || znak == ' ') {
        *p = znak;
        if(p<morze+1000)p++;
      }
    } while (znak != EOF);
    *p = '\0';
    /*printf("%s", morze);
    printf("\n\n");*/
    fclose(ulaz);

    p = morze;
    pocetak = morze;
    kraj = morze;
    i=0;
    while (*p != '\0') {
      /*pocetak = p;*/
      if (*p == ' ') {
        novi_string[i] = *p;
        if (i < 100)
          i++;
      } else if (*p != ' '){
        pocetak = p;
      while (*p!='\0' && *p != ' ') {
        if (*p != '\0')
          p++;
      }
      if (*p == ' ' || *p=='\0') {
        kraj = p;
        znak = vrati_slovo(pocetak, kraj);
        /*printf("%c", znak);*/
      if (znak >= 'A' && znak <= 'Z' || znak >= '0' && znak <= '9') {
        novi_string[i] = znak;
        if (i < 100)
          i++;
        novi_string[i] = *p;
        if (i < 100 && *p!='\0')
          i++;
      }
      else{
          /*Ako je znak koji ne predsavlja slovo*/
          if(*p!='\0' && *p==' ' && *(p+1)==' '){
              p++;
              if(*p==' '){
                  novi_string[i] = *p;
                  if (i < 100 && *p!='\0')
                    i++;
                }
            }
        }
      }
        /*novi_string[i] = *p;
        if (i < 100 && *p!='\0')
          i++;
      }*/
      }
      
      if (*p != '\0')
        p++;
    }
    novi_string[i]='\0';
    /*Sada imamo string u kojem se nalaze slova, brojevi te razmaci*/
    pocetak = novi_string;
    while (*pocetak != '\0') {
      if (*pocetak == ' ' && *(pocetak + 1) != ' ') {
        kraj = pocetak;
        while (*kraj != '\0') {
          *kraj = *(kraj + 1);
          kraj++;
        }
      }
      pocetak++;
    }
    /*Ostalo je jos da izbacimo duple razmake*/
    pocetak = novi_string;
    while (*pocetak != '\0') {
      if (*pocetak == ' ' && (*(pocetak + 1) == ' ' || *(pocetak + 1) == '\0')) {
        kraj = pocetak;
        while (*kraj != '\0') {
          *kraj = *(kraj + 1);
          kraj++;
        }
      }
      pocetak++;
    }
    /*Jos da spremimo sting u datoteku*/
    izlaz = fopen("tekst.txt", "w");
    if (izlaz == NULL) {
      printf("Pogeska pri pristupanju tekst.txt");
    } else {
      pocetak = novi_string;
      while (*pocetak != '\0') {
        znak = *pocetak;
        fputc(znak, izlaz);
        pocetak++;
      }
      fclose(izlaz);
    }
  }
}

int main() {
  dekodiraj();
  /*Provjera radi li funkcija koja vraca znak
  char s[100]=".----";
  char*p=s;
  char*q=s+5;

  printf("%c", vrati_slovo(p,q));*/
  return 0;
}