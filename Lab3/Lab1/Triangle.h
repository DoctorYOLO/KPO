#pragma once
#include <string>
#include "Shape.h"

class CTriangle : public Shape
{
public:
	CTriangle(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3);
	virtual double squareCalc() const;
	virtual double perimeterCalc() const;

private:
	double m_X1, m_Y1, m_X2, m_Y2, m_X3, m_Y3;
};

class TriangleCreator
{ 
public:
	static CTriangle *GetInstance(double X1, double Y1, double X2, double Y2, double X3, double Y3)
	{
		if (!m_instance)
		{
			m_instance = new CTriangle(X1, Y1, X2, Y2, X3, Y3);
		}
		return m_instance;
	}
private:
	static CTriangle *m_instance;
};
