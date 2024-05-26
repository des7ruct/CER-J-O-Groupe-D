  //////////////////
 // IMPORTATIONS //
//////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



  //////////////////
 // DECLARATIONS //
//////////////////

// Structures

typedef struct {
  /*
  Structure définissant une date composée de trois entiers, un jour, un mois, et une année.
  */

  int jour ;
  int mois ;
  int annee ;

} Date ;


typedef struct {
  /*
  Structure définissant une performance composée de quatre entiers, une heure, une minute, une seconde, 
  et une centiseconde.
  */

  int heure ;
  int minute ;
  int seconde ;
  int centiseconde ;

} Performance ;


typedef struct {
  /*
  Structure définissant un entrainement composée d'une date, d'une performance, et de 3 entiers :
  l'indice de l'athlète dans le tableau, l'indice de l'entrainement dans le tableau, et la position lors du relais.
  */

  int athlete ;
  Date date ;
  int epreuve ;
  Performance performance ;
  int position_relais ;

} Entrainement ;



// Fonctions

void espacements_menus() ;
void menu_principal() ;
void menu_entrainements() ;
void choix_historique_entrainements() ;
void historique_entrainements( int choix_tris ) ;
void nouvel_entrainement() ;
void menu_statistiques() ;
void fiches_performances() ;
void progres_athletes() ;
void envoie_au_jo() ;
int choix_securise( int minimum, int maximum ) ;
int saisie_nombre( char* nom_saisie, int minimum, int maximum ) ;
int choix_tableau( char* tableau[] ) ;
Date constructeur_date() ;
Performance constructeur_performance() ;
int* tri_entrainements( int choix ) ;
void constructeur_liste_entrainement() ;
void affichage_liste( int* tableau_entrainements, int choix ) ;



// Constantes

#define NOMBRE_ATHLETES 10
#define NOMBRE_EPREUVES 5
#define NOMBRE_ENTRAINEMENTS_MAX 1000

const char * TABLEAU_ATHLETES[] = { "ATHLETES", "Alice FINOT", "Clémence BERETTA", "Cyréna SAMBA-MAYELA", "Gémima JOSEPH", "Laëticia BAPTE", "Mekdes WOLDU", "Méline ROLLIN", "Mélody JULIEN", "Pauline STEY", "Rénelle LAMOTE", NULL } ;// classés par ordre alphabétique

const char * TABLEAU_EPREUVES[] = { "EPREUVES", "100m", "400m", "5000m", "Marathon", "Relais 4x400m", NULL } ;