homework2b: driver.o halfstring.o mystring.o
		gcc -o homework2b *.o
driver.o halfstring.o mystring.o: driver.c halfstring.c mystring.c halfstring.h mystring.h
		gcc -ansi -pedantic-errors -Wall -c *.c
clean:
		rm -f *.o homework2b
