Homework9: $HOME/tools/libHomework9.so
		gcc -dynamiclib -o libHomework9.so Homework9.o
		mv libHomework9.so $HOME/tools/libHomework9.so
Homework9.o: homework9.c
		gcc -ansi -pedantic-errors -Wall -fPIC -I $JAVA_HOME/include -I $JAVA_HOME/include/linux -c Homework9.c
Homework9.h: Homework9.java
		javah -classpath . Homework9
		javac Homework9.java
