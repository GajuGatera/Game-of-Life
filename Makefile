# Makefile for the Rational class

runlife: lifemain.o life.o
	g++ lifemain.o life.o -o runlife

lifemain.o: lifemain.cpp life.h
	g++ -c -std=c++11 lifemain.cpp -o lifemain.o

life.o: life.cpp life.h
	g++ -c life.cpp -o life.o

clean:
	rm *.o runlife