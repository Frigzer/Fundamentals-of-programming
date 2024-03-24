#include <stdio.h>

#define MAXLINE 100

int main( void ) // program kopiowania z stdin na stdout
{
  //int c;
  //c = getchar();
  //while (c != EOF) {
  //  putchar(c);
  //  c = getchar ();
  //}
  
  // 1. zamiana programu jak wyżej na program wykorzystujący formę skrótową 
  // (po sprawdzeniu działania programu oryginalnego, należy go wykomentować w całości,
  // a następnie napisać (odkomentować) wersję skróconą (poniżej)
  
  // while( (c = getchar()) != EOF && c!='\n') { putchar(c); }
  // printf("\n");
   
  // - po sprawdzeniu poprawności działania wprowadzenie kończenia wczytywania
  //   po wpisaniu znaku końca linii
  
  
  // 2. Dodanie wczytywania do tablicy znaków
  //    - definicja tablicy przed pętlą (z zadaną maksymalna długością napisu)
  //    - po wczytaniu do zmiennej c i wypisaniu na ekranie, podstawienie do tablicy
  //    - uwaga na zakończenie tablicy:
  //       - długość nie może być zbyt duża (wprowadzenie nowych warunków)
  //       - koniec musi byc zawsze zgodny z konwencją
  
  /*int c;
  char s[MAXLINE];
  int zakres=MAXLINE-1;
  int i;
  for (i=0; i<zakres && (c=getchar()) != EOF; i++)
    s[i] = c;
  if (c == '\n') { s[i] = c; i++; } // koniec linii też do tablicy
    s[i] = '\0'; // od 0 do i - czyli i+1 elementów tablicy
  printf("Wartosc tablicy:\n%s\n",s);*/
  
  // 3. Dodanie wypisywania wczytanych znaków jako liczb całkowitych
  
  
  /*int c;
  char s[MAXLINE];
  int zakres=MAXLINE-1;
  int i;
  int l;
  for (i=0; i<zakres && (c=getchar()) != EOF; i++){
    s[i] = c; 
    if(c!='\n' && c!=' ' && c!='\t'){
      l = c - '0';
      printf("%c jako int: %d\n",c, l);
    }
  }
  if (c == '\n') { s[i] = c; i++; } // koniec linii też do tablicy
    s[i] = '\0'; // od 0 do i - czyli i+1 elementów tablicy
  printf("Wartosc tablicy:\n%s\n",s);
 

  // Program switch.c - w innym pliku

  //-------------------------------- 3.0 ------------------------------------

  // 5. Wpisanie kodu (na podstawie wykładu) zliczającego liczbę znaków w tablicy
  //    - ewentualna zamiana pętli for na while
  
  for (i = 0; s[i] != '\0'; i++) {};
    printf("Ilosc znakow w petli: %d\n",i-1);

  
  // 6. Wpisanie kodu (na podstawie wykładu) przepisującego zawartość jednej tablicy
  //    znaków do drugiej (ewentualna zamiana pętli while na do)
  
  char z[MAXLINE];
  i=0; 
  char t;
  while( (t=s[i])!='\0' ) { z[i]=t; i++; }
  z[i] = '\0';

  // 7. Wpisanie kodu (na podstawie wykładu) porównującego zawartość dwóch tablic
  //    - ewentualna zamiana pętli do na while lub for

  i=0;
  int wynik=0;
  do{
  if(s[i]!=z[i]) { wynik=1; break; }
  i++;
  } while (s[i]!= '\0' && z[i]!= '\0');
  if(wynik==1) printf("Tablice nie sa identyczne\n");
  else printf("Tablice sa identyczne\n");*/


  //-------------------------------- 4.0 ------------------------------------

  // 8. Napisanie kodu tworzenia tablicy o okreslonej długości i wypełniania
  //     losowymi znakami ( z tablicy ASCII - od 0 do 127, lub dla wybranego
  //     podzbioru znaków, np. małych liter lub t.p.)

  // male litery
  int i=0;
  char a[MAXLINE];
  int p;
  int znaki[26]={0};
  srand( time( NULL ) );
  for(i=0; i<MAXLINE; i++){
    p= 97 + rand() % 26;
    a[i]=p;
    printf("[%d] element tablicy to: %c\n", i, a[i]);
    znaki[p-97]++;
  }
  a[i]="\0";

  // 9. Napisanie kodu tworzenia histogramu dla otrzymanej tablicy
  //    ( for(....) histogram[ tablica[i] - pierwszy_znak ] ++; )
  
  printf("\nznaki:\n");  
  for (i = 97; i < 123; i++) printf("%c = %d\n", i, znaki[i-97]);
  // 10. graficzna prezentacja histogramu
  
  printf("\nznaki graficznie:\n"); 
  int j=0; 
  for (i = 97; i < 123; i++){
    printf("%c = ", i);
    for(j=0; j<znaki[i-97]; j++)
      printf("%c", i);
    printf("\n");
  }
  
  //-------------------------------- 5.0 ------------------------------------

 

}

