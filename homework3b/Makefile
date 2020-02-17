homework3b: main.o user_interface.o database.o
		gcc -o homework3b main.o user_interface.o database.o
main.o: main.c
		gcc -ansi -pedantic-errors -Wall -c main.c
user_interface.o: user_interface.c user_interface.h
		gcc -ansi -pedantic-errors -Wall -c user_interface.c
database.o: database.c database.h
		gcc -ansi -pedantic-errors -Wall -c database.c
ready:
		touch main.c user_interface.c database.c
clean:
		rm -f *.o homework3b proof.txt output.txt
