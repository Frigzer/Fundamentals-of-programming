#include <stdlib.h>
#include <stdio.h>

// deklaracja początkowa funkcji
//void prosta_funkcja( void );

void prosta_funkcja( int *int_ptr, double *doublePtr );

// po sprawdzeniu działania programu:
// 1. zmiana deklaracji (prototypu) prosta_funkcja, tak aby mogła przyjmować
//    dwa wskazane argumenty z funkcji main: wskaznik_do_int i double_p
//    (starą deklarację najlepiej zakomentować i utworzyć nową z odpowiednimi
//    typami argumentów - znalezionymi w funkcji main)
//    - nazwy argumentów prosta_funkcja: int_ptr i doublePtr
// cd. zmiana definicji prosta_funkcja

int main (void)
{

  // ewentualnie %lu na %p zamienić
  int i = 1;
  
  int * wskaznik_do_int = &i; // wskazniki zawsze inicjowane przy definiowaniu  
  
  printf("\nprzed wywołaniem prostej funkcji\n"); 
  printf("\nwartość zmiennej typu int i jej adres:    i = %d, &i = %lu \n", 
	 i, &i);
  printf("to samo co powyżej, za pomocą wskaźników: i = %d, &i = %lu \n", 
	 *wskaznik_do_int, wskaznik_do_int);
  
  double pi = 3.14;
  double * double_p = NULL;
  printf("\nwartość zmiennej pi: %lf, adres zmiennej pi: %lu\n", pi, &pi);
  printf("wskaźnik double_p zainicjowany wartością NULL:      %lu\n", double_p);
  double_p = &pi;
  printf("wskaźnik double_p po podstawieniu wartości &pi:     %lu\n", double_p);
  
  // UWAGA: arytmetyka wskaźników:
  double_p++;
  printf("wskaźnik double_p po wykonaniu operacji double_p++: %lu\n", double_p);
  // na co teraz pokazuje *double_p ????? - nie wiadomo,
  // co się stanie gdy wykonanmy (*double_p)++ ????? - nie wiadomo, więc...
  double_p--; // ...wracamy do poprzedniej wartości &pi
  
  // wywołanie funkcji 
  //prosta_funkcja();

  // 4. wywołanie funkcji prosta_funkcja z nowymi argumentami wskaznik_do_int i double_p
  //    (po wykomentowania poprzedniego obecnie niepoprawnego wywołania)

  prosta_funkcja( wskaznik_do_int, double_p );

  printf("\n\npo powrocie z prostej funkcji: \n");
  printf("wartość zmiennej typu int i jej adres:    i = %d, &i = %lu \n", 
	 i, &i);
  printf("to samo co powyżej, za pomocą wskaźników: i = %d, &i = %lu \n", 
	 *wskaznik_do_int, wskaznik_do_int);
  printf("\nwartość zmiennej pi i jej adres:           pi = %lf, &pi = %lu\n", 
	 pi, &pi);
  printf("to samo co powyżej, za pomocą wskaźników:  pi = %lf, &pi = %lu \n", 
	 *double_p, double_p);

}

// 2. zmiana definicji prosta_funkcja
//    - dostosowanie nagłówka do prototypu (dwa argumenty)
void prosta_funkcja( int *int_ptr, double *doublePtr )
{

  // 3. wydrukowanie wartości argumentów i zmiennych, na które wskazują
  printf("\n\nwewnątrz prostej funkcji: \n");
  printf("\nwskaźnik zmiennej typu int i jej adres:    int_ptr = %d, &int_ptr = %lu \n", *int_ptr, &int_ptr);
  printf("wskaźnik doublePtr i adres:    doublePtr = %lf, &doublePtr = %lu\n", *doublePtr, &doublePtr);
  
  // 4. zmiana wywołania prosta_funkcja w funkcji main

  // 5. modyfikacja wartości wskazywanych zmiennych
  
  (*int_ptr)++;
  (*doublePtr)++;
  
  // 6. wydrukowanie wartości argumentów i zmiennych, na które wskazują
  
  printf("\npo modyfikacji wewnatrz funkcji:");
  printf("\nwskaźnik zmiennej typu int i jej adres:    int_ptr = %d, &int_ptr = %lu \n", *int_ptr, &int_ptr);
  printf("wskaźnik doublePtr i adres:    doublePtr = %lf, &doublePtr = %lu\n", *doublePtr, &doublePtr);

  // 7. uruchomienie i sprawdzenie działania: jakie wartości drukowane są
  //    w funkcji prosta funkcja, a jakie w funkcji main
  
  // wartość w funckji i w main po wywołaniu funkcji są takie same

  // 8. modyfikacja wartości przesłanych argumentów
  
  int_ptr++;
  doublePtr++;

  // 9. wydrukowanie wartości argumentów i zmiennych, na które aktualnie wskazują
  //    - czy ma to jakiś sens?

  printf("\npo kolejnej modyfikacji wewnatrz funkcji:");
  printf("\nwskaźnik zmiennej typu int i jej adres:    int_ptr = %d, &int_ptr = %lu \n", *int_ptr, &int_ptr);
  printf("wskaźnik doublePtr i adres:    doublePtr = %lf, &doublePtr = %lu\n", *doublePtr, &doublePtr);
 
  return;
}

