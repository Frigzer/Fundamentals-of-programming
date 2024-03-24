#ifndef _tekst_wieloliniowy_
#define _tekst_wieloliniowy_

#define MAX_DL_L 100 // maksymalna liczba znaków w jednej linii tekstu
#define MAX_N_L    3 // maksymalna liczba linii tekstu

// typ danych do p. 5 laboratorium
typedef struct linia_tekstu {
  char* znaki;
  int dlugosc_linii;
} linia_tekstu;

// funkcje wczytywania linii ze standardowego wejścia i drukowania linii
// opis z kontraktem na końcu pliku
int wczytaj_linie(char* linia, int max_dlugosc_linii);
void wydrukuj_linie(char* linia, int dlugosc_linii);

#endif
