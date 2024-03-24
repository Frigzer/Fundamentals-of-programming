#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES


#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-20 

/* ---------------------------------------------------------
  rownanie_kwadratowe - funkcja pobiera od użytkownika trzy 
  zmienne a,b,c i korzystająć ze wzoru ax^ + bx + c = 0
  oblicza i zwraca wartości dwóch pierwiastków rzeczywistych.
  W przypadku podania danych nie umożliwiających obliczenia
  dwóch pierwiastków rzeczywistych funkcja zwraca odpowiedzni
  komunikat dla użytkownika
---------------------------------------------------------- */ 

void rownanie_kwadratowe( SCALAR a, // argument wejsciowy podawany przez uzytkownika
                          SCALAR b, // argument wejsciowy podawany przez uzytkownika
                          SCALAR c, // argument wejsciowy podawany przez uzytkownika
                          SCALAR *x1, // argument wyjsciowy - wskaznik do naszego obliczonego pierwiastka
                          SCALAR *x2 // argument wyjsciowy - wskaznik do naszego obliczonego pierwiastka
                          ); // deklaracja funkcji


int main(void)
{


  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");


  SCALAR a, b, c;

  SCALAR x1, x2;

  // deklaracja wskaznikow
  SCALAR *wskaznik_do_x1 = &x1;
  SCALAR *wskaznik_do_x2 = &x2;
  

  for(;;){ // petla do zadania 5.0 - nie pozwala uzytkownikowi na wprowadzenie blednych wartosci
  
    printf("\nPodaj parametr a: "); scanf("%lf",&a); 
    printf("Podaj parametr b: "); scanf("%lf", &b); 
    printf("Podaj parametr c: "); scanf("%lf", &c);
    
    SCALAR delta = b*b - 4*a*c; // do zadania 5.0 - obliczenie delty
    
    // sprawdzanie czy użytkownik wprowadzil prawidlowe dane
    if( (fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER) ||  (delta<=0)){
      printf("\nPodano bledne wartosci - sprobuj jeszcze raz\n");
      continue;
    }
    else
      break; 
  }
  
  rownanie_kwadratowe( a, b, c, wskaznik_do_x1, wskaznik_do_x2 ); // wywolanie funkcji
  
  printf("Dwa pierwiastki rzeczywiste (main): x1 = %.12le, x2 = %.12le\n", x1, x2 );

  return(0);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  /*if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);

  }
  else{

    if(a==0) { // równanie liniowe

      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?

    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

      if(delta<0){

	printf("Dwa pierwiastki zespolone - nie umiem obliczyć\n");

      } else if (delta == 0){

	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );

      } else {

	SCALAR temp = sqrt(delta);
	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	       (-b-temp)/(2*a), (-b+temp)/(2*a) );

      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }*/  
}


void rownanie_kwadratowe( SCALAR a, SCALAR b, SCALAR c, SCALAR *x1, SCALAR *x2 ){ 
                                                           
                                                                                                             
  // funkcja oblicza wartosc rownania kwadratowego sluza do tego pobrane od uzytkownika zmienne
  // funkcja zwraca dwa pierwiastki rzeczywiste lub konczy program
  
  SCALAR delta = b*b - 4*a*c; // obliczenie delty
  SCALAR temp = sqrt(delta); // przypisanie do zmiennej pomocniczej pierwiastka z delty
  (*x1) = (-b - temp) / (2 * a); // obliczenie pierwszego pierwiastka równania
  (*x2) = (-b + temp) / (2 * a); // obliczenie drugiego pierwiastka równania

  
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // sprawdzenie czy a i b sa rowne 0

      printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
      exit(-1);

    }
    else{

      if(a==0) { // przy probie obliczenia rownania liniowego funkcja konczy sie

        printf("Rownanie liniowe - koniec funkcji\n");
	exit(0);

      }
      else{    

        if(delta<0){ // przy probie obliczenia pierwiastkow zespolonych funkcja konczy sie

	  printf("Dwa pierwiastki zespolone - koniec funkcji\n");
	  exit(0);

        } else if (delta == 0){ // przy probie obliczenia tylko jednego pierwiastka rzeczywistego funkcja konczy sie

	  printf("Jeden pierwiastek rzeczywisty - koniec funkcji\n ");
	  exit(0);

        } else { // przy probie obliczenia dwoch pierwiastkow rzeczywistych funkcja prawidlowo poda wynik
	  printf("Dwa pierwiastki rzeczywiste (funkcja rownanie_kwadratowe): x1 = %.12le, x2 = %.12le\n", *x1, *x2);
        }
      }
    }
}

