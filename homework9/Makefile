libHomework9.so: Homework9.o
		gcc -shared -o libHomework9.so Homework9.o
Homework9.o: Homework9.c Homework9.h Homework9.class Homework9.java
		gcc -ansi -pedantic-errors -Wall -fPIC -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" -c Homework9.c
Homework9.h: Homework9.java Homework9.class Homework9.java
		javah -classpath . Homework9
Homework9.class: Homework9.java		
		javac Homework9.java
clean:
		rm libHomework9.so Homework9.o Homework9.h Homework9.class
ready:
		touch Homework9.java Homework9.c

