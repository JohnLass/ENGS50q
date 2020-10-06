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
#include <inttypes.h>

typedef struct ll {
    void *data;
	struct ll *next;
} ll_t;

typedef struct rq {
	struct ll *front;
	struct ll *back;
} rq_t;


queue_t* qopen(void) {
	// ll_t* fptr=(ll_t*)malloc(sizeof(ll_t));
	rq_t* ptr=(rq_t*)malloc(sizeof(rq_t));

	// fptr=NULL;
	ptr->front=NULL;
	ptr->back=NULL;
	return((queue_t*)ptr);
}

void qclose(queue_t *qp){
	ll_t *hold=NULL;
	if(qp!=NULL){
		rq_t *ptr=(rq_t*)qp;
		if(ptr->front!=NULL){
			ll_t *incp;
			for(incp=ptr->front; incp!=NULL;){
				if(incp->data!=NULL){
					free(incp->data);
				}
				hold=incp->next;
				free(incp);
				incp=hold;
			}
		}
		free(ptr);
	}
}


int32_t qput(queue_t *qp, void *elementp){
	int32_t rtrn = 1;
	ll_t* ob = NULL;
	if(qp!=NULL){
		if(elementp!=NULL){
			 //if both arguments are valid, need to cast the qp and allocate space for new node
			 rq_t *ptr = (rq_t*)qp;
			 ll_t *newp = (ll_t*) malloc(sizeof(ll_t));
			 newp->data = elementp;
			 //if it isnt the first thing reassign the back thing in list to point to new one and reassign back pointer
			 if(ptr->front != NULL){
				 ob = ptr->back;
				 ob->next = newp;
				 ptr->back = newp;
			 }else{
				 //set front and back to new thing
				 ptr->front = newp;
				 ptr->back = newp;			 
			 }
			 rtrn = 0;
		}
	}
	return rtrn;
}





void* qget(queue_t *qp){
	void *rtrn = NULL;

	if(qp!=NULL){
		rq_t *ptr = (rq_t *) qp;
		if(ptr->front != NULL){
			ll_t *hold = NULL;
			hold = ptr->front;
			ptr->front = hold->next;
			rtrn = hold->data;
			free(hold);
		}else{
			printf("line is empty, bud\n");

		}
	}
	
	return rtrn;
}




void qapply(queue_t *qp, void (*fn)(void* elementp));



void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);




void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);



void qconcat(queue_t *q1p, queue_t *q2p);
