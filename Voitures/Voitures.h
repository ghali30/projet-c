#pragma once
typedef enum {essence,diesel,hybride,electrique}carburant ;
typedef enum {automatique,manuelle}transmition  ;
typedef enum {non_disponible,disponible}disponibilite;
typedef struct {
	long id;
	char marque[15];
	char nom_utilisateur[25];
	char model[15];
    carburant ca;
	int  nbr_place;
	transmition tr;
	float prix_j;
	disponibilite di ;
}voiture;
void afficherMD();
void afficherMenu();
void Ajouter();
void Supprimer();
void Modifier();
void choix();
void Afficher();
void Trier_prix();
void Trier_marque();
int CHOIX;
int ch;
