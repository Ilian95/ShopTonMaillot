#include "client.h"

// Fonction qui crée un client 
Customer create_customer(){
  Customer client;
  
  printf("Entrer le nom du client : ");
  scanf("%s",client.nom);

  //Verifie la taille du nom
  while(strlen(client.nom) > 50 || strlen(client.nom) <= 0){
    printf("\nErreur sur la saisie du nom : ");
    printf("\nEntrer à nouveau le nom du produit: \n\n");
    scanf("%s", client.nom);
  }
  
  printf("Entrer le prénom du client : ");
  scanf("%s",client.prenom);

  //Verifie la taille du prénom
  while(strlen(client.prenom) > 50 || strlen(client.prenom) <= 0){
    printf("\nErreur sur la saisie du nom : ");
    printf("\nEntrer à nouveau le nom du produit: \n\n");
    scanf("%s", client.prenom);
  }
  
  printf("Entrer un nom d'utilisateur : ");
  scanf("%s",client.nom_utilisateur);

  //Verifie la taille du nom d'utilisateur
  while(strlen(client.nom_utilisateur) > 50 || strlen(client.nom_utilisateur) <= 0){
    printf("\nErreur sur la saisie du nom : ");
    printf("\nEntrer à nouveau le nom du produit: \n\n");
    scanf("%s", client.nom_utilisateur);
  }
  
  printf("Entrer un mot de passe : ");
  scanf("%s",client.mdp);

  //Verifie la taille du mot de passe
  while(strlen(client.mdp) > 50 || strlen(client.mdp) <= 0){
    printf("\nErreur sur la saisie du nom : ");
    printf("\nEntrer à nouveau le nom du produit: \n\n");
    scanf("%s", client.mdp);
  }
  
  return client;
}


// Permet de stocker un client dans fichier
FILE* FilesCustomers(Customer client){
  FILE* fichier;

  // Verifie l'accessibilité du fichier
  fichier = fopen(client.nom_utilisateur, "w");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }

  // Ecrit les données du client dans un fichier
  fprintf(fichier, "Nom : %s\n", client.nom);
  fprintf(fichier, "Prénom : %s\n", client.prenom);
  fprintf(fichier, "Nom d'utilisateur : %s\n", client.nom_utilisateur);
  fprintf(fichier, "%s\n", client.mdp);
  fprintf(fichier, "Pasdachat\n");

  return fichier;
}


//Mode Connexion
char* login(){
  FILE* f = NULL;
  Customer client;
  int comp;
  char nom_utilis[50];
  char mdp[50];
  char mdp2[50];
  
  printf("\nEntrer votre nom d'utilisateur : ");
  scanf("%s",nom_utilis);
  
  printf("Entrer votre mot de passe : ");
  scanf("%s",mdp);

  //Verifie si le client existe
  f = fopen(nom_utilis,"r");
  if (f == NULL) {
    printf("\n< Nom d'utilisateur incorrect >\n\n");
    login();
  }
  else{
    fgets(mdp2,50,f);
    fgets(mdp2,50,f);
    fgets(mdp2,50,f);
    fgets(mdp2,50,f);
    
    if(mdp2[strlen(mdp2)-1]=='\n'){
      mdp2[strlen(mdp2)-1]='\0';
    }
    
    if(strcmp(mdp,mdp2) == 0){
      printf("\n< Vous êtes connectés >\n\n");
    }
      
    else{
      printf("< Mot de passe incorrect >\n");
      login();
    }
  }
  fclose(f);

  return nom_utilis;
}