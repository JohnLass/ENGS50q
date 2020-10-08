/* get1.test.c --- tests getting from an empty queue and getting from a queue that hasn't been open
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 11:50:11 2020 (-0400)
 * Version: 
 * 
 * Description: opens a queue, gets from it, checks if null, trys getting from a queue that hasn't been opened, checks if null 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"
#include "listfun.h"


int main(void){
	queue_t *q1, *q2;
	car_t *testp, *testp2;
	
	q1 = qopen();
	q2 = NULL;
	
	testp = qget(q1);

	if(testp != NULL){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}	
	
	qclose(q1);

	testp2 = qget(q2);
	
	if(testp2 != NULL){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}	

	qclose(q2);
	
	exit(EXIT_SUCCESS);
}
