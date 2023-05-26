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


//Fonction calculant la place disponible dans le magasin
int DisplaySpace(){
  FILE* f = NULL;
  FILE* f2 = NULL;
  char str[30];
  char stock[30];
  int stock2;
  char taille[30];
  int taille2 = 0;
  int sum = 0;

  //Verifie l'accessibilité au fichier
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
    
    //Verifie l'accessibilité du fichier
    f2 = fopen(str, "r");
    if (f2 == NULL){
      printf("Ouverture du fichier impossible\n");
    }
    
    else{
      //Récupère le stock et la taille
      fgets(stock, 30, f2);
      fgets(stock, 30, f2);
      fgets(stock, 30, f2);
      fgets(taille, 30, f2);
      fgets(taille, 30, f2);
      
      //Retire les tabulation du fichier
      if(taille[strlen(taille) - 1] =='\n'){
        taille[strlen(taille) - 1] = '\0';
      }
      
      //Récupère la taille
      if(strcmp(taille, "petit") == 0){
        taille2 = 1;
      }
      else if(strcmp(taille, "moyen") == 0){
        taille2 = 2;
      }
      else if(strcmp(taille, "grand") == 0){
        taille2 = 4;
      }
      
      //Récupère et ajoute le stock du produit a la place occupée du magasin
      stock2 = atoi(stock);
      sum += (stock2*taille2);
      
      fclose(f2);
    }
  }
  fclose(f); 
  return sum;
}


//Affiche la liste des produits
void ListP(){
  FILE* f;
  char str[30];
  
  //Verifie l'accessibilité du fichier produit.txt
  f = fopen("produit.txt", "r");
  if (f == NULL){
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }

  printf("\nVoici la liste des produits :\n\n");
  
  //Parcours le fichier produit.txt et affiche son contenu
  while(fgets(str, 30, f) != NULL){ 
    printf("- %s", str);
  }
  printf("\n");
  fclose(f);
}


//Fonction permettant de chercher le stock d'un produit
void SearchStock(){
  char nom[30];
  char nomf[30];
  FILE* f = NULL;
  char stock[30];
  
  printf("\nSaisissez le nom du produit que vous recherchez:\n\n");
  scanf("%s",nom);

  strcpy(nomf, nom);
  strcat(nom, ".txt");

  //Verifie l'accessibilité du fichier
  f = fopen(nom, "r");
  if (f == NULL) {
    printf("\nLe produit que vous chercher n'existe pas.\n"); 
  }
  
  else{
    //Récupère le stock
    fgets(stock, 30, f);
    fgets(stock, 30, f);
    fgets(stock, 30, f);
    printf("\nStock du produit %s : %s",nomf ,stock);
    fclose(f);
  }
}


//Fonction augmentant le stock d'un produit
void IncreaseStock(int sum, int Space){
  char nom[30];
  char nomf[30];
  FILE* f = NULL;
  char stock[30];
  char numr[30];
  char prix[30];
  char taille[30];
  int stock1, stock2, stockf;
  int numrf;
  int prixf;
  int taille2;

  printf("\n\nSaisissez le nom du produit dont vous voulez augmenter le stock:\n\n");
  scanf("%s",nom);

  strcpy(nomf, nom);
  strcat(nom, ".txt");

  //Vérifie l'accessibilité du fichier
  f = fopen(nom, "r");
  if (f == NULL) {
    printf("\nLe produit que vous avez entré n'existe pas.\n");  
  }
  
  else{
    //Recupere les valeurs du produit
    fgets(stock, 30, f);
    fgets(numr, 30, f);
    fgets(stock, 30, f);
    fgets(prix, 30, f);
    fgets(taille, 30, f);
    fclose(f);

    //Remet en entier certaines valeures
    stock1 = atoi(stock);
    numrf = atoi(numr);
    prixf = atoi(prix);
    
    //Retire les espaces et tabulations de la taille créer par le fichier
    if((taille[strlen(taille) - 1] =='\n')||taille[strlen(taille) - 1] ==' '){
        taille[strlen(taille) - 1] = '\0';
    }
    
    //Récupère la taille du produit
    if(strcmp(taille, "petit") == 0){
      taille2 = 1;
    }
    else if(strcmp(taille, "moyen") == 0){
      taille2 = 2;
    }
    else if(strcmp(taille, "grand") == 0){
       taille2 = 4;
    }
    
    //Demande l'augmentation ou la baisse du stock
    printf("\nSaisissez de combien vous voulez augmentez (ou réduire) le stock de %s (Stock : %d):\n\n",nomf, stock1);
    scanf("%d",&stock2);
    stockf = stock1 + stock2;
    
    //Vérifie s'il reste de la place dans la boutique
    if(((stockf*taille2)+sum) > 1000){
      printf("\nErreur !!! Vous avez mit une quantité du produit trop  élevée\n\n<Opération annulée>\n");
      printf("\nPlace restante dans le magasin: %d \n",Space-sum);
    }
    
    else{
      //Affiche le stock du produit
      printf("\nLe produit %s a maintenant un stock de : %d ;\n",nomf,stockf);
      
      //Remet les valeurs du produit dans son fichier
      f = fopen(nom, "w");
      fprintf(f, "%s \n",nomf);
      fprintf(f, "%d \n",numrf);
      fprintf(f, "%d \n",stockf);
      fprintf(f, "%d \n",prixf);
      fprintf(f, "%s",taille);
      fclose(f);
    }
  }
}


// Fonction créant un produit
Product CreateProduct(int sum, int Space) {
  Product p;
  int taille2;

  printf("\nEntrer le nom du produit: \n\n");
  scanf("%s", p.nom);
  
  //Verifie la taille du nom
  while(strlen(p.nom) > 30 || strlen(p.nom) <= 0){
    printf("\nErreur sur la saisie du nom : ");
    printf("\nEntrer à nouveau le nom du produit: \n\n");
    scanf("%s", p.nom);
  }
  
  //Choisi un num de ref aléatoire pour le produit
  p.num_ref = rand() % 1001 + 10000;
  
  //Demande une quantité pour le produit
  printf("\nSaisissez la quantité du produit ajouté: \n\n");
  scanf("%d", &p.qte);
  
  //Demande une quantité pour le produit
  printf("\nEntrer le prix du produit: \n\n");
  scanf("%d", &p.prix);

  //Demande une quantité pour le produit
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

//Lance le mode gestion
void Management(){
  Product p;
  int Space = 1000;
  int choix;
  int sum = DisplaySpace();
  
  //Affiche le haut de l'acceuil
  printf("            ACCEUIL                \n\n");
  printf("\n< Place restante dans le magasin : %d >\n\n", Space-sum);
  printf("- Appuyer sur 1 pour la liste des produits; \n \n- Appuyer sur 2 pour chercher le stock d'un produit; \n \n- Appuyer sur 3 pour augmenter le stock d'un produit; \n \n- Appuyer sur 4 pour ajouter un produit; \n \n- Appuyer sur 5 pour quitter;\n \n");
  scanf("%d", &choix);

  //Effectue la suite du programme en fonction du choix de l'utilisateur
  switch(choix){
    case 1:
      ListP();
      printf("\nRetour à l'acceuil...\n \n");
      printf("################################ \n \n");
      Management();
      break;
      
    case 2:
      SearchStock();
      printf("\nRetour à l'acceuil...\n \n");
      printf("################################ \n \n");
      Management();
      break;
      
    case 3:
      IncreaseStock(sum, Space);
      sum = DisplaySpace();
      printf("\nLe magasin a un stock Occupé de %d / %d Libre. \n",sum, Space);
      printf("\nRetour à l'acceuil...\n \n");
      printf("################################ \n\n");
      Management();
      break;
      
    case 4:
      p = CreateProduct(sum, Space);
      printf("\n<Produit créé>\n");
      FILE* f = FileProduct(p);
      printf("\n<Produit enregistré dans un fichier>\n");
      printf("\nRetour à l'acceuil...\n\n\n");
      printf("################################ \n\n");
      Management();
      break;
      
    case 5:
      printf("\nPassez une bonne journée, au revoir ! \n");
      break;
      
    default:
      printf("\nErreur de saisie... \n");
      printf("\nRetour à l'acceuil...\n\n");
      printf("################################ \n\n");
      Management();
      break;
  }
}


int main(void) {
  srand(time(NULL));

  //Choix du mode
  char mode[30];  
  printf("\nBonjour !\n\nChoisissez entre mode gestion ou mode achat : ");
  scanf("%s",mode);
  printf("\n");

  //Effectue la suite du programme en fonction du choix de l'utilisateur
  if(strcmp(mode, "gestion") == 0) {
    printf("\n");
    printf("################################ \n");
    printf("          MODE GESTION \n");
    printf("################################ \n");
    DisplayStock();
    printf("\n");
    printf("################################ \n");
    printf("\n");
    Management();
  }
  else if(strcmp(mode, "achat") == 0) {
    printf("\n");
    printf("################################ \n");
    printf("             MODE ACHAT \n");
    printf("################################ \n");
    printf("\n");
  }
  else{
    printf("Erreur de saisie... \n");
    exit(1);
  }
  
  return 0;
}
