#pragma once
#include <string>
#include "Shape.h"

class CCircle : public Shape
{
public:
	CCircle(double &r);
	virtual double squareCalc() const;
	virtual double perimeterCalc() const;

private:
	double m_R;
};

