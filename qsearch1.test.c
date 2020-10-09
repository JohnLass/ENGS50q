/* qsearch1.test.c --- 
 * 
 * 
 * Author: John J. Lass
 * Created: Fri Oct  9 00:10:39 2020 (-0400)
 * Version: 
 * 
 * Description: Program to test the funtionality of queue search feature
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
	car_t *p2 = makecar("car2", 128.3, 800);
	car_t *p3 = makecar("car3", 8.3, 22800);
	bool (*fn)(void *cp, const void* keyp);
	car_t *testp;
	
	fn = searchfn;
	q = qopen();
	
	qput(q, p1);
	qput(q, p2);
	qput(q, p3);
	
	testp = qsearch(q,fn,"p6");
	print_node((void *)testp);
	qclose(q);
	
	exit(EXIT_SUCCESS);
}
