/*
 * CommandLine.h is the CommandLine class header file
 *
 * CS232 Norman
 * @author Andrew Corum, amc49
 * partner: Mark Davis, mjd85
 * March 11, 2017
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;

private:
	vector<string> argv;
	bool noAmp;
};
