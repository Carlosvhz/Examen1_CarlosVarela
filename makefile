run: main.o pieza.o marine.o general.o
	g++ main.o pieza.o marine.o general.o -o run

main.o: pieza.h marine.h main.cpp
	g++ -c main.cpp

pieza.o:	pieza.h pieza.cpp
	g++ -c pieza.cpp

marine.o:	marine.h marine.cpp
	g++ -c marine.cpp

general.o:	general.h general.cpp
	g++ -c general.cpp

clear:
	rm *.o run
