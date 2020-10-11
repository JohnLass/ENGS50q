CFLAGS=-Wall -pedantic -std=c11 -g

all: mkemptyq.test first_queue.test queue_put.test mult.test put2.test get1.test mult2.test put3.test apply1.test apply2.test qsearch1.test qsearch2.test concat1.test apply3.test remove1.test remove2.test remove3.test remove4.test null.test concat2.test


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

apply1.test:	apply1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o apply1.test.o -o apply1.test

apply2.test:		apply2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o apply2.test.o -o apply2.test

apply3.test:		apply3.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o apply3.test.o -o apply3.test

qsearch1.test:	qsearch1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o qsearch1.test.o -o qsearch1.test

qsearch2.test:	qsearch2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o qsearch2.test.o -o qsearch2.test

remove1.test:	remove1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o remove1.test.o -o remove1.test

remove2.test:	remove2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o remove2.test.o -o remove2.test

remove3.test:	remove3.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o remove3.test.o -o remove3.test

remove4.test:	remove4.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o remove4.test.o -o remove4.test

null.test:	null.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o null.test.o -o null.test

concat1.test:	concat1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o concat1.test.o -o concat1.test

concat2.test:	concat2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o concat2.test.o -o concat2.test


clean:
				rm -f *.o mkemptyq.test first_queue.test queue_put.test put1.testl debugq.test mult.test put2.test get1.test mult2.test put3.test apply1.test apply2.test qsearch1.test qsearch2.test remove1.test remove2.test remove3.test concat1.test remove4.test null.test


