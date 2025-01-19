#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Voitures.h"


int main() {
     char name[20];
     int id;
     printf("\033[30;47mVous etes client ou developpeur ? ( 1 = client , 2 = developpeur ): \033[0m ");
     scanf("%d",&ch);
     rewind(stdin);
     if(ch == 1){
        printf("Entrer votre nom :");
        gets(name);
        rewind(stdin);
        afficherMenu();
     }
     else if(ch == 2){
     name :
        printf("Entrer votre nom : ");
        gets(name);
        rewind(stdin);
        if(strcmp(name,"Amine")==0 || strcmp(name,"Majd")==0 || strcmp(name,"Houssam")==0 || strcmp(name,"Adam")==0 || strcmp(name,"Yassine")==0){
           id:
               printf("entrer l 'ID :");
               scanf("%d",&id);
               if(id == 2025){
                afficherMD();
            }
            else{
                printf("ID incorrect ressayer .\n");
                goto id;
            }
        }
        else{
            printf("Nom incorrect ressayer . \n");
            goto name;
        }
         }
      else{
        printf("Choix invalide.");
        exit(1);
      }
         return 0;

}
