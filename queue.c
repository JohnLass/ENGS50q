/* queue.c --- 
 * 
 * 
 * Author: John J. Lass, Tyler Neath, Robert Carangelo
 * Created: Sun Oct  4 14:48:46 2020 (-0400)
 * Version: 1.0
 * 
 * Description:Functions to create and manioulate queues of different data 
 * types
 */

#include "queue.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ll {
    void *data;
	struct ll *next;
} ll_t;

typedef struct rq {
	struct ll *front;
	struct ll *back;
} rq_t;


queue_t* qopen(void) {
	ll_t* fptr=(ll_t*)malloc(sizeof(ll_t));
	rq_t* ptr=(rq_t*)malloc(sizeof(rq_t));

	// fptr=NULL;
	ptr->front=fptr;
	ptr->back=fptr;
	return((queue_t*)ptr);
}

void qclose(queue_t *qp){
	rq_t *ptr=(rq_t*)qp;
	ll_t *incp;
	for(incp=ptr->front; incp!=NULL; incp=incp->next){
		free(incp);
	}
	free(ptr);
}


int32_t qput(queue_t *qp, void *elementp);


void* qget(queue_t *qp);



void qapply(queue_t *qp, void (*fn)(void* elementp));



void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);




void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);



void qconcat(queue_t *q1p, queue_t *q2p);
