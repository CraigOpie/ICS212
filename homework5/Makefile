homework5: iofunctions.o driver.o
		gcc -o homework5 iofunctions.o driver.o
iofunctions.o: iofunctions.c iofunctions.h
		gcc -ansi -pedantic-errors -Wall -c iofunctions.c
driver.o: driver.c
		gcc -ansi -pedantic-errors -Wall -c driver.c
clean:
		rm -f iofunctions.o homework5 driver.o
