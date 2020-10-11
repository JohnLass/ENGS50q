/* remove4.test.c --- removes the last item and checks to make sure it worked, also checks removing from an empty queue, also checks removing from null queue
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sun Oct 11 11:36:33 2020 (-0400)
 * Version: 
 * 
 * Description: removes the third item, checks it, gets the next two and checks them, tries removing again from empty list
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
	queue_t *q;
	car_t *p1 = makecar("car1", 28.3, 2800);
	car_t *p2 = makecar("car2", 128.3, 800);
	car_t *p3 = makecar("car3", 8.3, 22800);
	bool (*fn)(void *cp, const void* keyp);
	car_t *testp;
	
	fn = search_plate;
	q = qopen();
	
	qput(q, p1);
	qput(q, p2);
	qput(q, p3);
	
	testp = qremove(q,fn,(void *) "car3");

	if(!(checkcar(testp, "car3", 8.3, 22800))){
		printf("Failed3\n");
		exit(EXIT_FAILURE);
	}
	free(testp);
	testp = qget(q);
	
	if(!(checkcar(testp, "car1", 28.3, 2800))){
		printf("Failed1\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	testp = qget(q);


	if(!(checkcar(testp, "car2", 128.3, 800))){
		printf("Failed2\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	testp = qremove(q,fn,(void *) "car3");
	

	if(testp != NULL){
		printf("Failed3\n");
		exit(EXIT_FAILURE);
	}
	
	
	testp = qremove(q,fn,(void *) "car3");	

	if(testp != NULL){
		printf("Failed3\n");
		exit(EXIT_FAILURE);
	}

	qclose(q);
	
	exit(EXIT_SUCCESS);
}
