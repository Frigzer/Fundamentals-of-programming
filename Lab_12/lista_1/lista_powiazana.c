#include <stdlib.h>
#include <stdio.h>

typedef struct element_listy* wsk_el_list;

typedef struct element_listy{
  char* nazwa_wezla;
  int klucz;
  wsk_el_list nastepny_wezel; // wskaźnik do kolejnego elementu
} el_list;

int wstaw_na_poczatek( /* funkcja zwraca kod sukcesu lub bledu */
  el_list** Glowa_wsk, /* lista - identyfikowana przez wskaznik */ 
  el_list* Element_wsk     /* wskaznik do elementu wstawianego na liste */
		       )
{
  
  //printf("Glowa %lu, Element_wsk %lu\n", *Glowa_wsk, Element_wsk);
  
  Element_wsk->nastepny_wezel=*Glowa_wsk;
  *Glowa_wsk=Element_wsk;
  
  //printf("Glowa %lu, Element_wsk %lu\n", *Glowa_wsk, Element_wsk);
  return 0;
  
}

void drukuj_lista( /* funkcja zwraca kod sukcesu lub bledu */
  el_list* Glowa   /* lista - identyfikowana przez wskaznik */ 
		   )
{
  el_list* Element_wsk=Glowa; 
  printf("wydruk listy:   ");
  while(Element_wsk!=NULL){
    //printf("%s: ", Element_wsk->nazwa_wezla); // napis!
    printf("%d  , ", Element_wsk->klucz); 
    Element_wsk = Element_wsk->nastepny_wezel;
  }
  printf("koniec\n");
}

int usun_lista(     /* procedura zwraca kod sukcesu lub bledu */
  el_list** Glowa_wsk,   /* lista - identyfikowana przez wskaznik */ 
  el_list*  Element_wsk  /* wskaznik do elementu usuwanego z listy */
		    )
{
  
  if(*Glowa_wsk==Element_wsk){
    *Glowa_wsk=Element_wsk->nastepny_wezel;
  }
  else{
    el_list* poprzedni_wezel = *Glowa_wsk;
    while(poprzedni_wezel->nastepny_wezel != Element_wsk){
      poprzedni_wezel = poprzedni_wezel->nastepny_wezel;
    }
    poprzedni_wezel->nastepny_wezel = Element_wsk->nastepny_wezel;
  }
  return 0;
}


el_list* wyszukaj_lista( /* procedura zwraca wskaźnik do wyszukanego elementu */
  el_list* Glowa,   /* lista - identyfikowana przez wskaznik */ 
  int  klucz         /* in: klucz do wyszukiwania */
  )
{
  el_list* Element_wsk = Glowa; 
  while(Element_wsk!=NULL){
    if(Element_wsk->klucz == klucz) break;
    Element_wsk = Element_wsk->nastepny_wezel;
  }
  return Element_wsk;
}


int main ()
{
  
  printf("\nZabawa z listą\n");
  printf(" - naciśnięcie klawisza ENTER powoduje zmianę listy\n");
  printf(" - CTRL+C kończy program\n");

  el_list* Glowa = NULL;

  int k=0;
  for(;;){

    getchar();
    if(drand48()<0.5) {

      el_list* element_wsk = malloc(sizeof(el_list));
      
      element_wsk->nazwa_wezla = malloc( 100*sizeof(char) );
      //element_wsk->nazwa_wezla = "Wezel";
      k++;
      sprintf(element_wsk->nazwa_wezla, "Węzeł %d", k);
      element_wsk->klucz = 10*drand48();
      element_wsk->nastepny_wezel = NULL;
      
      wstaw_na_poczatek(&Glowa, element_wsk);
      printf("wstawione - %d :  ", element_wsk->klucz);
      drukuj_lista(Glowa);
      
    }
    else {

      int j=10*drand48();
      el_list* Element_wsk = wyszukaj_lista(Glowa, j);
      printf("klucz %d",j);
      if(Element_wsk!=NULL) printf(" znaleziony !\n");
      else printf(" nie znaleziony\n");
      if(Element_wsk!=NULL) {
	usun_lista(&Glowa, Element_wsk);
	printf("po usunięciu :  ");
	drukuj_lista(Glowa);
	free(Element_wsk); // co stanie się jeśli nie będziemy pamiętac o zwolnieniu pamięci?
      }
    }
  }
  

}
