#include <math.h>
#include <stdio.h>

int main() {
  /*S obzirom da se unose jednocifreni poeni i da se oni sabiraju, to su oni
   * integeri*/
  int poenS, poenF, zbirS = 0, zbirF = 0, brojacS = 0, brojacF = 0;
  /*Kada govorimo o vrsti pogotka S/D/T/O/I/X onda koristimo char*/
  char pogodakS, pogodakF;

  /*Prvo unosimo poene za Sabita*/
  printf("Unesite pogotke za Sabita: ");
  do {
      scanf("\n%c", &pogodakS);
      /*Zbog osjetljivosti C-a moramo staviti qn pri unosu chara*/
      /*Trebamo provjeriti da li je uneseno nedefinisano slovo*/
    if(pogodakS!='X' && pogodakS!='I' && pogodakS!='O' && pogodakS!='S' && pogodakS!='D' && pogodakS!='T' && pogodakS!='.') {
      printf("Neispravni ulazni podaci.\n");
      printf("Unesite pogotke za Sabita: ");
      /*Brojac vracamo na 0 jer treba da nam se ponovi unos za Sabita*/
      brojacS = 0;
      /*Sumu poena takodjer moramo vratiti na 0 jer unos krece ispocetka*/
      zbirS = 0;
      /*Korisnik treba ponovno poceti sa unosom*/
      scanf("\n%c", &pogodakS);
    }
    else if (pogodakS == 'X'){
      zbirS = zbirS + 0;
      brojacS++;
    }
    else if (pogodakS == 'I'){
      zbirS = zbirS + 50;
      brojacS++;
    }
    else if (pogodakS == 'O'){
      zbirS = zbirS + 25;
      brojacS++;
    }  
    /*Ako pogodi nesto od T, D ili S moramo omoguciti unos broja poena*/
    else if (pogodakS == 'T') {
      scanf("%d", &poenS);
      /*Ako zelimo jos vise ograniciti korisnika, mozemo ispitati da li je broj poena koji je unio unutar dozvoljenog opsega 0-9*/
      /*if(poenS<1 || poenS>9) printf("Neispravan unos podataka");
      else... pa onda racunanje zbira i povecavanje brojaca unutar elsa - ovako bi trebalo za svaki brojcani unos*/
      zbirS = zbirS + 3 * poenS;
      brojacS++;
    } else if (pogodakS == 'D') {
      scanf("%d", &poenS);
      zbirS = zbirS + 2 * poenS;
      brojacS++;
    } else if (pogodakS == 'S') {
      scanf("%d", &poenS);
      zbirS = zbirS + poenS;
      brojacS++;
    }
    /*Unosom tacke, unos se zavrsava*/
    else if (pogodakS == '.') {
      break;
    }
  } while (brojacS < 10);

  /*Sada trebamo unijeti poene za Fadilu*/
  printf("Unesite pogotke za Fadilu: ");
  do {
    scanf("\n%c", &pogodakF);
    /*Dodajemo \n ispred novog unosa da kompajler ne bi enter za kraj prvog
     * unosa citao kao Fadilin unos*/
     /*Treba provjeriti da li je uneseno nedefinisano slovo*/
    if(pogodakF!='X' && pogodakF!='I' && pogodakF!='O' && pogodakF!='S' && pogodakF!='D' && pogodakF!='T' && pogodakF!='.') {
      printf("Neispravni ulazni podaci.\n");
      printf("Unesite pogotke za Fadilu: ");
      /*Brojac na 0 jer krecemo ispocetka*/
      brojacF = 0;
      /*Sumu moramo vratiti na nulu jer s unosom krecemo od pocetka*/
      zbirF = 0;
      /*Korisnik treba ponovno poceti sa unosom*/
      scanf("\n%c", &pogodakF);
      /*printf("Fadila %d\n%d",brojacF, zbirF);*/
    }
    else if (pogodakF == 'X'){
      zbirF = zbirF + 0;
      brojacF++;
    }
    else if (pogodakF == 'I'){
      zbirF = zbirF + 50;
      brojacF++;
    }
    else if (pogodakF == 'O'){
      zbirF = zbirF + 25;
      brojacF++;
    }
    /*Kao i za Sabita ako pogodi nesto od T, D ili S moramo omoguciti unos
     * broja poena*/
    else if (pogodakF == 'T') {
      scanf("%d", &poenF);
      zbirF = zbirF + 3 * poenF;
      brojacF++;
    } else if (pogodakF == 'D') {
      scanf("%d", &poenF);
      zbirF = zbirF + 2 * poenF;
      brojacF++;
    } else if (pogodakF == 'S') {
      scanf("%d", &poenF);
      zbirF = zbirF + poenF;
      brojacF++;
    }
    /*Unosom tacke, unos se zavrsava*/
    else if (pogodakF == '.') {
      break;
    }
   }while(brojacF < 10);

  /*Sada kada imamo unesen broj poena za oboje mozemo poceti razmatrati
   * rezultat*/
  if (zbirF > 301 && zbirS > 301) {
    printf("Oba igraca su premasila potrebni broj poena, rezultat je "
           "nerijesen.");
  } else if (zbirF > 301 && zbirS <= 301) {
    printf("Fadila je premasila potrebni broj poena, Sabit je ostvario %d "
           "poena. "
           "Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede.",
           zbirS, 301 - zbirS);
  } else if (zbirF <= 301 && zbirS > 301) {
    printf("Sabit je premasio potrebni broj poena, Fadila je ostvarila %d "
           "poena. "
           "Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.",
           zbirF, 301 - zbirF);
  }
  /*Ako ni jedno nije premasilo potrebni broj poena onda ispisujemo sljedece*/
  else {
    if (zbirS > zbirF) {
      printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. "
             "Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede.",
             zbirS, zbirF, 301 - zbirS);
    } else if (zbirF > zbirS) {
      printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. "
             "Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.",
             zbirS, zbirF, 301 - zbirF);
    } else {
      printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. "
             "Rezultat je nerijesen.",
             zbirS, zbirF);
    }
  }
  return 0;
}

