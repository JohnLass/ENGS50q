/* qsearch2.test.c --- 
 * 
 * 
 * Author: John J. Lass
 * Created: Fri Oct  9 01:32:25 2020 (-0400)
 * Version: 
 * 
 * Description: 
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
	car_t *p2 = makecar("car2", 28.3, 800);
	car_t *p3 = makecar("car3", 28.3, 22800);
	bool (*fn)(void *cp, const void* keyp);
	car_t *testp;
	int yr = 22800;
	int yr2 = 2800;
	double pricec = 28.3;
	
	fn = search_plate;
	q = qopen();
	
	qput(q, p1);
	qput(q, p2);
	qput(q, p3);
	/*
	testp =(car_t *) qsearch(q,fn,(void *) "car2");
	print_node((void *)testp);


	if(!(checkcar(testp, "car2", 128.3, 800))){
		printf("Failed1\n");
		exit(EXIT_FAILURE);
	}

	fn = search_year;
	testp = (car_t *) qsearch(q,fn, &yr);
	print_node((void *)testp);
	
	if(!(checkcar(testp, "car3", 8.3, 22800))){
		printf("Failed2\n");
		exit(EXIT_FAILURE);
	}
*/
	fn = search_price;
	testp = (car_t *) qsearch(q,fn, &pricec);
	print_node((void *)testp);
	
	if(!(checkcar(testp, "car1", 28.3, 2800))){
		printf("Failed3\n");
		exit(EXIT_FAILURE);
	}

	qclose(q);

	
	exit(EXIT_SUCCESS);
}
