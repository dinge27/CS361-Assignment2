run: main.o catalog.o character.o
	g++ main.o catalog.o character.o -o run

main.o: main.cpp
	g++ -c main.cpp

catalog.o: catalog.cpp catalog.h
	g++ -c catalog.cpp

character.o: character.cpp character.h
	g++ -c character.cpp