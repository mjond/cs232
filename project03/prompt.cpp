#include "prompt.h"

Prompt::Prompt()
{
	path = getcwd(buffer, PATH_MAX + 1);
}

char* Prompt::get() const
{
	return path;
}