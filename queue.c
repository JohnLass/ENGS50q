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

void debugq(queue_t *cp){
	if(cp!=NULL){
		printf("Queue has been created\n");
		rq_t *ptr = (rq_t*)cp;
		printf("This is the front pointer: %p\n",(void *) ptr->front);
		printf("This is the back pointer: %p\n", (void *)ptr->back);
		
		if(ptr->front != NULL){
			ll_t *incp;
			for(incp=ptr->front; incp!=NULL; incp = incp->next){
				printf("This is the ll_t's next: %p\n",(void *)incp->next);
				if(incp->data != NULL){
					printf("Node's data is not empty\n");
				}else{
					printf("Node's data is empty\n");
				}
			}
			
		}
		
	}
	else{
		printf("This should point to nil %p\n", cp);
	}
}

queue_t* qopen(void) {
	// ll_t* fptr=(ll_t*)malloc(sizeof(ll_t));
	rq_t* ptr=(rq_t*)malloc(sizeof(rq_t));

	// fptr=NULL;
	ptr->front=NULL;
	ptr->back=NULL;
	//	debugq((queue_t*)ptr);
	return((queue_t*)ptr);
}

void qclose(queue_t *qp){
	ll_t *hold=NULL;
	
	if(qp!=NULL){
		rq_t *ptr=(rq_t*)qp;
		//debugq((queue_t*) ptr);
		//printf("This is ptr's front %p\n", (void*) ptr->front);
		if(ptr->front!=NULL){
			//ll_t *incp;
			//debugq((queue_t*) ptr);
			/*for(incp=ptr->front; incp!=NULL;){
				if(incp->data!=NULL){
					free(incp->data);
				}
				hold=incp->next;
				incp = NULL;
				//printf("This is incp %p\n", (void*)incp);
				free(incp);
				incp = hold;
				
				//	debugq((queue_t*)ptr);
				}*/
			do{
				if(ptr->front->data!=NULL){
					free(ptr->front->data);
				}
				hold = ptr->front;
				ptr->front = hold->next;
				free(hold);
				
			}	while(ptr->front != NULL);
		}
		//	debugq((queue_t*)ptr);
		//ptr->front = NULL;
		//ptr->back = NULL;
		//ptr = NULL;
		//debugq((queue_t*)ptr);
		free(ptr);
		//	debugq((queue_t*)ptr);
	}
}


int32_t qput(queue_t *qp, void *elementp){
	int32_t rtrn = 1;

	if(qp!=NULL){
		if(elementp!=NULL){
			 //if both arguments are valid, need to cast the qp and allocate space for new node
			 rq_t *ptr = (rq_t*)qp;
			 ll_t *newp;
			 if( (newp = (ll_t*) malloc(sizeof(ll_t))) == NULL)
				 return rtrn;
			 newp->data = elementp;
			 newp->next = NULL;
			 //if it isnt the first thing reassign the back thing in list to point to new one and reassign back pointer
			 if(ptr->front != NULL){
				 ptr->back->next = newp;
				 ptr->back = newp;
			 }else{
				 //set front and back to new thing
				 ptr->front = newp;
				 ptr->back = newp;			 
			 }
			 rtrn = 0;
		}
	}
	//debugq(qp);
	return rtrn;
}





void* qget(queue_t *qp){
	void *rtrn = NULL;

	if(qp!=NULL){
		rq_t *ptr = (rq_t *) qp;
		if(ptr->front != NULL){
			ll_t *hold = NULL;
			hold = ptr->front;
			

			if(ptr->front == ptr->back)
				ptr->back = NULL;

			ptr->front = hold->next;
			rtrn = hold->data;
			free(hold);

		}else{
			printf("queue is empty\n");
		}

	}
	
	return rtrn;
}




void qapply(queue_t *qp, void (*fn)(void* elementp)){
	/*
	if(qp!=NULL){
		rq_t *ptr = (rq_t *) qp;
		ll_t *front = NULL;
		for(incp=ptr->front; incp!=NULL; incp=incp->next){
			fn(incp);
		}
		}*/
}



void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);




void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);



void qconcat(queue_t *q1p, queue_t *q2p);
