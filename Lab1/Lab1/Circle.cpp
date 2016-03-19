#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include "Circle.h"
#include "MyFunctions.h"

using namespace std;

CCircle::CCircle(double &R) :
	m_R(R) {}

double CCircle::squareCalc() const
{
	const double PI = 3.14;

	return PI * (m_R * m_R);
}

double CCircle::perimeterCalc() const
{
	const double PI = 3.14;

	return 2 * PI * m_R;
}

