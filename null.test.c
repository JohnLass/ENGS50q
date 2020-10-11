/* remove5.test.c --- tests sending a null pointer to a bunch of different functions
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sun Oct 11 11:55:55 2020 (-0400)
 * Version: 
 * 
 * Description: Teats sending a null argument to concat, remove, search and apply
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listfun.h"
#include "queue.h"
#include <stdbool.h>

int main(void){
	queue_t *q1 = NULL;
	queue_t *q2 = NULL;
	car_t *testp;
	bool (*fn) (void *cp, const void* keyp);
	void (*fn2) (void *elementp);
	
	fn = search_plate;
	
	testp = qremove(q1,fn,(void *) "car3");

	if(testp != NULL){
		printf("Fail1\n");
		exit(EXIT_FAILURE);
	}
	
	
	testp = qsearch(q1,fn,(void *) "car3");
	
	if(testp != NULL){
		printf("Fail1\n");
		exit(EXIT_FAILURE);
	}

	qconcat(q1,q2);

	
	fn2 = print_node;
	
	qapply(q1,fn2);
	
	exit(EXIT_SUCCESS);
}
