#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "Triangle.h"
#include "MyFunctions.h"

using namespace std;

CTriangle::CTriangle(double &X1, double &Y1, double &X2, double &Y2, double &X3, double &Y3) :
	m_X1(X1), m_Y1(Y1), m_X2(X2), m_Y2(Y2), m_X3(X3), m_Y3(Y3) {}

double CTriangle::squareCalc() const
{
	double a = fabs(sqrt(((m_X2 - m_X1) * (m_X2 - m_X1)) + ((m_Y2 - m_Y1) * (m_Y2 - m_Y1))));
	double b = fabs(sqrt(((m_X3 - m_X2) * (m_X3 - m_X2)) + ((m_Y3 - m_Y2) * (m_Y3 - m_Y2))));
	double c = fabs(sqrt(((m_X3 - m_X1) * (m_X3 - m_X1)) + ((m_Y3 - m_Y1) * (m_Y3 - m_Y1))));

	return ((m_X3 - m_X2) * (m_Y2 - m_Y1) - (m_X2 - m_X1) * (m_Y3 - m_Y2)) / 2;
}

double CTriangle::perimeterCalc() const
{
	double a = fabs(sqrt(((m_X2 - m_X1) * (m_X2 - m_X1)) + ((m_Y2 - m_Y1) * (m_Y2 - m_Y1))));
	double b = fabs(sqrt(((m_X3 - m_X2) * (m_X3 - m_X2)) + ((m_Y3 - m_Y2) * (m_Y3 - m_Y2))));
	double c = fabs(sqrt(((m_X3 - m_X1) * (m_X3 - m_X1)) + ((m_Y3 - m_Y1) * (m_Y3 - m_Y1))));

	return a + b + c;
}