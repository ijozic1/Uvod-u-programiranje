#include <stdio.h>
#include <math.h>

int main(){
    double Bojan, Tarik, Mirza, Iparb, Ipart, Iparm, IIparb, IIpart, IIparm, prisb, prist, prism, zadb, zadt, zadm, zavrsb, zavrst, zavrsm;
    int ocjenab=5, ocjenat=5, ocjenam=5, prolazb, prolazt, prolazm;
    /*Unos podataka*/
    /*scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &Ipart, &IIpart, &prist, &zadt, &zavrsb, &Iparb, &IIparb, &prisb, &zadb, &zavrst, &Iparm, &IIparm, &prism, &zadm, &zavrsm);*/
    printf("Unesite bodove za Tarika: \n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &Ipart);
    /*Provjera da li su bodovi u dozvoljenom okviru*/
    if(Ipart<0 || Ipart>20){
        printf("Neispravan broj bodova");
    }
    else{
        printf("II parcijalni ispit: ");
        scanf("%lf", &IIpart);
        if(IIpart<0 || IIpart>20){
            printf("Neispravan broj bodova");
        }
        else{
            printf("Prisustvo: ");
            scanf("%lf", &prist);
            if(prist<0 || prist>10 ){
                printf("Neispravan broj bodova");
            }
            else{
                printf("Zadace: ");
                scanf("%lf", &zadt); 
                if(zadt<0 || zadt>10){
                    printf("Neispravan broj bodova");
                }
                else{
                    printf("Zavrsni ispit: ");
                    scanf("%lf", &zavrst);
                    if(zavrst<0 || zavrst>40){
                        printf("Neispravan broj bodova");
                    }
                    else{
                        printf("Unesite bodove za Bojana: \n");
                        printf("I parcijalni ispit: ");
                        scanf("%lf", &Iparb);
                        if(Iparb<0 || Iparb>20){
                            printf("Neispravan broj bodova");
                        }
                        else{
                            printf("II parcijalni ispit: ");
                            scanf("%lf", &IIparb);
                            if(IIparb<0 || IIparb>20){
                                printf("Neispravan broj bodova");
                            }
                            else{
                                printf("Prisustvo: ");
                                scanf("%lf", &prisb);
                                if(prisb<0 || prisb>10){
                                    printf("Neispravan broj bodova");
                                }
                                else{
                                    printf("Zadace: ");
                                    scanf("%lf", &zadb); 
                                    if(zadb<0 || zadb>10){
                                        printf("Neispravan broj bodova");
                                    }
                                    else{
                                        printf("Zavrsni ispit: ");
                                        scanf("%lf", &zavrsb);
                                        if(zavrsb<0 || zavrsb>40){
                                            printf("Neispravan broj bodova");
                                        }
                     else{
                        printf("Unesite bodove za Mirzu: \n");
                        printf("I parcijalni ispit: ");
                        scanf("%lf", &Iparm);
                        if(Iparm<0 || Iparm>20){
                           printf("Neispravan broj bodova");
                         }
                         else{
                            printf("II parcijalni ispit: ");
                            scanf("%lf", &IIparm);
                            if(IIparm<0 || IIparm>20){
                               printf("Neispravan broj bodova");
                             }
                               else{
                                   printf("Prisustvo: ");
                                   scanf("%lf", &prism);
                                   if(prism<0 || prism>10){
                                      printf("Neispravan broj bodova");
                                    }
                                    else{
                                       printf("Zadace: ");
                                       scanf("%lf", &zadm); 
                                       if(zadm<0 || zadm>10 || zavrsm<0 || zavrsm>40){
                                          printf("Neispravan broj bodova");
                                        }
                                        else{
                                           printf("Zavrsni ispit: ");
                                           scanf("%lf", &zavrsm);
                                           if(zavrsm<0 || zavrsm>40){
                                              printf("Neispravan broj bodova");
                                           }
                         /*Ako su svi bodovi ok racunamo broj bodova za svakog od momaka*/
                                          else{
                                              Bojan=Iparb+IIparb+prisb+zadb+zavrsb;
                                              Tarik=Ipart+IIpart+prist+zadt+zavrst;
                                              Mirza=Iparm+IIparm+prism+zadm+zavrsm;
                   /*Odredjujemo da li je svaki od momaka prosao i koju je ocjenu dobio*/
                                          if(Bojan>=55){
                                              prolazb=1;
                                              if(Bojan>=55 && Bojan<65) ocjenab=6;
                                              else if(Bojan>=65 && Bojan<75) ocjenab=7;
                                              else if(Bojan>=75 && Bojan<85) ocjenab=8;
                                              else if(Bojan>=85 && Bojan<92) ocjenab=9;
                                              else ocjenab=10;
                                          }
                                          else{
                                               prolazb=0;
                                          }

                                          if(Tarik>=55){
                                                prolazt=1;
                                                if(Tarik>=55 && Tarik<65) ocjenat=6;
                                                else if(Tarik>=65 && Tarik<75) ocjenat=7;
                                                else if(Tarik>=75 && Tarik<85) ocjenat=8;
                                                else if(Tarik>=85 && Tarik<92) ocjenat=9;
                                                else ocjenat=10;
                                             }
                                             else{
                                                prolazt=0;
                                             }

                                             if(Mirza>=55){
                                                prolazm=1;
                                                if(Mirza>=55 && Mirza<65) ocjenam=6;
                                                else if(Mirza>=65 && Mirza<75) ocjenam=7;
                                                else if(Mirza>=75 && Mirza<85) ocjenam=8;
                                                else if(Mirza>=85 && Mirza<92) ocjenam=9;
                                                else ocjenat=10;
                                              }
                                              else{
                                                prolazm=0;
                                              }
        
                                   /*Provjeravamo koliko je momaka proslo*/
                                    if(prolazb==1 && prolazm==1 && prolazt==1){ 
                                       printf("Sva tri studenta su polozila.\n");
                                      /*Provjeravamo koliko ih je dobilo istu ocjenu*/
                                       if(ocjenab==ocjenat && ocjenam==ocjenab){
                                          printf("Sva tri studenta imaju istu ocjenu.\n");
                                       }
                                       else if((ocjenab==ocjenat && ocjenam!=ocjenat) || (ocjenab==ocjenam && ocjenam!=ocjenat) || (ocjenam==ocjenat && ocjenat!=ocjenab)){
                                       printf("Dva od tri studenta imaju istu ocjenu.\n");
                                       }
                                      else{ 
                                         printf("Svaki student ima razlicitu ocjenu.\n");
                                      }
                                    }

                                  else if ((prolazb==1 && prolazm==1 && prolazt==0) || (prolazb==1 && prolazm==0 && prolazt==1) || (prolazb==0 && prolazm==1 && prolazt==1)){
                                         printf("Dva studenta su polozila.\n");
                                      /*if((ocjenab==ocjenat && ocjenat!=ocjenam) || (ocjenab==ocjenam && ocjenam!=ocjenat) || (ocjenam==ocjenat && ocjenat!=ocjenab)){
                                      printf("Dva od tri studenta imaju istu ocjenu.\n");}
                                       else{
                                       printf("Svaki student ima razlicitu ocjenu.\n");}*/
                                   }
            
                                  else if((prolazt==1 && prolazm==0 && prolazb==0) || (prolazb==1 && prolazm==0 && prolazt==0) || (prolazm==1 && prolazb==0 && prolazt==0)){
                                   printf("Jedan student je polozio.\n");}
                                  else if((prolazb==0 && prolazm==0 && prolazt==0) || (prolazb==0 && prolazm==0 && prolazt==0) || (prolazb==0 && prolazm==0 && prolazt==0)){
                                    printf("Nijedan student nije polozio.\n");
                                   }}}}}}}}}}}}}}}}
    return 0;
}
