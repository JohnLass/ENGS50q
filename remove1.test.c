/* remove1.test.c --- first test on qremove to see if it works
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sat Oct 10 13:19:04 2020 (-0400)
 * Version: 
 * 
 * Description: removes an item from the middle of the queue
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
	
	testp = qremove(q,fn,(void *) p2);
	

	if(!(checkcar(testp, "car2", 128.3, 800))){
		printf("Failed1\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	testp = qget(q);


	if(!(checkcar(testp, "car1", 28.3, 2800))){
		printf("Failed2\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	testp = qget(q);
	

	if(!(checkcar(testp, "car3", 8.3, 22800))){
		printf("Failed3\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	
	qclose(q);

	
	exit(EXIT_SUCCESS);
}
