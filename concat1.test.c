/* concat1.test.c --- first test on concat
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 16:50:23 2020 (-0400)
 * Version: 
 * 
 * Description: makes 2 queuea of cars, concatonates, then checks to see if it concatonated correctly
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"
#include "listfun.h"


int main(void){
	queue_t *first_q;
	queue_t *second_q;

	car_t *car11 = makecar("car11", 11.1, 2031);
	car_t *car12 = makecar("car12", 12.1, 2032);
	car_t *car21 = makecar("car21", 123.1, 20531);
	car_t *car22 = makecar("car22", 11.441, 231);
	car_t *testp;

	first_q = qopen();
	second_q = qopen();

	qput(first_q, car11);
	qput(first_q, car12);
	qput(second_q, car21);
	qput(second_q, car22);

	qconcat(first_q,second_q);
	
	testp = qget(first_q);
	
	
	if(!checkcar(testp,"car11", 11.1, 2031)){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}
	free(testp);
	testp = qget(first_q);
	
	
	if(!checkcar(testp,"car12", 12.1, 2032)){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}
	free(testp);
	testp = qget(first_q);

	if(!checkcar(testp,"car21", 123.1, 20531)){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}
	free(testp);
		
	qclose(first_q);


	exit(EXIT_SUCCESS);
}
