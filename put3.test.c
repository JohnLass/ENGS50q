/* put3.test.c --- Tests putting to a NULL queue, and putting a NULL arguement to a real queue
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 12:06:18 2020 (-0400)
 * Version: 
 * 
 * Description: trys putting to a NULL queue, also opens a real queue, trys putting a null argument to it 
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
	car_t *p1 = NULL;
	car_t *p2 = makecar("Car1", 60.3, 2012);
	int32_t test1 = 0;
	int32_t test2 = 0;
	
	q1 = qopen();
 
	test1 = qput(q1, p1);
	
	if(test1 == 0){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}	
	
	qclose(q1);

	q2 = NULL;
	test2 = qput(q2, p2);

	if(test2 == 0){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}	

	free(p2);
	
	exit(EXIT_SUCCESS);
}
