/*
 * CommandLine.cpp contains the methods to parse a command string
 * from an istream (typically cin).
 *
 * CS232 Norman
 * @author Andrew Corum, amc49
 * partner: Mark Davis, mjd85
 * March 11, 2017
 */

#include "CommandLine.h"
#include <algorithm>
#include <cstring>

/*
 * CommandLine class constructor
 * Input: in, an istream& (preferably cin)
 * Postcondition: 'noAmp' reflects if 'in' contains an ampersand or not
 * 								argv contains the arguments described in 'in'
 */
CommandLine::CommandLine(istream& in) {
	noAmp = true;
	string temp;

	if (in.peek() != '\n') {	// check to see if cin is empty
		while (in >> temp) {
			if (temp == "&" ) {		// note if there is an ampersand
				noAmp = false;
			} else {
				argv.push_back(temp);	// add the command/argument to argv
			}
			temp = "";
			if (in.peek() == '\n') { break; }	// break when cin is empty
		}
	}
	argv.push_back("");
}

/*
 * getCommand() is the command return method
 * Return: a char* that contains the contents of argv[0]
 */
char* CommandLine::getCommand() const {
	char* output = new char[argv[0].length()];
	strcpy(output, argv[0].c_str());
	return output;
}

/*
 * getArgCount() is the argc return method
 * Return: an int representing the # of arguments in argv
 */
int CommandLine::getArgCount() const {
	return argv.size() - 2;
}

/*
 * getArgVector() is the argv return method
 * Return: a char** containing argv
 */
char** CommandLine::getArgVector() const {
	char** output = new char*[argv.size()];
	
	// fill the each char* in output with argv[i]
	for (int i = 0; i < argv.size(); i++) {
		output[i] = new char[argv[i].length()];
		strcpy(output[i], argv[i].c_str());
	}
	output[argv.size() - 1] = NULL;
	return output;
}

/*
 * getArgVector(int i) is the indexing argv return method
 * Return: a char* containing argv[i]
 */
char* CommandLine::getArgVector(int i) const {
	char* output = new char[argv[i].length()];
	strcpy(output, argv[i].c_str());
	return output;
}

/*
 * noAmpersand() returns the 'no Ampersand' state
 * Return: a bool, noAmp
 */
bool CommandLine::noAmpersand() const {
	return noAmp;
}
