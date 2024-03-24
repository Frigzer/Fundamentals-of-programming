#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 9.a znalezienie za pomocą: man 3 bsearch lub man 3 qsort typu funkcji porównującej
//     dwa elementy tablicy 
// 9.b deklaracja (za pomocą właściwego prototypu) funkcji porównującej
int my_compare (const void * a, const void * b);
// 9.c definicja funkcji - najlepiej na końcu pliku
// 9.d wywołanie funkcji sortowania qsort w funkcji main


#define ROZMIAR_TABLICY 10 // można potem zwiększyć do np. 1000 po wykomentowaniu wydruków
#define test
// funkcja wyszukiwania zadanej wartości (klucz) w tablicy (tab_int)
int* binsearch_iter(// funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		    // lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
	      int klucz,     // wyszukiwana wartość
	      int tab_int[], // tablica liczbowa
	      int n          // długość tablicy
	       );

// funkcja wyszukiwania zadanej wartości (klucz) w podtablicy tablicy (tab_int)
// od indeksu początkowego (pocz) do indeksu końcowego (kon)
int* binsearch_rekur(//funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		     //lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
	      int klucz,     // wyszukiwana wartość
	      int tab_int[], // tablica liczbowa
	      int pocz,      // indeks poczatkowego elementu podtablicy
	      int kon        // indeks końcowego elementu podtablicy
	       );


int main(int argc, char** argv)
{

  if(argc<=1) { printf( "Nie podano sciezki i nazwy pliku\n"); exit(0); }
  
  
  FILE *plik;
  int i;
  int* tablica_int = malloc(ROZMIAR_TABLICY*sizeof(int));
  int* tablica2_int = malloc(ROZMIAR_TABLICY*sizeof(int));
  srand(time(NULL)); // inicjowanie generatora liczb losowych aktualnym czasem

  plik=fopen(argv[1],"w");
  if(plik==NULL) printf("Blad odczytu");
  
  for(i=0; i<ROZMIAR_TABLICY; i++){
    tablica_int[i] = rand()%1000; // losowa liczba z zakresu 0-999
    fprintf(plik, "%d\n" ,tablica_int[i]);
    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
  }
  fclose(plik);
  
  printf("Tablica po odczycie z pliku");
  plik=fopen(argv[1],"r");
  if(plik==NULL) printf("Blad odczytu");
  for(i=0; i<ROZMIAR_TABLICY; i++){
    tablica2_int[i] = rand()%1000; // losowa liczba z zakresu 0-999
    fscanf(plik, "%d" ,&tablica_int[i]);
    printf("Iteracja %d: tablica2_int[%d] = %d\n", i, i, tablica_int[i]);
  }
  fclose(plik);
  // 9.d wywołanie funkcji sortowania qsort w funkcji main
   qsort(tablica_int, ROZMIAR_TABLICY, sizeof(int), my_compare);

  // 9.e sprawdzenie działania poprzez wydruk (wewnątrz dyrektywy kompilacji warunkowej)
  printf("Po sortowaniu:\n");
   #ifdef test
  for(i=0; i<ROZMIAR_TABLICY; i++){
    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
    
  }
  for(i=0; i<ROZMIAR_TABLICY-1; i++){
    if(tablica_int[i+1]>=tablica_int[i])
      continue;
    else{
      printf("Bledne sortowanie\n");
      break;
    }
  }
  
   #endif

  // 9.e sprawdzenie działania poprzez operacje porównywania kolejnych elementów
  //     (wewnątrz dyrektywy kompilacji warunkowej)

  // 11 i 12.
  //for(;;){
    //int k;
    //printf("Podaj liczbę całkowitą 0-999\n"); scanf("%d", &k);

    // wywołanie wyszukiwania funkcją binsearch_iter (później binsearch_rekur)
    // int* wsk_el = binsearch_iter(k, tablica_int, ROZMIAR_TABLICY);
    
    //if(wsk_el==NULL) printf("Nie znaleziono...\n");
    //else{
    //  int indeks = wsk_el - tablica_int;
    //  printf("Znaleziono na pozycji %d (%d == %d == %d)\n",
    //	     wsk_el - tablica_int, k, *wsk_el, tablica_int[indeks]);
    //}

  
  // wywołanie wyszukiwania zgodnie z prototypem bsearch */

  // porównanie wartości zwróconych przez bsearch i binsearch_iter (binsearch_rekur)

  // odpowiednie wydruki
  
  // } 

}

int my_compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}


// funkcja wyszukiwania wartości (wyszukiwana_liczba) w tablicy (tab_int)
int* binsearch_iter(// funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		    // lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
		   int wyszukiwana_liczba,   // wyszukiwana wartość
		   int tab_int[], // tablica liczbowa
		   int n    // długość tablicy
		    )
{

  int low = 0; // dolny (lewy) indeks aktualnie przeszukiwanej pod-tablicy
  int high = n-1; // górny (prawy) indeks aktualnie przeszukiwanej pod-tablicy

  // dopóki jest jeszcze coś do przeszukania
  while (low <= high) {
    // znajdź środek przeszukiwanej tablicy
    int mid = (low+high) / 2;
    // jeśli element może być w lewej części
    if (wyszukiwana_liczba < tab_int[mid]){
      // zmień górny indeks na dotychczasowy środek 
      high = mid - 1;
    // jeśli element może być w prawej części
    } else if (wyszukiwana_liczba > tab_int[mid]) {
      // zmień dolny indeks na dotychczasowy środek 
      low = mid + 1;
    } else {
      // wartość znaleziona
      //return mid;
      return &tab_int[mid];
    }
  }
  // jeśli low > high - koniec przeszukiwania
  return NULL; // wartość nie znaleziona
}

