#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROZMIAR_TABLICY 10

void main(void)
{

  int tablica_int[ROZMIAR_TABLICY] = {0};

  // 1. inicjowanie tablicy w momencie definowania:

  // a. wszystkie wartości

  //int tablica_int[ROZMIAR_TABLICY] = {2,34,76,23,8,-65,12,65,7,2};
  
  // b. początkowe wartości

  //int tablica_int[ROZMIAR_TABLICY] = {4,1,-5,23};

  // 2. nadanie wartości w pętli

  // a. zależnych od wartości zmiennej sterujacej
  
  /*for(int i=0; i<ROZMIAR_TABLICY; i++){

    tablica_int[i]=i;
      
  }*/
  // b. wczytywanych z klawiatury za pomocą scanf
  
  /*for(int i=0; i<ROZMIAR_TABLICY; i++){

    printf("Podaj wartość dla %d elementu tablicy: ", i);
    scanf("%d", &tablica_int[i]);

  }printf("\n");*/

  // 3. zamiana pętli for nadawania wartości na pętlę while

  /*int i=0;
  while(i<ROZMIAR_TABLICY){
  
    printf("Podaj wartość dla %d elementu tablicy: ", i);
    scanf("%d", &tablica_int[i]);
    
    i++;
    
  }printf("\n");*/

  // 4. zamiana poniższej pętli for na pętlę do
  // (jak zwykle najlepiej wykomentować starą pętlę i wpisać poniżej nową pętlę)


  /*i=0;
  do{
  
    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
    
    i++;
    
  }while(i<ROZMIAR_TABLICY);*/
  
  /*for(int i=0; i<ROZMIAR_TABLICY; i++){

    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
      
  }*/ // default loop
  

  // 5. wyszukiwanie wartości maksymalnej w tablicy (pętla for)
  
  /*int max=tablica_int[0];
  int min=tablica_int[0];
  
  for(int i=0; i<ROZMIAR_TABLICY; i++){

    if(tablica_int[i]>max)
      max=tablica_int[i];
    if(tablica_int[i]<min)
      min=tablica_int[i];
      
  }
  
  printf("Maksymalna wartość tablicy to: %d\n", max);
  printf("Minimalna wartość tablicy to: %d\n", min);*/

  // 6. obliczanie sumy elementów tablicy (pętla while)
  
  /*int suma=0;
  
  i=0;
  
  while(i<ROZMIAR_TABLICY){
  
    suma+=tablica_int[i];
    
    i++;
    
  }
  
  printf("Suma elementów tablicy wynosi: %d\n", suma);*/

  //-------------------------------- 3.0 ------------------------------------

  // 7. tablica z wartościami losowymi i wyszukiwanie zadanych wartości

  // a. nowa definicja tablicy (np. tablicy znaków)
  
  char tabz[ROZMIAR_TABLICY]={0};

  // b. nadawanie wartości losowych wyrazom tablicy
  //    (np. liczby z zakresu 33-126, czyli odpowiadające znakom ASCII)
  //    -> odpowiednie wydruki
  
  srand( time( NULL ) );
  for(int i=0; i<ROZMIAR_TABLICY; i++){
    tabz[i]= 33 + rand() % 93;
    printf("[%d] element tablicy to: %d\n", i, tabz[i]);
  }

  // c. sprawdzenie losowości - obliczenie wartości średniej w tablicy
  //    (w odpowiedniej pętli) - porównanie z teoretyczną średnią
  //    -> odpowiednie wydruki
  
  int suma=0;
  for(int i=0; i<ROZMIAR_TABLICY; i++){
    suma+=tabz[i];
  }
  
  int suma_teoretyczna=0;
  for(int i=33; i<=126; i++){
    suma_teoretyczna+=i;
  }
  
  printf("Średnia teoretyczna wynosi: %f\n",suma_teoretyczna/(float)93);
  printf("Średnia rzeczywista wynosi: %f\n",suma/(float)ROZMIAR_TABLICY);
  printf("Różnica wynosi: %lf\n",(fabs((suma_teoretyczna / (float)93)-(suma / (float)ROZMIAR_TABLICY))));

  // d. wyszukiwanie zadanej wartości
  //    -> odpowiednie wydruki w momencie znalezienia wartości
  //    np. "Znaleziono wartość %.. w %d elemencie tablicy\n", ...
  

  //  d1. wyszukanie tylko jednej (pierwszej) wartości - pętla while
  //      (lub pętla for i break)

  int szukana;
  bool nieznaleziono;
  for(;;){
    nieznaleziono=1;
    printf("Podaj jakiej wartości szukasz: ");
    scanf("%d", &szukana);
    for(int i=0; i<ROZMIAR_TABLICY; i++){
      if(szukana==tabz[i]){
        printf("Znaleziono wartość %d w %d elemencie tablicy\n", szukana, i);
        nieznaleziono=0;
        return 0;
      }
    }
    if(nieznaleziono==1)
     printf("Nie znaleziono szukanej liczby\n");
  }

  //  d2. wyszukanie (i wypisanie) wszytskich wartości - pętla for
  //      (lub pętla while)
  
  /*int szukana;
  bool nieznaleziono;
  for(;;){
    nieznaleziono=1;
    printf("Podaj jakiej wartości szukasz: ");
    scanf("%d", &szukana);
    for(int i=0; i<ROZMIAR_TABLICY; i++){
      if(szukana==tabz[i]){
        printf("Znaleziono wartość %d w %d elemencie tablicy\n", szukana, i);
        nieznaleziono=0;
        //break; // zadanie d1
      }
    }
    if(nieznaleziono==1)
     printf("Nie znaleziono szukanej liczby\n");
  }*/

  //-------------------------------- 4.0 ------------------------------------

  
}
