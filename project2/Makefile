project_debug: userinterface.o llist.o
		g++ -o project_debug userinterface.o llist.o
llist.o: llist.cpp llist.h record.h
		g++ -c -ansi -pedantic-errors -Wall -DDEBUGMODE llist.cpp
userinterface.o: userinterface.cpp userinterface.h
		g++ -c -ansi -pedantic-errors -Wall -DDEBUGMODE userinterface.cpp
ready:
		touch userinterface.cpp llist.cpp
clean:
		rm -f *.o project*
