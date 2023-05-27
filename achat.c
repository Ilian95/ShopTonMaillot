#include "achat.h"

// Affiche l'historique d'achat
void Purchases(char nom[50], int nb_a){
  FILE* f = NULL;
  char achat1[50];
  char achat2[50];
  char achat3[50];
  int nbl = 0;

  //Effectue le programme en fonction du nombre d'achats
  switch(nb_a){
    case 1:
      //Verifie l'accessibilité au fichier
      f = fopen(nom, "r");
      if (f == NULL) {
        printf("Ouverture du fichier impossimble.\n");  
      }
      else{
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        
        //Retire les espaces et tabulations créer par le fichier
        if((achat1[strlen(achat1) - 1] =='\n')||achat1[strlen(achat1) - 1] ==' '){
        achat1[strlen(achat1) - 1] = '\0';
        }

        //Verifie si le client a au moins 1 achat
        if(strcmp(achat1,"Pasdachat")==0){
          printf("Vous n'avez pas d'achats récents\n\n");
        }
        else{
          printf("\nVoici le dernier produit acheté:\n\n %s \n\n", achat1);
        }
      }
    break;

    case 2:
      //Verifie l'accessibilité au fichier
      f = fopen(nom, "r");
      if (f == NULL) {
        printf("Ouverture du fichier impossible.\n");  
      }
      else{
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat2, 50, f);
        printf("\nVoici les deux derniers produit acheté:\n\n - %s - %s\n\n", achat1, achat2);
      }
    break;

    case 3:
      //Verifie l'accessbilité au fichier
      f = fopen(nom, "r");
      if (f == NULL) {
        printf("Ouverture du fichier impossimble.\n");  
      }
      else{
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat1, 50, f);
        fgets(achat2, 50, f);
        fgets(achat3, 50, f);
        printf("\nVoici les derniers produits acheté:\n\n - %s - %s - %s \n\n", achat1, achat2, achat3);
      }
    break;

    default:
      //Vérifie l'accessibilité au fichier
      f = fopen(nom, "r");
      if (f == NULL) {
        printf("Ouverture du fichier impossimble.\n");  
      }

      //Recupère les 3 derniers achats
      while(fgets(achat1, 50, f) != NULL){
        nbl++;
      }
      rewind(f);
      for(int i = 0; i < nbl-3;i++){
        fgets(achat1, 50, f);
      }
      fgets(achat1, 50, f);
      fgets(achat2, 50, f);
      fgets(achat3, 50, f);
      printf("\nVoici les derniers produits acheté:\n\n - %s - %s - %s \n\n", achat1, achat2, achat3);
    break;
  }
}


//Fonction permettant de chercher et d'acheter un produit
void Search_and_buy_Produit(int prixtot, char nomU[50], int nb_a){
  char nom[50];
  char nomf[50];
  FILE* f = NULL;
  char product[50];
  char stock[30];
  char numr[30];
  char prix[30];
  char taille[30];
  int stock1, stock2, stockf;
  int numrf;
  int prixf;
  int taille2;
  int choix;
  FILE* f2 = NULL;
  char nom2[50];
  char prenom[50];
  char mdp[50];
  char achat[50];
  
  printf("\nSaisissez le nom du produit que vous recherchez:\n");
  scanf("%s",nom);

  strcpy(nomf, nom);
  strcat(nom, ".txt");

  //Verifie l'accessibilité au fichier
  f = fopen(nom, "r");
  if (f == NULL) {
    printf("Le produit que vous chercher n'existe pas.\n");  
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
    
    //Verifie la taille du produit
    if(strcmp(taille, "petit") == 0){
      taille2 = 1;
    }
    else if(strcmp(taille, "moyen") == 0){
      taille2 = 2;
    }
    else if(strcmp(taille, "grand") == 0){
       taille2 = 4;
    }

    //Demande la quantité voulue par l'utilisateur
    printf("\nSaisissez la quantité pour ce maillot : %s \n- Stock : %d \n- Prix : %d\n\n",nomf, stock1,prixf);
    scanf("%d",&stock2);
    nb_a ++;

    //Verifie que le client entre une quantité valide
    if(stock1<stock2){
      printf("Vous avez saisi une quantité trop élevé");
      stockf = stock1;
    }
    else{
      stockf = stock1 - stock2;
      //Affiche le stock du produit
      printf("\nLe produit %s a maintenant un stock de : %d ;\n",nomf,stockf);

      //Verifie l'accessibilité au fichier
      f2 = fopen(nomU, "r");
      if (f == NULL) {
        printf("Ouverture du fichier impossible.\n");  
      }
      else{
        fgets(nom2, 50, f2);
        fgets(prenom, 50, f2);
        fgets(achat, 50, f2);
        fgets(mdp, 50, f2);
        fgets(achat, 50, f2);
        fclose(f2);

        //Retire les espaces et tabulations créer par le fichier
        if((achat[strlen(achat) - 1] =='\n')||achat[strlen(achat) - 1] ==' '){
          achat[strlen(achat) - 1] = '\0';
        }

        if(strcmp(achat, "Pasdachat") == 0){
          //Verifie accessibilité au fichier
          f2 = fopen(nomU, "w");
          if (f == NULL) {
            printf("Ouverture du fichier impossible.\n");  
          }
          else{
            fprintf(f2, "%s", nom2);
            fprintf(f2, "%s", prenom);
            fprintf(f2, "%s\n", nomU);
            fprintf(f2, "%s", mdp);
            fclose(f2);
          }
        }
        //Verifie accessibilité au fichier
        f2 = fopen(nomU, "a");
        if (f2 == NULL) {
        printf("Ouverture du fichier impossible.\n");  
        }
        else{
          fprintf(f2, "%s\n", nomf);
        }
        fclose(f2);
      }
    }  
      
    //Remet les valeurs du produit dans son fichier
    f = fopen(nom, "w");
    fprintf(f, "%s \n",nomf);
    fprintf(f, "%d \n",numrf);
    fprintf(f, "%d \n",stockf);
    fprintf(f, "%d \n",prixf);
    fprintf(f, "%s",taille);
    fclose(f);

    //Met a jour le prix total
    prixtot += prixf * stock2;
    
    printf("\nVoulez vous achetez un autre article: (1 pour oui)(2 pour non):\n");
    scanf("%d",&choix);
    
    if(choix==1){
      Search_and_buy_Produit(prixtot, nomU, nb_a);
    }
    else if(choix==2){
      printf("\nLe Prix total de l'achat est : %d \n\n",prixtot);
      printf("Retour à l'acceuil...\n\n");
    }
    else{
      printf("Erreur de saisie...");
      exit(1);
    }
  }
}


// Fonction qui permet supprimer un client
void delete_customer(){
  char file[30];

  printf("\nVous allez supprimer votre compte\n");
  printf("\nEntrez votre nom d'utilisateur : ");
  scanf("%s",file);
    
  if (remove(file) == 0){
    printf("\nVotre compte a été supprimé avec succès.\n");
  }    
  else{    
    printf("Impossible de supprimer le fichier client\n");
    perror("Erreur");    
  }
}


//Fonction affiche l'acceuil
void home(char nom[50]){
  int choix,choixA,prixtot = 0;
  int nb_a = 0;
  FILE* f = NULL;
  char str[50];

  //Verifie accessibilité au fichier
  f = fopen(nom, "r");
  if (f == NULL) {
    printf("Le produit que vous chercher n'existe pas.\n");  
  }
  else{
    while(fgets(str, 50, f) != NULL){
      nb_a++;
    }
    nb_a -= 4;
  }
  fclose(f);
  
  printf("################################ \n\n");
  printf("            ACCEUIL                \n\n");

  Purchases(nom, nb_a);
  
  printf("Appuyer sur:\n\n 1 - Recherche/Achat d'un maillot\n\n 2 - Supprimer votre compte\n\n 3 - Deconnexion\n\n");

  //Verifie l'entree utilisateur
  if(scanf("%d",&choix) != 1){
    printf("Choix invalide. Entrez un entier.\n\n");

    //Vide le flux d'entrée
    int e;
    while((e = getchar()) != '\n' && e != EOF){}
  }
    
  switch(choix){
    case 1:
      Search_and_buy_Produit(prixtot,nom,nb_a);
      home(nom);
      break;
    
    case 2:
      delete_customer();
      printf("\nPassez une bonne journée, au revoir ! \n");
      break;
    
    case 3:
      printf("\n< Vous êtes déconnecté >\n");
      printf("\nPassez une bonne journée, au revoir ! \n");
      break;
    
    default :
      printf("< Erreur de saisie... >\n\n");
      home(nom);
      break;
    }
  }
  

// Mode Achat
void Buy(){
  int choix1;
  char nom[50];

  printf("     CONNEXION/INSCRIPTION     \n\n");

  printf("Appuyer sur:\n\n 1 - Connexion \n\n 2 - Inscription \n\n 3 - Quitter\n\n");

  //Verifie l'entree utilisateur
  if(scanf("%d",&choix1) != 1){
    printf("Choix invalide. Entrez un entier.\n\n");

    //Vide le flux d'entrée
    int e;
    while((e = getchar()) != '\n' && e != EOF){}
  }
    

  switch(choix1){
    case 1 :
      strcpy(nom, login());
      home(nom);
      break;
      
    case 2 :
      printf("\nVous allez créer votre compte\n\n");
      Customer client = create_customer();
      FILE* fichierclient = FilesCustomers(client);
      printf("\nVotre compte est créer vous devez vous reconnecter pour y accéder\n\n");
      break;

    case 3:
      printf("\nPassez une bonne journée, au revoir ! \n");
      break;
    
    default :
      printf("< Erreur de saisie... >\n\n");
      Buy();
      break;
  }
}