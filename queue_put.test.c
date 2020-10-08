/* queue_put.test.c --- Checks if que put and get work with multiple emtries
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Tue Oct  6 02:19:32 2020 (-0400)
 * Version: 
 * 
 * Description: puts two things in a queue and gets both of them then closes
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"
#include "listfun.h"


int main(void){
	queue_t *newq = NULL;
	car_t *first_item = makecar("keystone",40.4,595);
	car_t *second_item = makecar("etna",50,40);
	car_t *testp = NULL;

	newq = qopen();
	qput(newq,first_item);
	qput(newq,second_item);
	testp = qget(newq);
	

	if(!checkcar(testp,"keystone",40.4,595)){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}
	
	free(testp);
	testp = qget(newq);

	if(!checkcar(testp,"etna",50,40)){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}

	free(testp);
	qclose(newq);
	 
	exit(EXIT_SUCCESS);
}
