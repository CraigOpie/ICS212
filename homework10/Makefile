homework10: homework10.o Giratina.o Mewtwo.o Arceus.o Pokemon.o
		g++ -o homework10 homework10.o Giratina.o Mewtwo.o Arceus.o Pokemon.o
homework10.o: homework10.cpp
		g++ -ansi -pedantic-errors -Wall -c homework10.cpp
Giratina.o: Giratina.cpp
		g++ -ansi -pedantic-errors -Wall -c Giratina.cpp
Mewtwo.o: Mewtwo.cpp
		g++ -ansi -pedantic-errors -Wall -c Mewtwo.cpp
Arceus.o: Arceus.cpp
		g++ -ansi -pedantic-errors -Wall -c Arceus.cpp
Pokemon.o: Pokemon.cpp
		g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp
ready:
		touch homework10.cpp Giratina.cpp Mewtwo.cpp Arceus.cpp Pokemon.cpp
clean:
		rm -f homework10 homework10.o Giratina.o Mewtwo.o Arceus.o Pokemon.o
