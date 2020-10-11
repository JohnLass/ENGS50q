/* concat2.test.c --- test concatonating empty queues
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sun Oct 11 12:16:57 2020 (-0400)
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
	queue_t *q1, *q2, *q3, *q4;
	car_t *car11 = makecar("car11", 11.1, 2031);
	car_t *car12 = makecar("car12", 1.1, 2031);
	//car_t *car21 = makecar("car21", 211.1, 31);
	
	q1 = qopen();
	q2 = qopen();
	q3 = qopen();
	q4 = qopen();

	qconcat(q1,q2);

	qput(q3, car11);
	qput(q3, car12);

	qconcat(q1,q3);

	qconcat(q1, q4);
	
	qclose(q1);


}
