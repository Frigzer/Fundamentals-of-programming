#include <stdio.h>
#include <stddef.h>

// do zadania na 5.0

#define N 24

// deklaracja nowej struktury

struct zadanie5 {
  double d;
  char tab_c[N];
  int m;
};

// wyrownanie adresow polega na madrym zarzadzaniu alokowanej pamieci przez strukture 
// skladowane ktorych typ zawiera wiecej miejsca powinnym byc deklarowane w pierwszej kolejnosci

// deklaracja nowszej struktury

struct prezent {
  // struct prezent nazwa; // pojawil się error
  struct prezent * nazwa;
  int ilosc;
};

// definicja typu strukturalnego (można podać obie postacie i korzystać później z jednej z nich)
// 3.a bez użycia typedef

struct dane {
  char *imie;
  char *nazwisko;
  int wiek;
  double srednia_ocen;
}; 

// struct dane uczen_1; // przyklad deklaracji zmiennej

// 3.b z użyciem typedef

/* typedef struct {
  char *imie;
  char *nazwisko;
  int wiek;
  double srednia_ocen;
} dane; */

// dane uczen_1; // przyklad deklaracji zmiennej

// 5.1.a deklaracja funkcji fun_strukt

void fun_strukt(struct dane argument);

// 5.3.a deklaracja funkcji fun_strukt_out

struct dane fun_strukt_out(struct dane argument);

// 5.5.a deklaracja funkcji fun_strukt_wsk

struct dane fun_strukt_wsk(struct dane * argument);

// zadanie na 4.0

struct dane fun_strukt_wsk_kopia(struct dane * argument);

struct dane fun_strukt_wsk_inout(struct dane * argument);

// zadanie na 5.0

struct dane * fun_struct_wsk_out(struct dane argument);

int main (void)
{

  // 4.1 definicja zmiennej (np. obiekt_1) typu strukturalnego
  
  struct dane obiekt_1;

  // 4.2 nadanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  
  obiekt_1.imie="Cezary";
  obiekt_1.nazwisko="Dabrowski";
  obiekt_1.wiek=21;
  obiekt_1.srednia_ocen=3.1;

  // 4.3 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_1: ....", ....);
  
  printf("Poczatkowe wartosci pol obiekt_1:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_1.imie, obiekt_1.nazwisko, obiekt_1.wiek, obiekt_1.srednia_ocen);

  // 5.2.1 wywołanie funkcji fun_strukt (po deklaracji w p. 5.1.a i definicji w p. 5.1.b)
  //      z obiektem 1 jako argumentem 
  
  fun_strukt (obiekt_1);

  // 5.2.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt - wartości pól obiekt_1: ....", ....);
  
  printf("Po wywołaniu fun_strukt - wartości pól obiekt_1:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_1.imie, obiekt_1.nazwisko, obiekt_1.wiek, obiekt_1.srednia_ocen);

  // 5.4.1 wywołanie funkcji fun_strukt_out (po deklaracji w p. 5.3.a i definicji w p. 5.3.b)
  //      z obiektem_1 jako argumentem i przepisaniem wyniku z powrotem do obiektu_1
  
  obiekt_1 = fun_strukt_out (obiekt_1);

  // 5.4.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
  //        printf("- wartości pól obiekt_1: ....", ....);

  printf("Po wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
  printf("- wartości pól obiekt_1:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_1.imie, obiekt_1.nazwisko, obiekt_1.wiek, obiekt_1.srednia_ocen);
  
  // 4.4 definicja drugiej zmiennej typu strukturalnego  (np. obiekt_2)
  //    połączona z inicjowaniem za pomocą listy wartości
  
  struct dane obiekt_2 = { "Mariusz", "Rzepa", 56, 5.0 };

  // 4.5 definicja wskaźnika (np. obiekt_2_wsk) do struktury zainicjowanego adresem obiektu_2
  
  struct dane * obiekt_2_wsk = &obiekt_2;

  // 4.6 wypisanie wartości pól obiektu_2 z pomocą wskaźnika do obiektu i operatora ->
  //    np. printf("Początkowe wartości pól obiekt_2: ....", ....);
  
  printf("Poczatkowe wartosci pol obiekt_2:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_2_wsk->imie, obiekt_2_wsk->nazwisko, obiekt_2_wsk->wiek, obiekt_2_wsk->srednia_ocen);

  // 5.6.1 wywołanie funkcji fun_strukt_wsk (po deklaracji w p. 5.5.a i definicji w p. 5.5.b)
  //      ze zmienną obiekt_2_wsk jako argumentem

  fun_strukt_wsk (&obiekt_2);

  // 5.6.2 wypisanie wartości pól zmiennej obiekt_2 z pomocą wskaźnika do obiektu i operatora ->
  //    np. printf("Po wywołaniu fun_strukt_wsk - wartości pól obiekt_2: ....", ....);

  printf("Po wywołaniu fun_strukt_wsk - wartości pól obiekt_2:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_2_wsk->imie, obiekt_2_wsk->nazwisko, obiekt_2_wsk->wiek, obiekt_2_wsk->srednia_ocen);

  // 4.7 definicja trzeciej zmiennej typu strukturalnego  (np. obiekt_3)
  //    połączona z inicjowaniem za pomocą przepisania zawartości obiektu_2 w jednej
  //    operacji przypisania

  struct dane obiekt_3 = obiekt_2;

  // 4.8 wypisanie wartości pól zmiennej obiekt_3 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_3: ....", ....);
  
  printf("Poczatkowe wartosci pol obiekt_3:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_3.imie, obiekt_3.nazwisko, obiekt_3.wiek, obiekt_3.srednia_ocen);

  //-------------------------------- 3.0 ------------------------------------

  // 8. wywołanie funkcji fun_strukt_wsk_kopia (po odpowiedniej deklaracji i definicji)
  //    z adresem obiektu 3 jako argumentem oraz przypisanie (skopiowanie) zwracanej przez
  //    fun_strukt_wsk_kopia struktury (z całą zawartością) do nowej zmiennej obiekt_4
  //    zaprojektowanego typu w operacji inicjowania

  struct dane obiekt_4 = fun_strukt_wsk_kopia(&obiekt_3);

  //    wypisanie wartości pól zmiennej obiekt_4 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_4: ....", ....);

  printf("Początkowe wartości pól obiekt_4:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_4.imie, obiekt_4.nazwisko, obiekt_4.wiek, obiekt_4.srednia_ocen);

  // 10. wywołanie funkcji fun_strukt_wsk_inout (po odpowiedniej deklaracji i definicji)
  //     z adresem obiektu 4 jako argumentem

  fun_strukt_wsk_inout(&obiekt_4);

  //    wypisanie wartości pól zmiennej obiekt_4 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt_wsk_inout - wartości pól obiekt_4: ....", ....);
  
  printf("Po wywołaniu fun_strukt_wsk_inout - wartości pól obiekt_4:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt_4.imie, obiekt_4.nazwisko, obiekt_4.wiek, obiekt_4.srednia_ocen);

  //-------------------------------- 4.0 ------------------------------------

  // zadanie na 5.0
  
  // sprawdzenie czy fun_struct_wsk_out zwraca wartosc NULL
  
  // if((fun_struct_wsk_out(obiekt_4))==NULL)
  //   printf("NULL\n");
  // else
  //   printf("Nie NULL\n");
  
  // if(fun_struct_wsk_out(obiekt_4))
  //   printf("Funkcja malloc nie zwrocila NULL\n");
  // else
  //   printf("Funkcja malloc zwrocila NULL\n");

  struct dane *obiekt_5 = fun_struct_wsk_out(obiekt_4);
  
  // zwolnie pamieci
  
  free(obiekt_5);
  
  // wykorzystanie nowego typu strukturalnego
  
  struct zadanie5 test;
  
  // rozmiar zmiennej
  
  size_t rozmiar_obiektu = sizeof(test);
  
  // wypisanie
  
  printf("Dla N rownego: %d, rozmiar pojedynczej zmiennej wynosi: %lu\n", N, rozmiar_obiektu);
  
  // dla N = 1 rozmiar = 16
  // dla N = 10 rozmiar = 24
  // dla N = 100 rozmiar = 112
  // rozmiar zalezy tez od kolejnosci definiowania skladowych
  
  printf("Koniec programu.\n");
}

// 5.1.b definicja funkcji fun_strukt

void fun_strukt (struct dane obiekt)
{

  // wypisanie wartości pól struktury przesłanej jako argument
  // np. printf("Wewnątrz fun_strukt - wartości pól obiektu argumentu: ...", ...);

  printf("Wewnątrz fun_strukt - wartości pól obiektu argumentu:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt.imie, obiekt.nazwisko, obiekt.wiek, obiekt.srednia_ocen);

  // modyfikacja wartości pól struktury
  
  obiekt.imie="Tadeusz";
  obiekt.nazwisko="Wysoki";
  obiekt.wiek=36;
  obiekt.srednia_ocen=4.85;

  // wypisanie zmodyfikowanych wartości pól struktury 
  // np. printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu: ...", ...);
  
  printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt.imie, obiekt.nazwisko, obiekt.wiek, obiekt.srednia_ocen);

}


// 5.3.b definicja funkcji fun_strukt_out

struct dane fun_strukt_out (struct dane obiekt)
{

  // wypisanie wartości pól struktury przesłanej jako argument

  printf("Wewnątrz fun_strukt_out - wartości pól obiektu argumentu:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt.imie, obiekt.nazwisko, obiekt.wiek, obiekt.srednia_ocen);

  // modyfikacja wartości pól struktury
  
  obiekt.imie="Kazimierz";
  obiekt.nazwisko="Tetmajer";
  obiekt.wiek=94;
  obiekt.srednia_ocen=3.14;

  // wypisanie zmodyfikowanych wartości pól struktury 
  
  printf("Wewnątrz fun_strukt_out - zmodyfikowane wartości pól obiektu argumentu:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt.imie, obiekt.nazwisko, obiekt.wiek, obiekt.srednia_ocen);

  // zwrócenie struktury ze zmodyfikowanymi wartościami pól do funkcji wywołującej
  
  return obiekt;

}


// 5.5.b definicja funkcji fun_strukt_wsk

struct dane fun_strukt_wsk (struct dane * obiekt)
{

  // wypisanie wartości pól struktury wskaźnik do której został przesłany jako argument

  printf("Wewnątrz fun_strukt_wsk - wartości pól obiektu argumentu:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt->imie, obiekt->nazwisko, obiekt->wiek, obiekt->srednia_ocen);

  // modyfikacja wartości pól struktury
  
  obiekt->imie="Charlie";
  obiekt->nazwisko="Wong";
  obiekt->wiek=12;
  obiekt->srednia_ocen=5.9999991;

  // wypisanie zmodyfikowanych wartości pól struktury 

  printf("Wewnątrz fun_strukt_wsk - zmodyfikowane wartości pól obiektu argumentu:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , obiekt->imie, obiekt->nazwisko, obiekt->wiek, obiekt->srednia_ocen);

}

// zadanie na 4.0

struct dane fun_strukt_wsk_kopia(struct dane * obiekt)
{

  // przepisanie zawartosci struktury do zmiennej lokalnej
  
  struct dane local = *obiekt;
  
  // nadanie wartosci zmiennej lokalnej
  
  local.imie="Thomas";
  local.nazwisko="Jefferson";
  local.wiek=19;
  local.srednia_ocen=4.62;
  
  // wypisanie wartosci zmiennej lokalnej
  
  printf("Wewnątrz fun_strukt_wsk_kopia - wartości pól zmiennej lokalnej:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , local.imie, local.nazwisko, local.wiek, local.srednia_ocen);
  
  // zwrocenie struktury - zmiennej lokalnej
  
  return local;
  
}

struct dane fun_strukt_wsk_inout(struct dane * obiekt)
{
  
  // przepisanie zawartosci struktury do zmiennej lokalnej
  
  struct dane local = *obiekt;
  
  // nadanie wartosci zmiennej lokalnej
  
  local.imie="Gregory";
  local.nazwisko="Rasputin";
  local.wiek=74;
  local.srednia_ocen=2.13;
  
  // wypisanie wartosci zmiennej lokalnej
  
  printf("Wewnątrz fun_strukt_wsk_inout - wartości pól zmiennej lokalnej:\nimie: %s\nnazwisko: %s\nwiek: %d\nsrednia_ocen: %lf\n\n"
          , local.imie, local.nazwisko, local.wiek, local.srednia_ocen);
  
  // przepisanie zawartosci struktury ze zmiennej lokalnej do struktury w funkcji wywolujacej
  
  *obiekt=local;
  
}

// zadanie na 5.0

struct dane * fun_struct_wsk_out(struct dane obiekt)
{
  
  // definicja zmiennej zawierajacej informacje o rozmiarze obiektu
  
  size_t rozmiar_obiektu = sizeof (obiekt);
  
  // wypisanie zawartosci sizeof (obiekt)
  
  printf("Zawartosc zwracana przez sizeof: %lu\n", rozmiar_obiektu);
  
  // alokacja pamieci dla struktury
  
  // void *malloc(rozmiar_obiektu);
  
  // zdefiniowanie nowej struktury w obszarze dynamicznym
  
  struct dane * dynamic = NULL;
  
  // przypisanie wartosci argumentu do struktury na stercie
  
  dynamic = malloc(sizeof (obiekt));
  
  if(dynamic==NULL)
    printf("Funkcja malloc zwrocila NULL\n");
  else
    printf("Funkcja malloc nie zwrocila NULL\n");
  
  return dynamic;
  
}
