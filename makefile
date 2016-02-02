Project01: project1.o Fraction.o
	g++ -g project1.o Fraction.o -o Project01
project1.o: project1.cpp
	g++ -g -c project1.cpp
Fraction.o: Fraction.cpp Fraction.h
	g++ -g -c Fraction.cpp
clean:
	rm *.o Project01
