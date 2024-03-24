#include <stdio.h>

// deklaracja funkcji
int prosta_funkcja( );

int main ( void )
{

  // 1. definicja zmiennej test np. typu int z inicjowaniem
  
  int test=420;
  
  // 2. drukowanie wartości zmiennej test
  printf("przed wywołaniem prostej funkcji: %d\n", test);

  // wywołanie funkcji
  //prosta_funkcja();

  // 6. (po wykomentowaniu wywołania powyżej) wywołanie funkcji z argumentem
  
  prosta_funkcja(test);
  
  // 7, 8, 9 - co trzeba zmienić po wykonaniu kroków 5 i 6, żeby program zadziałał?
  
  // należało usunąć argument void przy deklaracji funkcji, ewentualnie można go zamienić na int

  // 2. drukowanie wartości zmiennej test
  printf("po powrocie z prostej funkcji: %d\n", test);

}

// 5. zmiana definicji - przyjmowanie argumentu
int prosta_funkcja( int arg )
{

  // 3. definicja zmiennej test np. typu int z inicjowaniem
  
  int test=007;

  // 4. drukowanie wartości zmiennej test
  printf("wewnątrz prostej funkcji: zmienna lokalna %d\n", test);

  //11. drukowanie wartości argumentu
  printf("wewnątrz prostej funkcji: argument przed modyfikacją %d\n", arg);
  
  // 10. zmiana wartości przesłanego argumentu
  
  arg=2137;
  
  // 11. drukowanie wartości argumentu
  printf("wewnątrz prostej funkcji: argument po modyfikacji %d\n", arg);

  return (arg);
}

