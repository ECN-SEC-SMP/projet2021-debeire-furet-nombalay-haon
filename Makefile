all: monopoly.out

monopoly.out: main.o Achetables.o Case.o Constructibles.o Fixes.o Gares.o Joueur.o Plateau.o
	g++ -o monopoly.out Achetables.o Case.o Constructibles.o Fixes.o Gares.o Joueur.o Plateau.o

main.o: main.cpp
	g++ -c main.cpp

Achetables.o: Achetables.cpp Achetables.h
	g++ -c Achetables.cpp

Case.o: Case.cpp Case.h
	g++ -c Case.cpp

Constructibles.o: Constructibles.cpp Constructibles.h
	g++ -c Constructibles.cpp

Fixes.o: Fixes.cpp Fixes.h
	g++ -c Fixes.cpp

Gares.o: Gares.cpp Gares.h
	g++ -c Gares.cpp

Joueur.o: Joueur.cpp Joueur.h
	g++ -c Joueur.cpp

Plateau.o: Plateau.cpp Plateau.h
	g++ -c Plateau.cpp

clean:
	rm *.out
	rm *.o