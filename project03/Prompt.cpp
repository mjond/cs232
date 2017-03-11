/*
	Prompt class represents the command line prompt

	CS232 Norman
	@author Mark Davis mjd85
	partner: Andrew Corum amc49
	March 8, 2017
*/
#include "Prompt.h"

/*
	@author Mark Davis
	Prompt class constructor

	retrieves current working directory using getcwd()
*/
Prompt::Prompt()
{
	path = getcwd(buffer, PATH_MAX + 1); //get current working directory
}

/*
	@author Mark Davis
	Prompt class accessor

	returns current working directory
*/
char* Prompt::get() const
{
	return path; //return path variable
}