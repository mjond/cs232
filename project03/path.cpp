#include "path.h"

Path::Path()
{
	pPath = getenv("PATH");

	pch = strtok (pPath, ":");

}

int Path::find(const string& program)
{
	return 0;
}

string Path::getDirectory(int i)
{
	return 0;
}