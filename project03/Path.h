/*
	Path class stores PATH directories in a vector 
	and provides function to search the directories

	CS232 Norman
	@author Mark Davis mjd85
	partner: Andrew Corum amc49
	March 8, 2017
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdexcept>

using namespace std;

class Path {

//public methods
public:
	Path(); //constructor
	int find(const string& program); 
	char* getDirectory(int i) const;

//private variable and vector

	//vector to store the directories
	vector<char*> filePath;

	//path variable
	char* path;
};