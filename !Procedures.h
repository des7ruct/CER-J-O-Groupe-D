void espacements_menus() {
  /*
  Protocole permettant d'afficher des espaces dans la console entre les choix utilisateurs
  afin de mieux différencier les menus entre eux.
  */

  // Variables

  int indice ;


  // Code

  for ( indice = 0 ; indice < 20 ; indice++ ) {
    printf( " \n " ) ;
  }
}



void constructeur_liste_entrainement() {
  /*
  Protocole initialisant la liste de tout les entrainements de tout les athlètes.
  */

  // Variables

  FILE* fichier = NULL ;
  int indice ;
  int indice_bis ;
  int indice_ter ;
  int champ = 0 ;
  char temp ;
  char temp_bis[6] ;
  int fin_du_fichier ;


  // Code

  for ( indice=1 ; indice <= NOMBRE_ATHLETES ; indice++ ) {
    printf( "\n" ) ;
    printf( "%s \n", TABLEAU_ATHLETES[indice] ) ;
    printf("Ath Epr   J     M     A     Heu   Min   Sec   Cent  PosRelais") ;
    printf( "\n" ) ;
    
    fichier = fopen( TABLEAU_ATHLETES[indice], "r" ) ;
    fin_du_fichier = 0 ;

    if (fichier == NULL) {
      printf( "Ouverture du fichier impossible \n" ) ;
      exit( 1 ) ;
    }

    while ( fin_du_fichier != 1 ) {
      for ( indice_ter=0 ; indice_ter < 6 ; indice_ter++ ) {
        temp_bis[indice_ter] = ' ' ;
      }

      temp_bis[0] = 'a' ;
      indice_bis = 0 ;
      temp = 0 ;

      while ( (temp != 32) && (indice_bis < 5) && (fin_du_fichier != 1) ) {
        temp = fgetc( fichier ) ;

        if ( temp == EOF ) {
          fin_du_fichier = 1 ;
        }

        if ( (temp != 32) && ( fin_du_fichier != 1 ) ) {
          temp_bis[indice_bis] = temp ;
          indice_bis++ ;
        }
      }
      
      if ( temp_bis[0] != 'a' ) {
        printf( "%s", temp_bis ) ;
      }
    }

    fclose( fichier ) ;
  }
}



void menu_principal() {
  /*
  Protocole servant de menu principal au programme :
    - permet d'accéder au menu des entrainements
    - permet d'accéder aux statistiques
    - permet de quitter le programme
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n MENU PRINCIPAL \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Afficher Le Menu Des Entrainements \n" ) ;
  /*
  printf( " \n " ) ;
  printf( "\n 2 ----- Afficher Le Menu Des Statistiques \n" ) ;
  */
  printf( " \n " ) ;
  printf( "\n 2 ----- Quitter Le Programme \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 2 ) ;

  if ( choix == 1 ) {
    menu_entrainements() ;
  }
  /*
  else if ( choix == 2 ) {
    menu_statistiques() ;
  }
  */
}



void menu_entrainements() {
  /*
  Protocole servant de menu d'entrainement au programme :
    - permet d'accéder au choix de l'affichage de l'historique d'entrainement
    - permet d'ajouter un entrainement
    - permet de retourner au menu principal
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n MENU ENTRAINEMENTS \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Afficher L'Historique Des Entrainements \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Ajouter Un Entrainement \n" ) ;

  printf( " \n " ) ;
  printf( "\n 3 ----- Retourner Au Menu Principal \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 3 ) ;

  if ( choix == 1 ) {
    choix_historique_entrainements() ;
  }

  else if ( choix == 2 ) {
    nouvel_entrainement() ;
  }

  else {
    menu_principal() ;
  }
}



void choix_historique_entrainements() {
  /*
  Protocole permettant de choisir l'affichage de l'historique des entrainements :
    - permet d'accéder à l'historique des entrainements triés par épreuve
    - permet d'accéder à l'historique des entrainements triés par date
    - permet d'accéder à l'historique des entrainements triés par athlète
    - permet de retourner au menu des entrainements
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n CHOIX DU TRI DE L'HISTORIQUE \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;
  /*
  printf( " \n " ) ;
  printf( "\n 1 ----- Trier Par Epreuve \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Trier Par Date \n" ) ;
  */
  printf( " \n " ) ;
  printf( "\n 1 ----- Trier Par Athlète \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Retourner Au Menu Des Entrainements \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 2 ) ;

  if ( choix == 1 ) {
    historique_entrainements( 1 ) ;
  }
  /*
  else if ( choix == 2 ) {
    historique_entrainements( 2 ) ;
  }

  else if ( choix == 3 ) {
    historique_entrainements( 3 ) ;
  }
  */
  else {
    menu_entrainements() ;
  }
}



void affichage_liste( int* tableau, int choix ) {
  /*
  Protocole permettant d'afficher une page de liste d'entrainements.
    - 1 trier par épreuve
    - 2 trier par date
    - 3 trier par athlète
  */
  /*
  // Variables
 
  int indice ;
  

  // Code
  if ( choix == 1 ) {
    for ( indice = 0 ; tableau[indice] != '\0' ; indice += 10 ) {
      printf( "%s %s %d/%d/%d %dh:%dm:%ds:%dc position relais (0 = pas de relais) : %d ", TABLEAU_EPREUVES[tableau[indice]], TABLEAU_ATHLETES[tableau[indice+1]], tableau[indice+2], tableau[indice+3], tableau[indice+4], tableau[indice+5], tableau[indice+6], tableau[indice+7], tableau[indice+8], tableau[indice+9] ) ;
    }
  }

  else if ( choix == 2 ) {
    for ( indice = 0 ; tableau[indice] != '\0' ; indice += 10 ) {
      printf( "%d/%d/%d %s %s %dh:%dm:%ds:%dc position relais (0 = pas de relais) : %d ", tableau[indice], tableau[indice+1], tableau[indice+2], TABLEAU_ATHLETES[tableau[indice+3]], TABLEAU_EPREUVES[tableau[indice+4]], tableau[indice+5], tableau[indice+6], tableau[indice+7], tableau[indice+8], tableau[indice+9] ) ;
    }
  }

  else {
    for ( indice = 0 ; tableau[indice] != '\0' ; indice += 10 ) {
      printf( "%s %s %d/%d/%d %dh:%dm:%ds:%dc position relais (0 = pas de relais) : %d ", TABLEAU_ATHLETES[tableau[indice]], TABLEAU_EPREUVES[tableau[indice+1]], tableau[indice+2], tableau[indice+3], tableau[indice+4], tableau[indice+5], tableau[indice+6], tableau[indice+7], tableau[indice+8], tableau[indice+9] ) ;
    }
  }
  */
}



void historique_entrainements( int choix_tris ) {
  /*
  Protocole d'affichage de l'historique, prenant un entier :
    - affiche l'historique par épreuve, date, ou athlète dépendant de choix_tris
    - permet de naviguer entre les différentes pages
    - permet de retourner au choix de l'affichage de l'historique d'entrainements
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n HISTORIQUE_ENTRAINEMENTS \n" ) ;
  printf( " \n " ) ;
  
  /*
  affichage_liste( (tri_entrainements(choix_tris)), choix_tris ) ;
  */

  constructeur_liste_entrainement() ;
  
  printf( " \n " ) ;
  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Retourner Au Choix Du Tri De L'Historique \n" ) ;

  printf( "\n 2 ----- Quitter Le Programme \n" ) ;

  printf( " \n " ) ;
  
  choix = choix_securise( 1, 2 ) ;
  
  if ( choix == 1 ) {
    choix_historique_entrainements() ;
  }
}



void nouvel_entrainement() {
  /*
  Protocole d'ajout d'entrainement :
    - permet de choisir un athlète et un type d'entrainement, de saisir la date et la performance à l'entrainement
    - permet d'annuler l'opération et de retourner au menu des entrainements
  */

  // Variables

  Entrainement entrainement ;
  FILE* fichier = NULL ;
  int choix = 0 ;


  // Code
  entrainement.athlete = choix_tableau( &TABLEAU_ATHLETES ) ;

  if ( entrainement.athlete == 0 ) {
    menu_entrainements() ;
  }

  else {
    entrainement.epreuve = choix_tableau( &TABLEAU_EPREUVES ) ;
    entrainement.position_relais = 0 ;

    if ( entrainement.epreuve == 0 ) {
      menu_entrainements() ;
    }    

    else if ( entrainement.epreuve == 5 ) {
      entrainement.position_relais = saisie_nombre( "POSITION RELAIS", 1, 4 ) ;
      
      if ( entrainement.position_relais == -1 ) {
        menu_entrainements() ;
      }    
    }

    if ( entrainement.epreuve != 0 ) {
      entrainement.date = constructeur_date() ;

      if ( (entrainement.date.jour == -1) || (entrainement.date.mois == -1) || (entrainement.date.annee == -1) ) {
        menu_entrainements() ;
      }

      else {
        entrainement.performance = constructeur_performance() ;

        if ( (entrainement.performance.heure == -1) || (entrainement.performance.minute == -1) || (entrainement.performance.seconde == -1) || (entrainement.performance.centiseconde == -1) ) {
          menu_entrainements() ;
        }

        else {
          fichier = fopen( TABLEAU_ATHLETES[entrainement.athlete], "a" ) ;
          
          if (fichier == NULL) {
            printf( "Ouverture du fichier impossible \n" ) ;
            exit( 1 ) ;
          }

          fprintf( fichier, "%d %d %d %d %d %d %d %d %d %d\n", entrainement.athlete, entrainement.epreuve, entrainement.date.jour, entrainement.date.mois, entrainement.date.annee, entrainement.performance.heure, entrainement.performance.minute, entrainement.performance.seconde, entrainement.performance.centiseconde, entrainement.position_relais ) ;
          fclose( fichier ) ;

          espacements_menus() ;
          espacements_menus() ;
          
          printf("L'entrainement a été ajouté, veuillez saisir votre choix : \n") ;
         
          printf( " \n " ) ;
          printf( "\n 1 ----- Retourner Au Menu Des Entrainements \n" ) ;

          printf( " \n " ) ;
          printf( "\n 2 ----- Quitter Le Programme \n" ) ;

          espacements_menus() ;

          choix = choix_securise( 1, 2 ) ;

          if ( choix == 1 ) {
            menu_entrainements() ;
          }
        }
      }
    }
  }
}



void menu_statistiques() {
  /*
  Protocole servant de menu de statistiques au programme :
    - permet d'accéder aux fiches de performances des athlètes
    - permet d'observer les progrès des athlète
    - permet d'afficher qui envoyer au J-O
    - permet de retourner au menu principal
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n MENU STATISTIQUES \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Accéder Aux Fiches De Performances \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Observer Les Progrès Des Athlètes \n" ) ;

  printf( " \n " ) ;
  printf( "\n 3 ----- Afficher Qui Envoyer Aux J-O \n" ) ;

  printf( " \n " ) ;
  printf( "\n 4 ----- Retourner Au Menu Principal \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 4 ) ;

  if ( choix == 1 ) {
    fiches_performances() ;
  }

  else if ( choix == 2 ) {
    progres_athletes() ;
  }

  else if ( choix == 3 ) {
    envoie_au_jo() ;
  }

  else {
    menu_principal() ;
  }
}



void fiches_performances() {
  /*
  Protocole affichant la fiche de performance :
    - permet d'afficher le meilleur temps, le pire temps, et le temps moyen d'un athlète à une
      épreuve
    - permet de retourner au menu des statistiques
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n FICHES PERFORMANCES \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Afficher La Fiche D'Un Athlète \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Retourner Au Menu Des Statistiques \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 2 ) ;

  if ( choix == 1 ) {
    //fiche_athlete() ;
  }

  else if ( choix == 2 ) {
    menu_statistiques() ;
  }
}



void progres_athletes() {
  /*
  Protocole affichant les progrès d'un athlète :
    - permet d'afficher la différence de temps d'un athlète pour une même épreuve entre deux 
      dates
    - permet de retourner au menu des statistiques
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n PROGRES ATHLETES \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Afficher Les Progrès D'Un Athlète \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Retourner Au Menu Des Statistiques \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 2 ) ;

  if ( choix == 1 ) {
    //progres_athlete() ;
  }

  else if ( choix == 2 ) {
    menu_statistiques() ;
  }  
}



void envoie_au_jo() {
  /*
  Protocole affichant qui envoyer au Jeux-Olympiques :
    - permet d'afficher les 3 meilleurs athlètes avec les 3 meilleurs temps moyens pour une 
      épreuve donnée
    - permet de retourner au menu des statistiques
  */

  // Variables

  int choix = 0 ;


  // Code

  espacements_menus() ;
  espacements_menus() ;

  printf( "\n ENVOIE AU J-O \n" ) ;

  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;

  printf( " \n " ) ;
  printf( "\n 1 ----- Choisir L'Epreuve Pour Laquelle Afficher Les 3 Meilleurs Athlètes \n" ) ;

  printf( " \n " ) ;
  printf( "\n 2 ----- Retourner Au Menu Des Statistiques \n" ) ;

  espacements_menus() ;

  choix = choix_securise( 1, 2 ) ;

  if ( choix == 1 ) {
    // meilleurs_temps() ;
  }

  else if ( choix == 2 ) {
    menu_statistiques() ;
  }  
}
