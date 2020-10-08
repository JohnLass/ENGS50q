CFLAGS=-Wall -pedantic -std=c11 -g

all: mkemptyq.test first_queue.test queue_put.test put1.test put2.test debugq.test mult.test get1.test


mkemptyq.test.o:	mkemptyq.test.c queue.h
									gcc $(CFLAGS) -c mkemptyq.test.c


first_queue.test.o:	first_queue.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c first_queue.test.c

queue_put.test.o:	queue_put.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c queue_put.test.c

put1.test.o:			put1.test.c queue.h 
									gcc $(CFLAGS) -c put1.test.c

put2.test.o:			put2.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c put2.test.c

get1.test.o:			get1.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c get1.test.c

debugq.test.o:		debugq.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c debugq.test.c

mult.test.o:		mult.test.c queue.h list.h listfun.h
									gcc $(CFLAGS) -c mult.test.c

mkemptyq.test:	mkemptyq.test.o	queue.o 
								gcc $(CFLAGS) queue.o mkemptyq.test.o -o mkemptyq.test	

first_queue.test:	first_queue.test.o	queue.o list.o listfun.o
									gcc $(CFLAGS) queue.o list.o listfun.o first_queue.test.o -o first_queue.test	

queue_put.test:		queue_put.test.o	queue.o list.o listfun.o
									gcc $(CFLAGS) queue.o list.o listfun.o queue_put.test.o -o queue_put.test

put1.test:		put1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o put1.test.o -o put1.test

put2.test:		put2.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o put2.test.o -o put2.test

get1.test:		get1.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o get1.test.o -o get1.test

debugq.test:		debugq.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o debugq.test.o -o debugq.test

mult.test:		mult.test.o	queue.o list.o listfun.o
							gcc $(CFLAGS) queue.o list.o listfun.o mult.test.o -o mult.test

clean:
				rm -f *.o mkemptyq.test first_queue.test queue_put.test put1.testl debugq.test mult.test put2.test get1.test
