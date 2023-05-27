#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure Client
typedef struct{
  char nom[50];
  char prenom[50];
  char nom_utilisateur[50];
  char mdp[50];
}Customer;

// Fonction qui crée un client 
Customer create_customer();

// Permet de stocker un client dans fichier
FILE* FilesCustomers(Customer client);

//Mode Connexion
char* login();