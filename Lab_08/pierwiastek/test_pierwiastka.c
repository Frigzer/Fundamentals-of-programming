#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define ACCURACY (1.e-5) // do przeprowadzania obliczeń i sprawdzenia dokładności wyniku

// 1 i 2 zaprojektowanie prototypu funkcji obliczania pierwiastka i umieszczenie go 
//       jako deklaracji funkcji

double pierwiastek( );


// 0. przed wykonaniem ćwiczenia cały kod w funkcji main (analiza, uruchomienie)   
int main( void ) {
  
  double liczba;
  //double dokladnosc = ACCURACY;
  
  for(;;){
    
    
    printf("\nPodaj wartość liczby dodatniej :\n");
    scanf("%lf",&liczba);

    //if(liczba<=0.0) break;
    
    //printf("Pierwiastek wynosi: %18.15lf\n", pierwiastek(liczba,dokladnosc));
    //printf("Suma pierwiastkow liczby wynosi: %18.15lf\n",pierwiastek(liczba,dokladnosc)+pierwiastek(liczba,dokladnosc));
    //printf("Jako argument zewnetrznego wywolania: %18.15lf\n",pierwiastek(pierwiastek(liczba,dokladnosc),dokladnosc));

    double bl;
    // w wariancie pierwszym każda liczba ujemna przerywa program
    // (nie wywołujemy funkcji dla argumentów ujemnych)
    // przy modyfikacji kontraktu można to zmienić
    

    // 0. przed wykonaniem ćwiczenia cały kod w funkcji main (analiza, uruchomienie) 
    
    // 3. wywołanie zaprojektowanej funkcji obliczania pierwiastka
    
    //if(liczba<0.0) return (0);
    //printf("\tzałożona dokładność (względna) obliczania pierwiastka w funkcji main: %18.15lf\n", ACCURACY);
    //pierwiastek(liczba,dokladnosc);
    if((bl=pierwiastek(liczba/*,dokladnosc*/))==false){ 
      printf("Podano liczbe nie dodatnia\n"); 
      continue;
    }
    
    printf("blad wzgledny wyniku: %18.15lf", bl); 
    

    // 4. wydruk obliczonego pierwiastka

    // ewentualne dodatkowe wywołania funkcji obliczania pierwiastka, zgodnie z instrukcją

    // 5. zakończenie nieskończonej pętli for i funkcji main
    
    

    // 6. nagłowek - początek definicji funkcji
// definicja funkcji + komentarze (z komentarzy można tworzyć dokumentację):

// funkcja oblicz_pierwiastek oblicza pierwiastek za pomocą wzoru Herona
//               dla dowolnej liczby podwójnej precyzji większej od zera
// czy kontrakt wymaga specjalnych działań dla liczb ujemnych?
// wariant 1. funkcja zakłada, że argument jest nie mniejszy niż zero
// wariant 2. dla liczb mniejszych od zera funkcja zwraca kod błędu: -1
//   implementacja w kodzie, np.
//  if(arg<0){
//    // obsługa błędu wejścia, np.
//    return(-1.0); // wyjaśnienie w dokumentacji
//  }

    
    // 7. przekształcenie kodu poniżej, tak aby stanowił treść funkcji
    //    (z odpowiednim argumentem i własnymi zmiennymi lokalnymi)
    //    (uwaga: brak nieskończonej pętli for - co zamiast break?)
    
    /*double pierwiastek = 1.0;
    double temp; int iteracje=0;
    // obliczenia pierwiastka za pomocą wzoru Herona
    do{
      iteracje++;
      temp = pierwiastek;
      pierwiastek = 0.5 * (temp + liczba/temp);

      // dodatkowe wydruki kontrolne
      // np. do debugowania działania funkcji

//    printf("wartość %20.15lf, \tbłąd  %20.15lf,     błąd kwadratu %20.15lf\n", 
//	   pierwiastek, fabs(pierwiastek - temp)/pierwiastek, 
//	   fabs(pierwiastek*pierwiastek - arg)/arg);
      
      
      // sprawdzenie warunku wyjścia z pętli - błąd względny obliczania pierwiastka
    } while(fabs(pierwiastek*pierwiastek - liczba)/liczba > ACCURACY); */
    
    // wydruki kontrolne - można je wyłączyć po zdebugowaniu funkcji
    /*printf("\nliczba do obliczenia pierwiastka: %18.15lf\n", liczba);
    printf("\tzałożona dokładność (względna) obliczania pierwiastka: %18.15lf\n", 
	   ACCURACY);
    // ten wydruk można (po odpowiedniej modyfikacji skopiować także do main)
    printf("\tpierwiastek liczby: obliczony %18.15lf, dokładny %18.15lf\n", 
	   pierwiastek, sqrt(liczba));
    printf("liczba iteracji %d, błąd bezwzględny: %18.15lf, błąd względny: %18.15lf\n",
	   iteracje, pierwiastek-sqrt(liczba), (pierwiastek-sqrt(liczba))/sqrt(liczba));*/


    // 8. zamiana zakończenia funkcji main (z pętlą for) na zakończenie funkcji
    //    obliczania pierwiastka

    // ---------------- 3.0 --------------------------------
    
  }
}

double pierwiastek( double l/*, double dokladnosc*/){
  
  if(l<=0) return false;
  //dokladnosc*=0.1;
  double p = 1.0;
  double t; 
  int i=0;
  
  do{
      i++;
      t = p;
      p = 0.5 * (t + l/t);
      } while(fabs(p*p - l)/l > ACCURACY); 
  //printf("\nliczba do obliczenia pierwiastka: %18.15lf\n", l);
  //printf("\tzałożona dokładność (względna) obliczania pierwiastka w funkcji pierwiastek: %18.15lf\n", dokladnosc);
  //printf("\tpierwiastek liczby: obliczony %18.15lf, dokładny %18.15lf\n", p, sqrt(l));
  //printf("liczba iteracji %d, błąd bezwzględny: %18.15lf, błąd względny: %18.15lf\n", i, p-sqrt(l), (p-sqrt(l))/sqrt(l));
  return ((p-sqrt(l))/sqrt(l));
  //return sqrt(l);
}
// dla 10^7 i 10^-7 blad wzgledny jest praktycznie identyczny






// im mniejsza wartosc to blad bezwzgledny jest mniejszy
// im wieksza wartosc to blad wzgledny jest mniejszy, blad bezwzgledny staje sie duzo wiekszy

