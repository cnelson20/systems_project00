all: song.o library.o
		gcc -o myTunes song.o library.o

song.o: song.c song.h
		gcc -c song.c song.h

library.o: library.c library.h
		gcc -c library.c library.h
		
main.o: main.c
		gcc -c main.c
		
run:
		./struct
