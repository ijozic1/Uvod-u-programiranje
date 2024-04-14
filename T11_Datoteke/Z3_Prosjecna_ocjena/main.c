#include <math.h>
#include <stdio.h>

int main() {
  int predmet, ocjena = 0, br_indeksa, n, br_studenata = 0;
  double prosjek = 0, prolaznost, br_ocjena=0;

  printf("Unesite predmet: ");
  scanf("%d", &n);

  FILE *ulaz = fopen("ispiti.txt", "r");
  if (ulaz == NULL) {
    printf("Pogreska pri otvaranju datoteke ispiti.txt");
    return 1;
  }
  while (fscanf(ulaz, "%d %d %d\n", &br_indeksa, &predmet, &ocjena) == 3) {
    if (predmet == n) {
      if (ocjena > 5) {
        ++br_ocjena;
      }
      br_studenata++;
      prosjek += ocjena;
    }
  }
  if(br_studenata==0){
    printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!", n);
    return 2;
  }
  prosjek = prosjek / br_studenata;
  prosjek = (round(prosjek * 100)) / 100;
  prolaznost = (br_ocjena / br_studenata) * 100;
  prolaznost = round(prolaznost);
  printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", prosjek, prolaznost);
  fclose(ulaz);
  return 0;
}
