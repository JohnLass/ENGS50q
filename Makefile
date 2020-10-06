CFLAGS=-Wall -pedantic -std=c11 -g

all: mkemptyq.test 


mkemptyq.test.o:	mkemptyq.test.c queue.h
									gcc $(CFLAGS) -c mkemptyq.test.c


mkemptyq.test:	mkemptyq.test.o	queue.o 
								gcc $(CFLAGS) queue.o mkemptyq.test.o -o mkemptyq.test	

clean:
				rm -f *.o 
