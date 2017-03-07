#include <iostream>
#include <unistd.h>
#include <limits.h>

using namespace std;

class Prompt {
public:
	//methods
	Prompt();
	char* get() const;
	
	//variables
	char buffer[PATH_MAX + 1];
	char* path=NULL;
};