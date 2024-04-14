#include <stdio.h>

int main() {
  int niz[100], vel, niz2[1000], vel2, i;
  printf("Unesite velicinu niza: ");
  scanf("%d", &vel);
  printf("Unesite clanove niza: ");
  for (i = 0; i < vel; i++)
    scanf("%d", &niz[i]);

  /* === OVDJE UBACITI KOD === */
  int j, brojac = 0, pomocni_niz_br[100], velicina_pomocnog = 0,
         pomocni_niz_cifre[1000], vel_cifre = 0, broj, cifra, brojac_cifara = 0,
         potencija = 1;
  /*Uneseni niz prvo moramo podijeliti na cifre i smjestiti u pomocni niz*/
  for (i = 0; i < vel; i++) {
    broj = niz[i];
    brojac_cifara = 0;
    while (broj > 0) {
      broj = broj / 10;
      brojac_cifara++;
    }
    broj = niz[i];
    while (brojac_cifara - 1 >= 0) {
      potencija = 1;
      /*Racunamo potenciju cifre*/
      for (j = 0; j < brojac_cifara - 1; j++)
        potencija *= 10;
      cifra = broj / potencija;
      cifra = cifra % 10;
      pomocni_niz_cifre[vel_cifre++] = cifra;
      brojac_cifara--;
    }
    if (niz[i] == 0)
      pomocni_niz_cifre[vel_cifre++] = niz[i];
  }

  /*U pomocni niz brojaca cemo smjestati broj koliko puta se ponavlje neki element uzastopno*/
  /*Prodjemo kroz pomocni niz u kojem nam se nalaze cifre i popunimo pomocni niz brojaca*/
  for (i = 0; i < vel_cifre; i++) {
    brojac = 0;
    for (j = i; j < vel_cifre; j++) {
      if (pomocni_niz_cifre[j] == pomocni_niz_cifre[i])
        brojac++;
      else
        break;
    }
    pomocni_niz_br[velicina_pomocnog++] = brojac;
    i = i + brojac - 1;
  }

  /*Modificirati cemo niz sa ciframa tako sto cemo izbaciti sve cifre koje se ponavljaju*/
  for (i = 1; i < vel_cifre; i++) {
    if (pomocni_niz_cifre[i] == pomocni_niz_cifre[i - 1]) {
      for (j = i; j < vel_cifre - 1; j++) {
        pomocni_niz_cifre[j] = pomocni_niz_cifre[j + 1];
      }
      vel_cifre--;
      i--;
    }
  }

  /*Velicina drugog niza je velicina_pomocnog*2*/
  vel2 = velicina_pomocnog * 2;
  velicina_pomocnog = 0;
  vel_cifre = 0;
  for (i = 0; i < vel2; i += 2) {
    /*Na indeks i smjestamo broj iz niza, a na indeks i+1 broj koliko puta se on
     * uzastopno ponavlja*/
    niz2[i] = pomocni_niz_cifre[vel_cifre++];
    niz2[i + 1] = pomocni_niz_br[velicina_pomocnog++];
  }
  /*=== KRAJ UBACENOG KODA===*/

  printf("Finalni niz glasi:\n");
  for (i = 0; i < vel2; i++)
    printf("%d ", niz2[i]);
  return 0;
}
