#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "client.h"

// Affiche l'historique d'achat
void Purchases(char nom[50], int nb_a);

//Fonction permettant de chercher et d'acheter un produit
void Search_and_buy_Produit(int prixtot, char nomU[50], int nb_a);

// Fonction qui permet supprimer un client
void delete_customer();

//Fonction affiche l'acceuil
void home(char nom[50]);

// Mode Achat
void Buy();