#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-20

#ifndef M_PI // standardy C99 i C11 nie wymagają definiowania stałej M_PI
#define M_PI (3.14159265358979323846)
#endif

#define DOKLADNOSC 0.001
//#define MAX_LICZBA_WYRAZOW 1111111111
#define MAX_LICZBA_WYRAZOW 111111

void main( void ){
 
  SCALAR x;
  SCALAR wyrazenie;
  for(;;){
    printf("Podaj liczbę z przedziału (0;1): ");
  if(sizeof(SCALAR)==4){ // czterobajtowe liczby zmiennoprzecinkowe -> float
    scanf("%f", &x);
  }
  else{
    scanf("%lf", &x);
  }
    printf("Wartość liczby: %.15lf\n",x);
    if(x<1 && x>0){
      break;
    }
    else{
      printf("Podano liczbę z poza przedziału\n");
    }
  }
  wyrazenie=1/(1-x);
  printf("Wartość wyrażenia 1/(1-x) wynosi: %.15lf\n", wyrazenie);
  //  1/(1-x)
  return 0;
}



  // całka
  /* h   = 1.0 / (SCALAR) n; */
  /* sum = 0.0; */
  /* for (i = 1; i <= n; i++) { */
  /*   x = h * ((SCALAR)i - 0.5); */
  /*   sum += 4.0 / (1.0 + x*x); */
  /* } */
  /* mypi = h * sum; */
