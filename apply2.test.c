/* apply2.test.c --- calls qapply on an empty queue
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Thu Oct  8 16:20:22 2020 (-0400)
 * Version: 
 * 
 * Description: calls qapply on an empty queue
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listfun.h"
#include "queue.h"

int main(void){
	queue_t *q1, *q2;

	void (*fn)(void *cp);
	
	
	fn = print_node;
	q1 = qopen();
	q2 = NULL;
	
	qapply(q1, fn);
	qapply(q2, fn);
	
	qclose(q1);
	
	exit(EXIT_SUCCESS);
}
