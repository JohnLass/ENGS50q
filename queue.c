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

queue_t *front=NULL;
queue_t *back=NULL;


queue_t* qopen(void) {

	



void qclose(queue_t *qp);



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
