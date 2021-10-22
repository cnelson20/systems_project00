all: myTunes
	
myTunes: song.o library.o main.o
		gcc -o myTunes song.o library.o main.o

song.o: song.c song.h
		gcc -c song.c

library.o: library.c library.h
		gcc -c library.c		

main.o: main.c
		gcc -c main.c

run:
		./myTunes
