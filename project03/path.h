#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Path {
public:
	Path();
	int find(const string& program);
	string getDirectory(int i);

private:
	//vector to store the directories
	vector<string> filePath;

	//path variable
	char* pPath;
};