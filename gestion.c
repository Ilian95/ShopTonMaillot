#include "gestion.h"

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
    do{
      printf("\nSaisissez de combien vous voulez augmentez le stock de %s (Stock : %d):\n\n",nomf, stock1);
      scanf("%d",&stock2);
    }while(stock2<=0); 
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

  //Verifie l'entree utilisateur
  if(scanf("%d",&choix) != 1){
    printf("Choix invalide. Entrez un entier.\n");

    //Vide le flux d'entrée
    int e;
    while((e = getchar()) != '\n' && e != EOF){}
  }

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