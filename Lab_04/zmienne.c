// //** zmienne.c - prosty program ilustrujący wykorzystanie i drukowanie zmiennych oraz
// //**             ewentualne problemy z precyzją przechowywania

// //** słowo USES informuje, że w pliku będą używane funkcje opisane w plikach nagłówkowych
#include <stdio.h> // USES - deklaracje funkcji wejścia/wyjścia
#include <math.h> // USES - deklaracje funkcji matematycznych

// //** definicja symbolu - w kodzie używany jest symbol, preprocesor zamienia każde wystąpienie
// //** symbolu w kodzie na podany łańcuch znaków
#define TOLERANCE 1e-12 // tolerancja - wartość względnej różnicy liczb (l1-l2)/l1
                        // //** poniżej której dwie liczby zmiennoprzecinkowe są uznawane za równe
// //** UWAGA: tolerancja powinna być różna dla float i double (tutaj wartość typowa dla double)

// //** bez użycia #define i nazwanych wartości (np. TOLERANCE - można jeszcze zwiekszyć czytelność nazwy)
// //** w kodzie pojawiają się tzw. "magic numbers" - liczby w kodzie, o których po pewnym czasie
// //** nikt nie wie co oznaczają, dlaczego tyle wynoszą, skąd się wzięły


// //** zwrot kodu błędu lub sukcesu (zwyczajowo kod sukcesu -> 0)
int main(void)
{

  /* 1. STANDARDOWE DEKLARACJE-DEFINICJE I WYPISYWANIE WARTOŚCI ZMIENNYCH */

  // //** definicje
   int n; // nazwy zmiennych - znaczące, niekoniecznie krótkie, z dużymi i małymi literami
        // nazwy krótkie, nieznaczące dla zmiennych pomocniczych stosowanych lokalnie
   char znak_do_testowania;

  // //** podstawianie wartości - inicjowanie
  n = 7; // instrukcja przypisania - stałe liczbowe i podstawowe operacje
  znak_do_testowania = 'a'; // stała znakowa

  printf("\nwartość zmiennej n = %d, wartość zmiennej znak_do_testowania = %c\n",
	 n, znak_do_testowania );

  printf("\nZadanie_1\n");  //poczatek zadania 1
  short int zmienna_a=65;
  char zmienna_b;
  long int zmienna_c;
  float zmienna_d;
  double zmienna_e;
  unsigned zmienna_f=12;
  
  zmienna_b='L';
  zmienna_c=12344;
  zmienna_d=2.5;
  zmienna_e=1.87;

  printf("wartosc zmiennej a = %d,\nwartosc zmiennej b = %c,\nwartosc zmiennej c = %ld,\nwartosc zmiennej d = %f,\nwartosc zmiennej e = %lf\n",zmienna_a, zmienna_b, zmienna_c, zmienna_d, zmienna_e);

  printf("\nbledne uzycie zmiennej f %c",zmienna_f);  //bledne uzycie zmiennej
  printf("\nbledne uzycie zmiennej d %d\n",zmienna_d);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie po jednej zmiennej każdego z omawianych na wykładzie typów - w tym typów
  // //**   z określeniami: short, long, unsigned
  // //** - podstawienie do każdej zmiennej dowolnie wybranej, poprawnej wartości
  // //** - zdefiniowanie połączone z nadaniem wartości (zainicjowniem) ponownie dla jednej zmiennej
  // //**   każdego z omawianych na wykładzie typów
  // //** - wypisanie wartości zdefiniowanych zmiennych na ekranie w oknie terminala: dobranie odpowiedniego
  // //**   symbolu formatowania dla każdego typu - sprawdzenie poprawności działania (czyli wydrukowania
  // //**   nadanej wartości)
  // //** - sprawdzenie efektu błędnego użycia symbolu formatowania: kiedy wydruk przestaje być poprawny
  // //**   (np. zmienna typu unsigned drukowana jako int, zmienna float drukowana jako int itd., itp,)
  

  /* 2. PROSTE OPERACJE */

  // //** operatory i ich priorytety
    int m;
    m = 2 * n + 3;
    int o = 2 * (n + 3); // definicja z inicjowaniem
    printf("\nn = %d, (2 * n + 3) = %d != (2 * (n + 3)) = %d\n", n, m, o);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych, w których wynik zależał będzie od kolejności
  // //**   zapisu i priorytetów wykonywanych operacji - testowanie poprawnego użycia nawiasów

  printf("\nZadanie 2.1\n");
  int suma;
  suma = zmienna_a + zmienna_c;
  double dzialanie = suma * (zmienna_d * zmienna_e);
  printf("\nSuma a + c wynosi %d, wynikiem dzialania (a+c)*(d*e) jest %lf\n",suma, dzialanie);;


  // //** operatory jednoargumentowe i ich priorytety
    int p = n++;  
    n--; // powrót do początkowej wartości n
    int q = ++n;  
    n--; // powrót do początkowej wartości n
    printf("\nn = %d, wynik podstawienia: 'p = n++;' - %d, wynik podstawienia: 'q = ++n;' - %d\n", 
  	 n, p, q);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych z operatorami jednoargumentowymi, w których wynik
  // //** zależał będzie od priorytetów wykonywanych operacji - testowanie poprawnego użycia nawiasów

  printf("\nZadanie 2.2\n");
  int za=1;
  int zb=za++;
  za--;
  int zc=++zb;
  zb--;
  printf("\nza=%d, zb=%d czyli za++, zc=%d czyli zc=++zb\n",za,zb,zc);

  // //** operatory / - dzielenie całkowite i % - modulo
    n = 1574;
    m = n % 7;
    o = n / 7;
    printf("\nn = %d, n/7 = %d, reszta - n%7 = %d, n = (n/7)*7 + (n%7) = %d\n",
    	 n, o, m, o*7+m);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych z funkcją modulo:
  // //**   - sprawdzanie podzielności jednych liczb przez inne
  // //**   - dzielenie z resztą i uzyskiwanie pierwotnej wartości (dla innych liczb niż w przykładzie
  // //**     powyżej)

  printf("\nZadanie 2.3\n");
  za = 15747;
    zb = za % 9;
    zc = za / 9;
    printf("\nza = %d, za/9 = %d, reszta - za%9 = %d, za = (za/9)*9 + (za%9) = %d\n",
    	 za, zc, zb, zc*9+zb);


  /* 3. DEFINICJE STAŁYCH SYMBOLICZNYCH */

  // //**** UWAGA: definicje symboli #define powinny być na początku pliku (po #include) !!!!!!!!!!
           // //** kompilator w pierwszej fazie działania zastąpi wszystkie wystąpienia
           // //** symboli odpowiednimi wyrażeniami z #define
  #define SIEDEM 7 // wystąpienia symbolu SIEDEM są w kodzie zamieniane na 7
    int r = SIEDEM; // w assemblerze r jest zmienną - ma adres, SIEDEM znika zamienione na 7
    printf("\nr = %d, stała SIEDEM = %d\n", r, SIEDEM); 

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - nadanie wartości kilku symbolom - wartości powinny być stałymi różnych typów liczbowych
  // //** - podstawienie do zmiennych wartości za pomocą symboli okreslonych w #define i wydrukowanie
  // //**   wartości zmiennych (UWAGA: po podstawieniu za symbol napisu stanowiącego zapis liczby,
  // //**   funkcjonuje on w kodzie jako liczba określonego typu - jak w przykładzie powyżej - drukując
  // //**   go należy odpowiednio dobrać formatowanie)

  printf("\nZadanie 3\n"); 

  #define CZTERY 4
    int zd = CZTERY;
    printf("\nzd = %d, CZTERY = %d\n", zd, CZTERY);   
  #define _znak "ZnaK" // zmiana wielkości liter w ciągu znakowym
  char znak[]=_znak;
  printf("\n%s\n",znak);

  /* 4. ZMIENNE ZMIENNOPRZECINKOWE: FLOAT I DOUBLE */

  // //**** UWAGA na dokładność:
  // //** wygodne wyrażanie w postaci liczby cyfr znaczących:
  // //** x = 123456789.123456789123456
  // //**   - dla liczb pojedynczej precyzji co najmniej 6 cyfr znaczących 
  // //**       pierwsze cyfry 123456 - na pewno sensowne, reszta cyfr może być bez znaczenia (śmieci)
  // //**         (czyli zapisana w zmiennej liczba to ok. 1234560000 +/- 10000),
  // //**   - dla liczb podwójnej precyzji co najmniej 15 cyfr znaczących
  // //**       123456789.123456 - na pewno sensowne 
  // //**         (zapisana liczba to ok. 123456789.123456 +/- 0.0000001)
 
  // //** definicja z inicjowaniem 
    float f = 1.0f/3.0f;  // zapis stałej float z literką f
    float g = 1.0f/3.0; 
    double d = 1.0/3.0; 
    double e = 1.0f/3.0; 

  
    printf("\nliczby zmiennoprzecinkowe:\n");
    printf("float  -  f = 1.0f/3.0f = %f  (dokładnie: %20.15f)\n", f, f);
    printf("float  -  g = 1.0f/3.0  = %f  (dokładnie: %20.15f)\n", g, g);
    printf("double -  d =  1.0/3.0  = %lf  (dokładnie: %20.15lf)\n", d, d);
    printf("double -  e = 1.0f/3.0  = %lf  (dokładnie: %20.15lf)\n", e, e);
    int s = 1/3;
    printf("(liczba całkowita s = 1/3 = %d - dzielenie całkowite)\n", s);
    int t = 1.0/3.0;
    printf("(liczba całkowita t = 1.0/3.0 = %d - obcięcie przy konwersji)\n", t);
    printf("\n");
    printf("float  -  f = 1.0f/3.0f = %e  (dokładnie: %20.15e)\n", f, f);
    printf("double -  d =  1.0/3.0  = %le  (dokładnie: %20.15le)\n", d, d);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie kilku zmiennych typów float i double oraz nadanie im wartości
  // //**   za pomocą stałych typu float i double
  // //** - wydrukowanie wartości zdefiniowanych i zainicjowanych zmiennych z wystarczającą liczbą cyfr,
  // //**   tak aby zobaczyć jaka jest dokładność (jaki jest błąd wartości zmiennej w stosunku do podstawianej 
  // //**   matematycznej wartości (może to dotyczyć także prostych ułamków dziesiętnych, np. 0.1, 0.2, 0.3)  

    printf("\nZadanie 4\n"); 
    
    float f1=10.0f/12.0f;
    float f2=9.0f/4.3f; 
    double d1=13.2/5.0;
    double d2=3.0/8.1;
    printf("\nfloat  -  f1 = 10.0f/12.0f = %f  (dokładnie: %20.15f)\n", f1, f1);
    printf("float  -  f2 = 9.0f/4.3f = %f  (dokładnie: %20.15f)\n", f2, f2);
    printf("double -  d1 =  13.2/5.0  = %lf  (dokładnie: %20.15lf)\n", d1, d1);
    printf("double -  d2 = 3.0/8.1  = %lf  (dokładnie: %20.15lf)\n", d2, d2);
    
    
  
  //-------------------------------------------- 3.0 --------------------------------------------


  /* 5. OPERATORY RELACJI I WARTOŚCI LOGICZNE  */

  // //** wartość logiczna wyrażeń - obliczanie i zapis w zmiennych
    int a =  n<m ;
    _Bool b = n<m || n>m ;
    printf("\nWartość logiczna wyrażenia: %d<%d wynosi %d (int a = n<m = %d)\n", 
  	 n, m, n<m, a);
    printf("\nWartość logiczna wyrażenia: %d<%d lub %d>%d wynosi %d (_Bool b = n<m||n>m = %d)\n", 
  	 n, m, n, m, (n<m)||(n>m), b);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - skonstruowanie kilku złożonych wyrażeń logicznych, które będą np. sprawdzać zasady rachunku zdań:
  // //**   (p lub q) i r  =? (p i r) lub (q i r) - czy jest to równoważne
  // //**   (p i q) lub r  =? (p lub r) i (q lub r) - czy jest to równoważne
  // //** - jaka jest kolejność operacji i wynik w przypadku usuwania kolejnych nawiasów

  printf("\nZadanie 5\n");
  
  _Bool p1 = 0;
  _Bool q1 = 0;
  _Bool r1 = 1;
  _Bool b1= (p1 || q1) && r1;
  _Bool b2= (p1 && r1) || (q1 && r1);
  _Bool b3= (p1 && q1) || r1;
  _Bool b4= (p1 || r1) && (q1 ||r1);
  printf("\nWartości logiczne: p = %d, q = %d, r = %d\n", p1, q1, r1);
  printf("\nWartość logiczna zdania:(p lub q) i r = (p i r) lub (q i r) wynosi: %d",b1=b2);
  printf("\nWartość logiczna zdania: (p i q) lub r = (p lub r) i (q lub r) wynosi %d",b3=b4);
  printf("\n");

  /* 6. Operatory oraz niejawne i jawne konwersje typów  */
  
   e = f; // e typu double, f typu float 
   d = 1111 + 1000 * n; // d = (double) ...;
   n = f + 2.5; // n = (int) ...;
   printf("\nNiejawne i jawne konwersje typów:\n");
   printf("n = %d, f = %f, d = %lf, e = %le\n", n, f, d, e);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zapisanie kilku wyrażeń z operacjami na zmiennych różnych typów i zapisie do zmiennej
  // //** - sprawdzenie otrzymanego wyniku: jakich konwersji dokonał kompilator?
  // //** - zapisanie kilku wyrażeń z jawną konwersją typów, obserwacja otrzymanych wyników (np.
  // //**   dla kilku wariantów podstawienia do f:  n / 3 , (double) n / 3 ,  n / 3.0 , (double) (n / 3)
  
  printf("\nZadanie 6\n");
  
  int z1=16;
  float z2=18.0f;
  double z3=9.0;
  int z4=z2/z3;
  float z5=z1/4;
  double z6= z2/(-3);
  printf("\nWartość zmiennej z1 = %d, zmiennej z2 = %f, zmiennej z3 = %lf", z1, z2, z3);
  printf("\nz4 = z2/z3 - JAKO INT = %d\nz5 = z1/4 - JAKO FLOAT = %f\nz6 = z2/(-3) - JAKO DOUBLE = %lf", z4, z5, z6 );
  printf("\nz4 = z2/z3 - JAKO DOUBLE = %lf,\nz5 = z1/4 - JAKO INT = %d,\nz6 = z2/(-3) - JAKO FLOAT = %f", (double)z2/z3, (int)z1/4, (float)z2/(-3));
  n=4;
  printf("\n\nWartość n = %d", n);
  printf("\nn/3 = %d, \n(double) n/3 = %lf, \nn/3.0 = %lf, \n(double) (n/3) = %lf", n/3, (double)n/3, n/3.0, (double)(n/3));
  printf("\n");
  
    /* 7. DEFINICJE STAŁYCH SYMBOLICZNYCH (CD.) */

  // //** UWAGA: definicje symboli #define powinny być na początku pliku (po #include) !!!!!!!!!!
  // //** najlepszym sposobem na "magic numbers" jest umieszczenie ich na początku pliku
  // //** zakodowanych w postaci "stałych nazwanych" (RAZEM Z ODPOWIEDNIMI KOMENTARZAMI), np.:
   #define JednaTrzeciaFloat (1.0f/3.0f) // 1/3 z dokładnością float (czasem nazwa zastępuje komentarz)
   #define JednaTrzecia (1.0/3.0) // uwaga na odczyt przy podstawieniu (rola nawiasów)
           // //** brak nawiasów może spowodować problemy z kolejnością wykonywania operacji
           // //** 3.0*1.0/3.0 może być różne od 3.0*(1.0/3.0)
           // //** (3*1)/3 jest na pewno różne od 3*(1/3)
           // //** 3*1/3 może być różne od 3*(1/3)


  // //** Precyzja stałych i zmiennych
  // //** (uwaga na mozliwe modyfikacje dokonywane przez kompilator (np. (1.0f/3.0f)*3.0f -> 1.0)
    d = JednaTrzecia * 3.0;
    e = JednaTrzeciaFloat * 3.0;
    printf("\nPrecyzja stałych i niejawne konwersje:\n");
    printf("(1.0/3.0)*3.0: \tJednaTrzecia -> d = %20.15lf; \n\t\tJednaTrzeciaFloat -> e = %20.15lf\n", d, e);

  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie symbolu zawierającego wyrażenie arytmetyczne bez użycia nawiasu
  // //**   (np. #define JednaTrzecia (1.0/3.0) ) i znalezienie zastosowania prowadzącego do błędu
  // //**   (np. dla symbolu powyżej operacja: (1.0/3.0) / JednaTrzecia ), obserwacja wyniku
  // //** - wyjaśnienie źródła błędu
  // //** - własne przykłady dla powyższej sytuacji

  printf("\nZadanie 7\n");
  #define JednaTrzecia2 1.0/3.0
  float z7 = JednaTrzecia2 * 3.0;  
  float z8=(1.0/3.0) / JednaTrzecia ;
  printf("\n(1.0/3.0) / JednaTrzecia -> z8 = %20.15lf",z8);
  printf("\nJednaTrzecia2 -> z7 = %20.15lf",z7);
  printf("\nJednaTrzecia/JednaTrzecia2 = %20.15lf, ale\nJednaTrzecia/JednaTrzeciaFloat = %20.15lf\n WYNIKA TO Z RÓŻNICY PRECYZJI FLOAT I DOUBLE", d/z7, (double)d/e);
  printf("\n");

  //-------------------------------------------- 4.0 --------------------------------------------
  
  // //** WŁASNE EKSPERYMENTY
  // //** ze zmiennymi całkowitymi, operatorami i ich priorytetami
  // //** np. sprawdzenie efektu operacji m+n, m++n, m+++n, m++++n, m+++++n, m+++n++++, itd.
  //printf("\nn = %d, m = %d\n", n, m);
  //o = m...n;
  //printf("\tpo operacji o = m...n = %d: n = %d, m = %d\n", o, n, m);

  printf("\nZadanie 8\n");
  n=2;
  m=4;
  printf("\nn = 2\nm = 4\nm+n = %d, po tej operacji n = %d, m = %d\n", m+n, n, m);
  printf("m+(++n) = %d, po tej operacji n = %d, m = %d\n", m+(++n), n, m);
  printf("m+++n = %d, po tej operacji n = %d, m = %d\n", m+++n, n, m);
  printf("(m++)+n = %d, po tej operacji n = %d, m = %d\n", (m++)+n, n, m);
  printf("(m++)+(++n) = %d, po tej operacji n = %d, m = %d\n", (m++)+(++n), n, m);
  printf("++m+(++n) = %d, po tej operacji n = %d, m = %d\n", ++m+(++n), n, m);
  printf("++m+n = %d, po tej operacji n = %d, m = %d\n", ++m+n, n, m);
  printf("++m+n++ = %d, po tej operacji n = %d, m = %d\n", ++m+n++, n, m);
 

  /* 7. PROBLEMY Z PRECYZJĄ LICZB ZMIENNOPRZECINKOWYCH */

    printf("\nProblemy z precyzją zmiennych float i double:\n");

  // //** kłopoty z precyzją:
    float fx1 = 1.23e7;
    float fx2 = 1.23e-7;

    printf("\nfloat: fx1 = %20.15lf, fx2 = %20.15lf, \n", fx1, fx2);
    if( (fx1+fx2)-fx1 == fx2 ){
      printf("\n(fx1+fx2)-fx1 == fx2 (dla float)\n");
    }
    else {
      printf("\n(fx1+fx2)-fx1 != fx2 (dla float) ( (fx1+fx2)-fx1 = %.15lf )\n",
    	   (fx1+fx2)-fx1);
    }

   //** kłopoty z precyzją:
    double dx1 = 1.23e7;
    double dx2 = 1.23e-7;


    printf("\ndouble: dx1 = %20.15lf, dx2 = %20.15lf, \n",
    	 dx1, dx2);
    if( (dx1+dx2)-dx1 == dx2 ){
      printf("\n(dx1+dx2)-dx1 == dx2 (dla double)\n");
    }
    else {
      printf("\n(dx1+dx2)-dx1 != dx2 (nawet dla double!) ( (dx1+dx2)-dx1 = %.15lf )\n",
    	   (dx1+dx2)-dx1);
    }
 

  // //** obsługa błędów - temat rzeka
  // //** wariant prosty:

  // //** chcemy obliczyć 1 / ( (fx1+fx2)-fx1 ) - powinno być równe 1/fx2

  // //** próba uniknięcia dzielenia przez zero:
  // //** if( fx2 != 0.0 ){ - błędy: 1. (fx1+fx2)-fx1 != fx2, 2. porównanie float

  // //** poprawna próba uniknięcia dzielenia przez zero lub utraty precyzji:
  // //** (należy wcześniej odkomentować definicje stałej nazwanej TOLERANCE na początku pliku)
    /*if( fabs ((fx1+fx2)-fx1) < TOLERANCE){
      printf("\nPróba dzielenia przez liczbę bliską zero! Przerwanie programu!\n");    
    return(-1); 
    // //** lub exit(-1) - exit przerywa wykonanie całego programu, nie tylko aktualnej funkcji    
    }*/

    float fx3 = 1.0f / ((fx1+fx2)-fx1); // powinno byc równe 1/fx2...
    printf("\n1.0f / ((fx1+fx2)-fx1) = %20.15lf\n", fx3);
  
    double dx3 = 1.0 / ((dx1+dx2)-dx1); // powinno byc równe 1/dx2...
    printf("\n1.0/((dx1+dx2)-dx1) = %.12lf  != 1.0/dx2 = %.12lf\n", dx3, 1.0/dx2);
    printf("Zostały tylko trzy cyfry znaczące na skutek skończonej precyzji...\n");

    printf("\nZadanie 9\n");
    /*Problem (1/x)*x dla float i double*/
    float fx4=1.0000000f;
    float x=0.0000000000000000000000000000000000000001212f;/* Dla tak małej liczby x jest przyrównywany do 0, mimo że nim nie jest. */
    printf("\nx= %.64f", x);
    printf("\n\n(1/x)*x = %.64f, a powinno wynosić 1\n", (fx4/x)*x);
  
    float w1=1.0f;
    float w2=0.00000001f; //WARTOŚĆ GRANICZNA dla float, dla w2<=0.00000001f - w2 jest uznawane za 0, mimo że w2!=0;
    printf("\nw1=%.15f", w1);
    printf("\nw2=%.15f", w2);
    printf("\n(w1+w2)=%.15f", w1+w2);
    double w3=1.0;
    double w4=0.0000000000000001; //WARTOŚĆ GRANICZNA dla double, dla w4<=0.0000000000000001 - w4 jest uznawane za 0, mimo że w4!=0; ("DWA RAZY WIĘKSZA PRECYZJA OD FLOAT")
    printf("\nw3=%.15lf\nw4=%.20lf", w3, w4);
    printf("\n(w3+w4)=%.32lf", w3+w4);
    float w5=72.0000000000000000f;
    float w6=0.00000000000009999999f;
    printf("\n(w5+w6)-w5= %.20f\n(w5-w5)+w6= %.20f", (w5+w6)-w5, (w5-w5)+w6);//Brak łączności i przemienności operacji prowadzi do różnych wyników działań, które matematycznie są sobie równe.
    
  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu jego działania)
  // //**(opis działania kodu z wyjaśnieniem przyczyn problemów z precyzją powinien znaleźć sie w sprawozdaniu)
  // //** - zadania rozszerzające z tematu laboratorium  
  
  printf("\nProgram dotarł do końca\n");
  return(0);
}

