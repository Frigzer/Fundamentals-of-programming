#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

#define graniczna 100

// 0. numeracja kolejnych kroków ćwiczeń odpowiada numeracji w temacie laboratorium
//    - początek modyfikacji kodu (po wstępnym uruchomieniu programu za pomocą
//      utworzonego pliku Makefile) -> p.4 w funkcji power_int_rekur

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base
int power_int(int base, int n);

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base w sposób rekurencyjny
int power_int_rekur(int m, int n);

//int main (void)
  
// 5. modyfikacja programu polegająca na podawaniu argumentów w linii komend
 int main (int argc, char** argv) 
  
{

  // cd. 5 - sprawdzenie poprawności wywołania (np. modyfikując poniższy kod)
   if(argc<=2) { printf( "Nie podano argumentów\n"); exit(0); }
  
  // cd. 5 uzyskanie argumentów liczbowych z przesłanych napisów w linii komend
  //
   int base = my_atoi( argv[1] );
   int exp = my_atoi( argv[2] );
  //
  // sprawdzająca asercja?
  // ...
  //
  // wykonanie operacji na przesłanych argumentach
   printf("Dane z linii poleceń: %d^%d=%d\n", base, exp, power_int(base,exp));

  // koniec p. 5 -> p. 6 w funkcji power_int_rekur

  int i;
  for (i = 0; i < 10; ++i){
    //printf("iteracyjnie:   \t%d^%d = %3d \t%d^%d = %6d\n",
	//   2, i, power_int(2,i), -3, i, power_int(-3,i));
    
    // 4.1.a 
     printf("rekurencyjnie: \t%d^%d = %3d \t%d^%d = %6d\n",
             2, i, power_int_rekur(2,i), -3, i, power_int_rekur(-3,i));
    
  }

  int base_f=0, exp_f=0;
  // 7. wczytywanie argumentów z pliku (i ewentualny zapis do pliku)
  //
  // 7.a definicja wskaźnika do pliku
  FILE *plik;
  // 7.b otwarcie pliku (sciezka np. ./dane.txt, tryb odczytu)
  plik=fopen("dane.txt","r");
  if(plik==NULL) printf("Blad odczytu");
  // 7.c wczytanie argumentów z pliku
  
  fscanf(plik,"%d %d", &base_f, &exp_f);
  // 7.d zamknięcie pliku
  fclose(plik);
  // 7.e wykonanie operacji na argumentach
  base_f++;
  exp_f++;
  // 7.f wydruk sprawdzający
  // 
  printf("Dane z pliku: %d^%d=%d\n", base_f, exp_f, power_int(base_f,exp_f));
  int wynik=power_int(base_f,exp_f);
  // ewentualnie:
  // 7.g otwarcie pliku (tryb dopisywania)
  plik=fopen("wynik.txt","w");
  // 7.h dopisanie wyniku do pliku
  fprintf(plik, "%d",wynik);
  // 7.i zamknięcie pliku
  fclose(plik);
  // koniec p.7 ------------------------- 3.0 -------------------------
  
  return 0;
}

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base
int power_int(int base, int n)
{
  int i, p;
  p=1;
  for (i = 1; i <= n; ++i){
    p = p * base;
  }
  return p;
}

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base w sposób rekurencyjny
int power_int_rekur(int m, int n){

  int potega=1;
  
  assert(
   n>=0
  );
  void _assert(
   char const* message,
   char const* filename,
   unsigned line
  );
  void _wassert(
   wchar_t const* message,
   wchar_t const* filename,
   unsigned line
  );
  
  // 4.1 napisanie wersji rekurencyjnej dla funkcji obliczania potęgi
  //
  // ...
  //
  
  if(n==1)
    potega=m;
  else if (n>1){
    potega = power_int_rekur( m,  --n);
    potega*=m;
  }
  //    4.1.a sprawdzenie działania poprzez wykomentowanie odpowiedniej linii w main
  //
  // 4.2. umieszczenie wewnątrz funkcji makra assert sprawdzającego n>=0
  //      -> powyżej kodu z 4.1 !
  //
  // 4.2.a i b uruchomienie programu z błędnymi danymi - z makrem włączonym i wyłączonym
  //    - włączanie i wyłączania makra poprzez zmianę opcji kompilacji
  //      (zrzuty ekranu do zamieszczenia w sprawozdaniu)

  // 6. wprowadzenie zmiennej statycznej zliczającej liczbę wywołań funkcji power_int_rekur
  //
  // - definicja z inicjowaniem
  static int liczba_wywolan=0;
  // ...
  // - zwiększanie wartości
  liczba_wywolan++;
  // ...
  // - wydruk informacyjny
  printf("Wywołanie nr %d funkcji power_int_rekur\n", liczba_wywolan);
  if(liczba_wywolan>graniczna)
    printf("Przekroczono wartosc graniczna");
  //
  // koniec p. 6

  return potega;
}


// funkcja pomocnicza przekształcająca napis (liczbę zapisaną literowo) w liczbę całkowitą
int my_atoi(char s[])
{
  int sign=1; // = (s[0]=='-') ? -1 : 1;
  if(s[0]=='-') sign=-1;
  int i=0;
  if (s[0]=='+' || s[0]=='-') i++;  
  int n = 0;
  while( s[i] >= '0' && s[i] <= '9' ) {
    n = 10 * n + (s[i] - '0');
    i++;
  }
  return sign*n;
}

