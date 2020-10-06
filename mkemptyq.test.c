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


int main(void) {

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
}
	
