CFLAGS=-Wall -pedantic -std=c11 -g

all: mkemptyq.test first_queue.test queue_put.test


mkemptyq.test.o:	mkemptyq.test.c queue.h
									gcc $(CFLAGS) -c mkemptyq.test.c


first_queue.test.o:	first_queue.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c first_queue.test.c

queue_put.test.o:	queue_put.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c queue_put.test.c

mkemptyq.test:	mkemptyq.test.o	queue.o 
								gcc $(CFLAGS) queue.o mkemptyq.test.o -o mkemptyq.test	

first_queue.test:	first_queue.test.o	queue.o list.o listfun.o
									gcc $(CFLAGS) queue.o list.o listfun.o first_queue.test.o -o first_queue.test	

queue_put.test:		queue_put.test.o	queue.o list.o listfun.o
									gcc $(CFLAGS) queue.o list.o listfun.o queue_put.test.o -o queue_put.test

clean:
				rm -f *.o 
