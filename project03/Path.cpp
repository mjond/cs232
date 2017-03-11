/*
	Path class stores PATH directories in a vector 
	and provides function to search the directories

	CS232 Norman
	@author Mark Davis mjd85
	partner: Andrew Corum amc49
	March 8, 2017
*/

#include "Path.h"

/*
	@author Mark Davis
	Path class constructor

	retrieves the PATH variable and stores the directories in a vector
*/
Path::Path()
{
	path = getenv("PATH"); //get PATH environment variable
	char* pch;
	pch = strtok (path, ":"); //invoke seperator value to seperate directories
	while (pch != NULL)
	{
		filePath.push_back(pch); //push each directory into the vector
		pch = strtok(NULL, ":");
	}
}

/*
	@author Mark Davis

	find(const string& program) searches the directories vector
	and searches for a given program
	
	parameter: program, a string

	return: programIndex, index of the given program
*/
int Path::find(const string& program)
{
	int programIndex;
	DIR *dir;
	//initiate dirent object
	struct dirent *ent;
	//loop through directory vector for given program 
	for (unsigned i = 0; i < filePath.size(); i++) {
		//if index value is not null
		if ((dir = opendir(filePath[i])) != NULL) { 
			//while dirent value not null
			while ((ent = readdir(dir)) != NULL) { 
				if (ent->d_name == program) {
					programIndex = i; 
				}
			}
			closedir(dir);
		}
	}
	//return index of the given program
	return programIndex;
}

/*
	@author Mark Davis
	
	getDirectory(int i) searches for a directory given a specific index

	parameter: int i

	return: filePathCopy - a string of the directory
*/
char* Path::getDirectory(int i) const
{
	if (i > filePath.size()) {
		//throw error if index is out of range
		throw range_error("index is out of range");
	}
	//else return the directory at given index
	char* filePathCopy = filePath[i];
	return filePathCopy;
}