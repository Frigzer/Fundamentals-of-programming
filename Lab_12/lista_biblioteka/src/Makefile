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
LIB = -L../lib -llista_powiazana -lm
# katalogi z plikami naglowkowymi i  pliki naglowkowe 
INC = -I../include

zabawa: main.o 
	$(LD) $(LDFL) -o zabawa main.o $(LIB)

main.o: main.c 
	$(CC) $(CFL) -c main.c $(INC)
	
clean:
	rm -f *.o 

