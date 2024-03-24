#include <stdio.h>

int main(void)
{
  
  char c;
  for(;;){  // wykonywanie nieskończenie wiele razy

    printf("\nWprowadź cyfrę od 0 do 6, lub naciśnij q aby zakończyć: "); // użytkownik ma możliwosć wyjścia z programu za pomocą klawisza q
    scanf(" %c",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyć się \n ?)
    if(c=='0')printf("Wprowadzono: 0\n");
    else if(c=='1')printf("Wprowadzono: 1\n");
    else if(c=='2')printf("Wprowadzono: 2\n");
    else if(c=='3')printf("Wprowadzono: 3\n");
    else if(c=='4')printf("Wprowadzono: 4\n");
    else if(c=='5')printf("Wprowadzono: 5\n");
    else if(c=='6')printf("Wprowadzono: 6\n");
    else if(c=='q')break; // wprowadzenie q wywołuję instrukcję która kończy pętlę i tym samym cały program
    else printf("Wprowadzono: znak spoza zakresu 0-6\n");
  }

}
