/* mkemptyq.test.c --- 
 * 
 * 
 * Author: John J. Lass
 * Created: Sun Oct  4 20:59:09 2020 (-0400)
 * Version: 
 * 
 * Description: Test file for the create new queue function
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
	
