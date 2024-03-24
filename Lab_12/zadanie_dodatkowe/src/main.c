#include <stdlib.h>
#include <stdio.h>
#define tekst_wieloliniowy "tekst_wieloliniowy.h"
#include tekst_wieloliniowy

int main( void )
{

  // podstawowa struktura danych do przechowywania tekstu
  char tekst_wieloliniowy_tab_2D[MAX_N_L][MAX_DL_L]; 

  int zakres = MAX_DL_L - 1; // w napisie jako tablicy znaków miejsce na \0
  int dlugosc_linii[MAX_N_L]; // tablica do przechowywania długości linii tekstu

  // wczytanie i drukowanie MAX_N_L pojedynczych linii
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    char* linia = tekst_wieloliniowy_tab_2D[nr_linii];
    dlugosc_linii[nr_linii] = wczytaj_linie(linia, zakres);
    wydrukuj_linie(linia, dlugosc_linii[nr_linii]);
  }

  printf("Rozmiar struktury danych (tablica 2D):\t\t %lu B\n",
	 sizeof(tekst_wieloliniowy_tab_2D) );

  // 4. nowa struktura danych
  // a) definicja
  char* tekst_wieloliniowy_tab_wsk[MAX_N_L] = {NULL};

  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii
  // wczytanie i drukowanie MAX_N_L pojedynczych linii
  
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    tekst_wieloliniowy_tab_wsk[nr_linii] = malloc( MAX_DL_L*sizeof(char));
    dlugosc_linii[nr_linii] = wczytaj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], dlugosc_linii[nr_linii]);
    
  }


  int rozmiar_str_danych = sizeof(tekst_wieloliniowy_tab_wsk);
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    rozmiar_str_danych += MAX_DL_L*sizeof(char);
    // dla wersji dynamicznej alokacji linii w nowej funkcji wczytaj_linie_dyn:
    // rozmiar_str_danych += dlugosc_linii[nr_linii]*sizeof(char);
  }
  printf("Rozmiar struktury danych (tablica wskaźników):\t %d B\n", rozmiar_str_danych);
  
  // 6. nowa struktura danych (typ struktury (p.5) - definicja na początku pliku)
  // a) definicja tablicy struktur 
  //    (mozna użyć notacji z typedef lub bez)
  struct linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];
  //linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];
 
  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii
  
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    
    tekst_wieloliniowy_tab_str[nr_linii].znaki = malloc( MAX_DL_L*sizeof(char)); 
    dlugosc_linii[nr_linii] = wczytaj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, dlugosc_linii[nr_linii]);
    
  }
  

  rozmiar_str_danych = sizeof(tekst_wieloliniowy_tab_str);
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    rozmiar_str_danych += MAX_DL_L*sizeof(char);
    //rozmiar_str_danych += .....dlugosc_linii*sizeof(char);
  }
  printf("Rozmiar struktury danych (tablica struktur):\t %d B\n", rozmiar_str_danych);
  
  
  
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    free (tekst_wieloliniowy_tab_wsk[nr_linii]);
    free (tekst_wieloliniowy_tab_str[nr_linii].znaki);
  }
  
}
