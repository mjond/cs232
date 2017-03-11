/*
 * MAShell.h is the header file for the MAShell
 *
 * CS232 Norman
 * @author Mark Davis, mjd85
 * @authro Andrew Corum, amc49
 * March 11, 2017
 */

#include <iostream>
#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"
#include "Environment.h"

using namespace std;

class MAShell {
public:
	MAShell();
	//virtual ~MAShell();
	void run();
};

