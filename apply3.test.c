/* apply3.test.c --- test for passing null function to qapply 
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sat Oct 10 11:37:02 2020 (-0400)
 * Version: 
 * 
 * Description: Passes a null function to qapply and checks to make sure it gives an error message
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

	
	fn = NULL;
	q = qopen();

	qput(q, p1);
	qput(q, p2);
	qput(q, p3);
	qapply(q, fn);

	
	qclose(q);
	
	exit(EXIT_SUCCESS);
}
