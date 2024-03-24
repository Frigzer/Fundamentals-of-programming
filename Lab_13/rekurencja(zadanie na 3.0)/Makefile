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

zabawa: potega.o
	$(LD) $(LDFL) -o zabawa  potega.o $(LIB) -std=c99

potega.o: potega.c 
	$(CC) $(CFL)  -c potega.c $(INC) -std=c99

clean:
	rm -f *.o 


