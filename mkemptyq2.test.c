/* mkemptyq2.test.c --- 
 * 
 * 
 * Author: John J. Lass
 * Created: Sun Oct  4 22:12:24 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
queue_t *newqp=NULL;
	queue_t *new1qp=NULL;
	queue_t *new2qp=NULL;

	newqp=qopen();
	new1qp=qopen();
	new2qp=qopen();

	if(newqp==NULL || new1qp==NULL || new2qp==NULL){

		exit(EXIT_FAILURE);

	}else{

		exit(EXIT_SUCCESS)

			}
	
