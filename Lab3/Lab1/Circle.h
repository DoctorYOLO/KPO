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

class CircleCreator
{
public:
	static CCircle *GetInstance(double radius)
	{
		if (!m_instance)
		{
			m_instance = new CCircle(radius);
		}
		return m_instance;
	}
private:
	static CCircle *m_instance;
};