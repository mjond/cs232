/*
	Prompt class represents the command line prompt

	CS232 Norman
	@author Mark Davis mjd85
	partner: Andrew Corum amc49
	March 8, 2017
*/
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <string>

using namespace std;

class Prompt {
public:
	//public methods
	Prompt(); //constructor
	char* get() const; //accessor

private:
	//private variables
	char buffer[PATH_MAX + 1]; //variable to hold current path
	char* path;
};