#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure Produit
typedef struct {
  char nom[30];
  int num_ref;
  int qte;
  int prix;
  char taille[20];
} Product;

//Fonction affichant les besoin de restockage
void DisplayStock();

// Fonction créant un produit
Product CreateProduct(int sum, int Space);

// Permet de stocker un produit dans un fichier
FILE* FileProduct(Product p);

//Lance le mode gestion
void Management();