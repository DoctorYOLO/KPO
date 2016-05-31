#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "MyFunctions.h"

using namespace std;

string GetFiguresName(string str)
{
	if (str.find("TRIANGLE") != string::npos)
	{
		return "TRIANGLE";
	}

	if (str.find("RECTANGLE") != string::npos)
	{
		return "RECTANGLE";
	}

	if (str.find("CIRCLE") != string::npos)
	{
		return "CIRCLE";
	}
}

void PrintToFile(Shape *objShape, string figuresName, ofstream &fout)
{
	string result;
	stringstream ss;

	ss << figuresName << ":P=" << objShape->perimeterCalc() << ";S=" << objShape->squareCalc() << "\n";
	ss >> result;
	fout << result << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 2)
	{
		printf("Wrong amount of arguments\n");
		return 1;
	}

	ifstream fin;
	ofstream fout;
	string str;
	Shape *objShape = nullptr;
	MyFunctions toDouble;
	string figuresName;
	fin.open(argv[1]);
	fout.open("output.txt");

	while (getline(fin, str))
	{
		figuresName = GetFiguresName(str);
		if (figuresName == "TRIANGLE")
		{
			size_t pos1 = str.find("P1");
			size_t pos2 = str.find("P2");
			size_t pos3 = str.find("P3");
			string A = str.substr(pos1 + 3, pos2 - pos1 - 5);
			string B = str.substr(pos2 + 3, pos3 - pos2 - 5);
			string C;
			C.append(&str[pos3 + 3]);

			size_t pos = A.find(",");
			string x1 = A.substr(0, pos);
			string y1;
			y1.append(&A[pos + 1]);

			pos = B.find(",");
			string x2 = B.substr(0, pos);
			string y2;
			y2.append(&B[pos + 1]);

			pos = C.find(",");
			string x3 = C.substr(0, pos);
			string y3;
			y3.append(&C[pos + 1]);

			double X1 = toDouble.StrToDouble(x1);
			double Y1 = toDouble.StrToDouble(y1);
			double X2 = toDouble.StrToDouble(x2);
			double Y2 = toDouble.StrToDouble(y2);
			double X3 = toDouble.StrToDouble(x3);
			double Y3 = toDouble.StrToDouble(y3);

			objShape = TriangleCreator::GetInstance(X1, Y1, X2, Y2, X3, Y3);

			PrintToFile(objShape, figuresName, fout);
			
		}
		else if (figuresName == "RECTANGLE")
		{
			size_t pos1 = str.find("P1");
			size_t pos2 = str.find("P2");
			string A = str.substr(pos1 + 3, pos2 - pos1 - 5);
			string B;
			B.append(&str[pos2 + 3]);

			size_t pos = A.find(",");
			string x1 = A.substr(0, pos);
			string y1;
			y1.append(&A[pos + 1]);

			pos = B.find(",");
			string x2 = B.substr(0, pos);
			string y2;
			y2.append(&B[pos + 1]);

			double X1 = toDouble.StrToDouble(x1);
			double Y1 = toDouble.StrToDouble(y1);
			double X2 = toDouble.StrToDouble(x1);
			double Y2 = toDouble.StrToDouble(y2);
			double X3 = toDouble.StrToDouble(x2);
			double Y3 = toDouble.StrToDouble(y2);

			objShape = RectangleCreator::GetInstance(X1, Y1, X2, Y2, X3, Y3);

			PrintToFile(objShape, figuresName, fout);
		}
		else if (figuresName == "CIRCLE")
		{
			size_t pos = str.find("R=");
			string R;
			R.append(&str[pos + 2]);
			double r = toDouble.StrToDouble(R);

			objShape = CircleCreator::GetInstance(r);

			PrintToFile(objShape, figuresName, fout);
		}
	}
	if (objShape != nullptr)
		delete objShape;
	fin.close();
	fout.close();
	system("pause");
	return 0;
}

