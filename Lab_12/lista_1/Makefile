SHELL = /bin/sh

# kompilator C
CC = gcc
# konsolidator (linker, loader) C
LD = gcc
# archiwizator (program do tworzenia bibliotek)
AR = ar -ru

# opcje kompilacji
# wersja do debugowania
CFL = -g -DMY_DEBUG
# wersja zoptymalizowana 
# OPT = -O3
#opcje linkowania
LDFL = 
# katalogi z bibliotekami i dolaczane biblioteki
# biblioteki
#LIB = -L../lib -llista_powiazana -lm
# katalogi z plikami naglowkowymi i  pliki naglowkowe 
#INC = -I../include

zabawa: lista_powiazana.o
	$(LD) $(LDFL) -o zabawa  lista_powiazana.o $(LIB)

lista_powiazana.o: lista_powiazana.c 
	$(CC) $(CFL) -c lista_powiazana.c $(INC)

clean:
	rm -f *.o 

