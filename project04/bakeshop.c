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

bool customerWaiting;
int customersInStore = 0;
int availableBread = 0;

//have a function for the baker checking out?
void bakerCheckingOut() {

//process payment
fprintf(stderr, "Baker handed out reciept");
}


//and one for baking bread?
void bakeBread() {

}

//then one for the customers...?
void customer() {
//enter store

//wait for bread

//obtain bread and pay for bread

//

}

/*
Author: Mark Davis
parameter: none
return: 0
function: 
*/
int main() {
	//initiate semaphors
	sem_init(sem_t, )

	fprintf(stderr, "****** Bakery is starting up ******");
	pthread_t bakingThread, cashierThread, customerThread;

	pthread_create (&thread1, NULL, customer(), NULL);
	pthread_create (&thread2, NULL, customer(), NULL);
	pthread_create (&thread3, NULL, customer(), NULL);
	pthread_create (&thread4, NULL, customer(), NULL);
	pthread_create (&thread5, NULL, customer(), NULL);
	pthread_create (&thread6, NULL, customer(), NULL);
	pthread_create (&thread7, NULL, customer(), NULL);
	pthread_create (&thread8, NULL, customer(), NULL);
	pthread_create (&thread9, NULL, customer(), NULL);
	pthread_create (&thread10, NULL, customer(), NULL);


	pthread_exit(NULL);
	return 0;
}

