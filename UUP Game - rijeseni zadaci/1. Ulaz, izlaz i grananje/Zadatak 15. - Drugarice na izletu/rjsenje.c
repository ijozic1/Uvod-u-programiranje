#include <math.h>
#include <stdio.h>

int main() {
  char padavineSa, padavineMo, padavineBi, vrijemeSa, vrijemeMo, vrijemeBi;
  double tempSa, tempMo, tempBi;
  int tSa, tMo, tBi, AnjaSa, AnjaMo, AnjaBi, ElmaSa, ElmaMo, ElmaBi, UnaSa, UnaMo, UnaBi;
  printf("Unesite prognozu za Sarajevo:\n");
  printf("Temperatura: ");
  scanf("%lf", &tempSa);
  printf("Padavine (D/N): ");
  /*C je osjetljiv pa enter moze ocitati prije chara, zato je dobro prvo postaviti novi red prije novog chara*/
  scanf("\n%c", &padavineSa);
  if (padavineSa != 'd' && padavineSa != 'D' && padavineSa != 'n' &&
      padavineSa != 'N')
    printf("Pogresan unos.");
  else {
    printf("Unesite prognozu za Mostar:\n");
    printf("Temperatura: ");
    scanf("%lf", &tempMo);
    printf("Padavine (D/N): ");
    scanf("\n%c", &padavineMo);
    if (padavineMo != 'd' && padavineMo != 'D' && padavineMo != 'n' && padavineMo != 'N')
      printf("Pogresan unos.");
    else {
      printf("Unesite prognozu za Bihac:\n");
      printf("Temperatura: ");
      scanf("%lf", &tempBi);
      printf("Padavine (D/N): ");
      scanf("\n%c", &padavineBi);
      if (padavineBi != 'd' && padavineBi != 'D' && padavineBi != 'n' && padavineBi != 'N')
        printf("Pogresan unos.");
      else {
        /*Provjeravamo kakvo je stanje po pianju padavina u svakom od gradova*/
        /*k - kisa, s - snijeg, S - sunce*/
        if ((padavineSa == 'd' || padavineSa == 'D') && tempSa > 0) vrijemeSa = 'k';
        else if ((padavineSa == 'd' || padavineSa == 'D') && tempSa < 0) vrijemeSa = 's';
        else if (padavineSa == 'n' || padavineSa == 'N') vrijemeSa = 'S';

        if ((padavineMo == 'd' || padavineMo == 'D') && tempMo > 0) vrijemeMo = 'k';
        else if ((padavineMo == 'd' || padavineMo == 'D') && tempMo < 0) vrijemeMo = 's';
        else if (padavineMo == 'n' || padavineMo == 'N') vrijemeMo = 'S';

        if ((padavineBi == 'd' || padavineBi == 'D') && tempBi > 0) vrijemeBi = 'k';
        else if ((padavineBi == 'd' || padavineBi == 'D') && tempBi < 0) vrijemeBi = 's';
        else if (padavineBi == 'n' || padavineBi == 'N') vrijemeBi = 'S';

        /*Provjeravamo kakvo je vrijeme u svakom od gradova zavisno od temperature*/
        /*5 - vrlo vruce, 4 - vruce, 3 - onako, 2 - hladno, 1 - vrlo hladno*/
        if (tempSa < (-5)) tSa = 1;
        else if (tempSa >= (-5) && tempSa < 5) tSa = 2;
        else if (tempSa >= 5 && tempSa < 20) tSa = 3;
        else if (tempSa >= 20 && tempSa < 30) tSa = 4;
        else if (tempSa >= 30) tSa = 5;

        if (tempMo < (-5)) tMo = 1;
        else if (tempMo >= (-5) && tempMo < 5) tMo = 2;
        else if (tempMo >= 5 && tempMo < 20) tMo = 3;
        else if (tempMo >= 20 && tempMo < 30) tMo = 4;
        else if (tempMo>=30) tMo = 5;

        if (tempBi < (-5)) tBi = 1;
        else if (tempBi >= (-5) && tempBi < 5) tBi = 2;
        else if (tempBi >= 5 && tempBi < 20) tBi = 3;
        else if (tempBi >= 20 && tempBi < 30) tBi = 4;
        else if (tempBi >= 30) tBi = 5;

        /*Sada razmotrimo kako vrijeme u pojedinim gradovima odgovara kojoj od djevojaka*/
        /*Ajni odgovara ako je sunce ili snijeg, a ne odgovara joj kisa*/
        if (vrijemeSa == 'k') AnjaSa = 0;
        else AnjaSa = 1;
        if (vrijemeMo == 'k') AnjaMo = 0;
        else AnjaMo = 1;
        if (vrijemeBi == 'k') AnjaBi = 0;
        else AnjaBi = 1;
        /*Elmi ne odgovara kada je vrlo vruce ili vrlo hladno*/
        if (tempSa<(-5) || tempSa>=30) ElmaSa = 0;
        else ElmaSa = 1;
        if (tempMo<(-5) || tempMo>=30) ElmaMo = 0;
        else ElmaMo = 1;
        if (tempBi<(-5) || tempBi>=30) ElmaBi = 0;
        else ElmaBi = 1;
        /*Uni ne odgovaraju padavine i kad je vrijeme onako*/
        if (vrijemeSa !='S' || tSa == 3) UnaSa = 0;
        else UnaSa = 1;
        if (vrijemeMo !='S' || tMo == 3) UnaMo = 0;
        else UnaMo = 1;
        if (vrijemeBi !='S' || tBi == 3) UnaBi = 0;
        else UnaBi = 1;

        /*Sada trebamo provjeriti u koji grad ce ici prijateljice*/
        if (AnjaSa == 1 && ElmaSa == 1 && UnaSa == 1) printf("Drugarice idu u Sarajevo.");
        else if (AnjaMo == 1 && ElmaMo == 1 && UnaMo == 1) printf("Drugarice idu u Mostar.");
        else if (AnjaBi == 1 && ElmaBi == 1 && UnaBi == 1) printf("Drugarice idu u Bihac.");

        else if (AnjaSa == 1 && ElmaSa == 1 && UnaSa == 0) printf("Anja i Elma mogu u Sarajevo.");
        else if (AnjaSa == 1 && ElmaSa == 0 && UnaSa == 1) printf("Anja i Una mogu u Sarajevo.");
        else if (AnjaSa == 0 && ElmaSa == 1 && UnaSa == 1) printf("Elma i Una mogu u Sarajevo.");

        else if (AnjaMo == 1 && ElmaMo == 0 && UnaMo == 1) printf("Anja i Una mogu u Mostar.");

        else if (AnjaMo == 0 && ElmaMo == 1 && UnaMo == 1) printf("Elma i Una mogu u Mostar.");
        else if (AnjaMo == 1 && ElmaMo == 1 && UnaMo == 0) printf("Anja i Elma mogu u Mostar.");
        

        else if (AnjaBi == 1 && ElmaBi == 1 && UnaBi == 0) printf("Anja i Elma mogu u Bihac.");
        else if (AnjaBi == 1 && ElmaBi == 0 && UnaBi == 1) printf("Anja i Una mogu u Bihac.");
        else if (AnjaBi == 0 && ElmaBi == 1 && UnaBi == 1) printf("Elma i Una mogu u Bihac.");

        else printf("Ne odgovara niti jedan grad.");
      }
    }
  }
  return 0;
}
