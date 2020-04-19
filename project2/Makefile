# Executables to build using 'make all'
EXECUTABLES = project project_debug

# The default compiler
CC = g++

# The FLAGS variables sets compile flags for the CC
CFLAGS = -c -ansi -pedantic-errors -Wall
DFLAGS = -c -ansi -pedantic-errors -Wall -DDEBUGMODE

# The object files to be linked
OBJS = userinterface.o llist.o
DOBJS = userinterface_debug.o llist_debug.o

# Make commands
all: $(EXECUTABLES)

# Alter the existing files
ready:
		touch userinterface.cpp llist.cpp
clean:
		rm -f $(EXECUTABLES) $(OBJS) core.*

# Create project
project: $(OBJS)
		$(CC) -o project $(OBJS)
llist.o: llist.cpp llist.h record.h
		$(CC) $(CFLAGS) llist.cpp
userinterface.o: userinterface.cpp userinterface.h
		$(CC) $(CFLAGS) userinterface.cpp

# Create project_debug
project_debug: $(DOBJS)
		$(CC) -o project_debug $(OBJS)
llist_debug.o: llist.cpp llist.h record.h
		$(CC) $(DFLAGS) llist.cpp
userinterface_debug.o: userinterface.cpp userinterface.h
		$(CC) $(DFLAGS) userinterface.cpp
