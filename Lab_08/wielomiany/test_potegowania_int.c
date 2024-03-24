#include <stdio.h>
#include <limits.h>

// funkcja oblicza potęgę całkowitą liczby całkowitej
//int potega_int(int m, int n);
//int oblicz_wielomian_int (int tab_wsp[], int argument, int stopien);
int oblicz_wielomian_int_Horner (int tab[], int argument, int stopien);

int main (void)
{

  /*int i;
  for (i = 0; i < 10; i++){
    printf("i = %d \t2^i = %d \t(-3)^i = %d\n", 
	   i, potega_int(2,i), potega_int(-3,i));
  }*/
  
  int stopien;
  //int suma;
  int suma_horner;
  int argument;
  //printf("Ktorego stopnia wielomian chcesz obliczyć? ");
  //scanf("%d", &stopien);
  //if(stopien<0) return (0);
  stopien=100;
  int tab[stopien+1]; // tablica wspolczynnikow wielomianu
  //printf("Podaj argument wielomianu: ");
  //scanf("%d", &argument);
  argument=12;
  srand( time( NULL ) );
  for(int j=0; j<=1000000; j++){
    //suma=0;
    for(int i=0; i<=stopien; i++){
      //printf("%d wspolczynnik wielomianu: ", i+1);
      //scanf("%d", &tab[i]);
      tab[i]= rand() % 1001; // do tego milion-razy
      //suma+= oblicz_wielomian_int(tab[i], argument, i);
    }
    suma_horner=oblicz_wielomian_int_Horner(tab, argument, stopien);
  }
  //suma_horner=oblicz_wielomian_int_Horner(tab, argument, stopien);
  //if((fabs(suma))>INT_MAX || (fabs(suma_horner))>INT_MAX ){ printf("Wynik przekracza INT_MAX"); return (0);} // sprawdzenie czy nie przekraczaja INT_MAX
  //printf("Wartosc wielomianu wynosi: %d\n", suma);
  //printf("Wartosc wielomianu hornerem wynosi: %d\n", suma_horner);
}

// funkcja oblicza potęgę całkowitą liczby całkowitej
//int potega_int( // funkcja zwraca wartość potegi podstawa^wykładnik
	     // int podstawa, // [in]: zadana podstawa 
	    //  int wykladnik // [in]: zadany wykładnik
	     //  )
//{
  //int potega = 1;
  //for (int i = 1; i <= wykladnik; i++){
    //potega *= podstawa;
  //}
  //return potega;
//}
//
//int oblicz_wielomian_int (int tab_wsp[], int argument, int stopien){

  //return (int)tab_wsp*potega_int( argument, stopien);
//}

int oblicz_wielomian_int_Horner (int tab[], int argument, int stopien){
  
  
  if(stopien==0) return tab[0];
  
  int wynik = tab[stopien];

  for(int i=stopien-1;i>=0;i--)
    wynik = tab[i] + argument*wynik;
	
  return wynik;
}

// czasy dla stopien 50, argument 4
// f:oblicz_wielomian_int: real 0m6,011s,  user 0m0,003s,  sys 0m0,000s
// f:oblicz_wielomian_int_horner: real 0m2,772s,  user 0m0,000s,  sys 0m0,003s


// modyfikacje potega_int_1 - sprawdzanie w trakcie obliczeń czy obliczane wartości 
//                           nie przekraczają zakresu liczb całkowitych INT_MAX
//                           (zdefiniowane w pliku limits.h)


// Przypadek schematu Hornera dla wielomianu 4 stopnia
// a[0] + a[1]*x + a[2]*x^2 + a[3]*x^3 + a[4]*x^4:
//
// a[0] + x*( a[1] + x*( a[2] + x*( a[3] + x*a[4]) ) )
//
