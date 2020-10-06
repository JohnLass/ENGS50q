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
	queue_t *newq;
	newq = qopen();
	
	car_t *p1 = makecar("keystone",40.4,595);
	//	car_t *p2 = makecar("the",55,55);

		qput(newq,p1);
		//	qput(newq,p2);
		//p1 = qget(newq);
#if 0	
	if(!checkcar(p,"keystone",40.4,595)){
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}	
	//print_node(testp);
	*/
	qclose(newq);
	//	free(p);
	//free(newq);
#endif
	free(p1);
	//free(p2);
	qclose(newq);
	exit(EXIT_SUCCESS);
}
