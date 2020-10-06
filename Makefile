CFLAGS=-Wall -pedantic -std=c11 -g

all:	first_queue.test mkemptyq.test 

first_queue.test.o:	first_queue.test.c queue.h
										gcc $(CFLAGS) -c first_queue.test.c

mkemptyq.test.o:	mkemptyq.test.c queue.h
									gcc $(CFLAGS) -c mkemptyq.test.c

first_queue.test:	first_queue.test.o	queue.o 
									gcc $(CFLAGS) queue.o first_queue.test.o -o first_queue.test	

mkemptyq.test:	mkemptyq.test.o	queue.o 
								gcc $(CFLAGS) queue.o mkemptyq.test.o -o mkemptyq.test	

clean:
				rm -f *.o 
