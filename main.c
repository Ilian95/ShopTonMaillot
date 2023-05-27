#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "produit.h"
#include "client.h"


int main(void) {
  srand(time(NULL));

  //Choix du mode
  char mode[30];  
  printf("\nBonjour !\n\nChoisissez entre mode gestion ou mode achat : ");
  scanf("%s",mode);
  printf("\n");

  //Effectue la suite du programme en fonction du choix de l'utilisateur
  if(strcmp(mode, "gestion") == 0) {
    printf("\n################################ \n");
    printf("          MODE GESTION \n");
    printf("################################ \n\n");
    DisplayStock();
    printf("\n################################ \n\n");
    Management();
  }
  else if(strcmp(mode, "achat") == 0) {
    printf("\n");
    printf("\n################################ \n");
    printf("          MODE ACHAT \n");
    printf("################################ \n\n");
    printf("\n");
    Buy();
  }
  else{
    printf("Erreur de saisie... \n");
    exit(1);
  }
  
  return 0;
}