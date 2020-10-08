/* apply1.test.c --- tests apply on a 3 car list
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 13:34:13 2020 (-0400)
 * Version: 
 * 
 * Description puts three cars in a list, declares print node and passes print node to the qapply funtion, then closes queue: 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listfun.h"
#include "queue.h"

int main(void){
	queue_t *q;
	car_t *p1 = makecar("car1", 28.3, 2800);
	car_t *p2 = makecar("car2", 128.3, 800);
	car_t *p3 = makecar("car3", 8.3, 22800);
	void (*fn)(void *cp);
	car_t *testp;
	
	fn = print_node;
	q = qopen();

	qput(q, p1);
	qput(q, p2);
	qput(q, p3);
	qapply(q, fn);

	testp = qget(q);
	print_node(testp);

	free(testp);
	
	qclose(q);
	
	exit(EXIT_SUCCESS);
}
