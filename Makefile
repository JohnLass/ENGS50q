CFLAGS=-Wall -pedantic -std=c11 -g

all: mkemptyq.test first_queue.test queue_put.test mult.test put2.test get1.test mult2.test put3.test                                            

%.o:  %.test.c listfun.h list.h queue.h
			gcc $(CFLAGS) -c $<  

mkemptyq.test:		mkemptyq.test.o	queue.o 
									gcc $(CFLAGS) queue.o mkemptyq.test.o -o mkemptyq.test	

first_queue.test:	first_queue.test.o	queue.o list.o listfun.o
									gcc $(CFLAGS) queue.o list.o listfun.o first_queue.test.o -o first_queue.test	

queue_put.test:		queue_put.test.o	queue.o list.o listfun.o
									gcc $(CFLAGS) queue.o list.o listfun.o queue_put.test.o -o queue_put.test

put2.test:		put2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o put2.test.o -o put2.test

put3.test:		put3.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o put3.test.o -o put3.test

get1.test:		get1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o get1.test.o -o get1.test

debugq.test:		debugq.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o debugq.test.o -o debugq.test

mult.test:		mult.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o mult.test.o -o mult.test

mult2.test:		mult2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o mult2.test.o -o mult2.test



clean:
				rm -f *.o mkemptyq.test first_queue.test queue_put.test put1.testl debugq.test mult.test put2.test get1.test mult2.test put3.test


