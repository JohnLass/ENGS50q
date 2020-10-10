/* remove2.test.c --- Test on removing first element
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sat Oct 10 14:19:40 2020 (-0400)
 * Version: 
 * 
 * Description: remove first element, check its value, then check to see queue now starts with second person
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
	
	testp = qremove(q,fn,(void *) p1);
	

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
	testp = qget(q);
	

	if(!(checkcar(testp, "car3", 8.3, 22800))){
		printf("Failed3\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	
	qclose(q);

	
	exit(EXIT_SUCCESS);
}
