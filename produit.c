#include "produit.h"

//Fonction affichant les besoin de restockage
void DisplayStock(){
  FILE* f = NULL;
  char str[30];
  FILE* f2 = NULL;
  char nom[30];
  char stock[30];
  int stockp;
  int nbp_n = 0;
  int nbp_b = 0;
  int a,b,c;
  char nom_i[30];
 
  //Tableau pour les produits nuls et pour les produits avec un stock bas
  Product* produit_n = malloc(sizeof(Product));
  Product* produit_b = malloc(sizeof(Product));

  printf("        BESOIN DE RESTOCKAGE            \n\n");
  
  //Verifie l'accessibilité au fichier produit.txt
  f = fopen("produit.txt", "r");
  if (f == NULL){
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }

  //Parcours le fichier produit.txt
  while(fgets(str, 30, f) != NULL){
    //Retire les tabulation du fichier
    if(str[strlen(str) - 1] =='\n'){
        str[strlen(str) - 1] = '\0';
    }
    strcat(str, ".txt");
    
    //Verifie l'accessibilité au fichier
    f2 = fopen(str, "r");
    if (f2 == NULL){
      printf("Ouverture du fichier impossible\n");
    }
      
    else{
      //Récupère le nom 
      fgets(nom, 30, f2);
      
      //Retire les tabulation du fichier
      if(nom[strlen(nom) - 1] =='\n'){
        nom[strlen(nom) - 1] = '\0';
      }

      //Récupère le stock
      fgets(stock, 30, f2);
      fgets(stock, 30, f2);
      stockp = atoi(stock);
      
      //Enregistre le produit et son stock dans un tableau selon son stock restant
      if(stockp == 0){
        nbp_n ++;
        produit_n = realloc(produit_n, nbp_n * sizeof(Product));
        strcpy(produit_n[nbp_n-1].nom, nom);
        produit_n[nbp_n-1].qte = stockp;
      }
      else{
        nbp_b ++;
        produit_b = realloc(produit_b, nbp_b * sizeof(Product));
        strcpy(produit_b[nbp_b-1].nom, nom);
        produit_b[nbp_b-1].qte = stockp;
      }
    } 
  }
  
  //Affiche les produits nuls
  printf("Produits ayant un stock nul : \n\n");
  for(int i = 0; i<nbp_n;i++){
    printf(" - %s: %d\n",produit_n[i].nom,produit_n[i].qte);
  }
  if(nbp_n==0){
    printf("< il n'y a aucun produit ayant un stock nul >\n\n");
  }
  
  //Trie le tableau des stock bas
  for(a = 0; a<nbp_b-1; a++){
    for(b = a+1; b<nbp_b; b++){
      if(produit_b[a].qte > produit_b[b].qte){
        c = produit_b[a].qte;
        produit_b[a].qte = produit_b[b].qte;
        produit_b[b].qte = c;
        strcpy(nom_i, produit_b[a].nom);
        strcpy(produit_b[a].nom, produit_b[b].nom);
        strcpy(produit_b[b].nom, nom_i);
      }
    }
  }
  
  //Affiche les besoins de restockage
  printf("Voici les 5 produits ayant le stock le + bas : \n\n");
  for(int j = 0; j<5;j++){
    printf(" - %s: %d\n",produit_b[j].nom,produit_b[j].qte);
  }
}

// Fonction créant un produit
Product CreateProduct(int sum, int Space) {
  Product p;
  FILE* f = NULL;
  char str[30];
  FILE* f2 = NULL;
  char num_r[30];
  int num_rf;
  int taille2;

  printf("\nEntrer le nom du produit: (moins de 30 caractère et sans espace)\n\n");
  scanf("%s", p.nom);
  
  //Verifie la taille du nom
  while(strlen(p.nom) > 30 || strlen(p.nom) <= 0){
    printf("\nErreur sur la saisie du nom : ");
    printf("\nEntrer à nouveau le nom du produit: \n\n");
    scanf("%s", p.nom);
  }
  
  //Choisi un num de ref aléatoire pour le produit
  p.num_ref = rand() % 1001 + 10000;

  //Verifie l'accessibilité au fichier produit.txt
  f = fopen("produit.txt", "r");
  if (f == NULL){
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }

  //Parcours le fichier produit.txt
  while(fgets(str, 30, f) != NULL){
    //Retire les tabulation du fichier
    if(str[strlen(str) - 1] =='\n'){
        str[strlen(str) - 1] = '\0';
    }
    strcat(str, ".txt");
    
    //Verifie l'accessibilité au fichier
    f2 = fopen(str, "r");
    if (f2 == NULL){
      printf("Ouverture du fichier impossible\n");
    }
      
    else{
      //Récupère le num de reference
      fgets(num_r, 30, f2);
      fgets(num_r, 30, f2);
      num_rf = atoi(num_r);
      //Vérifie que le num de reference est unique
      while(p.num_ref == num_rf){
        p.num_ref = rand() % 1001 + 10000;
      }
    }
    fclose(f2);
  }
  fclose(f);
  
  //Demande une quantité pour le produit
  printf("\nSaisissez la quantité du produit ajouté: \n\n");
  scanf("%d", &p.qte);

  //Verifie l'entree utilisateur
  if(scanf("%d",&p.qte) != 1){
    printf("Choix invalide. Entrez un entier.\n\n");

    //Vide le flux d'entrée
    int e;
    while((e = getchar()) != '\n' && e != EOF){}
  }
  
  //Demande un prix pour le produit
  printf("\nEntrer le prix du produit: \n\n");
  scanf("%d", &p.prix);

  //Verifie l'entree utilisateur
  if(scanf("%d",&p.prix) != 1){
    printf("Choix invalide. Entrez un entier.\n\n");

    //Vide le flux d'entrée
    int e;
    while((e = getchar()) != '\n' && e != EOF){}
  }

  //Demande et verifie la taille du produit
  printf("\nEntrer la taille du produit : (petit, moyen ou grand) \n\n");
  scanf("%s", p.taille);
  while((strcmp(p.taille, "petit") != 0)&&(strcmp(p.taille, "moyen") != 0)&&(strcmp(p.taille, "grand") != 0)){
    printf("\nMauvaise saisie\n");
    printf("\nEntrer à nouveau la taille du produit : (petit, moyen  ou grand) \n\n");
  scanf("%s", p.taille);
  }

  //Enlève les tabulations
  if(p.taille[strlen(p.taille) - 1] =='\n'){
    p.taille[strlen(p.taille) - 1] = '\0';
  }
      
  //Récupère la taille
  if(strcmp(p.taille, "petit") == 0){
    taille2 = 1;
  }
  else if(strcmp(p.taille, "moyen") == 0){
    taille2 = 2;
  }
  else if(strcmp(p.taille, "grand") == 0){
    taille2 = 4;
  }
  
  //Verifie la place restante dans le magasin
  if(((p.qte*taille2)+sum) > 1000){
      printf("\nErreur !!! Vous avez mit une quantité du produit trop  élevée\n\n<Opération annulée>\n");
      printf("\nPlace restante dans le magasin: %d \n",Space-sum);
    exit(1);
  }

  return p;
}

// Permet de stocker un produit dans un fichier
FILE* FileProduct(Product p) {
  FILE *fichier;
  char nom[30];

  strcpy(nom,p.nom);
  strcat(nom, ".txt");

  // Verifie l'accessibilité du fichier
  fichier = fopen(nom, "w");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }

  // Ecrit chaque valeur du produit dans un fichier
  fprintf(fichier, "%s \n", p.nom);
  fprintf(fichier, "%d \n", p.num_ref);
  fprintf(fichier, "%d \n", p.qte);
  fprintf(fichier, "%d \n", p.prix);
  fprintf(fichier, "%s", p.taille);
  
  fclose(fichier);

  //Ouvre le fichier produit.txt et ajoute le nom du produit dedans
  FILE* fichier2 = fopen("produit.txt", "a");
  fprintf(fichier, "\n%s", p.nom);
  fclose(fichier2);

  return fichier;
}