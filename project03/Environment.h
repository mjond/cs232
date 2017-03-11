/*
 * Environment.h is the header file for the Environment Class
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

class Environment {
public:
	Environment();
	char** getEnv() const;
};
