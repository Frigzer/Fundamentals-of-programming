#include <stdlib.h>
#include <stdio.h>
#define tekst_wieloliniowy "tekst_wieloliniowy.h"
#include tekst_wieloliniowy



// funkcja wczytywania pojedynczej linii ze standardowego wejścia
// Uwaga na przykładowy kontrakt. W zadaniach dodatkowych można rozważyć inne kontrakty
// (może to oznaczac inne działanie funkcji i inne możliwe zwracane wartości)
int wczytaj_linie( // funkcja wypełnia tablicę znaków przekazaną poprzez wskaźnik
		   // wczytując znaki ze standardowego wejścia, bez przekroczenia
		   // maksymalnej liczby znaków przesłanej jako argument max_dlugosc_linii,
		   // umieszczając na końcu tablicy znak końca napisu \0
		   // (maksymalna liczba znaków nie obejmuje znaku końca napisu!)
		   // OUT: funkcja zwraca liczbę wczytanych znaków
		   // (uwaga: jeśli zwrócona liczba jest równa  max_dlugosc_linii
		   //  jest możliwe, że w buforze STDIN zostały jeszcze jakieś znaki,
		   //  co może stanowic problem przy kolejnym wywołaniu funkcji)
		  char* linia,           // IN/OUT: tablica znaków zadana poprzez wskaźnik
		  int max_dlugosc_linii  // IN: maksymalna liczba znaków w linii
		  )
{

  int zakres = max_dlugosc_linii;
  
  printf("\nWpisz zestaw maksymalnie %d znaków zakończony znakiem końca linii \\n\n",
	 zakres);
  
  int znak;
  int i;
  for (i=0; i<zakres && (znak=getchar()) != EOF && znak != '\n'; ++i){
    linia[i] = znak;
  }
  if (znak == '\n') {
    linia[i] = znak;
    ++i;
  }
  linia[i] = '\0'; // od 0 do i - czyli i+1 elementów tablicy
  // co stanie się w dalszej części programu jeśli nie umieścimy \0 w tablicy?
  
  return(i); // liczymy tylko znaki, bez \0 !!!

}

// funkcja drukowania pojedynczej linii jako tablicy znaków i jako napisu
void wydrukuj_linie(
		   char* linia,       // IN: tablica znaków zadana poprzez wskaźnik
		   int dlugosc_linii  // IN: liczba znaków w linii
		   )
{
  
  printf("\nLinia o długości %d wypisana jako tablica znaków:\n", dlugosc_linii);
  for(int i=0; i<dlugosc_linii; i++){
    printf("%c", linia[i]); // założenie: na końcu linii jest \n
  }
  
  printf("Linia o długości %d wypisana jako napis:\n", dlugosc_linii);
  printf("%s", linia);

}

