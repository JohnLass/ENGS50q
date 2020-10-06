/* listfun.c --- 
 * 
 * 
 * Author: John J. Lass
 * Created: Fri Oct  2 14:29:12 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include "listfun.h" 

car_t *makecar(char *platep,double price,int year) {
	 car_t *cp=NULL;
	 if((cp = (car_t*)malloc(sizeof(car_t)))==NULL) {
		 printf("[Error: malloc failed allocating car]\n");
		 return NULL;
	 }
	 cp->next = NULL;
	 strcpy(cp->plate,platep);
	 cp->price=price;
	 cp->year=year;
	 printf("Car created\n");
	 return cp;
 }

void print_node(car_t *cp){
	if(cp == NULL){
		printf("passed a null pointer\n");
	}else{
		printf("The car's licence plate is: %s\n", cp->plate);
		printf("The car's price is: %lf\n", cp->price);
		printf("The car's year is: %d\n", cp->year);
	}
	return;
}

void make_list(void){
	car_t * firstp = makecar("8008135", 60.4, 2020);
	car_t * secondp = makecar("p", 6020.2, 2003);
	car_t * lastp = makecar("rfc47", 3932.9, 20120);
	lput(lastp);
	lput(secondp);
	lput(firstp);
	return;
}

bool checkcar(car_t *cp, char *platep, double price, int year){
	if(cp->price != price)
		return false;
	if(strcmp(cp->plate,platep) != 0)
		return false;
	if(cp->year != year)
		return false;
	return true;
}

	
