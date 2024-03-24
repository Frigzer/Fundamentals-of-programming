#include <stdio.h>
#include <time.h>

#define ROZMIAR 10

void sortowanie_babelkowe(int rozmiar, int *tablica);
void zamien_wyrazy (int *int_1_p, int *int_2_p);
void zamien_wyrazy_indeks (int *tablica, int int_1_p, int int_2_p); // do zadanie 5.0 - funkcja przyjmuje indeksy
void sortowanie_przez_wstawianie (int rozmiar, int *tablica);

void main(void){

  int tab[ROZMIAR];
  srand( time( NULL ) );
  printf("Przed sortowaniem\n");
  for(int i=0; i<ROZMIAR; i++){
     tab[i] = rand() % 101;
     printf("[%d] element tablicy to: %d\n", i, tab[i]);
  }
  int *wsk = &tab;
  //sortowanie_babelkowe(ROZMIAR, wsk);
  sortowanie_przez_wstawianie(ROZMIAR, wsk);
  printf("Po sortowaniu\n");
  for(int i=0; i<ROZMIAR; i++){
     printf("[%d] element tablicy to: %d\n", i, tab[i]);
   }
}

void sortowanie_babelkowe(int n, int *tab){
  for(int i=0; i<n; i++)
    for(int j=1; j<n-i; j++)
      if(tab[j-1]> tab[j])
        zamien_wyrazy(&(tab[j-1]), &(tab[j]));
        zamien_wyrazy_indeks(tab ,j-1, j); // do zadania 5.0 - argumenty to indeksy
}

void zamien_wyrazy(int *pierwszy, int *drugi){
  int temp;
  temp = *pierwszy;
  *pierwszy = *drugi;
  *drugi = temp;
}

void zamien_wyrazy_indeks(int *tab, int pierwszy, int drugi){ // do zadania.5.0
  int temp;
  temp = (tab[pierwszy]);
  (tab[pierwszy]) = (tab[drugi]);
  (tab[drugi]) = temp;
}

void sortowanie_przez_wstawianie (int n, int *tab){
  int pom, j;
  for(int i=1; i<n; i++){
    pom = tab[i];
    j = i-1;
    while(j>=0 && tab[j]>pom){
      tab[j+1] = tab[j];
      --j;
    }
    tab[j+1] = pom;
  }
}
