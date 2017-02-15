/*
CS232, Project 1 - System Calls
Mark Davis
mjd85
February 8, 2017
*/

#include <stdio.h>
#include <string.h>
#include <signal.h>

void handleAlarm(int sign) {
	signal(SIGALRM, mypause);
	alarm(5);
}

int main(int argc, char *argv[])
{
	if (argc < 1) //if there are no arguments
		return 0; //quit the program

	char message[25] = "msg"; //variable for message
	int interrupt = 0; //variable for interruptsll
	int time = 5; //variable for time
	
	//loop through command line arguments to find values
	for (int i = 0; i < argc ; i++) {
		if(argv[i] == "+i") { //if interrupts are on
			interrupt = 1;
		}
		if(argv[i] == "-i") { //if interrupts are off
			interrupt = 0;
		}
		if(argv[i] == "+t") { //switch for time
			time = atoi(argv[i+1]); //assign value of argument in front of the time switch
		}
		if(argv[i] == "-m") { //switch for alternate message
			strcpy(message, argv[i+1]); //assign value of argument in front of the message switch
		}
	}
	printf("%s\n", message);
	printf("%s\n", interrupt);
	printf("%s\n", time);

	signal(SIGALRM, handleAlarm);
	//signal(SIGLARM, SIG_INT);
	alarm(time);

}

