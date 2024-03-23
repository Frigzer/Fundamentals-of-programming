#include <stdio.h>

int main(void)
{
  
  char c;
  for(;;){  // wykonywanie nieskończenie wiele razy

    printf("\nWprowadź cyfrę od 0 do 5, lub naciśnij q aby zakończyć: "); // użytkownik ma możliwosć wyjścia z programu za pomocą klawisza q
    scanf(" %c",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyć się \n ?)
    switch (c) {
    case '0': 
      printf("Wprowadzono: 0\n");
      break;
    case '1':
      printf("Wprowadzono: 1\n");
      break;
    case '2':
      printf("Wprowadzono: 2\n");
      break;
    case '3':
      printf("Wprowadzono: 3\n");
      break;
    case '4':
      printf("Wprowadzono: 4\n");
      break;
    case '5':
      printf("Wprowadzono: 5\n");
      break;
    case 'q': // wprowadzenie q wywołuję specyficzną instrukcję
      return 0; // return 0 kończy nasz program
      break;
    default:
      printf("Wprowadzono: znak spoza zakresu 0-5\n");
      break;
    }
  }

}
