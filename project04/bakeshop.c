/*
CS232, Project 2 - Process Synchchronization
Mark Davis  mjd85
April 5, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <semaphore.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

int availableBread = 0; //tracks amount of available bread
int totalBread = 0; //tracks total loaves baked
int customersWaiting = 0; //tracks number of waiting customers
long customerId; //holds customer who has customer semaphore
int customerCheckedOut = 0;
int breadSold = 0;

sem_t customerSem; //semaphore for customer actions
sem_t bakerSem; //semaphore for obtaining/buying bread
sem_t storeSem; //semaphore for baker baking and checking out


/*
Author: Mark Davis
parameter: none
return: void
function: baker checks out customers while not baking
*/
void* bakerCheckingOut() {
	while (customerCheckedOut < 10) { //while not all the customers are checked out
		if (breadSold > customerCheckedOut) { //check if the bread sold is 
			sem_wait(&bakerSem);
			//process payment
			fprintf(stderr, "Baker hands out receipt to customer #%ld \n", customerId);
			customerCheckedOut++;
			sem_post(&bakerSem);			
		}

	}
}


/*
Author: Mark Davis
parameter: none
return: void
function: baker bakes bread while not at cash register
*/
void* bakerBaking() {
	while (totalBread < 10) { //bake bread until 10 loaves total have been made
		sem_wait(&bakerSem); //open semaphore
		availableBread++;
		totalBread ++;
		fprintf(stderr, "Loaf of bread is available \n");
		sem_post(&bakerSem); //close semaphore
	}
	fprintf(stderr, "All loaves baked - baker is finished \n");
}


/*
Author: Mark Davis
parameter: Customer thread id
return: void
function: customers enter store when not full, obtain bread when available, 
		pay for bread, leave store
*/
void *customer(void *id) {
	long tempId; //local variable to hold customer id
	tempId = (long)id;

	fprintf(stderr, "Customer #%ld in the store\n", tempId);
	sem_wait(&storeSem); //open store semaphore

	sem_wait(&customerSem); //open customer semaphore
	customerId = (long)id; //store customer id in global variable for bakerCheckingOut to access
	//if there is no bread available, wait
	while (availableBread == 0) {
		usleep(1);
	}
	fprintf(stderr, "Customer #%ld obtains a loaf of bread\n", tempId);
	availableBread--; //one less bread is available
	breadSold++; //add one to total bread sold

	fprintf(stderr, "Customer #%ld paid\n", tempId);
	fprintf(stderr, "Customer #%ld gets receipt\n", tempId);

	//bakerCheckingOut();
	fprintf(stderr, "Customer #%ld leaves the store\n", tempId);

	//close semaphores
	sem_post(&customerSem);
	sem_post(&storeSem);
}


/*
Author: Mark Davis
parameter: none
return: 0
function: initiate semaphores, create threads and bind them to their proper functions,
	 exit when all threads have exited
*/
int main() {
	fprintf(stderr, "********* Bakery is starting up *********\n");

	//initiate semaphors
	sem_init(&customerSem, 0, 1);
	sem_init(&bakerSem, 0, 1);
	sem_init(&storeSem, 0, 5);

	pthread_t t[12]; ///initialize threads
	//create threads for baker baking and checking out
	pthread_create (&t[0], NULL, bakerBaking, NULL);
	pthread_create (&t[1], NULL, bakerCheckingOut, NULL);

	//create thread for each customer
	pthread_create (&t[2], NULL, customer, (void*) 1);
	pthread_create (&t[3], NULL, customer, (void*) 2);
	pthread_create (&t[4], NULL, customer, (void*) 3);
	pthread_create (&t[5], NULL, customer, (void*) 4);
	pthread_create (&t[6], NULL, customer, (void*) 5);
	pthread_create (&t[7], NULL, customer, (void*) 6);
	pthread_create (&t[8], NULL, customer, (void*) 7);
	pthread_create (&t[9], NULL, customer, (void*) 8);
	pthread_create (&t[10], NULL, customer, (void*) 9);
	pthread_create (&t[11], NULL, customer, (void*) 10);

	pthread_exit(NULL);
	return 0;
}