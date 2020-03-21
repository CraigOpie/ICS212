homework7a: driver.o iofunctions.o paint.o
		gcc -o homework7a driver.o iofunctions.o paint.o
driver.o: driver.c
		gcc -ansi -pedantic-errors -Wall -c driver.c
iofunctions.o: iofunctions.c
		gcc -ansi -pedantic-errors -Wall -c iofunctions.c
paint.o: paint.c
		gcc -ansi -pedantic-errors -Wall -c paint.c
ready:
		touch driver.c iofunctions.c paint.c
clean:
		rm -f *.o homework7a
