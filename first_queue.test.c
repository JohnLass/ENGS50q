/* first_queue.test.c --- makes a queue and puts one thing in it and checks if it worked
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Mon Oct  5 20:29:11 2020 (-0400)
 * Version: 
 * 
 * Description: puts one car in a queue, gets it, checks if it worked and closes the queue
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"
#include "listfun.h"


int main(void){
	queue_t *newq;
	car_t *p1 = makecar("keystone",40.4,595);
	car_t *p2;

	newq = qopen();
	qput(newq,p1);
	
	p2 = qget(newq);

	if(!checkcar(p2,"keystone",40.4,595)){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}	
	
	free(p2);
	qclose(newq);
	
	exit(EXIT_SUCCESS);
}
