CC=gcc 
AR=ar
FLAGS= -Wall -g 
OBJECTS_MAIN=main.o
OBJECTS_LIB= myBank.o myBank.h


all: mybanks mains

mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(Flags) -o mains $(OBJECTS_MAIN) libmyBank.a


mybanks: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all

clean: 
	rm -f *.o mains libmyBank.a


