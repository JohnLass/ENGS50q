/* mult2.test.c --- makes two queues with 2 different data types, also closes a queue with multiple entries
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 12:17:19 2020 (-0400)
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



typedef struct truck{
	int price;
	int year;
	char motor_type; 
}truck;



int main(void){
	queue_t *first_q, *second_q, *third_q;
	

	car_t *car1 = makecar("car11", 11.1, 2031);
	car_t *car2 = makecar("car12", 12.1, 2032);
	car_t *car3 = makecar("car21", 123.1, 20531);
	truck *truck1, *truck2;
	truck *testp;
	car_t *testp2;
	

	first_q = qopen();
	second_q = qopen();
	third_q = qopen();
	
	qput(first_q, car1);
	qput(first_q, car2);
	qput(first_q, car3);
	
	truck1  = (truck *) malloc(sizeof(truck));
	truck1->price = 15;
	truck1->year = 2015;
	truck1->motor_type = 'e';

	truck2  = (truck *) malloc(sizeof(truck));
	truck2->price = 1500;
	truck2->year = 2019;
	truck2->motor_type = 'g';

	qput(second_q, truck1);
	qput(second_q, truck2);

	qput(third_q, car1);
	qput(third_q, truck2);
	
	testp = qget(second_q);
	
	
	if(testp->price != 15){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}
	
	if(testp->year != 2015){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}

	if(testp->motor_type != 'e'){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}


	free(testp);


	testp2 = qget(third_q);

	if(!(checkcar(testp2,"car11", 11.1, 2031))){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}

	testp = qget(third_q);
	
	if(testp->price != 1500){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}
	
	if(testp->year != 2019){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}

	if(testp->motor_type != 'g'){
		printf("fail\n");
		exit(EXIT_FAILURE);
	}

	
	qclose(first_q);
	qclose(second_q);
	qclose(third_q);

	exit(EXIT_SUCCESS);
}
