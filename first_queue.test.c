/* first_queue.test.c --- makes a queue and puts one thing in it and checks if it worked
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Mon Oct  5 20:29:11 2020 (-0400)
 * Version: 
 * 
 * Description: 
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
	car_t *testp = NULL;

	newq = qopen();
	qput(newq,first_item);
	testp = qget(newq);
	
	if(!checkcar(testp,"keystone",40.4,595)){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}
	
	//print_node(testp);
	
	free(testp);
	qclose(newq);
	//free(newq);
	exit(EXIT_SUCCESS);
}
