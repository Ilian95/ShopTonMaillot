#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "produit.h"

//Fonction calculant la place disponible dans le magasin
int DisplaySpace();

//Affiche la liste des produits
void ListP();

//Fonction permettant de chercher le stock d'un produit
void SearchStock();

//Fonction augmentant le stock d'un produit
void IncreaseStock(int sum, int Space);

//Lance le mode gestion
void Management();