#include <math.h>
#include <stdio.h>

int zamijeni_podniz(int *p1, int *p2, const int *q1, const int *q2, const int *r1, const int *r2) {
    int velP, velQ, velR, broj_izbacivanja, *prvi, *pomocni, *kraj, *novi_kraj;
    const int *drugi, *treci;
    velP = p2 - p1;
    velQ = q2 - q1;
    velR = r2 - r1;
    /*Moramo posmatrati tri slucaja, kada su q i r jednaki, kada je q vece od r i kada je r vece od q*/
    /*Broj izbacivanja je varijabla koja broji koliko puta smo niz q zamijenili sa nizom r jer ce isto toliko puta biti promjenjena duzina niza p*/
    broj_izbacivanja=0;
    if (velQ == velR) {
        prvi = p1;
        while (prvi < p2) {
            drugi = q1;
            pomocni = prvi;
            while (pomocni < p2 && drugi < q2 && *pomocni == *drugi) {
                pomocni++;
                drugi++;
            }
            /*Ako smo dosli do kraja drugog niza znaci da smo pronasli podniz*/
            if (drugi == q2) {
                kraj = pomocni;
                pomocni = prvi;
                treci = r1;
                while (pomocni < kraj) {
                    *pomocni = *treci;
                    pomocni++;
                    treci++;
                }
                prvi = p1 - 1;
                broj_izbacivanja++;
            }
        prvi++;
        }
    } 
    else if (velR < velQ) {
        broj_izbacivanja=0;
        prvi = p1;
        while (prvi < p2) {
            /*Prvo provjerimo da li je q podniz u p*/
            drugi = q1;
            pomocni = prvi;
            while (pomocni < p2 && drugi < q2 && *pomocni == *drugi) {
                pomocni++;
                drugi++;
            }   
            /*Ako smo dosli do kraja drugog niza znaci da smo pronasli podniz*/
            if (drugi == q2) {
                kraj = pomocni;
                pomocni = prvi;
                treci = r1;
                while (treci < r2) {
                    *pomocni = *treci;
                    pomocni++;
                    treci++;
                }
                while (kraj < p2) {
                    *pomocni = *kraj;
                    pomocni++;
                    kraj++;
                }
                /*Ono sto sigurno znamo je nova velicina niza omodjenog sa p*/
                velP = velP - (velQ - velR);
                broj_izbacivanja++;
                prvi = p1 - 1;
            }
        prvi++;
        }
    } 
    else if (velR > velQ) {
        broj_izbacivanja=0;
        prvi = p1;
        while (prvi < p2) {
            /*Prvo provjerimo da li je q podniz u p*/
            drugi = q1;
            pomocni = prvi;
            while (pomocni < p2 && drugi < q2 && *pomocni == *drugi) {
                pomocni++;
                drugi++;
            }
            /*Ako smo dosli do kraja drugog niza znaci da smo pronasli podniz*/
            if (drugi == q2) {
                p2 = p2 + (velR - velQ);
                novi_kraj = p2-1;
                /*Prvo moramo osloboditi prostor za upis viska clanova*/
                kraj = pomocni;
                pomocni = prvi;
                while (novi_kraj > kraj) {
                    *novi_kraj = *(novi_kraj - (velR - velQ));
                    novi_kraj--;
                }
                treci = r1;
                while (treci < r2) {
                    *pomocni = *treci;
                    pomocni++;
                    treci++;
                }
                /*Ono sto sigurno znamo je nova velicina niza omodjenog sa p*/
                velP = velP - (velQ - velR);
                broj_izbacivanja++;
                prvi = p1 - 1;
            }
            prvi++;
        }
    }
  return broj_izbacivanja*(velR - velQ);
}
int main() {
  /*int niz1[15] = {1, 1, 2, 3, 2, 1, 2, 3, 3, 1};
  int niz2[3] = {1, 2, 3};
  int niz3[4] = {9, 9, 9, 9};
  int k = zamijeni_podniz(niz1, niz1 + 10, niz2, niz2 + 3, niz3, niz3 + 4);
  int i;
  printf("\n\n%d\n\n", k);
  for (i = 0; i < 10 + k; i++)
    printf("%d ", niz1[i]);*/
  return 0;
}
