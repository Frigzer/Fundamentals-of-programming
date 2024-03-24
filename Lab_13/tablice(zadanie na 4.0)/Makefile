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

zabawa: loop_table.o
	$(LD) $(LDFL) -o zabawa  loop_table.o $(LIB) -std=c99

potega.o: loop_table.c 
	$(CC) $(CFL)  -c loop_table.c $(INC) -std=c99

clean:
	rm -f *.o 


