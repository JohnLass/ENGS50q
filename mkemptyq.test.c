/* mkemptyq.test.c --- tests open and close without any puts
 * 
 * 
 * Author: John J. Lass
 * Created: Sun Oct  4 20:59:09 2020 (-0400)
 * Version: 
 * 
 * Description: Opens a queue, checks to make sure it is not null and then closes it
 * 
 */

#include "queue.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	queue_t *newqp=NULL;
	newqp=qopen();

	if(newqp==NULL){
		exit(EXIT_FAILURE); 
	}
	qclose(newqp);
	exit(EXIT_SUCCESS);
}
	
