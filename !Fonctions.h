int choix_securise( int minimum, int maximum ) {
  /*
  Fonction prenant deux entiers et renvoyant un entier au choix de l'utilisateur
  dans l'intervalle [minimum, maximum].
  */

  // Variables
  
  int choix = minimum - 1;

  
  // Code

  scanf(" %d", &choix) ;
  
  if ( (minimum <= choix) && (choix <= maximum) ) {
      return choix ;
  }

  else {
    while ( ((choix = getchar()) != '\n') && (choix != EOF) ) { }
    
    printf("Erreur, veuillez saisir un entier dans l'intervalle [%d, %d]. \n", minimum, maximum) ;
    
    return choix_securise( minimum, maximum ) ;
  }
}



int saisie_nombre( char nom_saisie[], int minimum, int maximum ) {
  /*
  Fonction permettant d'afficher un menu de saisie, et retourne le nombre choisi.
  */

  // Variables

  int choix ;

  // Code

  espacements_menus() ;
  espacements_menus() ;
      
  printf( "\n SAISIE %s \n", nom_saisie ) ;
  printf( " \n " ) ;
      
  printf("Veuillez saisir votre choix (nombre entre %d et %d), -1 pour annuler l'opération : \n", minimum, maximum) ;
  espacements_menus() ;
  
  choix = choix_securise( -1, maximum ) ;

  while ( (choix < minimum) && (choix > -1) ) {
    printf( "Erreur, le nombre saisi ne doit pas être dans l'intervalle ]-1 , %d[ \n", minimum ) ;
    choix = choix_securise( -1, maximum ) ;
  }

  return choix ;
}



int choix_tableau( char * tableau[] ) {
  /*
  Fonction affichant la liste de tout éléments d'un tableau et laissant l'utilisateur choisir parmis elles.
  */

  // Variables
  
  int choix = 0 ;
  int indice ;

  
  // Code

  espacements_menus() ;
  espacements_menus() ;
  
  printf( " \n " ) ;
  printf( "\n CHOIX %s \n", *tableau ) ;
  
  printf( " \n " ) ;
  printf( "Veuillez saisir votre choix : \n" ) ;
  
  printf( " \n " ) ;
  for ( indice = 1 ; tableau[indice] != NULL ; indice++ ) {
    printf( "\n %d ----- %s \n", indice, tableau[indice] ) ;
  } 
  
  printf( " \n " ) ;
  printf( "\n 0 ----- Annuler L'Opération \n" ) ;
  
  printf( " \n " ) ;
  choix = choix_securise( 0, (indice-1) ) ;

  return choix ;
}



Date constructeur_date() {
  /*
  Fonction permettant de construire une date.
  */
  
  // Variables
  
  Date date ;
  
  
  // Code
  
  date.jour = saisie_nombre( "JOUR", 1, 31 ) ;

  if ( date.jour == -1 ) {
    return date ;
  }

  else {
    date.mois = saisie_nombre( "MOIS", 1, 12 ) ; ;

    if ( date.mois == -1 ) {
      return date ;
    }
    
    else {
      date.annee = saisie_nombre( "ANNEE", 2005, 2024 ) ;
      return date ;
    }    
  }    
}



Performance constructeur_performance() {
  /*
  Fonction permettant de construire une performance.
  */
  
  // Variables
  
  Performance performance ;
  
  
  // Code
  
  performance.heure = saisie_nombre( "HEURE", 0, 5 ) ;

  if ( performance.heure == -1 ) {
    return performance ;
  }

  else {
    performance.minute = saisie_nombre( "MINUTE", 0, 59 ) ; ;

    if ( performance.minute == -1 ) {
      return performance ;
    }
    
    else {
      performance.seconde = saisie_nombre( "SECONDE", 0, 59 ) ;
      
      if ( performance.seconde == -1 ) {
        return performance ;
      }

      else {
        performance.centiseconde = saisie_nombre( "CENTISECONDE", 0, 99 ) ;
        return performance ;
      }
    }    
  }    
}



int* tri_entrainements( int choix ) {
  /*
  Fonction permettant de trier une liste d'entrainement en fonction du choix de l'utilisateur :
    - 1 trier par épreuve
    - 2 trier par date
    - 3 trier par athlète
  */

  // Variables
  /*
  int indice ;
  int indice_bis ;
  int indice_ter = 0 ;
  int* liste_triee = NULL ;
  int* liste_triee_bis = NULL ;
  Date date_max ;
  int* liste_entrainements_totale = NULL ;

  
  // Code
  
  liste_entrainements_totale = malloc( NOMBRE_ENTRAINEMENTS_MAX * 4 ) ;
  constructeur_liste_entrainement( &liste_entrainements_totale ) ;

  for (int i=0 ; liste_entrainements_totale[i] != -1 ;i++){
    printf("%d \n", liste_entrainements_totale[i]) ;
  }
  
  liste_triee = malloc( NOMBRE_ENTRAINEMENTS_MAX * 4 ) ;
  liste_triee_bis = malloc( NOMBRE_ENTRAINEMENTS_MAX * 4 ) ;

  if ( choix == 1 ) {
    for ( indice=0 ; liste_entrainements_totale[indice] != '\0' ; indice += 10 ) {
      liste_triee[indice] = liste_entrainements_totale[indice + 1] ;
      liste_triee[indice + 1] = liste_entrainements_totale[indice] ;

      for ( indice_bis = 2 ; indice_bis < 10 ; indice_bis++ ) {
        liste_triee[indice + indice_bis] = liste_entrainements_totale[indice + indice_bis] ;
      }
    }

    for ( indice_bis = 1 ; indice_bis <= NOMBRE_EPREUVES ; indice_bis++ ) {
      for ( indice = 0 ; liste_triee[indice] != '\0' ; indice += 10 ) {
        if ( liste_triee[indice] == indice_bis ) {
          liste_triee_bis[indice_ter] = liste_triee[indice] ;
          indice_ter++ ;
        }
      }
    }
    
    free( liste_triee_bis ) ;
    free( liste_entrainements_totale ) ;
    return liste_triee_bis ;
  }

  else if ( choix == 2 ) {
    for ( indice=0 ; liste_entrainements_totale[indice] != '\0' ; indice += 10 ) {
      liste_triee[indice] = liste_entrainements_totale[indice + 2] ;
      liste_triee[indice + 1] = liste_entrainements_totale[indice + 3] ;
      liste_triee[indice + 2] = liste_entrainements_totale[indice + 4] ;
      liste_triee[indice + 3] = liste_entrainements_totale[indice + 0] ;
      liste_triee[indice + 4] = liste_entrainements_totale[indice + 1] ;

      for ( indice_bis = 5 ; indice_bis < 10 ; indice_bis++ ) {
        liste_triee[indice + indice_bis] = liste_entrainements_totale[indice + indice_bis] ;
      }
    }

    date_max.jour = 0 ;
    date_max.mois = 0 ;
    date_max.annee = 0 ;

    for ( indice_bis=0 ; liste_triee[indice_bis] != '\0' ; indice_bis += 10 ) {
      for ( indice=0 ; liste_triee[indice] != '\0' ; indice += 10 ) {
        if ( (liste_triee[indice] >= date_max.jour) && (liste_triee[indice] != 0) && (liste_triee[indice+1] >= date_max.mois) && (liste_triee[indice+2] >= date_max.annee) ) {
          date_max.jour = liste_triee[indice] ;
          date_max.mois = liste_triee[indice+1] ;
          date_max.annee = liste_triee[indice+2] ;
          indice_ter = indice ;
        }
      }
      
      liste_triee_bis[indice_bis] = date_max.jour ;
      liste_triee_bis[indice_bis+1] = date_max.mois ;
      liste_triee_bis[indice_bis+2] = date_max.annee ;

      for ( indice=3 ; indice < 10 ; indice++ ) {
        liste_triee_bis[indice_bis + indice] = liste_triee[indice_ter + indice] ;
      }
      
      liste_triee[indice_ter] = 0 ;
    }
    
    free( liste_triee ) ;
    free( liste_entrainements_totale ) ;
    return liste_triee_bis ;
  }

  else {
    free(liste_triee) ;
    free(liste_triee_bis) ;
    return liste_entrainements_totale ;
  }
  */
}