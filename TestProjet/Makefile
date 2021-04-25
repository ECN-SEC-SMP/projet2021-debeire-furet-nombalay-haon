# A mettre a jour : répertoire d'installation de Google Test
GTEST_DIR = ../googletest/googletest
GTEST_LIB = ../googletest/lib

CPP_FLAGS = -isystem $(GTEST_DIR)/include  -g -Wall -Wextra -pthread -std=c++11

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

mytest.out: mytest.o Case.o Achetables.o Gares.o Joueur.o
	g++ $(CPP_FLAGS) -o mytest.out mytest.o Case.o Achetables.o Gares.o Joueur.o -lpthread $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/libgtest_main.a

mytest.o: mytest.cpp Joueur.h Gares.h Case.h Achetables.h
	g++ -c $(CPP_FLAGS) mytest.cpp

Case.o: Case.cpp Case.h
	g++ -c $(CPP_FLAGS) Case.cpp

Achetables.o: Achetables.cpp Achetables.h
	g++ -c $(CPP_FLAGS) Achetables.cpp

Gares.o: Gares.cpp Gares.h
	g++ -c $(CPP_FLAGS) Gares.cpp

Joueur.o: Joueur.cpp Joueur.h
	g++ -c $(CPP_FLAGS) Joueur.cpp

clean:
	rm *.out
	rm *.o