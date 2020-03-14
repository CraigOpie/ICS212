project: main.o user_interface.o database.o iofunctions.o
		gcc -o project1 main.o user_interface.o database.o iofunctions.o
main.o: main.c
		gcc -ansi -pedantic-errors -Wall -c main.c
iofunctions.o: iofunctions.c iofunctions.h
		gcc -ansi -pedantic-errors -Wall -c iofunctions.c
user_interface.o: user_interface.c user_interface.h
		gcc -ansi -pedantic-errors -Wall -c user_interface.c
database.o: database.c database.h
		gcc -ansi -pedantic-errors -Wall -c database.c
ready:
		touch main.c user_interface.c database.c iofunctions.c
clean:
		rm -f *.o project .database