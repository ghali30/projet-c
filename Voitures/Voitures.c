#include"Voitures.h"
#include <stdio.h>
#include <stdlib.h>
void afficherMenu() {
    printf("\n===================================\n");
    printf(" \033[1;36m\t  MENU PRINCIPAL \033[0m \n");
    printf("===================================\n");
    printf("1. Afficher les voitures \n");
    printf("2. Rechercher une voiture \n");
    printf("3. Trier les voitures par prix \n");
    printf("4. Trier les voitures par marque \n");
    printf("0. Quitter\n");
    printf("===================================\n");
    printf("Entrez votre choix (0 pour quitter) :  ");
   scanf("%d",&CHOIX);
    printf("===================================\n");

    printf("\n\n");
    choix(CHOIX);
}
void afficherMD() {
    printf("===================================\n");
    printf(" \033[1;36m\t  MENU PRINCIPAL \033[0m \n");
    printf("===================================\n");
    printf("1. Afficher les voitures \n");
    printf("2. Rechercher une voiture \n");
    printf("3. Trier les voitures par prix  \n");
    printf("4. Trier les voitures par marque \n");
    printf("5. Modifier une voiture \n");
    printf("6. Supprimer une voiture\n");
    printf("7. Ajouter une voiture\n");
    printf("0. Quitter\n");
    printf("===================================\n");
    printf("Entrez votre choix (0 pour quitter) :  ");
   scanf("%d",&CHOIX);
    printf("===================================\n");

    printf("\n\n");
    choix(CHOIX);
}

void Ajouter() {
     char c[10];
     int a,b;
     printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Ajouter une voiture ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
     scanf("%s",c);
    if(strcmp(c,"menu")==0){
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    }else{
        FILE*f=fopen("Data.csv","a");
        if(f==NULL){
            printf("erreur");
            exit(1);
        }
    voiture nouvelle_voiture;
    b=getchar();
    printf("Entrez le nom d'utilisateur :");
    gets(nouvelle_voiture.nom_utilisateur);
    printf("entrer l 'id :");
    scanf("%ld",&nouvelle_voiture.id);
    b=getchar();
    printf("Entrez la marque : ");
    gets(nouvelle_voiture.marque);
    printf("Entrez le modele : ");
    gets(nouvelle_voiture.model);
    printf("Entrez le type de carburant (0: essence, 1: diesel, 2: hybride, 3: electrique) : ");
    int carburant;
    scanf("%d",&carburant);
    nouvelle_voiture.ca =carburant;
    printf("Entrez le nombre de places : ");
    scanf("%d",&nouvelle_voiture.nbr_place);
    printf("Entrez le type de transmission (0: automatique, 1: manuelle) : ");
    int transmission;
    scanf("%d",&transmission);
    nouvelle_voiture.tr=transmission;
    printf("Entrez le prix de location par jour en dhs : ");
    scanf("%f",&nouvelle_voiture.prix_j);
    printf("Donner l'etat de disponibilite (1: disponible, 0: non_disponible):");
    int disponibilite;
    scanf("%d",&disponibilite);
    nouvelle_voiture.di=disponibilite;
    fprintf(f,"%s;%ld;%s;%s;%d;%d;%d;%.2f;%d\n ",nouvelle_voiture.nom_utilisateur,nouvelle_voiture.id,nouvelle_voiture.marque,nouvelle_voiture.model,nouvelle_voiture.ca,nouvelle_voiture.nbr_place,nouvelle_voiture.tr,nouvelle_voiture.prix_j,nouvelle_voiture.di);
    printf("La voiture est ajoutee avec succes. \n");
    printf("\033[30;47m Pour ressayer appuyer sur (0) pour effectuer une autre operation appuyer sur (1) pour quitter appuyer sur (2) : \033[0m");
    scanf("%d",&a);
        if(a==0){
            Ajouter();
        }else if(a==1){
            if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        }else{
              printf("\n Merci d'avoir utiliser le programme. A bientot !\n");
            exit(1);
             }
         fclose(f);           }
    }



void Modifier(){
     char c[10];
     int i=1;
  printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Modifier une voiture ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
   scanf("%s",c);
    if(strcmp(c,"menu")==0){
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    }
    else{
        long ID;
    printf("Entrez l'ID de la voiture a modifier : ");
    scanf("%ld", &ID);
    FILE *f = fopen("Data.csv", "r");
    FILE *ft=fopen("temp.csv","w");

    if (f == NULL || ft == NULL) {
        printf("Erreur \n");
        exit(1);
    }
    int b;

    voiture V;
    int found = 0;
while (fscanf(f, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",V.nom_utilisateur, &V.id, V.marque, V.model,&V.ca, &V.nbr_place, &V.tr, &V.prix_j, &V.di) != EOF) {
        if (V.id == ID) {
            found = 1;
            printf("Entrez les nouvelles informations :\n");

            printf("Nom d'utilisateur : ");
            scanf(" %[^\n]", V.nom_utilisateur);

            printf("Marque : ");
            scanf(" %[^\n]", V.marque);

            printf("Modèle : ");
            scanf(" %[^\n]", V.model);

            printf("Type de carburant (0: essence, 1: diesel, 2: hybride, 3: électrique) : ");
            scanf("%d", &V.ca);

            printf("Nombre de places : ");
            scanf("%d", &V.nbr_place);

            printf("Type de transmission (0: automatique, 1: manuelle) : ");
            scanf("%d", &V.tr);

            printf("Prix par jour : ");
            scanf("%f", &V.prix_j);

            printf("Disponibilite (0: non disponible, 1: disponible) : ");
            scanf("%d", &V.di);
        }
        fprintf(ft, "%s;%ld;%s;%s;%d;%d;%d;%.2f;%d\n",V.nom_utilisateur, V.id, V.marque, V.model,V.ca, V.nbr_place, V.tr, V.prix_j, V.di);
    }

    fclose(f);
    fclose(ft);

    if (found) {
        remove("Data.csv");
        rename("temp.csv", "Data.csv");
        printf("La voiture a ete modifiee avec succes.\n");
    } else {
        remove("temp.csv");
        printf("Voiture introuvable.\n");
    }
    int a;
 printf(" \033[30;47mPour reessayer appuyez sur (0), pour effectuer une autre operation appuyez sur (1), pour quitter appuyez sur (2) : \033[0m");    scanf("%d",&a);
        if(a==0){
            Modifier();
        }else if(a==1){
             if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        }else{
              printf("\n Merci d'avoir utiliser le programme. A bientot !\n");
             exit(1);
             }
}
    }


void Supprimer() {
    char c[10];
   printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Supprimer une voiture ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
    scanf("%s", c);

    if (strcmp(c, "menu") == 0) {
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    } else {
        long ID;
        printf("Entrez l'ID de la voiture a supprimer : ");
        scanf("%ld", &ID);

        FILE *f = fopen("Data.csv", "r");
        FILE *ft = fopen("temp.csv", "w");
        if (f == NULL || ft == NULL) {
            printf("Erreur.\n");
           exit(1);
        }

        voiture v;
        int found = 0;

        while (fscanf(f, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",v.nom_utilisateur,&v.id,v.marque,v.model,&v.ca,&v.nbr_place,&v.tr,&v.prix_j,&v.di)!=EOF) {
            if (v.id == ID) {
                found = 1;
                printf("\nVoiture avec ID %ld supprime avec succes.\n",ID);
            } else {
                fprintf(ft, "%s;%ld;%s;%s;%d;%d;%d;%.2f;%d\n",v.nom_utilisateur,v.id,v.marque,v.model,v.ca,v.nbr_place,v.tr,v.prix_j,v.di);
            }
        }

        fclose(f);
        fclose(ft);

        if (found) {
            remove("Data.csv");
            rename("temp.csv", "Data.csv");
        } else {
            remove("temp.csv");
            printf("Voiture avec ID %ld non trouvée.\n", ID);
        }

        int a;
 printf(" \033[30;47mPour reessayer appuyez sur (0), pour effectuer une autre operation appuyez sur (1), pour quitter appuyez sur (2) : \033[0m");    scanf("%d",&a);
        if(a==0){
            Supprimer();
        }else if(a==1){
             if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        }else{
              printf("\n Merci d'avoir utiliser le programme. A bientot !\n");
            exit(1);
    }
}
}


void Afficher() {
       char c[10];

   printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Afficher les voitures ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
   scanf("%s",c);
    if(strcmp(c,"menu")==0){
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    }
    else{
            FILE *f1=fopen("Data.csv","r");
            if(f1==NULL){
            printf("erreur");
             exit(1);
        }
            voiture V;
            int i=1;
             printf("La liste des voitures disponibles : \n\n");
      while (fscanf(f1, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",V.nom_utilisateur,&V.id,V.marque,V.model,&V.ca,&V.nbr_place,&V.tr,&V.prix_j,&V.di)!=EOF){
            if(V.di == 1){
                printf("\033[1;34mVOITURE      %d    :\033[0m \n",i);

                printf("Le nom de l'utilisateur est : %s \n",V.nom_utilisateur);
                printf("L'id du voiture         est : %ld \n",V.id);
                printf("La marque de la voiture est : %s \n",V.marque);
                printf("Le modele de la voiture est : %s \n",V.model);
                printf("Nombre de places        est : %d \n",V.nbr_place);
                printf("Carburant                   :");
                switch (V.ca) {
        case 0: printf(" Essence   \n"); break;
        case 1: printf(" Diesel    \n"); break;
        case 2: printf(" Hybride   \n"); break;
        case 3: printf(" Electrique\n"); break;
    }
                printf("Transmission                :");
                  switch (V.tr) {
        case 0: printf(" Automatique\n"); break;
        case 1: printf(" Manuelle\n"); break;
    }
         printf("Le prix par jour        est : %.2f\n",V.prix_j);

         i++;
    }
    }fclose(f1);
    int a;
 printf(" \033[30;47mPour reessayer appuyez sur (0), pour effectuer une autre operation appuyez sur (1), pour quitter appuyez sur (2) : \033[0m");    scanf("%d",&a);
        if(a==0){
            Afficher();
        }else if(a==1){
             if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        }else{
              printf("\n Merci d'avoir utiliser le programme. A bientot !\n");
            return 0;
}
    }
}
void Rechercher() {
       char c[10];
   printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Rechercher une voiture ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
   scanf("%s",c);
    if(strcmp(c,"menu")==0){
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    }
    else {
        FILE *f = fopen("Data.csv", "r");
        if (f == NULL) {
            printf("Erreur .\n");
            exit (1);
        }

        int choix;
        printf("Choisissez le type de recherche :\n");
        printf("1. Rechercher par ID\n");
        printf("2. Rechercher par marque\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        voiture v;
        int i=0,j=0;
        char m[30];
        long id;
        if (choix==1) {
            printf("Entrez l'ID de la voiture a rechercher : ");
            scanf("%ld",&id);

            while (fscanf(f, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",v.nom_utilisateur,&v.id,v.marque,v.model,&v.ca,&v.nbr_place,&v.tr,&v.prix_j,&v.di)!=EOF){
                if (v.id == id){
                printf("=======================================\n");
                printf("Le nom de l'utilisateur est : %s \n",v.nom_utilisateur);
                printf("L'id du voiture         est : %ld \n",v.id);
                printf("La marque de la voiture est : %s \n",v.marque);
                printf("Le modele de la voiture est : %s \n",v.model);
                printf("Nombre de places        est : %d \n",v.nbr_place);
                printf("Carburant                   :");
                switch (v.ca) {
        case 0: printf(" Essence   \n"); break;
        case 1: printf(" Diesel    \n"); break;
        case 2: printf(" Hybride   \n"); break;
        case 3: printf(" Electrique\n"); break;
    }
                printf("Transmission                :");
                  switch (v.tr) {
        case 0: printf(" Automatique\n"); break;
        case 1: printf(" Manuelle\n"); break;
    }
         printf("Le prix par jour        est : %.2f\n",v.prix_j);
                  printf("Disponibilite              :");
                  switch (v.di) {
        case 0: printf(" non disponible\n"); break;
        case 1: printf(" disponible\n"); break;
    }
                printf("=========================================\n\n");
                    i=1;
                    break;
                }
            }
            if(i==0) {
            printf("Voiture avec l'ID : %ld non trouver .\n",id);
        }
        } else if (choix==2){

            printf("Entrez la marque de la voiture a rechercher : ");
            scanf("%s",m);
            rewind(stdin);

            while (fscanf(f, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",v.nom_utilisateur,&v.id,v.marque,v.model,&v.ca,&v.nbr_place,&v.tr,&v.prix_j,&v.di)!=EOF){
                if (strcmp(v.marque,m)==0){
                printf("=======================================\n");
                printf("Le nom de l'utilisateur est : %s \n",v.nom_utilisateur);
                printf("L'id du voiture         est : %ld \n",v.id);
                printf("La marque de la voiture est : %s \n",v.marque);
                printf("Le modele de la voiture est : %s \n",v.model);
                printf("Nombre de places        est : %d \n",v.nbr_place);
                printf("Carburant                   :");
                switch (v.ca) {
        case 0: printf(" Essence   \n"); break;
        case 1: printf(" Diesel    \n"); break;
        case 2: printf(" Hybride   \n"); break;
        case 3: printf(" Electrique\n"); break;
    }
                printf("Transmission                :");
                  switch (v.tr) {
        case 0: printf(" Automatique\n"); break;
        case 1: printf(" Manuelle\n"); break;
    }
         printf("Le prix par jour        est : %.2f\n",v.prix_j);
                printf("Disponibilite                :");
                  switch (v.di) {
        case 0: printf(" non disponible\n"); break;
        case 1: printf(" disponible\n"); break;
    }
                printf("=======================================\n");
                    j=1;
                }
            }
       if(j==0) {
            printf("Voiture avec la marque %s non trouver .\n",m);
                }

        }
        else {
            printf("Choix invalide.\n");
               }

        fclose(f);
        int a;
        printf(" \033[30;47mPour reessayer appuyez sur (0), pour effectuer une autre operation appuyez sur (1), pour quitter appuyez sur (2) : \033[0m");
        scanf("%d", &a);
        if (a==0) {
            Rechercher();
        } else if (a==1) {
             if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        } else {
            printf("\nMerci d'avoir utilise le programme. A bientot !\n");
            exit(1);
        }
    }
}
void Trier_prix(){
         char c[10];
   printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Trier par prix ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
      scanf("%s",c);
    if(strcmp(c,"menu")==0){
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    }
    else {
        FILE *f = fopen("Data.csv", "r");
        if (f == NULL) {
            printf("Erreur .\n");
            exit(1);
        }

        voiture v[100];
        voiture temp;
        int cmp=0,i,j;

while (fscanf(f, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",v[cmp].nom_utilisateur,&v[cmp].id,v[cmp].marque,v[cmp].model,&v[cmp].ca,&v[cmp].nbr_place,&v[cmp].tr,&v[cmp].prix_j,&v[cmp].di)!=EOF){
            cmp++;
        }
        fclose(f);
        for (i=0;i<cmp-1;i++) {
            for (j=i+1;j<cmp;j++) {
                if (v[i].prix_j > v[j].prix_j) {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }


        printf("Liste des voitures triees par prix croissant :\n");
        for (int i = 0; i < cmp; i++) {
               printf("\033[1;34mVOITURE      %d    :\033[0m \n",i+1);

                printf("Le nom de l'utilisateur est : %s \n",v[i].nom_utilisateur);
                printf("L'id du voiture         est : %ld \n",v[i].id);
                printf("La marque de la voiture est : %s \n",v[i].marque);
                printf("Le modele de la voiture est : %s \n",v[i].model);
                printf("Nombre de places        est : %d \n",v[i].nbr_place);
                printf("Carburant                   :");
                switch (v[i].ca) {
        case 0: printf(" Essence   \n"); break;
        case 1: printf(" Diesel    \n"); break;
        case 2: printf(" Hybride   \n"); break;
        case 3: printf(" Electrique\n"); break;
    }
                printf("Transmission                :");
                  switch (v[i].tr) {
        case 0: printf(" Automatique\n"); break;
        case 1: printf(" Manuelle\n"); break;
    }
         printf("Le prix par jour        est : %.2f\n",v[i].prix_j);
                  printf("Disponibilite              :");
                  switch (v[i].di) {
        case 0: printf(" non disponible\n"); break;
        case 1: printf(" disponible\n"); break;
    }
        }

        int a;
 printf(" \033[30;47m Pour reessayer appuyez sur (0), pour effectuer une autre operation appuyez sur (1), pour quitter appuyez sur (2) : \033[0m");        scanf("%d", &a);
        if (a == 0) {
            Trier_prix();
        } else if (a == 1) {
            if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        } else {
            printf("\nMerci d'avoir utilise le programme. A bientot !\n");
            exit(1);
        }
    }
}
void Trier_marque(){
          char c[10];
   printf("\n\033[30;47mVous avez choisi l'option 3 : ^^ Trier par marque ^^.\033[0m\n");
   printf("\033[30;47mEnter ^ menu ^ pour aller vers le menu principale (autre pour continuer):\033[0m");
   scanf("%s",c);
    if(strcmp(c,"menu")==0){
         if (ch == 1)
            afficherMenu();
            else
            afficherMD();
    }
    else {
        FILE *f = fopen("Data.csv", "r");
        if (f == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            exit(1);
        }

        voiture v[100];
        voiture temp ;
        int cmp=0;

        while (fscanf(f, " %[^;];%ld;%[^;];%[^;];%d;%d;%d;%f;%d\n",v[cmp].nom_utilisateur,&v[cmp].id,v[cmp].marque,v[cmp].model,&v[cmp].ca,&v[cmp].nbr_place,&v[cmp].tr,&v[cmp].prix_j,&v[cmp].di)!=EOF){
            cmp++;
        }
        fclose(f);

        for (int i=0;i<cmp-1;i++) {
            for (int j = i + 1; j < cmp; j++) {
                if (strcmp(v[i].marque,v[j].marque)>0){
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
        printf("Liste des voitures triees par marque (ordre alphabetique) :\n");
        for (int i=0;i<cmp;i++) {
                printf("\033[1;34mVOITURE      %d    :\033[0m \n",i+1);
                printf("Le nom de l'utilisateur est : %s \n",v[i].nom_utilisateur);
                printf("L'id du voiture         est : %ld \n",v[i].id);
                printf("La marque de la voiture est : %s \n",v[i].marque);
                printf("Le modele de la voiture est : %s \n",v[i].model);
                printf("Nombre de places        est : %d \n",v[i].nbr_place);
                printf("Carburant                   :");
                switch (v[i].ca) {
        case 0: printf(" Essence   \n"); break;
        case 1: printf(" Diesel    \n"); break;
        case 2: printf(" Hybride   \n"); break;
        case 3: printf(" Electrique\n"); break;
    }
                printf("Transmission                :");
                  switch (v[i].tr) {
        case 0: printf(" Automatique\n"); break;
        case 1: printf(" Manuelle\n"); break;
    }
         printf("Le prix par jour        est : %.2f\n",v[i].prix_j);
                  printf("Disponibilite              :");
                  switch (v[i].di) {
        case 0: printf(" non disponible\n"); break;
        case 1: printf(" disponible\n"); break;
    }
        }

        int a;
 printf(" \033[30;47m Pour reessayer appuyez sur (0), pour effectuer une autre operation appuyez sur (1), pour quitter appuyez sur (2) : \033[0m");        scanf("%d", &a);
        if (a == 0) {
            Trier_marque();
        } else if (a == 1) {
             if (ch == 1)
            afficherMenu();
            else
            afficherMD();
        } else {
            printf("\nMerci d'avoir utilise le programme. A bientot !\n");
            return;
        }
    }
}

void choix(int CHOIX){
        switch (CHOIX) {
            case 1:
               Afficher();
                break;
            case 2:
                 Rechercher();
                break;
            case 3:
                 Trier_prix();
                break;
            case 4:
                 Trier_marque();
                break;
            case 5:
               Modifier();
                break;
            case 6:
               Supprimer();
                break;
            case 7:
               Ajouter();
                break;
            case 0:
                printf("\n Merci d'avoir utiliser le programme. A bientot !\n");
                break;
            default:
                printf("\n Choix invalide. Veuillez reessayer.\n");
        }
}
