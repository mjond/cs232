/*
 * Environment.cpp contains the methods to capture some of 
 * the current environment variables
 *
 * CS232 Norman
 * @author Andrew Corum, amc49
 * partner: Mark Davis, mjd85
 * March 11, 2017
 */

#include "Environment.h"
#include <stdlib.h>
#include <string.h>

/*
 * Environment class constructor
 */
Environment::Environment() {
}

/*
 * getEnv() is the return method for the environment
 * Returns: output, a char**, which contains 4 environment variables
 *          in "key=value" format
 */
char** Environment::getEnv() const {
	char** output = new char*[5];
	// PATH
	output[0] = new char[512];
	strcpy(output[0], "PATH=");
	strcat(output[0], getenv("PATH"));

	// DISPLAY
	output[1] = new char[512];
	strcpy(output[1], "DISPLAY=");
	strcat(output[1], getenv("DISPLAY"));

	// TERM
	output[2] = new char[512];
	strcpy(output[2], "TERM=");
	strcat(output[2], getenv("TERM"));

	// SHELL
	output[3] = new char[512];
	strcpy(output[3], "SHELL=");
	strcat(output[3], getenv("SHELL"));

	// NULL
	output[4] = NULL;
	return output;
}
