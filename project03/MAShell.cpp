/*
 * MAShell.cpp contains the run() functionality for the command shell
 *
 *
 * CS232 Norman
 * @author Mark Davis, mjd85
 * @author Andrew Corum, amc49
 * March 11, 2017
 */

#include "MAShell.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <exception>

/*
 * MAShell class constructor
 */
MAShell::MAShell() {

}

/*
 * MAShell run() method
 * Postcondition: Shell is running
 */
void MAShell::run() {
	Path myPath;
	Environment myEnv;	
	
	// Run the shell
	while(true) {
		Prompt myPrompt;
		cout << myPrompt.get() << "$ " << flush;
		if (cin.peek() == '\n') { cin.ignore(INT_MAX, '\n'); }
		CommandLine myCL(cin);

		//exit command handler
		if (!strcmp(myCL.getCommand(), "exit")) { break; }

		//pwd command handler
		if (!strcmp(myCL.getCommand(), "pwd")) { myPrompt.get(); }

		//cd command handler
		if (!strcmp(myCL.getCommand(), "cd")) {
			int rc = chdir(myCL.getArgVector(1));
			if (rc < 0) {
				cerr << "Cannot find directory: " << myCL.getArgVector(1) << endl;
			}
			continue;
		}
	
		char* filePath = new char[255];
		//Find program and create file path
		try {
		strcpy(filePath, myPath.getDirectory(myPath.find(myCL.getCommand())));
		} catch (exception& e) {
			cerr << "Can't find command: " << myCL.getCommand() << endl;
			continue;
		}
		strcat(filePath, "/");
		strcat(filePath, myCL.getCommand());

		int status;
		// fork the process
		pid_t pid = fork();

		// fork failure
		if (pid == -1) {
			cerr << endl << "Fork Failed!" << endl;
		}
		
		if (pid == 0) {
			//execve(filePath, myCL.getArgVector(), NULL);
			execve(filePath, myCL.getArgVector(), myEnv.getEnv());
		} else {
			if (myCL.noAmpersand()) {
				waitpid(pid, &status, WUNTRACED | WCONTINUED);
			}
		}
	}
}
