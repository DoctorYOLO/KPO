#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include "MyFunctions.h"

using namespace std;

MyFunctions::MyFunctions()
{
}

MyFunctions::~MyFunctions()
{
}

double MyFunctions::StrToDouble(string i)
{
	double temp;
	temp = stod(i);
	return temp;
}