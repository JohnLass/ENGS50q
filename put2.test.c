/* put2.test.c --- tests putting to a queue and closing it
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 11:16:21 2020 (-0400)
 * Version: 
 * 
 * Description: puts a car in a queue and then closes it
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


	newq = qopen();
	qput(newq,p1);
	

	qclose(newq);
	
	exit(EXIT_SUCCESS);
}
