CFLAGS=-Wall -pedantic -std=c11 -g

all:	listtest1 

listtest1.o:	listtest1.c list.h listfun.h
							gcc $(CFLAGS) -c listtest1.c

listtest1:	listtest1.o	list.o listfun.o
						gcc $(CFLAGS) list.o listfun.o listtest1.o -o listtest1	
clean:
				rm -f *.o listtest1
