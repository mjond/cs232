/*
CS232, Project 1 - System Calls
Mark Davis  mjd85
February 8, 2017
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>

char *message = "msg"; //variable for message
char *control = "ctrl-c doesn't work"; //variable for when cntrl-c is pressed
bool interrupt = false; //variable for interruptsll
int time = 5; //variable for time

/*

*/
void handleAlarm(int sign) {
	printf("%s\n", message);
	alarm(time);
}

/*

*/
void sigintHandler(int sign) {
	printf("%s\n", control);
}

/*

*/
int main(int argc, char *argv[])
{
	if (argc < 1) //if there are no arguments
		return 0; //quit the program
	
	//loop through command line arguments to find values
	for (int i = 0; i < argc ; i++) {
		if(strcmp(argv[i], "+i") == 0) { //if interrupts are on
			interrupt = true; //set interrupt to 1 for 'on'
		}
		if(strcmp(argv[i], "-i") == 0) { //if interrupts are off
			interrupt = false; //set interrupt to 0 for 'off'
		}
		if(strcmp(argv[i], "+t") == 0) { //switch for time
			time = atoi(argv[i+1]); //assign value of argument in front of the time switch
		}
		if(strcmp(argv[i], "-m") == 0) { //switch for alternate message
			message = argv[i+1]; //assign value of argument in front of the message switch
		}
	}
	printf("%s\n", message);
	printf("%d\n", interrupt);
	printf("%d\n", time);

	if (interrupt) {
		signal(SIGINT, sigintHandler);
	}

	signal(SIGALRM, handleAlarm); //bind the handler to the signal

	//loop for sending the anoying message
	for(;;) {
		alarm(time);
		pause();
	}

	return 0;
}

